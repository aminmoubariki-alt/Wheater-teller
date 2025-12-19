#include "DHTesp.h"
#include <LiquidCrystal_I2C.h>

#include <Arduino.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

DHTesp dht;
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define WEATHER_HOST "api.iot.hva-robots.nl"
#define LOCAL_HOST "SERVER HTTP"

#define BUTTON_PRESS_DEBOUNCE 100
#define ssid  "iotroam"
#define password "ItjVWWl2mz"

int pinButton = D6;
int screenIsOnn = true;
int lastButtonPress = 0;

void ICACHE_RAM_ATTR buttonPressed() {
  // check if the button was pressed twice in BUTTON_PRESS_DEBOUNCE ms.
  if (lastButtonPress > millis() + BUTTON_PRESS_DEBOUNCE) {
    return;
  }
  
  Serial.println("Button press detected");
  
  toggleScreen();
  lastButtonPress = millis();
}

void setup() {
  Serial.begin(9600);

  dht.setup(D5, DHTesp::DHT11);
  lcd.begin();
  lcd.backlight();

  pinMode(pinButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinButton), buttonPressed, RISING);

  WiFi.begin(ssid, password);

  // Keep in while-loop while the device is not connected to your accesspoint.
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); // Waiting on connection...
  }
}

void loop() {
  //    // read the input on analog pin 0:
  //  int sensorValue = analogRead(A0);
  //  lcd.print("De tempratuur is"); // Prints "Temprature" on the LCD
  //  delay(1000); // 5 seconds delay
  //  lcd.setCursor(1, 1); // Sets the location at which subsequent text written to the LCD will be displayed
  //  lcd.print(sensorValue);
  //  lcd.setCursor(3, 1);
  //  lcd.print(" Celsius");
  //  delay(3000);
  //  lcd.clear(); // Clears the display
  //  delay(500);
  //  lcd.noBlink(); // Turns off the blinking LCD cursor
  //  delay(500);
  //  lcd.noCursor(); // Hides the LCD cursor
  //  lcd.clear(); // Clears the LCD screen

  WiFiClient client;
  HTTPClient httpClient;

  httpClient.begin(client, "http://api.iot.hva-robots.nl/weather/Amsterdam/compact");
  int httpCode = httpClient.GET();

  if (httpCode == HTTP_CODE_OK) { // HTTP_CODE_OK == 200
    String payload = httpClient.getString();
    Serial.println(payload);
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (!error) {
      bool success = doc["success"]; // true

      JsonObject data = doc["data"];
      Serial.println("The data has been recieved");
      Serial.println(success);
      showDataOnLCD(data);
    } else {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
  } else {
    Serial.println("Unable to connect :(");
  }

  delay(5000);
}


void showDataOnLCD(JsonObject data) {

  const char* data_FeelsLikeC = data["FeelsLikeC"]; // "19"
  const char* data_FeelsLikeF = data["FeelsLikeF"]; // "66"
  const char* data_cloudcover = data["cloudcover"]; // "25"
  const String data_humidity = data["humidity"]; // "64"
  const char* data_localObsDateTime = data["localObsDateTime"]; // "2022-07-04 10:33 AM"
  const char* data_observation_time = data["observation_time"]; // "08:33 AM"
  const char* data_precipInches = data["precipInches"]; // "0.0"
  const char* data_precipMM = data["precipMM"]; // "0.0"
  const char* data_pressure = data["pressure"]; // "1020"
  const char* data_pressureInches = data["pressureInches"]; // "30"
  const char* data_temp_C = data["temp_C"]; // "19"
  const char* data_temp_F = data["temp_F"]; // "66"
  const char* data_uvIndex = data["uvIndex"]; // "4"
  const char* data_visibility = data["visibility"]; // "10"
  const char* data_visibilityMiles = data["visibilityMiles"]; // "6"
  const char* data_weatherCode = data["weatherCode"]; // "116"
  const char* data_weatherDesc_0_value = data["weatherDesc"][0]["value"]; // "Partly cloudy"
  const char* data_weatherIconUrl_0_value = data["weatherIconUrl"][0]["value"]; // nullptr

  const char* data_winddir16Point = data["winddir16Point"]; // "WSW"
  const char* data_winddirDegree = data["winddirDegree"]; // "250"
  const char* data_windspeedKmph = data["windspeedKmph"]; // "17"
  const char* data_windspeedMiles = data["windspeedMiles"]; // "11"


  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  String temp = "Temperatuur: " + String(sensorValue);
  String humditiy = "Humidity: " + data_humidity;
  lcd.clear(); // Clears the LCD screen
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print(humditiy);
}

void displayData(){
    // read the input on analog pin D5:
  float h = dht.getHumidity();
  float t = dht.getTemperature();
  lcd.print("Temprature:");
  lcd.print(t);
  lcd.print((char)223);// Prints "Temprature" on the LCD
  delay(1000); // 5 seconds delay
  lcd.setCursor(1, 1); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(1, 1);
  delay(3000);
  lcd.clear(); // Clears the display
  delay(500);
  lcd.noBlink(); // Turns off the blinking LCD cursor
  delay(500);
  lcd.noCursor(); // Hides the LCD cursor
  lcd.clear(); // Clears the LCD screen
}

void toggleScreen(){
  if (screenIsOnn)
    turnOffScreen();
  else
    turnOnScreen();

  screenIsOnn = !screenIsOnn;
}

void turnOnScreen() {
  lcd.backlight();
  lcd.display();
}

void turnOffScreen(){
  lcd.noBacklight();
  lcd.noDisplay();
}
