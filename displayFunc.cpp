#include "displayFunc.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "wifi_scan.h"

extern Adafruit_ST7735 tft;
void btn1(){ //wifi jammer
    tft.setTextColor(ST7735_RED, ST7735_WHITE);
    tft.println("pressed wifi jammer");
    delay(2000);
    
    wifi_scan();
    
}   
void btn2(){
    tft.setTextColor(ST7735_RED, ST7735_WHITE);
    tft.println("pressed bluetooth jammer");
    delay(2000);
}
void btn3(){
    tft.setTextColor(ST7735_RED, ST7735_WHITE);
    tft.println("PRESSED rgb color");
    delay(2000);

}
void blank(){

    tft.setTextColor(ST7735_BLACK);
    tft.setTextSize(1);
    tft.println("DI GUMAGANA");
    delay(500);
}
//after the starting
