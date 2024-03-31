
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MAX_MESSAGE_LENGTH 50
#include <stdint.h>



const unsigned char frame1 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x76, 0x20, 0x00, 0x00, 0x00, 0x00, 0x77, 0x50, 0x1d, 0xd8, 0x00, 0x1d, 0xd1, 
  0x06, 0x06, 0x04, 0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x45, 0x50, 0x11, 0x54, 0x00, 0x15, 0x5b, 
  0x0f, 0x0f, 0x06, 0x75, 0x20, 0x00, 0x00, 0x00, 0x00, 0x47, 0x50, 0x19, 0xd4, 0x00, 0x19, 0xd5, 
  0x1f, 0x1f, 0x84, 0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x44, 0x50, 0x11, 0x54, 0x00, 0x15, 0x11, 
  0x3e, 0x3f, 0xc4, 0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x74, 0x70, 0x11, 0x54, 0x00, 0x15, 0x11, 
  0x3e, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0x39, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x19, 0xcf, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0xee, 0x88, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0x8f, 0x80, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1d, 0xd8, 0x00, 0x00, 0x74, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x54, 0x00, 0x00, 0x08, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0xd4, 0x00, 0x00, 0x17, 
  0x00, 0x00, 0x07, 0x76, 0x70, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x01, 0x15, 0x54, 0x00, 0x00, 0x25, 
  0x06, 0x06, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x01, 0xdd, 0x58, 0x00, 0x00, 0x47, 
  0x0f, 0x0f, 0x06, 0x75, 0x70, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0x1f, 0x84, 0x55, 0x40, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3e, 0x3f, 0xc4, 0x55, 0x70, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3e, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0x39, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x01, 0x17, 0x77, 0x30, 0x00, 0x00, 
  0x00, 0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x01, 0x15, 0x22, 0x40, 0x00, 0x00, 
  0x19, 0xcf, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x01, 0x57, 0x22, 0x70, 0x00, 0x00, 
  0x3f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0xee, 0x88, 0x80, 0x00, 0x01, 0xb5, 0x22, 0x10, 0x00, 0x00, 
  0x3f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0xaa, 0xd9, 0x00, 0x00, 0x01, 0x15, 0x22, 0x60, 0x00, 0x00, 
  0x1f, 0x8f, 0x80, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x55, 0x97, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x85, 0x55, 0x55, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x1f, 0xf8, 0x00, 0x45, 0x55, 0x57, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xc0, 0xcf, 0xf3, 0x03, 0x25, 0x55, 0x55, 
  0x00, 0x00, 0x07, 0x76, 0x70, 0x00, 0x00, 0x00, 0x19, 0xe1, 0xe7, 0xe7, 0x87, 0x95, 0x25, 0x95, 
  0x06, 0x06, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x13, 0xe3, 0xf3, 0xcf, 0x8f, 0xc8, 0x00, 0x00, 
  0x0f, 0x0f, 0x06, 0x75, 0x30, 0x00, 0x00, 0x00, 0x17, 0xc7, 0xfb, 0xdf, 0x1f, 0xe8, 0x00, 0x00, 
  0x1f, 0x1f, 0x84, 0x55, 0x10, 0x00, 0x00, 0x00, 0x17, 0xc7, 0xfb, 0xdf, 0x1f, 0xe8, 0x00, 0x07, 
  0x3e, 0x3f, 0xc4, 0x55, 0x70, 0x00, 0x00, 0x00, 0x13, 0xe7, 0x33, 0xcf, 0x9c, 0xc8, 0x00, 0x05, 
  0x3e, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xf6, 0x03, 0xc7, 0xd8, 0x08, 0x00, 0x07, 
  0x1f, 0x39, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xfc, 0x03, 0xc3, 0xf0, 0x08, 0x00, 0x00, 
  0x0f, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0f, 0xc3, 0xc0, 0x3f, 0x08, 0x00, 0x00, 
  0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1b, 0xe3, 0xc0, 0x6f, 0x88, 0x00, 0x00, 
  0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x39, 0xf3, 0xcc, 0xe7, 0xc8, 0x00, 0x00, 
  0x00, 0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xf8, 0xfb, 0xdf, 0xe3, 0xe8, 0x00, 0x00, 
  0x19, 0xcf, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xf8, 0xfb, 0xdf, 0xe3, 0xe8, 0x00, 0x00, 
  0x3f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0xee, 0x88, 0x13, 0xf1, 0xf3, 0xcf, 0xc7, 0xc8, 0x00, 0x00, 
  0x3f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x19, 0xe1, 0xe7, 0xe7, 0x87, 0x90, 0x00, 0x00, 
  0x1f, 0x8f, 0x80, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x1c, 0xc0, 0xcf, 0xf3, 0x03, 0x20, 0x00, 0x00, 
  0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x1e, 0x00, 0x1f, 0xf8, 0x00, 0x40, 0x00, 0x00, 
  0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00
};



const unsigned char frame2 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x76, 0x20, 0x00, 0x00, 0x00, 0x00, 0x77, 0x50, 0x1d, 0xd8, 0x00, 0x1d, 0xd1, 
  0x03, 0xe0, 0x04, 0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x45, 0x50, 0x11, 0x54, 0x00, 0x15, 0x5b, 
  0x07, 0xc0, 0x06, 0x75, 0x20, 0x00, 0x00, 0x00, 0x00, 0x47, 0x50, 0x19, 0xd4, 0x00, 0x19, 0xd5, 
  0x07, 0xc0, 0x04, 0x55, 0x20, 0x00, 0x00, 0x00, 0x11, 0x44, 0x50, 0x11, 0x54, 0x00, 0x15, 0x11, 
  0x07, 0xc3, 0x84, 0x55, 0x20, 0x00, 0x00, 0x00, 0x11, 0x74, 0x70, 0x11, 0x54, 0x00, 0x15, 0x11, 
  0x03, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xdf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1c, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xee, 0x88, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1d, 0xd8, 0x00, 0x00, 0x74, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x54, 0x00, 0x00, 0x08, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0xd4, 0x00, 0x00, 0x17, 
  0x00, 0x00, 0x07, 0x76, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x54, 0x00, 0x00, 0x25, 
  0x03, 0xe0, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xdd, 0x58, 0x00, 0x00, 0x47, 
  0x07, 0xc0, 0x06, 0x75, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x07, 0xc0, 0x04, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x07, 0xc3, 0x84, 0x55, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xdf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x17, 0x77, 0x30, 0x00, 0x00, 
  0x3f, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x22, 0x40, 0x00, 0x00, 
  0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0x22, 0x70, 0x00, 0x00, 
  0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0xee, 0x88, 0x00, 0x00, 0x01, 0xb5, 0x22, 0x10, 0x00, 0x00, 
  0x1c, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x00, 0x00, 0x01, 0x15, 0x22, 0x60, 0x00, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x55, 0x97, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x85, 0x55, 0x55, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x1f, 0xf8, 0x00, 0x45, 0x55, 0x57, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x7c, 0x0f, 0xf1, 0xf0, 0x25, 0x55, 0x55, 
  0x00, 0x00, 0x07, 0x76, 0x70, 0x00, 0x00, 0x00, 0x18, 0xf8, 0x07, 0xe3, 0xe0, 0x15, 0x25, 0x95, 
  0x03, 0xe0, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x10, 0xf8, 0x03, 0xc3, 0xe0, 0x08, 0x00, 0x00, 
  0x07, 0xc0, 0x06, 0x75, 0x30, 0x00, 0x00, 0x00, 0x10, 0xf8, 0x73, 0xc3, 0xe1, 0xc8, 0x00, 0x00, 
  0x07, 0xc0, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x10, 0x79, 0xfb, 0xc1, 0xe7, 0xe8, 0x00, 0x07, 
  0x07, 0xc3, 0x84, 0x55, 0x70, 0x00, 0x00, 0x00, 0x10, 0x79, 0xfb, 0xc1, 0xe7, 0xe8, 0x00, 0x05, 
  0x03, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1b, 0xfb, 0xc0, 0x6f, 0xe8, 0x00, 0x07, 
  0x03, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x0f, 0xfb, 0xd0, 0x3f, 0xe8, 0x00, 0x00, 
  0x00, 0xdf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xfc, 0x0b, 0xdf, 0xf0, 0x28, 0x00, 0x00, 
  0x20, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xf6, 0x03, 0xdf, 0xd8, 0x08, 0x00, 0x00, 
  0x3f, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xe7, 0x83, 0xdf, 0x9e, 0x08, 0x00, 0x00, 
  0x3f, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xe7, 0x83, 0xdf, 0x9e, 0x08, 0x00, 0x00, 
  0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x87, 0xc3, 0xce, 0x1f, 0x08, 0x00, 0x00, 
  0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0xee, 0x88, 0x10, 0x07, 0xc3, 0xc0, 0x1f, 0x08, 0x00, 0x00, 
  0x1c, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x18, 0x07, 0xc7, 0xe0, 0x1f, 0x10, 0x00, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x1c, 0x0f, 0x8f, 0xf0, 0x3e, 0x20, 0x00, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x1e, 0x00, 0x1f, 0xf8, 0x00, 0x40, 0x00, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char frame3 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x76, 0x20, 0x00, 0x00, 0x00, 0x11, 0x77, 0x50, 0x1d, 0xd8, 0x00, 0x1d, 0xd1, 
  0x00, 0x3f, 0x04, 0x55, 0x60, 0x00, 0x00, 0x00, 0x22, 0x45, 0x50, 0x11, 0x54, 0x00, 0x15, 0x5b, 
  0x00, 0x7f, 0x06, 0x75, 0x20, 0x00, 0x00, 0x00, 0x22, 0x47, 0x50, 0x19, 0xd4, 0x00, 0x19, 0xd5, 
  0x30, 0xfc, 0x04, 0x55, 0x20, 0x00, 0x00, 0x00, 0x11, 0x44, 0x50, 0x11, 0x54, 0x00, 0x15, 0x11, 
  0x30, 0xf8, 0x04, 0x55, 0x20, 0x00, 0x00, 0x00, 0x11, 0x74, 0x70, 0x11, 0x54, 0x00, 0x15, 0x11, 
  0x38, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x3e, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0x67, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x73, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xf1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xee, 0x88, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1d, 0xd8, 0x00, 0x00, 0x74, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x54, 0x00, 0x00, 0x08, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0xd4, 0x00, 0x00, 0x17, 
  0x00, 0x00, 0x07, 0x76, 0x70, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x01, 0x15, 0x54, 0x00, 0x00, 0x25, 
  0x00, 0x3f, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x01, 0xdd, 0x58, 0x00, 0x00, 0x47, 
  0x00, 0x7f, 0x06, 0x75, 0x70, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x30, 0xfc, 0x04, 0x55, 0x40, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x30, 0xf8, 0x04, 0x55, 0x70, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x38, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3e, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x01, 0x17, 0x77, 0x30, 0x00, 0x00, 
  0x0f, 0x67, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x01, 0x15, 0x22, 0x40, 0x00, 0x00, 
  0x00, 0x73, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x01, 0x57, 0x22, 0x70, 0x00, 0x00, 
  0x00, 0xf1, 0xc0, 0x00, 0x00, 0x00, 0xee, 0x88, 0x80, 0x00, 0x01, 0xb5, 0x22, 0x10, 0x00, 0x00, 
  0x01, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xaa, 0xd9, 0x00, 0x00, 0x01, 0x15, 0x22, 0x60, 0x00, 0x00, 
  0x03, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x55, 0x97, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x85, 0x55, 0x55, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x1f, 0xf8, 0x00, 0x45, 0x55, 0x57, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xef, 0xf0, 0x1f, 0xa5, 0x55, 0x55, 
  0x00, 0x00, 0x07, 0x76, 0x70, 0x00, 0x00, 0x00, 0x18, 0x0f, 0xe7, 0xe0, 0x3f, 0x95, 0x25, 0x95, 
  0x00, 0x3f, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x16, 0x1f, 0x83, 0xd8, 0x7e, 0x08, 0x00, 0x00, 
  0x00, 0x7f, 0x06, 0x75, 0x30, 0x00, 0x00, 0x00, 0x16, 0x1f, 0x03, 0xd8, 0x7c, 0x08, 0x00, 0x00, 
  0x30, 0xfc, 0x04, 0x55, 0x10, 0x00, 0x00, 0x00, 0x17, 0x1e, 0x03, 0xdc, 0x78, 0x08, 0x00, 0x07, 
  0x30, 0xf8, 0x04, 0x55, 0x70, 0x00, 0x00, 0x00, 0x17, 0x9c, 0x03, 0xde, 0x70, 0x08, 0x00, 0x05, 
  0x38, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xcd, 0xe3, 0xdf, 0x37, 0x88, 0x00, 0x07, 
  0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xff, 0xf3, 0xdf, 0xff, 0xc8, 0x00, 0x00, 
  0x3e, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xff, 0xfb, 0xcf, 0xff, 0xe8, 0x00, 0x00, 
  0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xec, 0xfb, 0xc7, 0xb3, 0xe8, 0x00, 0x00, 
  0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0e, 0x7b, 0xc0, 0x39, 0xe8, 0x00, 0x00, 
  0x0f, 0x67, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1e, 0x3b, 0xc0, 0x78, 0xe8, 0x00, 0x00, 
  0x00, 0x73, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3e, 0x1b, 0xc0, 0xf8, 0x68, 0x00, 0x00, 
  0x00, 0xf1, 0xc0, 0x00, 0x00, 0x00, 0xee, 0x88, 0x10, 0x7e, 0x1b, 0xc1, 0xf8, 0x68, 0x00, 0x00, 
  0x01, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xaa, 0xd8, 0x19, 0xfc, 0x07, 0xe7, 0xf0, 0x10, 0x00, 0x00, 
  0x03, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xce, 0xa8, 0x1d, 0xf8, 0x0f, 0xe7, 0xe0, 0x20, 0x00, 0x00, 
  0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x1e, 0x00, 0x1f, 0xf8, 0x00, 0x40, 0x00, 0x00, 
  0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x88, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00
};




void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50); 
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();
  
  
}

String message;
void loop() {
  //check if new data is available to be read
  if(Serial.available()){
    message = Serial.readString();
  }
  //FRAME 1
  display.clearDisplay();
  display.drawBitmap(0, 0, frame1, 128, 32, SSD1306_WHITE);
  draw_message(message);
  display.display();
  delay(50);
  //FRAME 2
  display.clearDisplay();
  display.drawBitmap(0, 0, frame2, 128, 32, SSD1306_WHITE);
  draw_message(message);
  display.display();
  delay(50);
  //FRAME 3
  display.clearDisplay();
  display.drawBitmap(0, 0, frame3, 128, 32, SSD1306_WHITE);
  draw_message(message);
  display.display();
  delay(50);

}

//Function to draw a string on the display at the x,y coordinates
void drawchar(char * value,int x,int y) {
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(x, y);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.write(value);
}

//Function to decode incoming message with stats
//Message template: "fan1:fan2:fan3:cputemp:gputemp:cpuload:cpupower:cpufan"
void draw_message(String message){
  int message_type = 0;
  int x=0,y=0;
  char value[5];

  
  for(int i = 0; i < MAX_MESSAGE_LENGTH;i++){
    char letter[2];
    letter[0] = message[i];
    letter[1] = '\0';
    
    if(message[i] == '\n'){
      drawchar(value,x,y);
      break;
    }
    if(message[i] == ':'){
      drawchar(value,x,y);
      message_type++;
      value[0] = '\0';
    }else if(message_type == 0){//fan1
      x = 21;
      y = 14;
      strcat(value, letter);
    }else if(message_type == 1){//fan2
      x = 21;
      y = 35;
      strcat(value, letter);
    }else if(message_type == 2){//fan3
      x = 21;
      y = 57;
      strcat(value, letter);
    }else if(message_type == 3){//cpu temp
      x = 75;
      y = 11;
      strcat(value, letter);
    }else if(message_type == 4){//gpu temp
      x = 111;
      y = 52;
      strcat(value, letter);
    }else if(message_type == 5){//cpu load
      x = 104;
      y = 18;
      strcat(value, letter);
    }else if(message_type == 6){//cpu power
      x = 75;
      y = 27;
      strcat(value, letter);
    }else if(message_type == 7){//cpu fan
      x = 94;
      y = 9;
      strcat(value, letter);
    }
    
  }
}
