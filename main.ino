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


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);


int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;

int buttonIndex;

 
 //TEST CODE



//TEST CODE REVERT IF FAILS
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
    
    int switchButtonCursor;
    switchScreenCursor = 0;

    if(button1state==LOW){
        switchButtonCursor=0;
    }

    switch(switchButtonCursor){//good
        int buttonIndex;

        if(button1state==LOW){ //good
            buttonIndex=0;
            switchScreenCursor++;
        }
        else if(button2state==LOW){
            buttonIndex=1;
            switchScreenCursor--;
        }
        else if(button3state==LOW){
            buttonIndex=2;
            //thing=networksArray[switchScreenCursor];
        }
        case 0:
          if(button1state==LOW){
            buttonIndex=0;
             switchScreenCursor++;
            }
            else if(button2state==LOW){
                buttonIndex=1;
              switchScreenCursor--;
            }
          else if(button3state==LOW){
              buttonIndex=2;
                //thing=networksArray[switchScreenCursor];
            }
         break;
              switch(buttonIndex){
            

            case 0:
                caseButton0();
                break;
            case 1:
                caseButton1();
               break;
            case 2:
                caseButton2();
              default:
                break;
        }
    }

    /*if(button1state == LOW){
        delay(1000);
        wifi_scan();
        delay(1000);

        if(button1state == LOW){
            networkIndex == 0;
            buttonCursor++; 
            if(buttonCursor>=networksArray.size())screenCursor=0;
        }
        else if(button2state == LOW){
            networkIndex == 1;
            buttonCursor--; if(screenCursor<0)buttonCursor=networksArray.size()-1;
            if(buttonCursor<0)screenCursor=networksArray.size()-1;
        }
         else if(button3state == LOW){
            networkIndex == 2;
            buttonCursor = screenCursor;
        }     
        switch (networkIndex){
            case 0: // BUTTON UP
                caseButton0();
                break;
            case 1: // BUTTON DOWN
                caseButton1();
                break;
            case 2: // BUTTON SELECT
                caseButton2();
                break;
            default:
                tft.fillScreen(ST7735_YELLOW);
                tft.setTextColor(ST7735_WHITE); 
                tft.println("Invalid network index.");
                Serial.println("na trigger yung default sa scan");
                delay(200);       
                break;     
                
          
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
    }*/
}
