
'''
// ===============================
// AUTHOR     :         Ighor Tavares
// CREATE DATE     :    FEB 25,2020
// PURPOSE     :        Master's Project
// SPECIAL NOTES:       Please, ask permission to reuse this script (f.tavares@wustl.edu)
// ===============================

'''

import cv2 
import numpy as np 
import sys
import os
import argparse


parser = argparse.ArgumentParser()
parser.add_argument("-i","--Input", help = "Input Image Path")
args = parser.parse_args()
if args.Input:
    dir_name = args.Input

print (dir_name)
# Read image. 
# param1 = sys.argv[1]
param1 = dir_name
img = cv2.imread(param1, cv2.IMREAD_COLOR) 

# if sys.argc < 2 :
#     print("error")
# Convert to grayscale. 
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 

# Blur using 3 * 3 kernel. 
gray_blurred = cv2.cvtColor(gray, (3, 3)) 

# Apply Hough transform on the blurred image. 
detected_circles = cv2.HoughCircles(gray_blurred,  
                   cv2.HOUGH_GRADIENT, 2, 32, param1 = 30, 
               param2 = 100, minRadius = 10 , maxRadius = 50) 
# Draw circles that are detected. 
if detected_circles is not None: 
  
    # Convert the circle parameters a, b and r to integers. 
    detected_circles = np.uint16(np.around(detected_circles)) 
  
    for pt in detected_circles[0, :]: 
        a, b, r = pt[0], pt[1], pt[2] 
  
        # Draw the circumference of the circle. 
        cv2.circle(img, (a, b), r, (0, 255, 0), 2) 
  
        # Draw a small circle (of radius 1) to show the center. 
        cv2.circle(img, (a, b), 1, (0, 0, 255), 3) 
        cv2.imshow("Detected Circle", img) 


    k = cv2.waitKey(0) 
    if k == ord('q'):
        #key clicked saved image run other script. 
        cv2.imwrite("static_analysis.jpg", img)
        cv2.destroyAllWindows()
            
