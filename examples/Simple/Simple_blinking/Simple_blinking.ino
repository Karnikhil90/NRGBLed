#include <NRGBLed.h>
#include "NColors.h"

#define BLUE_PIN 3
#define GREEN_PIN 5
#define RED_PIN 6

NRGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);
// NPattern pattern(led);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Simple Blinking");
}


void loop() {
// NColors.h : File had been used 
  led.blink(DarkColors,DarkColorCount,3);

  led.blink(WarmColors,WarmColorCount,2);

  delay(1000); // Small delay before repeating patterns


}
