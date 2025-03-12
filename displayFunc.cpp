#include "displayFunc.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "wifi_scan.h"

extern std::vector<String> networksArray;
extern Adafruit_ST7735 tft;

int screenCursor = -1; // screen size ata parang ganon.. starting point ng navigator
int buttonCursor = 0; // eto yung navigator
int networkIndex; // eto yung pinaka gumagalaw sa buttons


void caseButton0(){
tft.fillScreen(ST7735_BLACK);
tft.setTextColor(ST7735_YELLOW, ST7735_WHITE);
tft.setTextSize(1);
tft.setCursor(0,0);
for(int q=0;q<networksArray.size();){
    if (screenCursor == buttonCursor){ 
        tft.setTextColor(ST7735_RED, ST7735_WHITE);//test line
        tft.println(networksArray[buttonCursor]); //test line
    }
    
    tft.println(networksArray[q]);
    q++;
}
Serial.println("button1 scan is working");
delay(200);

}
void caseButton1(){
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_YELLOW, ST7735_WHITE);
    tft.setTextSize(1);
    tft.setCursor(0,0);
    tft.println(networksArray[buttonCursor]);
    for(int q=0;q<networksArray.size();){
        tft.print(networksArray[buttonCursor]); //test line
        if (screenCursor == buttonCursor){
          tft.setTextColor(ST7735_RED, ST7735_WHITE);
          tft.println(networksArray[buttonCursor]); //test line
        }
        tft.println(networksArray[q]);
        q++;
    }
    Serial.println("button2 scan is working");
    delay(200);
}

void caseButton2(){
    if(buttonCursor == networkIndex){
        tft.fillScreen(ST7735_RED);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(1);
        tft.setCursor(0,0);
        tft.println("GUMAGANA BAIIIIII");
        Serial.println("gumagana scan nga baiiii");
        }
    delay(200);
}


void blank(){
  tft.fillScreen(ST7735_GREEN);
}
void btn2(){
  tft.fillScreen(ST7735_RED);
}
void btn3(){
  tft.fillScreen(ST7735_BLUE);
}