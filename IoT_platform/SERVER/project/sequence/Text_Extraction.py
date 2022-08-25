# -*- coding: utf8 -*-
import requests
import pytesseract
import cv2 
from gpiozero import DistanceSensor
import RPi.GPIO as GPIO
sensor = DistanceSensor(echo=21, trigger=20)
from random import randrange

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

path_seq = './sequence/'

def post_check(num):
  url = "http://180.83.19.43:7579/Mobius/test/"+ str(num) + "/user/check"
  headers =	{
          'Accept':'application/json',
          'X-M2M-RI':'12345',
          'X-M2M-Origin':'SIWLTfduOpL', # change to your aei
          'Content-Type':'application/vnd.onem2m-res+json; ty=4'
        }
  data =	{
        "m2m:cin": {
          "con": "1"
        }
      }
  requests.post(url, headers=headers, json=data)


def post_origin_data(num):
  url = "http://180.83.19.43:7579/Mobius/test/"+ str(num) +"/user/origin_data"
  headers =	{
          'Accept':'application/json',
          'X-M2M-RI':'12345',
          'X-M2M-Origin':'SIWLTfduOpL', # change to your aei
          'Content-Type':'application/vnd.onem2m-re1234s+json; ty=4'
        }
  number = randrange(1000, 9999, 1)
  print(number)
  data =	{
        "m2m:cin": {
          "con": str(number)
        }
      }
  requests.post(url, headers=headers, json=data)

def post_box1(num):
  url = "http://180.83.19.43:7579/Mobius/test/box1"
  headers =	{
          'Accept':'application/json',
          'X-M2M-RI':'12345',
          'X-M2M-Origin':'SIWLTfduOpL', # change to your aei
          'Content-Type':'application/vnd.onem2m-res+json; ty=4'
        }
  data =	{
        "m2m:cin": {
          "con": str(num)
        }
      }
  requests.post(url, headers=headers, json=data)

def post_sensor():
  url = "http://180.83.19.43:7579/Mobius/test/box1/servo"
  headers =	{
          'Accept':'application/json',
          'X-M2M-RI':'12345',
          'X-M2M-Origin':'SIWLTfduOpL', # change to your aei
          'Content-Type':'application/vnd.onem2m-res+json; ty=4'
        }
  data =	{
        "m2m:cin": {
          "con": "1"
        }
      }
  requests.post(url, headers=headers, json=data) 

def post_check(num):
  url = "http://180.83.19.43:7579/Mobius/test/"+ str(num) + "/user/check"
  headers =	{
          'Accept':'application/json',
          'X-M2M-RI':'12345',
          'X-M2M-Origin':'SIWLTfduOpL', # change to your aei
          'Content-Type':'application/vnd.onem2m-res+json; ty=4'
        }
  data =	{
        "m2m:cin": {
          "con": "1"
        }
      }
  requests.post(url, headers=headers, json=data)

def get_box_num(n):
  url = "http://180.83.19.43:7579/Mobius/test/box1/servo"
  headers = {'Accept':'application/json',
        'X-M2M-RI':'12345',
        'X-M2M-Origin':'SOrigin'}

  r = requests.get(url, headers=headers)

  try:
    r.raise_for_status()
    jr = r.json()
    
    print(jr)
    print(jr['m2m:cin']['con'])
  except Exception as exc:
    print('There was a problem: %s' % (exc))


def setServoPos(degree):
  # 각도는 180도를 넘을 수 없다.
  if degree > 180:
    degree = 180

  # 각도(degree)를 duty로 변경한다.
  duty = SERVO_MIN_DUTY+(degree*(SERVO_MAX_DUTY-SERVO_MIN_DUTY)/180.0)
  # 변경된 duty값을 서보 pwm에 적용
  servo.ChangeDutyCycle(duty)


# Gray scale
def gray(img_1, search):
  path = img_1
  image = cv2.imread(path)

  gray_tr01 = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
  border01, binary01 = cv2.threshold(gray_tr01, 150, 255, cv2.THRESH_BINARY)
  test = pytesseract.image_to_string(binary01,lang='kor+eng')
  # Remove Space
  test1 = test.replace(" ", "")
  print(test)
  result = test1.strip()
  # Find algorithm
  print(result)
  first = result.find(search)
  last = 0
  i = 0
  while True:
	  i=i+1
	  if result[first + i] == '호':
		  last = first+i
		  break
  out = result[last-3:last]
  return(out)  

# Extracr text from img
# def pullText(img_1, search):
  path = img_1
  image = cv2.imread(path)
  test = pytesseract.image_to_string(image,lang='kor+eng')
  # Remove Space
  test1 = test.replace(" ", "")
  result = test1.strip()
  # Find algorithm
  first = result.find(search)
  last = 0
  i = 0
  while True:
	  i=i+1
	  if result[first + i] == '호':
		  last = first+i
		  break
  out = result[first:last]
  return(out)

def sensorKey(key):
  # key = 100
  # while key >= 10:
  #   key = int(sensor.distance * 100)
  #   print(key)
  #   time.sleep(1)
  # return 1
  key = int(sensor.distance * 100)
  if key <= 10:
    return 1
  else:
    return 0
pins = (17, 18, 27) # 빨강은 18핀, 초록은 19핀, 파랑은 21핀 지정

def led(pins, color):
  RGBs = (
    (1,1,1), # 하양색
    (1,0,0), # 빨강색
    (0,1,0), # 초록색
    (0,0,1), # 파랑색
    (0,1,1), # 청록색
    (1,0,1), # 보라색
    (1,1,0) # 노랑색
  )

  GPIO.setup(pins[0], GPIO.OUT)
  GPIO.setup(pins[1], GPIO.OUT)
  GPIO.setup(pins[2], GPIO.OUT)

  GPIO.output(pins[0], RGBs[color][0])
  GPIO.output(pins[1], RGBs[color][1])
  GPIO.output(pins[2], RGBs[color][2])



# main_code
setServoPos(0)
time.sleep(1)
# cv2_capture
text = ""
cap = cv2.VideoCapture('/dev/video0')
i = 0
ikey = 0
while(cap.isOpened()):
  ret, img = cap.read() #계속 캡쳐 시작

  if not ret:
    continue
     
  cv2.imshow('img', img)
  key = 0

  if sensorKey(key) == 1:
    i += 1
    cv2.imwrite(path_seq +'img.jpg', img)
    print("img-on")
    ikey = 1
    break
  else:
    setServoPos(180)
    time.sleep(1)
    break


if ikey == 1:
  cap.release()
  text = gray(path_seq + "img101.png", "랩스")
  print(text)
  go = int(text)
  # time
  print("time :", math.ceil(time.time() - start),"sec")
  post_check(go)
  post_origin_data(go)
  post_box1(go)
  post_sensor()
  # led(18, 1)
  print("out")
servo.stop()

# while True:
#   n = "box1"
#   if get_box_num(n) == 0:
#     setServoPos(180)
#     time.sleep(1)
#     # GPIO.cleanup(pins)
#     # led(19, 2)
#     break
