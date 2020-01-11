This code is used for radar with USB-CAN interface.

The interface can be established over slcan as given below. 

files list

--> radar_parse.cpp       : main code for radar data parsing using socketCAN and C++

to run 

--> first connect to the radar ( makesure the device is connected to ttyUSB0 )

$ sudo slcand -o -c -f -s6 /dev/ttyUSB0 slcan0

$ sudo ifconfig slcan0 up 

--> And then
	
$ cd build

$ make

$ ./Radar_parser


--> after removing USB do (Closing) 

$ pkill slcand

