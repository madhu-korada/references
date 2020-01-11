> Listing all the ports ``` $ python -m serial.tools.list_ports ```

> Accessing ports ``` $ python -m serial.tools.miniterm <port_name> ```

PYTHON:

--> READ FROM SERIAL PORT:
```
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
  --> to read given number of bytes from the serial device
```
data = ser.read(size=5)
```

  --> to read the data from serial device while something is being written over it.
```
#for python2.7
data = ser.read(ser.inWaiting())

#for python3
ser.read(ser.inWaiting)

```



--> WRITE TO SERIAL PORT:
```
import serial

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, bytesize=EIGHTBITS)  # open serial port
print(ser.name)         # check which port was really used
ser.write(b'hello')     # write a string
ser.close()             # close port
```
CPP:


---- READ FROM SERIAL PORT:


---- WRITE TO SERIAL PORT:

