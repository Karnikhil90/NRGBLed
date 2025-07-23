#include <NRGBLed.h>
#include <NColors.h>
#include <NEffect.h>

NRGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);
NEffect effect(led);

void setup() {
  // Fade In
  effect.fadeIn(MAGENTA, 5000); // 5 sec fade in

  // Mid effects (total ~5 sec)
  effect.pulse(CYAN, 3, 400);
  delay(500);
  effect.strobe(YELLOW, 6, 100);
  delay(500);
  effect.wave(PrimaryColors, PrimaryColorCount, 2, 150);

  // Fade Out
  effect.fadeOut(MAGENTA, 5000); // 5 sec fade out
}

void loop() {
  // No repeating
}
