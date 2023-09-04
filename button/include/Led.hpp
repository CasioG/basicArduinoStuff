#pragma once
#include <Arduino.h>

class Led
{
private:
    int m_pinLed;

public:
    Led(const int &p_pinLed);
    void turnOn();
    void turnOff();
    void toogle();
};