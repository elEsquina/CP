import cv2
import numpy as np

# Load the pre-trained model
model_file = "opencv_face_detector_uint8.pb"
config_file = "opencv_face_detector.pbtxt"
net = cv2.dnn.readNetFromTensorflow(model_file, config_file)

# Open the camera (you can use 0 for default camera or specify the camera index)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    height, width = frame.shape[:2]
    blob = cv2.dnn.blobFromImage(frame, 1.0, (300, 300), (104.0, 177.0, 123.0), False, False)

    # Set the input to the network then run forward pass
    net.setInput(blob)
    detections = net.forward()

    for i in range(detections.shape[2]):
        confidence = detections[0, 0, i, 2]
        if confidence > 0.5:
            print("Human detected")

            box = detections[0, 0, i, 3:7] * np.array([width, height, width, height])
            (startX, startY, endX, endY) = box.astype("int")
            cv2.rectangle(frame, (startX, startY), (endX, endY), (0, 255, 0), 2)


    cv2.imshow("Face Recognition", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
