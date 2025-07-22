
# NRGBLed(v1.0)– RGB LED Control Library for Arduino

NRGBLed is an Arduino library that simplifies controlling RGB LEDs using PWM (analogWrite). It allows users to set custom colors, create visual patterns, and apply smooth lighting effects using intuitive functions.

This library is built for ease of use while providing powerful features for more advanced LED animations. It is suitable for students, hobbyists, and developers working with analog RGB LEDs.

---

## Key Features

* Uses PWM (analogWrite) to control individual red, green, and blue LED channels.
* Supports setting colors using RGB struct or hexadecimal values.
* Provides simple blinking and sequence playback using custom or predefined colors.
* Includes advanced effects like fade-in, fade-out, pulsing, strobing, breathing, shimmering, and color waves.
* Offers helper functions for converting between color formats.
* Comes with a predefined set of common color constants in the NColors module.

---

## Components

* NRGBLed: Core class for controlling RGB LED using three PWM pins.
* NEffect: Optional effect class that adds smooth transitions and light animations.
* NColors: A header file that defines an array of common RGB colors.
* NPattern (optional): Pattern helper for creating looping sequences and patterns.

---

## How It Works

The library works by sending PWM signals to the red, green, and blue pins of a common cathode RGB LED. Colors are created by adjusting the brightness of each channel individually using analogWrite. Timed delays and loops are used to animate the color transitions and effects.

---

## Requirements

* Arduino-compatible board with three PWM-capable pins.
* Arduino IDE or other compatible development environment.