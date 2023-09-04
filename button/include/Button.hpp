#pragma once
#include "Action.hpp"
#include <Arduino.h>

class Button
{
private:
    const int m_pinButton;
    Action *m_action;
    long m_lastChangedDate = 0;
    int m_lastButtonState = HIGH;
    int m_lastStableButtonState = HIGH;
    const int m_minTimeForButtonPressed = 25;

public:
    Button(const int p_pinBouton, Action *p__action);
    void tick();
};
