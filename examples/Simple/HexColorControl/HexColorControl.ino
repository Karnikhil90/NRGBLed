#include <NRGBLed.h>

NRGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);

void setup() {
  RGB fromHex = RGBLed::hexToRGB("#00CED1"); // DeepSkyBlue
  led.setColor(fromHex);
  delay(1000);
  led.off();
}

void loop() {}
