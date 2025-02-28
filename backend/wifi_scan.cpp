#include <ESP8266WiFi.h>
#include <Adafruit_ST7735.h>

extern Adafruit_ST7735 tft;

void setup(){
    Serial.begin(115200);
    delay(1000);
    Serial.println("Starting");

    WiFi.mode(WIFI_STA);

    Wifi.disconnect();
    delay(200);

    int networkCount = WiFi.scanNetworks();

    if(networkCount == 0){
        Serial.println("No networks detected..");
    }
    else{
        Serial.println("Network found ");
        Serial.print(networkCount);
        Serial.println(" ");
        
        for (int i=0;i<networkCount;i++){
            Serial.print(i+1);
            Serial.print(":");
            Serial.print(WiFi.SSID(i));
            if(WiFi.encryptionType(i)== END_TYPE_NONE){
                Serial.println("(Open)");
            }
            else{Serial.println("(Encrypted)");}
        }
    }
}
void loop(){
    delay(5000);
    Serial.println("\nRescanning..");
    int networkCount=WiFi.scanNetworks();

    if(networkCount>0){
        for(int i=0;i<networkCount;i++){
            Serial.print(i+1);
            Serial.print(":");
            Serial.print(WiFi.SSID(i));
        }
    }
}
//nakakatamad mag integrate