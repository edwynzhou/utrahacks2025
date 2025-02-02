# Rescue Detection Robot

This repository contains the code and documentation for a rescue detection robot project. The goal of this project is to create a robot that can detect human motion and move towards the detected humans. The robot is equipped with wheels for mobility and uses sensors to detect motion.

## Overview

Our Autonomous SOS Rescue Robot is an AI-powered search-and-rescue vehicle that can independently move through disaster zones, avoid obstacles, scan for survivors, and send out an SOS alert.

## Features
- Motion detection using OpenCV
- Autonomous navigation towards detected humans
- Real-time video processing
- Obstacle avoidance

### Human Detection Model

The human detection model uses OpenCV to process video frames from the robot's camera. It employs a pre-trained model to identify humans in the frame and calculate their positions relative to the robot. The key steps include:
- Capturing video frames from the camera
- Converting frames to grayscale
- Using a Haar Cascade classifier to detect humans
- Controlling the robot's movement based on detected human positions

