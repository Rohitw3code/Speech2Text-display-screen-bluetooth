#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

const int bluetoothTxPin = 10;  // Connect the Bluetooth module's TX pin to this Arduino pin
const int bluetoothRxPin = 9;  // Connect the Bluetooth module's RX pin to this Arduino pin

SoftwareSerial bluetoothSerial(bluetoothTxPin, bluetoothRxPin);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  bluetoothSerial.begin(9600);  

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
//    lcd.setCursor(0, 0);
    lcd.print(voice);


}
