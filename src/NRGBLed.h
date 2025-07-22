#ifndef NRGB_LED_H
#define NRGB_LED_H

#include <Arduino.h>

struct RGB {
  uint8_t RED;
  uint8_t GREEN;
  uint8_t BLUE;
};

class NRGBLed {
public:
  // Constructor
  NRGBLed(uint8_t r_pin, uint8_t g_pin, uint8_t b_pin);

  // Set color using RGB struct
  void setColor(const RGB& color);

  // Turn off LED
  void off();

  // Print RGB to Serial
  void print(const RGB& color);

  // Convert "#FFA500" or "FFA500" → RGB
  static RGB hexToRGB(const char* hexColorCode);

  // Convert RGB → 0xRRGGBB
  static uint32_t RGBToHex(const RGB& color);

  // Convert single hex digit → decimal
  static uint8_t hexToDecimal(uint8_t hex_code);

  // Blink single color
  void blink(const RGB& color, int onTime, int offTime, int count);

  // Blink single color with default time
  void blink(const RGB& color, int count); 

  // Blink array of colors
  void blink(const RGB* colors, size_t length, int onTime, int offTime, int count);

  // Blink array of colors with default time
  void blink(const RGB* colors, size_t length, int count);

private:
  uint8_t redPin;
  uint8_t greenPin;
  uint8_t bluePin;
};

#endif // NRGB_LED_H
