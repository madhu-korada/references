#ifndef SERIAL_H
#define SERIAL_H

//#include <config.h>
#include <assert.h>
#include <math.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <sys/time.h>

#define HAVE_LINUX_SERIAL_H

#undef HAVE_HI_SPEED_SERIAL
#ifdef HAVE_LINUX_SERIAL_H
#ifndef DISABLE_HIGHSPEEDSICK
#include <linux/serial.h>
#define HAVE_HI_SPEED_SERIAL
#endif
#endif

/*
 * the following macros can be used to get the first char, short, or int
 * out of an unstructured buffer (such as a void* that contains a struct
 * of unknown type).
 */
#define GETFIRSTUINT8(x)  (*((uint8_t*)x))
#define GETFIRSTINT8(x)   (*((int8_t*)x))
#define GETFIRSTUINT16(x) (*((uint16_t*)x))
#define GETFIRSTINT16(x)  (*((int16_t*)x))
#define GETFIRSTUINT32(x) (*((uint32_t*)x))
#define GETFIRSTINT32(x)  (*((int32_t*)x))

#if !defined WIN32
#define LOBYTE(w) ((uint8_t) (w & 0xFF))
#define HIBYTE(w) ((uint8_t) ((w >> 8) & 0xFF))
#endif
#define MAKEUINT16(lo, hi) ((((uint16_t) (hi)) << 8) | ((uint16_t) (lo)))

//#include <replace/replace.h>

#define DEFAULT_LASER_PORT "/dev/ttyMI0"
#define DEFAULT_LASER_CONNECT_RATE 9600
#define DEFAULT_LASER_TRANSFER_RATE 38400
#define DEFAULT_LASER_RETRIES 3
#define MAX_CONNECT_RATES 8


#include "string"

class  serialPort
    {
    public:
        // Constructor
        serialPort(const char *);
        ~serialPort();


        int readBytes (uint8_t *data, ssize_t maxlen);
        int writeBytes(uint8_t *data, ssize_t maxlen);

        // Set the terminal speed
        // Valid values are 9600 and 19200
        // opt=1 for 8N1; 2 for 7E1;
        // Returns 0 on success
        int ChangeTermSpeed(int speed, int opt);

    private:
        // Open the terminal
        // Returns 0 on success
        int OpenTerm(const char *);

        // Close the terminal
        // Returns 0 on success
        int CloseTerm();

        // device device file descriptor
        int device_fd;

        void flushBuffers();

        const char * serial_port_file;
        void setNewOptions(int baudrate, int databits, const std::string& parity, const std::string& stop, bool softwareHandshake, bool hardwareHandshake);
    };

#endif // SERIAL_H
