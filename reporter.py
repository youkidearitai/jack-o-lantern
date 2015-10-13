#!/usr/bin/env python

import serial
import time

# put device below here.
ser = serial.Serial('/dev/tty.usbserial-AH016NS4', 9600);
trickOrTreatCount = 0

try:
    while ser.readable():
        line = ser.readline()
        if line != "":
            trickOrTreatCount = trickOrTreatCount + 1
            print("Trick-Or-Treat!!")

        time.sleep(1)
except BaseException:
    ser.close()
    print("closed connection")
    print("Trick-Or-Treat count: {0}".format(trickOrTreatCount))

