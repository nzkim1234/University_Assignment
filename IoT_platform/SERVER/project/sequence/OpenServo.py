# -*- coding: utf8 -*-
import requests
from gpiozero import DistanceSensor
import RPi.GPIO as GPIO
sensor = DistanceSensor(echo=21, trigger=20)
from random import randrange

# Time test
import time
import math
start = time.time()

# Time test
import time
import math
start = time.time()

servoPin          = 18   # 서보 핀
SERVO_MAX_DUTY    = 12   # 서보의 최대(180도) 위치의 주기
SERVO_MIN_DUTY    = 3    # 서보의 최소(0도) 위치의 주기
GPIO.setup(servoPin, GPIO.OUT)  # 서보핀 출력으로 설정



servo = GPIO.PWM(servoPin, 50)  # 서보핀을 PWM 모드 50Hz로 사용하기 (50Hz > 20ms)
servo.start(0)  # 서보 PWM 시작 duty = 0, duty가 0이면 서보는 동작하지 않는다.

r = [101, 102, 103]

def setServoPos(degree):
  # 각도는 180도를 넘을 수 없다.
  if degree > 180:
    degree = 180

  # 각도(degree)를 duty로 변경한다.
  duty = SERVO_MIN_DUTY+(degree*(SERVO_MAX_DUTY-SERVO_MIN_DUTY)/180.0)
  # 변경된 duty값을 서보 pwm에 적용
  servo.ChangeDutyCycle(duty)

# main_code
setServoPos(180)
time.sleep(1)
servo.stop()
