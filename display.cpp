#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   15  // D8
#define TFT_RST  2   // D4
#define TFT_DC   0   // D3
#define TFT_MOSI 13  // D7 (SPI MOSI)
#define TFT_SCK  14  // D5 (SPI SCK)

const int button1 = 5;
const int button2 = 4;
const int button3 = 12;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;
void setup {
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    
}