// NPattern.h
#ifndef NPATTERN_H
#define NPATTERN_H

#include <Arduino.h>
#include "NRGBLed.h"

class NPattern {
public:
  NPattern(NRGBLed& led);

  // Play a predefined array of RGB colors
  void play(const RGB* pattern, size_t length, int delayTime = 500, bool loop = false, bool fade = false, int fadeSteps = 20);

  // Generate a rainbow color cycle animation
  void rainbow(int steps = 100, int delayTime = 20);

  // Flash a set of colors a number of times
  void flashColors(const RGB* colors, size_t length, int count = 10, int delayTime = 300);

  // Generate random RGB colors and flash them
  void random(int count = 10, int delayTime = 300);


private:
  NRGBLed& led;
};

#endif // NPATTERN_H