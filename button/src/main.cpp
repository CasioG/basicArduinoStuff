#include <Arduino.h>
#include "Boutton.hpp"
#include "Led.hpp"
#include "Action.hpp"
#include "ActionToogleLed.hpp"

Led *led;
ActionToogleLed *actionToogleLed;
Boutton *boutton;
uint8_t pinBoutton = 3;
uint8_t pinLed = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // init led
  led  = new Led(pinLed);

  // init action
  actionToogleLed = new ActionToogleLed(led);

  // init boutton
  boutton = new Boutton(pinBoutton, actionToogleLed);
}

void loop() {
  // put your main code here, to run repeatedly:
  boutton->tick();
}