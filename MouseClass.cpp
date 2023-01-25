#include "MouseClass.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


/*struct Mousecallback
{
    virtual bool hasData(int x, int y, bool left, bool middle, bool right) = 0;
};

void MouseClass::registerCallback(Mousecallback* mc)
{

}

*/


void MouseClass::run()
{   
    int fd;
    int bytes;
    unsigned char data[3];

    fd = open(this->pDevice.c_str(), O_RDWR);

    if (fd == -1) {
        printf("ERROR Opening %s\n", pDevice.c_str());
    }

    int left, middle, right;
    signed char x, y;

    while(this->running)
    {
        // Read Mouse     
        bytes = read(fd, data, sizeof(data));

        if(bytes > 0)
        {
            left = data[0] & 0x1;
            right = data[0] & 0x2;
            middle = data[0] & 0x4;

            x = data[1];
            y = data[2];

            //Callback here if hasData = true ?

            printf("x=%d, y=%d, left=%d, middle=%d, right=%d\n", x, y, left, middle, right);

        }   
    }

}

void MouseClass::mstart()
{
    this->running = 1;
    CppThread::start();
}

void MouseClass::mstop()
{
    this->running = 0;
    CppThread::join();
}