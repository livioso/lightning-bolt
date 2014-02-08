import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD);
GPIO.setup(21, GPIO.OUT)

bitSequenceStart = "01"
bitSequenceDevice = "0001"
# don't understand this part of the bit sequence yet
bitSequenceMysteriousPart = "110100011101" 
bitSequenceEnd = bitSequenceDevice * 2 + "0" * 1000

bitSequenceAll = bitSequenceStart + bitSequenceDevice * 17 + bitSequenceMysteriousPart + bitSequenceEnd

while True:

	for bit in bitSequenceAll:
		if bit == '1':
			GPIO.output(21, GPIO.HIGH)
    	else:
    		GPIO.output(21, GPIO.LOW)

    # time.sleep(0.5)