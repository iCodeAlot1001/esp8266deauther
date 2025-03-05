#include "wifi_scan.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>


enum 



void wifi_attack(){
    if (networksArray.empty()) {
        tft.println("No networks available for attack.");
        return;
    }
    tft.fillScreen(ST7735_BLACK);
    int networkIndex = 0; // Example index, you can change this based on your logic

    switch (networkIndex) {
        case 0:
            
            tft.println("Attacking network 1:");
            tft.println(networksArray[0]);
            // Add your attack logic here
            break;
        case 1:
            tft.println("Attacking network 2:");
            tft.println(networksArray[1]);
            break;
        default:
            tft.println("Invalid network index.");
            break;


}