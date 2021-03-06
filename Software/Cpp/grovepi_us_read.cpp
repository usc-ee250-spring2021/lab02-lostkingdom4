// GrovePi Example for using the digital write command
// http://dexterindustries.com/grovepi

/*
## License

   The MIT License (MIT)

   GrovePi for the Raspberry Pi: an open source platform for connecting Grove Sensors to the Raspberry Pi.
   Copyright (C) 2017  Dexter Industries

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include "grovepi.h"
using namespace GrovePi;

// sudo g++ -Wall grovepi_us_read.cpp grovepi.cpp -o grovepi_us_read.out -> without grovepicpp package installed
// sudo g++ -Wall -lgrovepicpp grovepi_us_read.cpp -o grovepi_us_read.out -> with grovepicpp package installed

int main()
{
	int pin = 4; // connected to digital port 4 (D4)
	int incoming; // variable to hold the data

	try
	{
		initGrovePi(); // initialize communication with the GrovePi

		// do this indefinitely
		while(true)
		{
			// read the processed data from the GrovePi
			incoming = ultrasonicRead(pin);

			// display it
			printf("[pin %d][ultrasonic read = %d cm]\n", pin, incoming);

			// and wait 50 ms for the ultrasonic sensor to get a new reading
			delay(50);
		}
	}
	catch(I2CError &error)
	{
		printf(error.detail());

		return -1;
	}

	return 0;
}
