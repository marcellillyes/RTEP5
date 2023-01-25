
#ifndef MOUSE_CLASS_H
#define MOUSE_CLASS_H


#include "CppThread.h"
#include <string>

//using namespace std;

struct Mousecallback
{
    virtual bool hasData(int x, int y, bool left, bool middle, bool right) = 0;
};


class MouseClass : public CppThread
{
public:

    MouseClass(std::string _pDevice){
        this->pDevice = _pDevice;
    }

    void registerCallback(Mousecallback* mc);

    void mstart();

    void mstop();

    bool running;

private:

    std::string pDevice;

private:

	void run();
    
};

#endif