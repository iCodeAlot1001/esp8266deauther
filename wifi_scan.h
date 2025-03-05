#ifndef WIFI_SCAN_H
#define WIFI_SCAN_H

extern Adafruit_ST7735 tft;
std::vector<String> networksArray;

void wifi_scan();
void wifi_scan_repeat();
#endif