#include "DHTesp.h"
DHTesp dht;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define WEATHER_HOST "api.iot.hva-robots.nl"
#define LOCAL_HOST "SERVER HTTP"
#include <Arduino.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define ssid  "iotroam"
#define password "ItjVWWl2mz"

const apiUrl = "http://e12ab93365a8e7.lhr.life/"

void setup() {
  lcd.begin();
  dht.setup(D5, DHTesp::DHT11);

  Serial.begin(9600);
  WiFi.begin(ssid, password);

  // Keep in while-loop while the device is not connected to your accesspoint.
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); // Waiting on connection...
  }
}

void loop() {
  WiFiClient client;
  HTTPClient httpClient;

  httpClient.begin(client, "http://api.iot.hva-robots.nl/weather/Amsterdam/compact");
  int httpCode = httpClient.GET();

  if (httpCode == HTTP_CODE_OK) { // HTTP_CODE_OK == 200
    String payload = httpClient.getString();
    Serial.println(payload);


    StaticJsonDocument<1024> doc;

    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    if (!error) {
      bool success = doc["success"]; // true

      JsonObject data = doc["data"];
      Serial.println("The data has been recieved");
      Serial.println(success);
      showDataOnLCD(data);

    }  else {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

  } else {
    Serial.println("Unable to connect :(");
  }

  delay(1000);
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
  const String data_temp_C = data["temp_C"]; // "19"
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


  // read the input on analog pin D5:
  float h = dht.getHumidity();
  float t = dht.getTemperature();
  String tempin = "IN:" + String(t);
  String humditiyout = " humid:" + data_humidity;
  String tempout = "OUT:" + data_temp_C;
  String humditiyin = "IN:" + String(h);
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print(tempin);
  lcd.print(humditiyin);
  lcd.setCursor(0, 1);
  lcd.print(tempout);
  lcd.print((char)223);
  lcd.print(humditiyout);
  //api calls.
  httpClient.begin(client, apiUrl . "database.php?type=out&humidity=" . data_humidity . "&celcius=" . data_temp_C);
  httpClient.GET();
  httpClient.begin(client, apiUrl . "database.php?type=in&humidity=" . String(h) . "&celcius=" . String(t));
  int httpCode = httpClient.GET();
  
  delay(5000);
  lcd.clear(); // Clears the LCD screen
}
