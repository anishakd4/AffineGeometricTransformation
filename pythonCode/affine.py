import cv2
import numpy as np

image = cv2.imread("../assets/putin.jpg")

cv2.line(image, (450, 100), (750, 650), (0, 0, 255), 5, cv2.LINE_AA, 0)
cv2.line(image, (750, 650), (1000, 300), (0, 0, 255), 5, cv2.LINE_AA, 0)
cv2.line(image, (1000, 300), (450, 100), (0, 0, 255), 5, cv2.LINE_AA, 0)

warpMat1 = np.float32([[1.2, 0.2, 2], [-0.3, 1.3, 1]])
warpMat2 = np.float32([[1.2, 0.3, 2], [0.2, 1.3, 1]])

result1 = cv2.warpAffine(image, warpMat1, (int(1.5*image.shape[1]), int(1.4*image.shape[0])), None, flags=cv2.INTER_LINEAR, borderMode=cv2.BORDER_REFLECT_101)
result2 = cv2.warpAffine(image, warpMat2, (int(1.5*image.shape[1]), int(1.4*image.shape[0])), None, flags=cv2.INTER_LINEAR, borderMode=cv2.BORDER_REFLECT_101)

cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.namedWindow("result1", cv2.WINDOW_NORMAL)
cv2.namedWindow("result2", cv2.WINDOW_NORMAL)

cv2.imshow("image", image)
cv2.imshow("result1", result1)
cv2.imshow("result2", result2)

cv2.waitKey(0)
cv2.destroyAllWindows()