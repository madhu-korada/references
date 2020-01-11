#include<serial.h>
#include<iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////////////////////////

serialPort::serialPort(const char* filename) :
    serial_port_file(filename)
    {
    // Serial port
    printf("\nCOMPORT IS: %s", filename);

    OpenTerm(filename);
    return;
    }

serialPort::~serialPort()
    {
    CloseTerm();
    }

////////////////////////////////////////////////////////////////////////////////
// Open the terminal
// Returns 0 on success
int serialPort::OpenTerm(const char * filename)
    {
    printf("\nOpenTerm()\n");

// #if defined (__QNXNTO__)
//     device_fd = ::open(PORT_FILE, O_RDWR , S_IRUSR | S_IWUSR );
// #else
//     device_fd = ::open(PORT_FILE, O_RDWR | O_SYNC , S_IRUSR | S_IWUSR );
// #endif

    device_fd = ::open(filename, O_RDWR | O_NONBLOCK, S_IRUSR | S_IWUSR );

    if ( device_fd < 0)
        {
        printf("unable to open serial port [%s]; [%s]",  filename, strerror(errno));
        return -1;
        }

    flushBuffers();

    // ChangeTermSpeed(9600,1);
    setNewOptions(115200,//9600, //int baudrate  (should be 115200)
                  8, //int databits,
                  "None", //const string& parity,
                  "1", //const string& stop,
                  false, //bool softwareHandshake,
                  false //bool hardwareHandshake
                 );


    // // set the serial port speed to 9600 to match the device
    // // later we can ramp the speed up to the SICK's 38K
    // //
    // struct termios term;
    // if( tcgetattr(  device_fd, &term ) < 0 )
    //     {
    //     printf("Unable to get serial port attributes\n");
        // cout << "graceful_exit" << endl;
        // graceful_exit(ERR_SER_GET_CONFIG);
    //     return -2;
    //     }
    //
    // cfmakeraw( &term );
    // if (false)//(PLSMode)
    //     {
    //     term.c_iflag |= INPCK;
    //     term.c_iflag &= ~IXOFF;
    //     term.c_cflag |= PARENB;
    //     }
    // //    fcntl( device_fd,F_SETFL,0); //GD for GPSINS
    // //    term.c_cc[VMIN]  = 1000000; //GD for GPSINS
    // //    term.c_cc[VTIME]  = 100000; //GD for GPSINS
    //
    // cfsetispeed( &term, B9600 );
    // cfsetospeed( &term, B9600 );
    //
    // if( tcsetattr(  device_fd, TCSAFLUSH, &term ) < 0 )
    //     {
    //     printf("\tUnable to set serial port attributes\n");
        // cout << "graceful_exit" << endl;
        // graceful_exit(ERR_SER_SET_CONFIG);
    //     return -3;
    //     }
    //
    // // Make sure queue is empty
    // //
    // flushBuffers();

    return 0;
    }


////////////////////////////////////////////////////////////////////////////////
// Close the terminal
// Returns 0 on success
//
int  serialPort::CloseTerm()
    {
    printf("\n\n\nCloseTerm(): %s closing device terminal\n", serial_port_file);

    ::close( device_fd);
    return 0;
    }





////////////////////////////////////////////////////////////////////////////////
// Write a packet to the device
//
int serialPort::writeBytes(uint8_t *data, ssize_t maxlen)
    {
    ssize_t bytes_written = ::write(  device_fd, data, maxlen);

    if(bytes_written < 0)
        {
        cout<<"SERIAL : "
            // <<current_datetime_to_string() // commented_by_me
            <<" : "<<serial_port_file
            <<" : write error "<<errno<<endl;
        }

    if(bytes_written < maxlen)
        {
        cout << "graceful_exit" << endl;
        // graceful_exit(ERR_SER_WRITE);
        }

    return bytes_written;
    }

int serialPort::readBytes(uint8_t *data, ssize_t maxlen)
    {
    int bytes_read = ::read( device_fd, data, maxlen);
    
    cout << "read bytes: " << bytes_read << endl;

    if(bytes_read < 0)
        {
        cout<<"SERIAL : "
            // <<current_datetime_to_string()
            <<" : "<<serial_port_file
            <<" : read error "<<errno<<endl;
        
        }

    return bytes_read;//all good
    }

void serialPort::flushBuffers()
    {
    tcflush( device_fd, TCIOFLUSH);
    }
void serialPort::setNewOptions(int baudrate, int databits, const string& parity, const string& stop, bool softwareHandshake, bool hardwareHandshake)
    {
    struct termios newtio;
    //   memset(&newtio, 0, sizeof(newtio));
    if (tcgetattr(device_fd, &newtio)!=0)
        {
        std::cout<<"tcgetattr() 3 failed"<<std::endl;
        }

    speed_t _baud=0;
    switch (baudrate)
        {
#ifdef B0
        case      0:
            _baud=B0;
            break;
#endif

#ifdef B50
        case     50:
            _baud=B50;
            break;
#endif
#ifdef B75
        case     75:
            _baud=B75;
            break;
#endif
#ifdef B110
        case    110:
            _baud=B110;
            break;
#endif
#ifdef B134
        case    134:
            _baud=B134;
            break;
#endif
#ifdef B150
        case    150:
            _baud=B150;
            break;
#endif
#ifdef B200
        case    200:
            _baud=B200;
            break;
#endif
#ifdef B300
        case    300:
            _baud=B300;
            break;
#endif
#ifdef B600
        case    600:
            _baud=B600;
            break;
#endif
#ifdef B1200
        case   1200:
            _baud=B1200;
            break;
#endif
#ifdef B1800
        case   1800:
            _baud=B1800;
            break;
#endif
#ifdef B2400
        case   2400:
            _baud=B2400;
            break;
#endif
#ifdef B4800
        case   4800:
            _baud=B4800;
            break;
#endif
#ifdef B7200
        case   7200:
            _baud=B7200;
            break;
#endif
#ifdef B9600
        case   9600:
            _baud=B9600;
            break;
#endif
#ifdef B14400
        case  14400:
            _baud=B14400;
            break;
#endif
#ifdef B19200
        case  19200:
            _baud=B19200;
            break;
#endif
#ifdef B28800
        case  28800:
            _baud=B28800;
            break;
#endif
#ifdef B38400
        case  38400:
            _baud=B38400;
            break;
#endif
#ifdef B57600
        case  57600:
            _baud=B57600;
            break;
#endif
#ifdef B76800
        case  76800:
            _baud=B76800;
            break;
#endif
#ifdef B115200
        case 115200:
            _baud=B115200;
            break;
#endif
#ifdef B128000
        case 128000:
            _baud=B128000;
            break;
#endif
#ifdef B230400
        case 230400:
            _baud=B230400;
            break;
#endif
#ifdef B460800
        case 460800:
            _baud=B460800;
            break;
#endif
#ifdef B576000
        case 576000:
            _baud=B576000;
            break;
#endif
#ifdef B921600
        case 921600:
            _baud=B921600;
            break;
#endif
        default:
            //   case 256000:
            //      _baud=B256000;
            break;
        }
    cfsetospeed(&newtio, (speed_t)_baud);
    cfsetispeed(&newtio, (speed_t)_baud);

    /* We generate mark and space parity ourself. */
    if (databits == 7 && (parity=="Mark" || parity == "Space"))
        {
        databits = 8;
        }
    switch (databits)
        {
        case 5:
            newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS5;
            break;
        case 6:
            newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS6;
            break;
        case 7:
            newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS7;
            break;
        case 8:
        default:
            newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS8;
            break;
        }
    newtio.c_cflag |= CLOCAL | CREAD;

    //parity
    newtio.c_cflag &= ~(PARENB | PARODD);
    if (parity == "Even")
        {
        newtio.c_cflag |= PARENB;
        }
    else if (parity== "Odd")
        {
        newtio.c_cflag |= (PARENB | PARODD);
        }

    //hardware handshake
    /*   if (hardwareHandshake)
          newtio.c_cflag |= CRTSCTS;
       else
          newtio.c_cflag &= ~CRTSCTS;*/
    newtio.c_cflag &= ~CRTSCTS;

    //stopbits
    if (stop=="2")
        {
        newtio.c_cflag |= CSTOPB;
        }
    else
        {
        newtio.c_cflag &= ~CSTOPB;
        }

    //   newtio.c_iflag=IGNPAR | IGNBRK;
    newtio.c_iflag=IGNBRK;
    //   newtio.c_iflag=IGNPAR;

    //software handshake
    if (softwareHandshake)
        {
        newtio.c_iflag |= IXON | IXOFF;
        }
    else
        {
        newtio.c_iflag &= ~(IXON|IXOFF|IXANY);
        }

    newtio.c_lflag=0;
    newtio.c_oflag=0;

    newtio.c_cc[VTIME]=1;
    newtio.c_cc[VMIN]=60;

    //   tcflush(device_fd, TCIFLUSH);
    if (tcsetattr(device_fd, TCSANOW, &newtio)!=0)
        {
        std::cout<<"tcsetattr() 1 failed"<<std::endl;
        }

    int mcs=0;
    ioctl(device_fd, TIOCMGET, &mcs);
    mcs |= TIOCM_RTS;
    ioctl(device_fd, TIOCMSET, &mcs);

    if (tcgetattr(device_fd, &newtio)!=0)
        {
        std::cout<<"tcgetattr() 4 failed"<<std::endl;
        }

    //hardware handshake
    if (hardwareHandshake)
        {
        newtio.c_cflag |= CRTSCTS;
        }
    else
        {
        newtio.c_cflag &= ~CRTSCTS;
        }
    /*  if (on)
         newtio.c_cflag |= CRTSCTS;
      else
         newtio.c_cflag &= ~CRTSCTS;*/
    if (tcsetattr(device_fd, TCSANOW, &newtio)!=0)
        {
        std::cout<<"tcsetattr() 2 failed"<<std::endl;
        }

    }

////////////////////////////////////////////////////////////////////////////////
// Set the terminal speed
// Valid values are 9600 and 38400
// Returns 0 on success
//
int  serialPort::ChangeTermSpeed(int speed, int opt)//opt=1 for 8N1; 2 for 7E1;
    {
    struct termios term;

    printf("\nChangeTermSpeed\n");
    // First set the common terminal settings
    if( tcgetattr(  device_fd, &term ) < 0 )
        {
        printf("\tunable to get device attributes\n");
        cout << "graceful_exit" << endl;
        // graceful_exit(ERR_SER_GET_CONFIG);
        return -2;
        }

    cfmakeraw( &term );
    if(false)//(PLSMode)
        {
        term.c_iflag |= INPCK;
        term.c_iflag &= ~IXOFF;
        term.c_cflag |= PARENB;
        }

    switch(opt)
        {
        case 1:
            term.c_cflag &= ~PARENB;
            term.c_cflag &= ~CSTOPB;
            term.c_cflag &= ~CSIZE;
            term.c_cflag |= CS8;
            break;

        case 2:
            term.c_cflag |= PARENB;
            term.c_cflag &= ~PARODD;
            term.c_cflag &= ~CSTOPB;
            term.c_cflag &= ~CSIZE;
            term.c_cflag |= CS7;
            break;

        default:
            printf("\tunknown Option %d\n", opt);
        }



    printf("Device: testing change of TERM speed: %d\n", speed);

    switch(speed)
        {
        case 9600:
            //printf( "terminal speed to 9600");

            cfsetispeed( &term, B9600 );
            cfsetospeed( &term, B9600 );

            if( tcsetattr(  device_fd, TCSAFLUSH, &term ) < 0 )
                {
                printf("\tUnable to set serial port attributes\n");
                cout << "graceful_exit" << endl;
                // graceful_exit(ERR_SER_SET_CONFIG);
                return -3;
                }
            break;

        case 38400:
            //printf( "terminal speed to 38400");

            cfsetispeed( &term, B38400 );
            cfsetospeed( &term, B38400 );

            if( tcsetattr(  device_fd, TCSAFLUSH, &term ) < 0 )
                {
                printf("\tUnable to set serial port attributes\n");
                cout << "graceful_exit" << endl;
                // graceful_exit(ERR_SER_SET_CONFIG);
                return -3;
                }
            break;

        case 19200:
            //printf( "terminal speed to 19200");

            cfsetispeed( &term, B19200 );
            cfsetospeed( &term, B19200 );

            if( tcsetattr(  device_fd, TCSAFLUSH, &term ) < 0 )
                {
                printf("\tUnable to set serial port attributes\n");
                cout << "graceful_exit" << endl;
                // graceful_exit(ERR_SER_SET_CONFIG);
                return -3;
                }
            break;

        case 57600:
            //printf( "terminal speed to 19200");

            cfsetispeed( &term, B57600 );
            cfsetospeed( &term, B57600 );

            if( tcsetattr(  device_fd, TCSAFLUSH, &term ) < 0 )
                {
                printf("\tUnable to set serial port attributes\n");
                cout << "graceful_exit" << endl;
                // graceful_exit(ERR_SER_SET_CONFIG);
                return -3;
                }
            break;

        case 115200:
            //printf( "terminal speed to 38400");

            cfsetispeed( &term, B115200 );
            cfsetospeed( &term, B115200 );

            if( tcsetattr(  device_fd, TCSAFLUSH, &term ) < 0 )
                {
                printf("\tUnable to set serial port attributes\n");
                cout << "graceful_exit" << endl;
                // graceful_exit(ERR_SER_SET_CONFIG);
                return -3;
                }
            break;

        default:
            printf("\tunknown speed %d\n", speed);
        }

    flushBuffers();
    return 0;
    }
