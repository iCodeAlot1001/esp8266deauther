#include <ESP8266WiFi.h>
#include <Adafruit_ST7735.h>
#include <vector>
#include "wifi_scan.h" 

extern Adafruit_ST7735 tft;

//ALREADY WORKING
//DO NOT TOUCH UNLESS THERES AN OPTIMIZATION OR UPGRADE

void wifi_scan(){
    tft.fillScreen(ST7735_RED);
    tft.setTextColor(ST7735_YELLOW);
    tft.setTextSize(1);
    tft.setCursor(0,0);
    
    Serial.begin(115200);
    delay(1000);
    tft.println("Starting the scan...");

    WiFi.mode(WIFI_STA);

    WiFi.disconnect();
    delay(200);

   std::vector<String> networksArray; //storage for networks


    int networkCount = WiFi.scanNetworks();

    if(networkCount == 0){
        tft.println("No networks detected..");
    }
    else{
        tft.println("Network found ");
        tft.print(networkCount);
        tft.println(" ");
        
        for (int i=0;i<networkCount;i++){
            tft.print(i+1);
            tft.print(":");
            tft.print(WiFi.SSID(i));

            String getVal = WiFi.SSID(i);
            networksArray.push_back(getVal);
            Serial.println(networksArray[i]);

            if(WiFi.encryptionType(i)== ENC_TYPE_NONE){
                tft.println("(Open)");
            }
            else{tft.println("(Encrypted)");}
        }
    }
}
void wifi_scan_repeat(){
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_YELLOW);
    tft.setTextSize(1);
    tft.setCursor(0,0);
    
    delay(5000);
    tft.println("\nRescanning..");
    int networkCount=WiFi.scanNetworks();

    if(networkCount>0){
        for(int i=0;i<networkCount;i++){
            tft.print(i+1);
            tft.print(":");
            tft.print(WiFi.SSID(i));
        }
    }
}