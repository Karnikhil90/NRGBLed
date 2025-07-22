// NPattern.cpp
#include "NPattern.h"

NPattern::NPattern(NRGBLed& led) : led(led) {}

void NPattern::play(const RGB* pattern, size_t length, int delayTime, bool loop, bool fade, int fadeSteps) {
  do {
    for (size_t i = 0; i < length; i++) {
      if (fade && i > 0) {
        RGB from = pattern[i - 1];
        RGB to = pattern[i];
        for (int step = 0; step <= fadeSteps; step++) {
          float progress = float(step) / fadeSteps;
          RGB interp = {
            uint8_t(from.RED + progress * (to.RED - from.RED)),
            uint8_t(from.GREEN + progress * (to.GREEN - from.GREEN)),
            uint8_t(from.BLUE + progress * (to.BLUE - from.BLUE))
          };
          led.setColor(interp);
          delay(delayTime / fadeSteps);
        }
      } else {
        led.setColor(pattern[i]);
        delay(delayTime);
      }
    }
  } while (loop);
}

void NPattern::rainbow(int steps, int delayTime) {
  for (int i = 0; i < steps; i++) {
    float hue = float(i) / steps;
    float r = abs(sin(TWO_PI * hue));
    float g = abs(sin(TWO_PI * hue + PI * 2 / 3));
    float b = abs(sin(TWO_PI * hue + PI * 4 / 3));
    RGB color = {
      uint8_t(r * 255),
      uint8_t(g * 255),
      uint8_t(b * 255)
    };
    led.setColor(color);
    delay(delayTime);
  }
}

void NPattern::flashColors(const RGB* colors, size_t length, int count, int delayTime) {
  for (int i = 0; i < count; i++) {
    for (size_t j = 0; j < length; j++) {
      led.setColor(colors[j]);
      delay(delayTime);
      led.off();
      delay(delayTime);
    }
  }
}

void NPattern::random(int count, int delayTime) {
  for (int i = 0; i < count; i++) {
    RGB color = {
      uint8_t(::random(0, 256)),
      uint8_t(::random(0, 256)),
      uint8_t(::random(0, 256))
    };
    led.setColor(color);
    delay(delayTime);
  }
}
