from ultralytics import YOLO
import cv2
import torch
import threading
import serial
import time

# Initialize Bluetooth communication with HC-06
#bluetooth = serial.Serial('/dev/cu.HC-06', 9600)  # Change to the correct port if needed
time.sleep(2)  # Allow Bluetooth to connect

# Load YOLOv8 model and move to Apple Metal GPU
device = "mps" if torch.backends.mps.is_available() else "cpu"
model = YOLO("yolov8n.pt").to(device)

# Load video stream from phone camera using FFmpeg (for speed)
video_path = "http://100.67.75.107:8080/video"
cap = cv2.VideoCapture(video_path, cv2.CAP_FFMPEG)

# Global frame storage for async processing
frame = None

def read_frames():
    """ Continuously reads frames in a separate thread for lower latency """
    global frame
    while True:
        ret, temp_frame = cap.read()
        if ret:
            frame = cv2.resize(temp_frame, (640, 480))  # Resize early to speed up processing

# Start async frame reader
thread = threading.Thread(target=read_frames, daemon=True)
thread.start()

while True:
    person_detected = False

    if frame is not None:
        # Run YOLOv8 inference with smaller input size
        results = model.track(frame, imgsz=416, persist=True)

        # Extract detections
        detections = results[0].boxes.xyxy.cpu().numpy()
        class_ids = results[0].boxes.cls.cpu().numpy()

        # Draw bounding boxes only for detected persons
        for i, detection in enumerate(detections):
            x_min, y_min, x_max, y_max = map(int, detection[:4])
            class_id = int(class_ids[i])

            if class_id == 0:  # Class 0 corresponds to "person"
                person_detected = True
                cv2.rectangle(frame, (x_min, y_min), (x_max, y_max), (0, 255, 0), 3)
                cv2.putText(frame, "Person", (x_min, y_min - 10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

        # Send Bluetooth command
        if person_detected:
            bluetooth.write(b'1')  # Send "1" to turn ON LED
            print("Person detected - Sending '1' to Arduino")
        else:
            bluetooth.write(b'0')  # Send "0" to turn OFF LED
            print("No person detected - Sending '0' to Arduino")

        # Display the frame
        cv2.imshow("Real-Time Person Detection", frame)

    # Exit if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

# Cleanup
cap.release()
cv2.destroyAllWindows()

bluetooth.close()  # Close Bluetooth connection when done