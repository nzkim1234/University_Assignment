import RPi.GPIO as GPIO
import time
from subprocess import call

class Sw420(object):
    def __init__(self, pin , led, buzzer):
        self.led = led
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.led,GPIO.OUT)
        self.pin = pin
        GPIO.setup(self.pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
        GPIO.add_event_detect(self.pin, GPIO.RISING, callback=self.callback, bouncetime=1)
        self.count = 0 
        self.buzzer = buzzer
        GPIO.setwarnings(False)
        GPIO.setup(23, GPIO.OUT)

    def callback(self , pin):
        self.count += 1

    def LedOn(self):
        p = GPIO.PWM(self.buzzer, 100)
        print("Oh my God!!")
        print(self.count)
        # GPIO.output(self.buzzer, True)
        p.start(100)
        p.ChangeDutyCycle(90)
        time.sleep(2)
        
    def LedOff(self):
        print(self.count)
        GPIO.output(self.led , 0)
        GPIO.output(self.buzzer, False)
    # def servoAct1(self):
    # 	call("echo 0=180 > /dev/servoblaster", shell = True)

    # def servoAct2(self):
    # 	call("echo 0=100 > /dev/servoblaster", shell = True)


def main():
    sensor = Sw420(24,16,23) #sw-420 시그널 GPIO, LED GPIO로 객체 생성
    try:
        while True:
            time.sleep(1)
            if sensor.count >=20: #민감도? 진동지속시간?
                sensor.LedOn() #LED를 켠다.
            else:
                sensor.LedOff()
            sensor.count = 0        
    except KeyboardInterrupt:
        GPIO.cleanup()

if __name__ == '__main__':
    main()
