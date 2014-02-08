import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD);
GPIO.setup(23, GPIO.OUT)

while True:
    GPIO.output(23, False)
    time.sleep(0.5)
    GPIO.output(23, True)