# Rescue Detection Robot

This repository contains the code and documentation for a rescue detection robot project. The goal of this project is to create a robot that can detect human motion and move towards the detected humans. The robot is equipped with wheels for mobility and uses sensors to detect motion.

## Inspiration
Natural disasters and emergency situations often require rapid response and efficient search-and-rescue operations. However, human rescuers face extreme risks in hazardous environments. We wanted to create an autonomous robot that can navigate disaster zones, detect survivors, and send an SOS alert to save lives.

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
- Controlling the robot's movement based on detected human positions

### What it does
Roams autonomously while avoiding obstacles.
Periodically spins in place to detect people nearby.(Every 20seconds)
Uses computer vision (YOLO) and PIR sensor(detecting human motion) to identify survivor.
if a person is detected, it sends an SOS signal

### How we built it
Arduino + L298N Motor Driver for movement.
Ultrasonic sensors for obstacle avoidance.
YOLO computer vision to detect survivors
PIR sensor to detect humans
Python + OpenCV for real-time object detection (YOLOv8) 
Machine learning models to identify and track humans.
