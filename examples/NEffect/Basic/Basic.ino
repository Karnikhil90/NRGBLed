#include <Arduino.h>
#include "NRGBLed.h"
#include "NColors.h"
#include "NEffect.h"

#define BLUE_PIN 3
#define GREEN_PIN 5
#define RED_PIN 6

// Create LED instance on pins 9, 10, 11
NRGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);
NEffect effect(led);  // Pass led to NEffect

void setup() {
  Serial.begin(9600);
  Serial.println("Starting LED Showcase...");
}

void loop() {
  Serial.println("==== PHASE 1: FADE IN (5s) ====");
  effect.fadeIn(GOLD, 2000);       // Fade in GOLD
  delay(500);
  effect.fadeIn(SALMON, 2000);     // Fade in SALMON
  delay(500);

  Serial.println("==== PHASE 2: MIDDLE SHOW (5s) ====");
  effect.breathing(MAGENTA, 2000); // Soft breathing
  delay(200);
  effect.strobe(RED, 6, 100);      // Eye-catching strobe
  delay(500);
  effect.wave(CoolColors, CoolColorCount, 2, 100); // Cool rainbow wave

  Serial.println("==== PHASE 3: FADE OUT (5s) ====");
  effect.fadeOut(PURPLE, 2000);
  delay(500);
  effect.fadeOut(BLUE, 2000);
  delay(500);

  Serial.println("Done! Restarting in 6 seconds...\n");
  led.off();
  delay(6000);
}
