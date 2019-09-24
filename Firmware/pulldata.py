'''
3D Printer: POE Lab 2

This script pulls data sent over USB
by the Ardino and saves it to be plotted
by numpy

authors: dtarazi315, awenstrup
'''
#Import statements
import serial
import numpy as np
import matplotlib as plt

#Variable definitions
port = '/dev/ttyACM1'
baudRate = 9600

a = 8442
b = -0.9307

values = list()

#Setup
serialPort = serial.Serial(port=port, baudrate=9600, timeout=None)

def adc_to_dist(num):
    return a * (num ** b)

print("running")
#Loop
running = True
while running:

    line = serialPort.readline()
    if len(line) > 0:
        #val = int(line.decode())
        #print(val)
        print(line.decode().strip())
        dist = adc_to_dist(int(line.decode().strip()))
        print('Distance is ', dist)
        values.append(dist)
        print()
