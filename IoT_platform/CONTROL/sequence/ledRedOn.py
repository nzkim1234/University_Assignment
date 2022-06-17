# -*- coding: utf8 -*-
import RPi.GPIO as GPIO
import time
import sys

# BOX1
pinBox1_R = 19 #red -> lt, rt
pinBox1_G = 26 #green

# BOX2
pinBox2_R = 20 #red
pinBox2_G = 21 #green

#BOX3
pinBox3_R = 27 #red
pinBox3_G = 17 #green

#BOX4
pinBox4_R = 16 #red
pinBox4_G = 12 #green

GPIO.setmode(GPIO.BCM)
GPIO.setup(pinBox1_R, GPIO.OUT)
GPIO.setup(pinBox1_G, GPIO.OUT)

GPIO.setup(pinBox2_R, GPIO.OUT)
GPIO.setup(pinBox2_G, GPIO.OUT)

GPIO.setup(pinBox3_R, GPIO.OUT)
GPIO.setup(pinBox3_G, GPIO.OUT)

GPIO.setup(pinBox4_R, GPIO.OUT)
GPIO.setup(pinBox4_G, GPIO.OUT)

if sys.argv[1] == '0' :
    GPIO.output(pinBox1_G, 1)
    GPIO.output(pinBox1_R, 0)
    GPIO.output(pinBox2_G, 1)
    GPIO.output(pinBox2_R, 0)
    GPIO.output(pinBox3_G, 1)
    GPIO.output(pinBox3_R, 0)
    GPIO.output(pinBox4_G, 1)
    GPIO.output(pinBox4_R, 0)

elif sys.argv[1] == 'on1' :
    GPIO.output(pinBox1_G, 0)
    GPIO.output(pinBox1_R, 1)

elif sys.argv[1] == 'off1' :
    GPIO.output(pinBox1_G, 1)
    GPIO.output(pinBox1_R, 0)

elif sys.argv[1] == 'on2' :
    GPIO.output(pinBox2_G, 0)
    GPIO.output(pinBox2_R, 1)

elif sys.argv[1] == 'off2' :
    GPIO.output(pinBox2_G, 1)
    GPIO.output(pinBox2_R, 0)

elif sys.argv[1] == 'on3' :
    GPIO.output(pinBox3_G, 0)
    GPIO.output(pinBox3_R, 1)

elif sys.argv[1] == 'off3' :
    GPIO.output(pinBox3_G, 1)
    GPIO.output(pinBox3_R, 0)

elif sys.argv[1] == 'on4' :
    GPIO.output(pinBox4_G, 0)
    GPIO.output(pinBox4_R, 1)

elif sys.argv[1] == 'off4' :
    GPIO.output(pinBox4_G, 1)
    GPIO.output(pinBox4_R, 0)

else :
    GPIO.cleanup(pinBox1_R)
    GPIO.cleanup(pinBox2_R)
    GPIO.cleanup(pinBox3_R)
    GPIO.cleanup(pinBox4_R)
    GPIO.cleanup(pinBox1_G)
    GPIO.cleanup(pinBox2_G)
    GPIO.cleanup(pinBox3_G)
    GPIO.cleanup(pinBox4_G)