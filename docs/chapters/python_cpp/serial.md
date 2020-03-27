---
layout: default
title: Serial
lang-ref: chapter1.0
---
#### BASIC COMMANDS:

Listing all the ports :- ``` $ python -m serial.tools.list_ports ```

Accessing ports :- ``` $ python -m serial.tools.miniterm <port_name> ```

#### PYTHON:

##### Read From Serial Port:
```python
import serial

ser = serial.Serial(
    port='/dev/ttyUSB0',\
    baudrate=9600,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=0)

print("connected to: " + ser.portstr)

while True:
    # using ser.readline() assumes each line contains a single reading
    # sent using Serial.println() on the Arduino
    reading = ser.readline().decode('utf-8')
    # reading is a string...do whatever you want from here
    print(reading)

ser.close()
```
###### to read given number of bytes from the serial device
```pyhton
data = ser.read(size=5)
```
###### to read the data from serial device while something is being written over it.
```python
#for python2.7
data = ser.read(ser.inWaiting())

#for python3
ser.read(ser.inWaiting)

```



##### Write To Serial Port: (update it)
```python
import serial
import time

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, bytesize=EIGHTBITS)  # open serial port
print(ser.name)         # check which port was really used
ser.write(b'hello')     # write a string
time.sleep(0.1)
ser.close()             # close port
```
#### CPP:

##### Open, Read and Write to a Serial Port:


The entire cpp code to open, read and write into a serial port is updated in serial_cpp which is inside serial_and_IO folder. check it out [here](https://github.com/madhu-korada/references/tree/master/serial_and_IO/serial_cpp)


Using slcan radar data was parsed through USB-CAN interface. Check out the readme and code [here](https://github.com/madhu-korada/references/tree/master/serial_and_IO/USB-CAN_radar_parser)
