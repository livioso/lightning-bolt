import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD);
GPIO.setup(21, GPIO.OUT)

while True:
    GPIO.output(21, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(21, GPIO.LOW)