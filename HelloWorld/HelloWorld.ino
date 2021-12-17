#include"TFT_eSPI.h"

TFT_eSPI tft;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(4);
  tft.drawString("Hello world!", 20, 100);

}

void loop() {

}
