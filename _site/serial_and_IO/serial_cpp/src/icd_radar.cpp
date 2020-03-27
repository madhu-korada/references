///////// This cpp file can open the port using serial.h

#include <iostream>
#include<serial.h>
// #include<error.h>
#include<icd_radar.h>

static const char * PORT_FILE = "/dev/ttyMSM1"; // for snapdragon
// static const char * PORT_FILE = "/dev/ttyUSB0"; // for FTDI
    
static uint8_t serial_buffer[SERIAL_BUFFER_SIZE];

using namespace std;

ICD::ICD(): serial(PORT_FILE)
{
    cout<<"ICD serial port opened"<<std::endl;
    // serial.OpenTerm();
    // serial.ChangeTermSpeed(115200,1);
    // setConfigValues("Res/fcw_radar.yaml");
}

ICD::~ICD()
{

}

int ICD::recv_packet_radar()
{
    memset((void*)serial_buffer, 0, SERIAL_BUFFER_SIZE);

    // cout<<"\n\nICD : " << " reading from serial port\n";

    int bytes_read = serial.readBytes(serial_buffer, SERIAL_BUFFER_SIZE);

    // cout << "bytes_read : " << bytes_read << "  , serial_buffer : " << serial_buffer << endl;

    if ( bytes_read > 0) // contains bytes
    {
        cout << "got data !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        // convert the data into 'int' and then print 
        for (uint8_t c : serial_buffer)
            std::cout << static_cast<int>(c) << "," << ' ';
        std::cout << endl;
        for (int i = 0; i < bytes_read; i++)
        {
            uint8_t byte = serial_buffer[i];
        }

        return 1;
    }
    else
    {
        std::cout << " couldn't read (or) Corrupted data  --------  " << std::endl;
        return 0;
    }
}
