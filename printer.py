#!/usr/bin/env python

class Printer(object):
    def __init__(self):
        pass

    def trickOrTreet(self, line):
        print("Trick-Or-Treat!!: {0}".format(line))

    def closed(self):
        print("closed connection")

    def onCount(self, trickOrTreatCount):
        print("Trick-Or-Treat count: {0}".format(trickOrTreatCount))

