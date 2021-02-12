""" EE 250L Lab 02: GrovePi Sensors

List team members here.

Insert Github repository link here.
"""

"""python3 interpreters in Ubuntu (and other linux distros) will look in a 
default set of directories for modules when a program tries to `import` one. 
Examples of some default directories are (but not limited to):
  /usr/lib/python3.5
  /usr/local/lib/python3.5/dist-packages

The `sys` module, however, is a builtin that is written in and compiled in C for
performance. Because of this, you will not find this in the default directories.
"""
import sys
import time
# By appending the folder of all the GrovePi libraries to the system path here,
# we are successfully `import grovepi`
sys.path.append('../../Software/Python/')
# This append is to support importing the LCD library.
sys.path.append('../../Software/Python/grove_rgb_lcd')

import grovepi
from grove_rgb_lcd import *

"""This if-statement checks if you are running this python file directly. That 
is, if you run `python3 grovepi_sensors.py` in terminal, this if-statement will 
be true"""

potentiometer = 0
grovepi.pinMode(potentiometer,"INPUT")

# Full value of the rotary angle is 300 degrees, as per it's specs (0 to 300)
full_angle = 1023
adc_ref= 5
# Vcc of the grove interface is normally 5v
grove_vcc = 5

refresh_flag = True

if __name__ == '__main__':
    PORT = 4    # D4

    while True:
        #So we do not poll the sensors too quickly which may introduce noise,
        #sleep for a reasonable time of 200ms between each iteration.
        time.sleep(0.2)
        sensor_value = grovepi.analogRead(potentiometer)

    	# Calculate the threshold distance(0 to 1023)
        Threshold = sensor_value

        distance = grovepi.ultrasonicRead(PORT)
        print("Threshold is ", Threshold)
        print("Distance is ", distance)
        if distance < Threshold:
            setText_norefresh("{}CM OBJ PRES\n{}CM".format(Threshold, distance))
            setRGB(255,0,0)
            refresh_flag = True
        else:
            if refresh_flag:
                setText("{}CM \n{}CM".format(Threshold, distance))
                setRGB(0,255,0)
                refresh_flag = False
            setText_norefresh("{}CM \n{}CM".format(Threshold, distance))

    
