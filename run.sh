#!/bin/bash
#Helper script to automate run/test . You can just ignore it if you don't want to use it.


if [ $# -ne 1 ] ; then
    echo " USAGE: $0  <output name> "
    exit 0
fi

arg_=$1


python motion_detector.py -o $1

#run static analysis on the countour frame
echo "$1/contour_frame.jpg"
sleep 1
python static_ana.py -i $1/contour_frame.jpg

