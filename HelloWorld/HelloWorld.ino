#include "TFT_eSPI.h"
#include "ADXL335.h"
#include "seeed_graphics_define.h"
#include "seeed_graphics_base.h"
#include "seeed_line_chart.h"

TFT_eSPI tft;
ADXL335 axl;

#define max_size 50

doubles accelerator_readings[3];
TFT_eSprite spr = TFT_eSprite(&tft);

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(4);
  tft.drawString("Hello world!", 20, 100);

  spr.createSprite(TFT_HEIGHT, TFT_WIDTH);

  axl.begin();
}

void loop() {
    spr.fillSprite(TFT_WHITE);
    float ax = axl.getAccelerationX();
    float ay = axl.getAccelerationY();
    float az = axl.getAccelerationZ();

    if (accelerator_readings[0].size() == max_size) {
        for (uint8_t i = 0; i<3; i++){
            accelerator_readings[i].pop();
        }
    }
    accelerator_readings[0].push(ax);
    accelerator_readings[1].push(ay);
    accelerator_readings[2].push(az);

    auto header = text(0, 0);
    header.value("Acceleration Readings");
    header.align(center);
    header.valign(vcenter);
    header.width(tft.width());
    header.thickness(2);
    header.height(header.font_height() * 2);
    header.draw();

    auto content = line_chart(20, header.height());
    content.height(tft.height() - header.height() * 1.5);
    content.width(tft.width() - content.x() * 2);
    content.based_on(-2.0);
    content.show_circle(false);
    content.value({accelerator_readings[0],accelerator_readings[1], accelerator_readings[2]});
    content.color(TFT_BLUE, TFT_RED, TFT_GREEN);
    content.draw();

    spr.pushSprite(0, 0);
    delay(50);
}
