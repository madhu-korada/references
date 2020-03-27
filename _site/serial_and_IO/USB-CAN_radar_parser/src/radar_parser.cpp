
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include <endian.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

#include <cerrno>
#include <csignal>
#include <cstdint>
#include <cstdio>
#include <cstring>



void processFrame(const struct can_frame& frame) {
    switch (frame.can_id) {
    case 0x60A:
    {
    	// std::cout << "Got 0x60A\n" << std::endl;
    	printf("Got 0x60A\n");
    	uint8_t byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7;
		
		byte0 = frame.data[0]; byte1 = frame.data[1]; byte2 = frame.data[2]; byte3 = frame.data[3];
		// byte4 = frame.data[4]; byte5 = frame.data[5]; byte6 = frame.data[6]; byte7 = frame.data[7];

		int no_of_objects = static_cast<int>(byte0);
		float object_measure = ((byte1)*256 + byte2);
		int objects_interface_version = static_cast<int>(byte3 >> 4);

		std::cout << "no_of_objects : " << no_of_objects << "\t"
				  << "radar cycle count : " << object_measure << "\t"
				  // << "objects_interface_version : " << objects_interface_version << "\t"
				  << std::endl;
    }
        break;
    case 0x60B:
    {
    	uint8_t byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7;
		
		byte0 = frame.data[0]; byte1 = frame.data[1]; byte2 = frame.data[2]; byte3 = frame.data[3];
		byte4 = frame.data[4]; byte5 = frame.data[5]; byte6 = frame.data[6]; byte7 = frame.data[7];

    	
    	int object_id = static_cast<int>(byte0);

		float radial_distance = ((byte1*32) + (byte2>>3))*0.2 - 500;

		float object_lateral_range = ((byte2 & 0x07)*256 + byte3)*0.2 - 204.6;

		float object_radial_speed = (byte4*4 + byte5>>6)*0.25 - 128;

		float object_lateral_speed = ((byte5 & 0x3F)*8 + byte6>>5)*0.25 - 64;

		int object_dynamic_attribute = (byte6 & 0x07) ;
		
		int object_RCS = (byte7 * 0.5) - 64;

		std::cout << "\nobject_id : " << object_id << "\t"
				  << "radial_distance : " << radial_distance << "\t"
				  << "lateral_range : " << object_lateral_range << "\t" 
				  << "radial_speed : " << object_radial_speed << "\t"  
				  << "lateral_speed : " << object_lateral_speed << "\t"
				  // << "dynamic_attribute : " << object_dynamic_attribute << "\t"
				  << "RCS : " << object_RCS << "\n"
				  << std::endl; 

        // std::cout << "Got 0x60B" << std::endl; // XXX
    }
        break;
    case 0x201:
    {
        // TODO: Work!
        // Radar statue
        break;
        
    }
    case 0x700:
    {
    	// Version Information
        break;
    }
    default:
        // Should never get here if the receive filters were set up correctly
        // std::cerr << "Unexpected CAN ID: 0x"
        //           << std::hex << std::uppercase
        //           << std::setw(3) << std::setfill('0')
        //           << frame.can_id << std::endl;
        // std::cerr.copyfmt(std::ios(nullptr));

        printf("Unexpected CAN ID \n");
        break;
    }
}



void print_can_frame(struct can_frame *frame)
{
    unsigned char *data = frame->data;
    unsigned int dlc = frame->can_dlc;
    unsigned int i;

    printf("%03X  [%u] ", frame->can_id, dlc);
    for (i = 0; i < dlc; ++i)
    {
        printf(" %02X", data[i]);
    }
    std::cout << std::endl;
}


int main()
// int get_can_data()
{
	printf("First line !!!!!\n");

	int sock;
	struct sockaddr_can addr;
	struct ifreq ifr;

	const char *ifname = "slcan0";

	if((sock = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Error while opening socket");
		return -1;
	}
	
	strcpy(ifr.ifr_name, ifname );
	ioctl(sock, SIOCGIFINDEX, &ifr);

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);

	if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Error in socket bind");
		return -2;
	}

	std::cout << "Radar connection Started" << std::endl;

    while (true) {  
        struct can_frame frame;

        // Read in a CAN frame
        int numBytes = ::read(sock, &frame, CAN_MTU);
        
        struct can_frame * frame_pointer = &frame;
        // print_can_frame(frame_pointer);

        switch (numBytes) {
        case CAN_MTU:
            // print_can_frame(frame_pointer);
            processFrame(frame);
            break;
        case -1:
            // Check the signal value on interrupt
            if (EINTR == errno)
                continue;

            // Delay before continuing
            std::perror("read");
            // std::this_thread::sleep_for(100ms);
        default:
            continue;
        }
    }

    // Cleanup
    if (::close(sock) == -1) {
        std::perror("close");
        return errno;
    }

    // std::cout << std::endl << "closing !!!!" << std::endl;
    return EXIT_SUCCESS;

    // Error handling (reverse order cleanup)
	errSetup:
	    ::close(sock);
	errSocket:
	    return errno;

}



  //   	uint8_t byte1, byte2, byte3, byte4, byte5, byte6, byte7, byte8;
		
		// byte1 = 0x57;
		// byte2 = 0x4E;
		// byte3 = 0xC4;
		// byte4 = 0x0C;
		// byte5 = 0x7F;
		// byte6 = 0x60;
		// byte7 = 0x18;
		// byte8 = 0x80;
  //       std::cout << "byte1 : " << static_cast<int>(byte1) << "\t"
  //       		  << "byte2 : " << static_cast<int>(byte2) << "\t"
  //       		  << "byte3 : " << static_cast<int>(byte3) << "\t"
  //       		  << "byte4 : " << static_cast<int>(byte4) << "\t" 
  //       		  << "byte5 : " << static_cast<int>(byte5) << "\t"
  //       		  << "byte6 : " << static_cast<int>(byte6) << "\t"
  //       		  << "byte7 : " << static_cast<int>(byte7) << "\t"
  //       		  << "byte8 : " << static_cast<int>(byte8) << "\t"
  //       		  << std::endl;




    // struct can_frame frame;
    // int nbytes;
    // nbytes = read(sock, &frame, sizeof(struct can_frame));

    
    // if (nbytes < 0) {
    //         perror("can raw socket read");
    //         return 1;
    // }

    //  // paranoid check ... 
    // if (nbytes < sizeof(struct can_frame)) {
    //         fprintf(stderr, "read: incomplete CAN frame\n");
    //         return 1;
    // }
    // std::cout << "nbytes : " << nbytes << std::endl;
    
    //  // do something with the received CAN frame 
    // struct can_frame * frame_pointer = &frame;
    
    // print_can_frame(frame_pointer);





    // int rc;
    // // Set a receive filter so we only receive select CAN IDs
    // {
    //     struct can_filter filter[3];

    //     filter[0].can_id   = 0x60A;
    //     filter[0].can_mask = CAN_SFF_MASK;
    //     filter[1].can_id   = 0x60B;
    //     filter[1].can_mask = CAN_SFF_MASK;
    //     filter[2].can_id   = 0x320;
    //     filter[2].can_mask = CAN_SFF_MASK;

    //     rc = ::setsockopt(
    //         sock,
    //         SOL_CAN_RAW,
    //         CAN_RAW_FILTER,
    //         &filter,
    //         sizeof(filter)
    //     );
    //     if (-1 == rc) {
    //         std::perror("setsockopt filter");
    //         // goto errSetup;
    //     }
    // }




