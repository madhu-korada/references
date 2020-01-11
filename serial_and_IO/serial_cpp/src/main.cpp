#include <iostream>
#include "icd_radar.h"

int main()
{
    std::cout << "First line!!!!!" << std::endl;
    ICD icd;
    std::cout << "icd object is created!!!!!" << std::endl;
    // icd.
    
    do
    {
        icd.recv_packet_radar();
        usleep(1*1000*100); //(for 100 ms latency)//(1 * 1000 * 1000);

    }
    while (true);
    


}