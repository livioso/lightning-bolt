import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD);
GPIO.setup(3, GPIO.IN)
GPIO.setup(5, GPIO.IN)
while True:
    input_value_GPIO3 = GPIO.input(3)
    input_value_GPIO5 = GPIO.input(5)

    print "GPIO 3 --" + str(input_value_GPIO3)
    print "GPIO 5 --" + str(input_value_GPIO5)