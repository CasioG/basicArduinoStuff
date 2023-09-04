#include "ActionToogleLed.hpp"

ActionToogleLed::ActionToogleLed(Led *p_led) : m_led(p_led)
{
    this->m_led->turnOff();
}


void ActionToogleLed::execute(){
    this->m_led->toogle();
}