# First entry (11/18/26) - 3.5 hrs
So we didn't realize we had to be journalling while making the project, but don't worry we'll go over each part of our process here in detail. 
Firstly, we searched through online to find some inspiration for the mechanics of the robot design. We used this project (https://blog.arduino.cc/2021/05/31/a-remote-controlled-arduino-nerf-tank/) as a base point for our CAD model since we are new to CAD and this provides us with a base point for mechanical design. 
We added added a 2nd degree of motion with a rotating stationary mount that lets the Nerf dart shoot left and right. We added more capacity to the magazine and created a stationary design with bottom mount to hide wiring.

<img width="452" height="561" alt="Screenshot 2026-11-20 at 5 56 11 PM" src="https://github.com/user-attachments/assets/290cdc17-140f-4164-b75f-09dd728cd15d" />
<img width="453" height="204" alt="Screenshot 2026-11-20 at 5 55 47 PM" src="https://github.com/user-attachments/assets/4950c08f-836c-42e7-b5d0-ced78c9e18e9" />
<img width="600" height="386" alt="Screenshot 2026-11-20 at 5 55 43 PM" src="https://github.com/user-attachments/assets/c7fa44c0-803a-4460-a80d-8fe5a12d977b" />


# Second entry (11/19/26) - 2 hrs
We did research into bounding box algorithms to use for the camera to search for the target. We landed on OpenCV as the best model. In VSCode we created a really basic bounding box algorithm to identify faces and put boxes around them. We made this algorithm based on documentation in the OpenCV docs and GeeksForGeeks. Then we created another algorithm for identifying a concentrated black space in the camera view. This took some tweaking to figure out how dark it considered a color as black and how big the object must be. Also we made it so that it identified a bounding box only after 3 consecutive frames of seeing a dark object, so that bounding boxes don't flicker in and out.
<img width="2880" height="1800" alt="Screenshot 2026-11-18 at 5 38 06 PM" src="https://github.com/user-attachments/assets/0c0d3c5c-ded9-4292-8b94-d70457681cba" />

# Third entry (11/20/26) - 3 hrs
