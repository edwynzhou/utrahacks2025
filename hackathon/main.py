import cv2
import serial  # Import serial module
import time

# Initialize Bluetooth communication with HC-06 (Change 'COM6' based on your PC)
bluetooth = serial.Serial('/dev/cu.HC-06', 9600)  # Adjust COM port based on HC-06 connection
time.sleep(2)  # Wait for the connection to establish

# Load the Haar cascade face detector
face_cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

# Open video stream from phone camera
video = cv2.VideoCapture(0)
address = "http://100.67.75.107:8080/video"
video.open(address)

while True:
    check, frame = video.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

    if len(faces) > 0:
        bluetooth.write(b'1')  # Send "1" to turn ON LEDs
        print("Face detected - Sending '1' to Arduino")
    else:
        bluetooth.write(b'0')  # Send "0" to turn OFF LEDs
        print("No face detected - Sending '0' to Arduino")

    for x, y, w, h in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 3)

    cv2.imshow('Face Detection', frame)

    if cv2.waitKey(1) == ord('q'):
        break

video.release()
cv2.destroyAllWindows()
bluetooth.close()  # Close Bluetooth connection when done
