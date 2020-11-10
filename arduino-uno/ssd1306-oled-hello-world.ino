#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LEBAR_LAYAR 128 // OLED display width, in pixels
#define TINGGI_LAYAR 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(LEBAR_LAYAR,TINGGI_LAYAR, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // check oled have alocated well or not
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
  Serial.println(F("SSD1306 allocation failed"));
  for(;;); // in case ssd1306 allocation failed it will stuck ini here
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30,10);
  display.print("Hello,");
  display.setCursor(40,30);
  display.print("World");
  display.display();
  
}

void loop() {
  

}
