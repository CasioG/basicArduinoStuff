#include <Arduino.h>
#include "Button.hpp"
#include "Led.hpp"
#include "Action.hpp"
#include "ActionToogleLed.hpp"

Led *led;
ActionToogleLed *actionToogleLed;
Button *button;
uint8_t pinButton = 4;
uint8_t pinLed = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // init led
  led  = new Led(pinLed);

  // init action
  actionToogleLed = new ActionToogleLed(led);

  // init button
  button = new Button(pinButton, actionToogleLed);
}

void loop() {
  // put your main code here, to run repeatedly:
  button->tick();
}