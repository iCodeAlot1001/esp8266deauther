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

// switch case settings .........

//int buttonState = LOW;
//enum Buttons { btn1, btn2, btn3 };




// ...........

int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;

int screenCursor = -1; // screen size ata parang ganon
int buttonCursor = 0; // eto yung navigator
int networkIndex = 0; // eto yung pinaka gumagalaw sa buttons
 
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

    if(button1state == LOW){
        btn1();
        delay(1000);
        wifi_scan();
        delay(1000);

        if(digitalRead(button1) == LOW){
            buttonCursor++; 
            if(buttonCursor>=networksArray.size())screenCursor=0;
        }
        else if(digitalRead(button2) == LOW){
            buttonCursor--; if(screenCursor<0)buttonCursor=networksArray.size()-1;
            if(buttonCursor<0)screenCursor=networksArray.size()-1;
        }
         else if(digitalRead(button3) == LOW){
            networkIndex = screenCursor;
        }     
        switch (networkIndex){
            case 0: // BUTTON UP
                tft.fillScreen(ST7735_BLACK);
                tft.setTextColor(ST7735_YELLOW, ST7735_WHITE);
                tft.setTextSize(1);
                tft.setCursor(0,0);
                for(int q=0;q<networksArray.size();){
                    if (screenCursor == buttonCursor){ //test line
                        tft.print(networksArray[buttonCursor]); //test line
                    }
                    tft.println(networksArray[q]);
                    q++;
                }
                break;
            case 1: // BUTTON DOWN
                tft.fillScreen(ST7735_BLACK);
                tft.setTextColor(ST7735_YELLOW, ST7735_WHITE);
                tft.setTextSize(1);
                tft.setCursor(0,0);
                tft.println(networksArray[buttonCursor]);
                for(int q=0;q<networksArray.size();){
                    if (screenCursor == buttonCursor){ //test line
                        tft.print(networksArray[buttonCursor]); //test line
                    }
                    tft.println(networksArray[q]);
                    q++;
                }
                break;
            case 2: // BUTTON SELECT
                if(buttonCursor == networkIndex){
                    tft.fillScreen(ST7735_RED);
                    tft.setTextColor(ST7735_WHITE);
                    tft.setTextSize(1);
                    tft.setCursor(0,0);
                    tft.println("GUMAGANA BAIIIIII");
                    Serial.println("gumagana nga baiiii");
                    }
                break;  
            default:
                tft.fillScreen(ST7735_YELLOW);
                tft.setTextColor(ST7735_WHITE); 
                tft.println("Invalid network index.");
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
    }
}

