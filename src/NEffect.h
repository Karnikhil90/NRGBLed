// NEffect.h
#ifndef NEFFECT_H
#define NEFFECT_H

#include <Arduino.h>
#include "NRGBLed.h"

class NEffect {
public:
  NEffect(NRGBLed& led);

  void fadeIn(const RGB& color, int duration = 1000);
  void fadeOut(const RGB& color, int duration = 1000);
  void breathing(const RGB& color, int duration = 2000);
  void fadeBetween(const RGB& from, const RGB& to, int steps = 50, int delayTime = 20);
  RGB interpolate(const RGB& start, const RGB& end, float progress);

  // Additional professional effects
  void pulse(const RGB& color, int pulseCount = 5, int interval = 300);
  void strobe(const RGB& color, int flashes = 10, int flashDuration = 100);
  void shimmer(const RGB& baseColor, int sparkleCount = 20, int delayTime = 50);
  void wave(const RGB* colors, size_t length, int cycles = 3, int delayTime = 100);

private:
  NRGBLed& led;
};

#endif // NEFFECT_H