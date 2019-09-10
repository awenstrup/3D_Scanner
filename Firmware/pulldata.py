'''
3D Printer: POE Lab 2

This script pulls data sent over USB
by the Ardino and saves it to by plotted
by numpy

authors: dtarazi315, awenstrup
'''
#Import statements
import serial
import numpy as np
import matplotlib as plt

#Variable definitions
port = '/dev/ttyACM0'
baudRate = 9600

#Setup
serialPort = serial.Serial(port, baudRate)

#Loop
running = True
while running:
    line = serialPort.readline().decode()
    if len(line) > 0:
        val = int(line)
        print(line)
