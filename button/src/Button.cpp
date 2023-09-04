#include "Button.hpp"

Button::Button(const int p_pinButton, Action *p_action)
    : m_pinButton(p_pinButton), m_action(p_action)
{
    pinMode(m_pinButton, INPUT);
}
void Button::tick()
{
    int buttonState = digitalRead(m_pinButton);
    long currentDate = millis();

    if (buttonState != m_lastButtonState)
    {
        m_lastChangedDate = currentDate;
        m_lastButtonState = buttonState;
    }

    if (currentDate - m_lastChangedDate > m_minTimeForButtonPressed)
    {
        if (m_lastStableButtonState == LOW && buttonState == HIGH)
        {
            Serial.println("action bouton");
            m_action->execute();
        }
        m_lastStableButtonState = buttonState;
    }
}