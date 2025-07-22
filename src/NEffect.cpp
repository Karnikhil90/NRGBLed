#include "NEffect.h"

NEffect::NEffect(NRGBLed& led) : led(led) {}

void NEffect::fadeIn(const RGB& color, int duration) {
  for (int i = 0; i <= 255; ++i) {
    RGB faded = { (uint8_t)(color.RED * i / 255), (uint8_t)(color.GREEN * i / 255), (uint8_t)(color.BLUE * i / 255) };
    led.setColor(faded);
    delay(duration / 255);
  }
}

void NEffect::fadeOut(const RGB& color, int duration) {
  for (int i = 255; i >= 0; --i) {
    RGB faded = { (uint8_t)(color.RED * i / 255), (uint8_t)(color.GREEN * i / 255), (uint8_t)(color.BLUE * i / 255) };
    led.setColor(faded);
    delay(duration / 255);
  }
}

void NEffect::breathing(const RGB& color, int duration) {
  fadeIn(color, duration / 2);
  fadeOut(color, duration / 2);
}

void NEffect::fadeBetween(const RGB& from, const RGB& to, int steps, int delayTime) {
  for (int i = 0; i <= steps; ++i) {
    float progress = (float)i / steps;
    led.setColor(interpolate(from, to, progress));
    delay(delayTime);
  }
}

RGB NEffect::interpolate(const RGB& start, const RGB& end, float progress) {
  RGB result;
  result.RED = start.RED + (end.RED - start.RED) * progress;
  result.GREEN = start.GREEN + (end.GREEN - start.GREEN) * progress;
  result.BLUE = start.BLUE + (end.BLUE - start.BLUE) * progress;
  return result;
}

void NEffect::pulse(const RGB& color, int pulseCount, int interval) {
  for (int i = 0; i < pulseCount; ++i) {
    fadeIn(color, interval);
    fadeOut(color, interval);
  }
}

void NEffect::strobe(const RGB& color, int flashes, int flashDuration) {
  for (int i = 0; i < flashes; ++i) {
    led.setColor(color);
    delay(flashDuration);
    led.off();
    delay(flashDuration);
  }
}

void NEffect::shimmer(const RGB& baseColor, int sparkleCount, int delayTime) {
  for (int i = 0; i < sparkleCount; ++i) {
    RGB sparkle = {
      (uint8_t)(baseColor.RED + random(-20, 20)),
      (uint8_t)(baseColor.GREEN + random(-20, 20)),
      (uint8_t)(baseColor.BLUE + random(-20, 20))
    };
    led.setColor(sparkle);
    delay(delayTime);
  }
  led.setColor(baseColor);
}

void NEffect::wave(const RGB* colors, size_t length, int cycles, int delayTime) {
  for (int c = 0; c < cycles; ++c) {
    for (size_t i = 0; i < length; ++i) {
      led.setColor(colors[i]);
      delay(delayTime);
    }
  }
}
