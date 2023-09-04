#pragma once
#include "Action.hpp"
#include "Led.hpp"
#include <Arduino.h>
class ActionToogleLed : public Action
{
private:
    Led *m_led;
public:
    ActionToogleLed(Led *p_led);
    void execute();
};