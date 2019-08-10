#include <M5Stack.h>
#include <WiFi.h>
#include "Ambient.h" 

Ambient ambient; 
unsigned int channelId = 13222; 
const char* writeKey = "*********"; 

WiFiClient client;
const char* ssid  = "*********";
const char* pwd   = "*********";

const int PIN_MODE = 22;

void setup() {
  M5.begin();
  Serial.begin(115200);

  // wifi接続
  M5.Lcd.println(ssid);   
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    M5.Lcd.print(".");
    delay(1500);
  } 
  M5.Lcd.println("connected");

  // ambient
  ambient.begin(channelId, writeKey, &client);

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
    ambient.set(1, 1);
  }
  else{
    M5.Lcd.setCursor(95, 25);M5.Lcd.print("Not Sensed");
    M5.Lcd.setCursor(95, 45);M5.Lcd.print("0");
    Serial.println("PIR Status: Not Sensed");
    Serial.println(" value: 0");
    ambient.set(1, 0);
  }
  ambient.send();
  delay(100);
}
