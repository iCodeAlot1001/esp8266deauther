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

const char button1 = 5; //D2
const char button2 = 4; //D1
const char button3 = 12; //D6 

const screenCursor = 0;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

// switch case settings .........

//int buttonState = LOW;
//enum Buttons { btn1, btn2, btn3 };




// ...........

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
        tft.setRotation(2);
        tft.fillScreen(ST7735_BLACK);
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(1);
        tft.setCursor(0,0);
        tft.println("SELECT AN ATTACK:");
        tft.println("BTN1 = WIFI JAMMER");
        tft.println("BTN2 = BLUETOOTH JAMMER");
        tft.println("BTN3 = RGB SCREEN");
        delay(2000);
}
void loop(){
    button1state = digitalRead(button1);
    button2state = digitalRead(button2);
    button3state = digitalRead(button3);
    int buttonCursor = 0;

    if(button1state == LOW){
        btn1();
        delay(1000);
        wifi_scan();
        delay(1000);

        if(digitalRead(BUTTON_1_PIN) == HIGH){
            buttonCursor++; 
        } else if(digitalRead(BUTTON_2_PIN) == HIGH){
            buttonCursor;
            if (condition)
        
            }
            
        } else if(digitalRead(BUTTON_3_PIN) == HIGH){
            networkIndex = 2;
        }

        switch (networkIndex){
            case 0: // BUTTON UP
                tft.println(networksArray[buttonCursor]);
                break;
            case 1: // BUTTON DOWN
                tft.println(networksArray[buttonCursor]);
                break;
            case 2: // BUTTON SELECT
                tft.println("Attacking network:");
                tft.println(networksArray[0]);
                break;  
            default:
                tft.println("Invalid network index.");
                break;            
          }
        }
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

