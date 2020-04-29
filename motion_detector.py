'''
// ===============================
// AUTHOR     :         Ighor Tavares
// CREATE DATE     :    FEB 16,2020
// PURPOSE     :        Master's Project
// SPECIAL NOTES:       Please, ask permission to reuse this script (f.tavares@wustl.edu)
// ===============================
'''

import cv2, time, pandas
from datetime import datetime
import os
import argparse

first_frame=None
status_list=[None,None]
times=[]
df=pandas.DataFrame(columns=["Start","End"])

#get args
parser = argparse.ArgumentParser()
parser.add_argument("-o","--Output", help = "Output name file")
args = parser.parse_args()
if args.Output:
    dir_name = args.Output



video=cv2.VideoCapture(1) #/change to 1 for usb webcan , 0 for built-in camera

while True:
    check, frame = video.read()
    status=0

    #get frame turns into 3 rgb channels to grayscale
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    #blur it to reduce noise from data frame
    gray=cv2.GaussianBlur(gray,(21,21),0)

    if first_frame is None:
        first_frame=gray
        continue


    delta_frame=cv2.absdiff(first_frame,gray)
    #create threshold for pattern
    thresh_frame=cv2.threshold(delta_frame, 30, 255, cv2.THRESH_BINARY)[1]
    thresh_frame=cv2.dilate(thresh_frame, None, iterations=2)

    #run findContours algo to identify patterns on frame once is changed from threshold
    contours, hierarchy=cv2.findContours(thresh_frame.copy(),cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
   
    for contour in contours:
        if cv2.contourArea(contour) < 100:
            continue
        status=1

        #builds contours
        (x, y, w, h)=cv2.boundingRect(contour)
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0,255,0), 3)
    status_list.append(status)


    #screen outputs
    cv2.imshow("Gray Frame",gray)
    cv2.imshow("Delta Frame",delta_frame)
    cv2.imshow("Threshold Frame",thresh_frame)
    cv2.imshow("Color Frame",frame)

    key=cv2.waitKey(1)
 
    #press "q" to close program and save results 
    if key==ord('q'):
        os.makedirs(dir_name)
        os.chdir(dir_name)
        cv2.imwrite("threshold_frame.jpg", thresh_frame)
        cv2.imwrite("contour_frame.jpg", frame)
        

        break

video.release()
cv2.destroyAllWindows