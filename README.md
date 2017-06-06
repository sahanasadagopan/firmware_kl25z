# firmware_kl25z4

README

In this Assignment two on board sensors are used first is the on board capacitive touch and the other is the temperature sensor.
The temperature sensor data is sent through the wifi wireless nordic module. 
If the capacitive touch is enable then the temperature value are sent to the nordic module through SPI communication.

Temperature module.

The temperature senor uses ADC converter for converting the meaasured value of temperature sensor.
The temperature sensor firmware is built modularly.
Before begining with the ADC module, the ADC is registered are beinging calibrated to take in 32 bit value and convert them to digital.
First the Clock for the ADC is enabled and selected.The the clock division and the resolution for conversion is selected.
The ADC0 is selected with differential mode as input.After the initializing procedure next the sensor reads data to the ADC_RA register. This value is then converted from analog to digital . Then the value from this is calculated and converted to hex value of the temperature.

Capacititve Touch 

The capcitive touch sensor is first initiated. The first task is to select the  port and the clock used by the touch sensor. The touch screen inteface is first set to the non-noise detection mode. Then the discharge current value rates are decided. For this assignment I have selected 2ua discharge rate. Then the internal oscilltor voltage is decided.
After initialisation the desired channel for data transfer for the touch screen is selected. Then based on the channel selected the software trigger start is enabled which scans the whole touch pad for any response.
Then there is a stop function that sets the end of scan flag bit high which stops the scaning.

As the scan detectes a change in the voltage the data that is being measured from the temperature sensor continously would send the data to the nordic module that is connected to the . The nordic nrf24l01+ is a wireless module that communicates through SPI protocoal there are simple 7 pin connection between the Nordic and the FRDM KL25Z4.

There is a CE and CSN pin which is used enabled high when the module is sending or recieving data and the other is used for chip select pin.
Nordic module 
First comes the process of initialising the register to write on the nordic module the chip select pin is disabled and then again enabled back before sending data through the nordic module.
SPI0 data register are used to write to the nordic module . while interacting with nordic module the register address where the data is being written should also be initialised.
