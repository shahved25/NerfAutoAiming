# First entry (11/18/26) - 3.5 hrs
So we didn't realize we had to be journalling while making the project, but don't worry we'll go over each part of our process here in detail. 
At first we were unsure about what type of project we wanted to do, so we brainstormed ideas by taking our strongest skills and noting them down and skills we wanted to learn. Through this process, we narrowed down our project idea and decided we wanted to build something that could detect objects and interact with the real world. We were interested in combining software with a physical design, so we began exploring how different parts interacted with one another. This led us to the idea of creating a Nerf Auto Aiming Mount that could eventually use a camera to find and aim toward a target.
Firstly, we searched through online to find some inspiration for the mechanics of the robot design. We used this project (https://blog.arduino.cc/2021/05/31/a-remote-controlled-arduino-nerf-tank/) as a base point for our CAD model since we are new to CAD and this provides us with a base point for mechanical design. 
We added added a 2nd degree of motion with a rotating stationary mount that lets the Nerf dart shoot left and right. We added more capacity to the magazine and created a stationary design with bottom mount to hide wiring.

<img width="452" height="561" alt="Screenshot 2026-11-20 at 5 56 11 PM" src="https://github.com/user-attachments/assets/290cdc17-140f-4164-b75f-09dd728cd15d" />
<img width="453" height="204" alt="Screenshot 2026-11-20 at 5 55 47 PM" src="https://github.com/user-attachments/assets/4950c08f-836c-42e7-b5d0-ced78c9e18e9" />
<img width="600" height="386" alt="Screenshot 2026-11-20 at 5 55 43 PM" src="https://github.com/user-attachments/assets/c7fa44c0-803a-4460-a80d-8fe5a12d977b" />


# Second entry (11/19/26) - 2 hrs
We had two ideas for the camera. One was to mount it on the turret so it moves until the target is in the center of the camera view. The other was to keep the camera in one place and use its view to figure out where the turret should aim.
We chose to mount the camera on the turret because we thought it would be more accurate and easier to set up.
Then we researched into bounding box algorithms to use for the camera to search for the target. We landed on OpenCV as the best model. In VSCode we created a really basic bounding box algorithm to identify faces and put boxes around them. We made this algorithm based on documentation in the OpenCV docs and GeeksForGeeks. Then we created another algorithm for identifying a concentrated black space in the camera view. This took some tweaking to figure out how dark it considered a color as black and how big the object must be. Also we made it so that it identified a bounding box only after 3 consecutive frames of seeing a dark object, so that bounding boxes don't flicker in and out.
<img width="1365" height="767" alt="Screenshot 2026-11-18 at 5 38 16 PM" src="https://github.com/user-attachments/assets/8dfb422b-36d0-4319-a743-a7f96e1df6bf" />

# Third entry (11/20/26) - 3 hrs
Created a arduino script in arduino c to control each type of motor. We researched into how we can run a python script with arduino code handling the actual movement of motors. This script contains the basic WASD controlling of the motors. We will need to have our laptop connected to the robot to process bounding box information and give directions to motor functions in arduino. We will possibly add a Raspberry Pi later to do that processing on board the robot. Then we finalized bill of materials and booked timeslots for 3d printing.
<img width="1151" height="387" alt="Screenshot 2026-11-20 at 6 18 48 PM" src="https://github.com/user-attachments/assets/644983d1-d6f8-4ae5-a703-b72c3a5d65f5" />
