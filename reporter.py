#!/usr/bin/env python

import serial
import time

# put device below here.
ser = serial.Serial('/dev/tty.usbserial-AH016NS4', 9600);

try:
    while ser.readable():
        line = ser.readline()
        print(line)

        time.sleep(1)

raise:
    ser.close()

