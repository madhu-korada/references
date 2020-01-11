#ifndef ICD_H
#define ICD_H

// #include <linux/serial.h>
#include"serial.h"
// use the size you require here
constexpr int SERIAL_BUFFER_SIZE   = sizeof(uint8_t)*87;

/////////////////////////////////////////////////////////

class ICD
{
public:
    ICD();
    ~ICD();

    int recv_packet_radar();

protected:
    serialPort serial;
};

#endif // ICD_H

