#!/usr/bin/env python

import serial
import time

import printer
#import tmciot

# put device below here.
ser = serial.Serial('/dev/tty.usbserial-AH016NS4', 9600);
trickOrTreatCount = 0

p = printer.Printer()
#p = tmciot.TmcIoT()

try:
    while ser.readable():
        line = ser.readline()
        if line != "":
            trickOrTreatCount = trickOrTreatCount + 1
            p.trickOrTreet(line)

        time.sleep(1)
except BaseException:
    ser.close()
    p.closed()
    p.onCount(trickOrTreatCount)

