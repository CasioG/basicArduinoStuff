#include "Boutton.hpp"

Boutton::Boutton(const int p_pinBoutton, Action *p_action)
    : m_pinBoutton(p_pinBoutton), m_action(p_action)
{
    pinMode(m_pinBoutton, INPUT);
}
void Boutton::tick()
{
    int bouttonState = digitalRead(m_pinBoutton);
    long currentDate = millis();

    if (bouttonState != m_lastBouttonState)
    {
        m_lastChangedDate = currentDate;
        m_lastBouttonState = bouttonState;
    }
    
    if (currentDate - m_lastChangedDate > m_minTimeForBouttonPressed)
    {
        if (m_lastStableButtonState == LOW && bouttonState == HIGH)
        {
            Serial.println("action bouton");
            m_action->execute();
        }
        m_lastStableButtonState = bouttonState;
    }
}