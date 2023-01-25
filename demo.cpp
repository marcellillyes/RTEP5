#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "MouseClass.h"


int main(int argc, char **argv) {

    MouseClass mymouse = MouseClass("/dev/input/mice");

    //Mousecallback mc;

    //mymouse.registerCallback(&mc);

    mymouse.mstart();

    sleep(10);

    mymouse.mstop();
}
