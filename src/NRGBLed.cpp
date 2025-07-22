#include "NRGBLed.h"

NRGBLed::NRGBLed(uint8_t r_pin, uint8_t g_pin, uint8_t b_pin) {
  redPin = r_pin;
  greenPin = g_pin;
  bluePin = b_pin;

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void NRGBLed::setColor(const RGB& color) {
  analogWrite(redPin, constrain(color.RED, 0, 255));
  analogWrite(greenPin, constrain(color.GREEN, 0, 255));
  analogWrite(bluePin, constrain(color.BLUE, 0, 255));
}

void NRGBLed::off() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void NRGBLed::print(const RGB& color) {
  Serial.print("R: ");
  Serial.print(color.RED);
  Serial.print(", G: ");
  Serial.print(color.GREEN);
  Serial.print(", B: ");
  Serial.println(color.BLUE);
}

uint8_t NRGBLed::hexToDecimal(uint8_t hex_code) {
  if (hex_code >= '0' && hex_code <= '9') return hex_code - '0';
  if (hex_code >= 'A' && hex_code <= 'F') return hex_code - 'A' + 10;
  if (hex_code >= 'a' && hex_code <= 'f') return hex_code - 'a' + 10;
  return 0;
}

RGB NRGBLed::hexToRGB(const char* hexColorCode) {
  RGB color = {0, 0, 0};
  if (!hexColorCode) return color;
  if (hexColorCode[0] == '#') hexColorCode++;
  if (strlen(hexColorCode) < 6) return color;

  color.RED   = (hexToDecimal(hexColorCode[0]) << 4) + hexToDecimal(hexColorCode[1]);
  color.GREEN = (hexToDecimal(hexColorCode[2]) << 4) + hexToDecimal(hexColorCode[3]);
  color.BLUE  = (hexToDecimal(hexColorCode[4]) << 4) + hexToDecimal(hexColorCode[5]);

  return color;
}

uint32_t NRGBLed::RGBToHex(const RGB& color) {
  return ((uint32_t)color.RED << 16) | ((uint16_t)color.GREEN << 8) | color.BLUE;
}

// Full version: blink a single color with specific timings
void NRGBLed::blink(const RGB& color, int onTime, int offTime, int count) {
  for (int i = 0; i < count; ++i) {
    setColor(color);
    delay(onTime);
    off();
    delay(offTime);
  }
}

// Simpler version: blink a single color with default 300ms timings
void NRGBLed::blink(const RGB& color, int count) {
  blink(color, 300, 300, count);
}

// Full version: blink an array of colors; each color blinks 'count' times
void NRGBLed::blink(const RGB* colors, size_t length, int onTime, int offTime, int count) {
  if (!colors || length == 0) return;

  for (size_t i = 0; i < length; ++i) {
    blink(colors[i], onTime, offTime, count); // Use single-color blink logic
  }
}

// Simpler version: blink color array with default timing
void NRGBLed::blink(const RGB* colors, size_t length, int count) {
  blink(colors, length, 300, 300, count);
}
