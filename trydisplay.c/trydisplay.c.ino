#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Pin definitions for ESP8266
#define TFT_CS   D8  // GPIO 15
#define TFT_RST  D4  // GPIO 2
#define TFT_DC   D3  // GPIO 0
#define TFT_MOSI D7  // GPIO 13 (SPI MOSI)
#define TFT_CLK  D5  // GPIO 14 (SPI SCK)

// Create display object (using hardware SPI)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  delay(100); // Brief pause to stabilize
  
  // Initialize the ST7735 display
  tft.initR(INITR_BLACKTAB); // Use INITR_BLACKTAB for 1.8" 128x160 displays
  // Alternatives: INITR_GREENTAB, INITR_REDTAB (check your display’s docs)
  tft.setRotation(1); // 0-3 for orientation (1 = landscape)
  tft.fillScreen(ST7735_BLACK); // Clear screen to black
  
  // Draw some test text
  tft.setCursor(5, 5);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);
  tft.println("ESP8266 ST7735");

  // Draw a red rectangle
  tft.drawRect(10, 30, 80, 40, ST7735_RED);
  
  // Draw a green filled circle
  tft.fillCircle(50, 100, 15, ST7735_GREEN);
}

void loop() {
  // Add dynamic updates here if desired
  delay(1000); // Just a placeholder
}