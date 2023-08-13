#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int bluetoothTxPin = 10;  // Connect the Bluetooth module's TX pin to this Arduino pin
const int bluetoothRxPin = 9;  // Connect the Bluetooth module's RX pin to this Arduino pin

SoftwareSerial bluetoothSerial(bluetoothTxPin, bluetoothRxPin);


void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);  
//  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  String voice;
  char c;

  if(voice.length() > 16 ){
    voice = "";
  }

  if (bluetoothSerial.available()) {
    char c = bluetoothSerial.read();
    voice += c;
  }
  
  Serial.print(voice);  // Print received characters to the Serial Monitor (optional)

  //Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(voice);
  display.display(); 
  
}
