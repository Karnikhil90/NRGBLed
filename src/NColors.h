#ifndef NCOLORS_H
#define NCOLORS_H

#include <Arduino.h>
#include "NRGBLed.h"

// [DEBUG]

#define BLUE_PIN 3
#define GREEN_PIN 5
#define RED_PIN 6


// Basic color defines
#define RED        {255, 0, 0}
#define GREEN      {0, 255, 0}
#define BLUE       {0, 0, 255}
#define YELLOW     {255, 255, 0}
#define CYAN       {0, 255, 255}
#define MAGENTA    {255, 0, 255}
#define WHITE      {255, 255, 255}
// #define BLACK      {0, 0, 0}
#define ORANGE     {255, 165, 0}
#define PINK       {255, 105, 180}
#define PURPLE     {128, 0, 128}
#define LIME       {191, 255, 0}
#define TEAL       {0, 128, 128}
#define INDIGO     {75, 0, 130}
#define VIOLET     {138, 43, 226}
#define BROWN      {139, 69, 19}
#define GREY       {128, 128, 128}
#define LIGHTGREY  {211, 211, 211}
#define SKYBLUE    {135, 206, 235}
#define GOLD       {255, 215, 0}
#define SALMON     {250, 128, 114}
#define NAVY       {0, 0, 128}
#define MINT       {189, 252, 201}
#define PEACH      {255, 218, 185}
#define AQUA       {0, 255, 255}

// Arrays of RGB structs

RGB AllColors[] = {
  RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE,
  ORANGE, PINK, PURPLE, LIME, TEAL, INDIGO, VIOLET,
  BROWN, GREY, LIGHTGREY, SKYBLUE, GOLD,
  SALMON, NAVY, MINT, PEACH, AQUA
};
const int AllColorCount = sizeof(AllColors) / sizeof(AllColors[0]);

// Primary Colors
RGB PrimaryColors[] = {
  RED, GREEN, BLUE
};
const int PrimaryColorCount = sizeof(PrimaryColors) / sizeof(PrimaryColors[0]);

// Secondary Colors
RGB SecondaryColors[] = {
  YELLOW, CYAN, MAGENTA
};
const int SecondaryColorCount = sizeof(SecondaryColors) / sizeof(SecondaryColors[0]);

// Warm Colors
RGB WarmColors[] = {
  RED, ORANGE, YELLOW, PINK, GOLD, PEACH, SALMON
};
const int WarmColorCount = sizeof(WarmColors) / sizeof(WarmColors[0]);

// Cool Colors
RGB CoolColors[] = {
  BLUE, CYAN, GREEN, TEAL, INDIGO, SKYBLUE, MINT, NAVY
};
const int CoolColorCount = sizeof(CoolColors) / sizeof(CoolColors[0]);

// Light Colors
RGB LightColors[] = {
  WHITE, LIGHTGREY, MINT, SKYBLUE, PEACH
};
const int LightColorCount = sizeof(LightColors) / sizeof(LightColors[0]);

// Dark Colors
RGB DarkColors[] = {
  NAVY, BROWN, INDIGO, PURPLE, TEAL
};
const int DarkColorCount = sizeof(DarkColors) / sizeof(DarkColors[0]);

#endif // NCOLORS_H
