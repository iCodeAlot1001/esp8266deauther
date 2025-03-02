#include "displayFunc.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "wifi_scan.h"

extern Adafruit_ST7735 tft;
void btn1(){ //wifi jammer
    tft.fillScreen(ST7735_BLACK);
    tft.setCursor(0,0);
    tft.setTextColor(ST7735_WHITE);
    tft.println("pressed wifi jammer");
    delay(2000);
    
    wifi_scan();
    
}   
void btn2(){
    tft.fillScreen(ST7735_BLACK);
    tft.setCursor(0,0);
    tft.setTextColor(ST7735_WHITE);
    tft.println("pressed bluetooth jammer");
    delay(2000);
}
void btn3(){
    tft.fillScreen(ST7735_BLACK);
    tft.setCursor(0,0);
    tft.setTextColor(ST7735_WHITE);
    tft.println("PRESSED rgb color");
    delay(2000);

}
void blank(){
    tft.fillScreen(ST7735_YELLOW);
    tft.setCursor(0,0);
    tft.setTextColor(ST7735_BLACK);
    tft.setTextSize(1);
    tft.println("DI GUMAGANA");
    delay(2000);
}
//after the starting
