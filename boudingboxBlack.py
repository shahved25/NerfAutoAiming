import cv2


BLACK_THRESHOLD = 45
MIN_FRAME_FRACTION = 0.005
MIN_BOX_FILL = 0.50


def find_black_boxes(frame):
    # A pixel counts as black when all three color channels are dark.
    mask = cv2.inRange(frame, (0, 0, 0), (BLACK_THRESHOLD,) * 3)
    _, _, regions, _ = cv2.connectedComponentsWithStats(mask, connectivity=8)
    min_black_area = mask.size * MIN_FRAME_FRACTION

    # The first row describes the background of the mask.
    boxes = []
    for x, y, width, height, black_area in regions[1:].tolist():
        if black_area < min_black_area or black_area < width * height * MIN_BOX_FILL:
            continue

        boxes.append((x, y, width, height))

    return boxes


def boxes_match(first, second):
    x1, y1, width1, height1 = first
    x2, y2, width2, height2 = second
    overlap_width = max(0, min(x1 + width1, x2 + width2) - max(x1, x2))
    overlap_height = max(0, min(y1 + height1, y2 + height2) - max(y1, y2))
    overlap = overlap_width * overlap_height
    combined_area = width1 * height1 + width2 * height2 - overlap
    return overlap >= 0.5 * combined_area


def main():
    camera = cv2.VideoCapture(0)
    try:
        if not camera.isOpened():
            raise SystemExit("Could not open the default webcam. Check camera permissions.")

        previous_boxes, older_boxes = [], []
        while True:
            ok, frame = camera.read()
            if not ok:
                raise SystemExit("Could not read a frame from the webcam.")

            boxes = find_black_boxes(frame)
            # Draw only after the region matches detections in both prior frames.
            for box in boxes:
                if not any(boxes_match(box, other) for other in previous_boxes):
                    continue
                if not any(boxes_match(box, other) for other in older_boxes):
                    continue

                cv2.rectangle(frame, box, (0, 255, 0), 2)

            older_boxes, previous_boxes = previous_boxes, boxes
            cv2.imshow("Black region detection", frame)
            if cv2.waitKey(1) & 0xFF == ord("q"):
                break
    finally:
        camera.release()
        cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
