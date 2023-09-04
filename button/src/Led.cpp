
#include "Led.hpp"

Led::Led(const int &p_pinLed) : m_pinLed(p_pinLed)
{
    pinMode(this->m_pinLed, OUTPUT);
    digitalWrite(this->m_pinLed, LOW);
}

void Led::turnOn()
{
    digitalWrite(this->m_pinLed, HIGH);
    Serial.println("Led is on");
}
void Led::turnOff()
{
    digitalWrite(this->m_pinLed, LOW);
    Serial.println("Led is off");
}
void Led::toogle()
{
    if (digitalRead(this->m_pinLed) == HIGH)
    {
        this->turnOff();
    }
    else
    {
        this->turnOn();
    }
}