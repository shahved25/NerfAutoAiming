import cv2


def main():
    detector = cv2.CascadeClassifier(
        cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
    )
    if detector.empty():
        raise SystemExit("Could not load the OpenCV face detector.")

    camera = cv2.VideoCapture(0)
    try:
        if not camera.isOpened():
            raise SystemExit("Could not open the default webcam. Check camera permissions.")

        while True:
            ok, frame = camera.read()
            if not ok:
                raise SystemExit("Could not read a frame from the webcam.")

            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            faces = detector.detectMultiScale(
                gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30)
            )

            for x, y, width, height in faces:
                cv2.rectangle(frame, (x, y), (x + width, y + height), (0, 255, 0), 2)

            cv2.imshow("Face detection", frame)
            if cv2.waitKey(1) & 0xFF == ord("q"):
                break
    finally:
        camera.release()
        cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
