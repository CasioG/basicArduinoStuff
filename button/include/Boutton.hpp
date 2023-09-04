#pragma once
#include "Action.hpp"
#include <Arduino.h>

class Boutton
{
private:
    const int m_pinBoutton;
    Action *m_action;
    long m_nextChangeDate = 0;
    int m_lastBouttonState = HIGH;
    int m_lastStableButtonState = HIGH;
    const int m_minTimeForBouttonPressed = 25;

public:
    Boutton(const int p_pinBouton, Action *p__action);
    void tick();
};
