import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD);
GPIO.setup(3, GPIO.IN)

for x in range(0, 5000):
    print str(x) + ";" + str(GPIO.input(3))