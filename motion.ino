#include <M5Stack.h>
#include <WiFi.h>

const int PIN_MODE = 22;

void setup() {
  M5.begin();
  Serial.begin(115200);
  // LCDの初期設定
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(80, 0); 
  M5.Lcd.println("PIR example");
  Serial.println("PIR example: ");
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.setTextColor(WHITE);
  pinMode(PIN_MODE, INPUT);
}

void loop() {
  M5.Lcd.setCursor(0,25); M5.Lcd.print("Status: ");
  M5.Lcd.setCursor(0,45); M5.Lcd.print("Value: ");
  
  M5.Lcd.fillRect(95,25,200,25,BLACK);
  M5.Lcd.fillRect(95,45,200,25,BLACK);
  
  if(digitalRead(PIN_MODE)==1){
    M5.Lcd.setCursor(95, 25);M5.Lcd.print("Sensing");
    M5.Lcd.setCursor(95, 45);M5.Lcd.print("1");
    Serial.println("PIR Status: Sensing");
    Serial.println(" value: 1");
  }
  else{
    M5.Lcd.setCursor(95, 25);M5.Lcd.print("Not Sensed");
    M5.Lcd.setCursor(95, 45);M5.Lcd.print("0");
    Serial.println("PIR Status: Not Sensed");
    Serial.println(" value: 0");
  }
  delay(100);
}
