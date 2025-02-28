#include "displayFunc.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
extern Adafruit_ST7735 tft;
void btn1(){ //wifi jammer
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE);
    tft.println("pressed wifi jammer");
    delay(2000);

}
void btn2(){
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE);
    tft.println("pressed bluetooth jammer");
    delay(2000);
}
void btn3(){
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE);
    tft.println("PRESSED rgb color");
    delay(2000);

}
