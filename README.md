# UTRAHacks 2025 - Human Motion Detection Robot

## Repository Overview

This repository contains the code and documentation for a human motion detection robot that surveys an area on wheels to detect humans. Below is a breakdown of the components in each folder:

### `/src`
Contains the source code for the robot's functionality.
- `motion_detection.py`: Implements the algorithms for detecting human motion.
- `robot_control.py`: Controls the movement and navigation of the robot.
- `camera_interface.py`: Interfaces with the camera to capture video feed.

### `/models`
Includes pre-trained models and training scripts.
- `human_detection_model.h5`: Pre-trained model for detecting humans.
- `train_model.py`: Script to train the human detection model.

### `/scripts`
Utility scripts for various tasks.
- `setup_environment.sh`: Sets up the development environment.
- `data_preprocessing.py`: Preprocesses data for training and testing.

### `/docs`
Documentation for the project.
- `README.md`: Overview and instructions for the project.
- `installation_guide.md`: Step-by-step guide to install dependencies and set up the project.
- `user_manual.md`: Instructions on how to operate the robot.

### `/tests`
Contains test cases to ensure the functionality of the robot.
- `test_motion_detection.py`: Unit tests for the motion detection module.
- `test_robot_control.py`: Unit tests for the robot control module.

## General Goal
The goal of this project is to develop a robot that can autonomously survey an area on wheels and detect the presence of humans using advanced motion detection algorithms and machine learning models.