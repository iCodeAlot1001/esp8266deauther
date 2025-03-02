#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include "displayFunc.h"
#include "wifi_scan.h"

#define TFT_CS   15  //D8
#define TFT_RST  2   //D4
#define TFT_DC   0   //D3
#define TFT_MOSI 13  //D7
#define TFT_SCK  14  //D5 

const int button1 = 5;
const int button2 = 4;
const int button3 = 12;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;

void setup(){
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);

    Serial.begin(115200);
    Serial.println("STARTING...");

        tft.initR(INITR_BLACKTAB);
        tft.setRotation(0);
        tft.fillScreen(ST7735_BLACK);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(1);
        tft.setCursor(0,0);
        tft.println("SELECT AN ATTACK:");
        tft.println("btn1 = WIFI JAMMER");
        tft.println("btn2 = BLUETOOTH JAMMER");
        tft.println("btn3 = RGB SCREEN");
        delay(2000);
}
void loop(){
    button1state = digitalRead(button1);
    button2state = digitalRead(button2);
    button3state = digitalRead(button3);

    if(button1state == LOW){
        btn1();
        delay(1000);
        wifi_scan();
        delay(2000);
        wifi_scan_repeat();
        delay(1000);
    }
    else if(button2state == LOW){
        btn2();
    }
    else if(button3state == LOW){
        btn3();
    }
    else{
        blank();
    }
}

