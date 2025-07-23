#include <NRGBLed.h>
#include <NColors.h>
#include <NEffect.h>

NRGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);
NEffect effect(led);

void setup() {
  effect.fadeIn(ORANGE, 2000);
  delay(500);
  effect.breathing(PURPLE, 4000); // 1 full breathe cycle in 4s
  delay(500);
  effect.fadeOut(ORANGE, 2000);
}

void loop() {}
