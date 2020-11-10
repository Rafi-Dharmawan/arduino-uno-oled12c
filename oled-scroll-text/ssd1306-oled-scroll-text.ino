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

  // check if oled dont allocated well
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("oled dont allocated well"));
    for(;;); // to stop the program if meet this condition
  }
  display.clearDisplay();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  scrollHello();
  scrollWorld();
}

void scrollHello(){
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(50,10);
  display.print("Hello,");
  display.display();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(8500);
//  display.stopscroll();
}

void scrollWorld(){
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,40);
  display.print("World.");
  display.display();

  // make scroll text
  display.startscrollright(0x00, 0x0F);
  delay(8500);
}
