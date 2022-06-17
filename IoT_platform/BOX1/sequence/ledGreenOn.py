# -*- coding: utf8 -*-
import RPi.GPIO as GPIO
import time

pins = (18, 19, 21) #빨 초 파

def led(pins, color):
    RGBs = (
        (1, 1, 1),  # 하양색
        (1, 0, 0),  # 빨강색
        (0, 1, 0),  # 초록색
        (0, 0, 1),  # 파랑색
        (0, 1, 1),  # 청록색
        (1, 0, 1),  # 보라색
        (1, 1, 0)  # 노랑색
    )
    GPIO.setmode(GPIO.BOARD)

    GPIO.setup(pins[0], GPIO.OUT)
    GPIO.setup(pins[1], GPIO.OUT)
    GPIO.setup(pins[2], GPIO.OUT)

    GPIO.output(pins[0], RGBs[color][0])
    GPIO.output(pins[1], RGBs[color][1])
    GPIO.output(pins[2], RGBs[color][2])

GPIO.cleanup(pins)
led(pins, 2)