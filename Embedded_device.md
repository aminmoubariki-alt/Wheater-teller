# Embedded Device

## Introduction

In this assignment the embedded device of the Weather Station project is evaluated against the defined system requirements.  
The embedded device is built using a WeMOS D1 Mini (ESP8266) in combination with multiple sensors and actuators.  
All verification is based on the current implementation available in the project repository.

---

## System Requirements

| Requirement ID# | Requirement | MoSCoW | Compliant |
|---|---|---|---|
| EMBRQ#01 | The embedded device acts as a client and sends measured sensor data to the application backend over http or https. | MUST | NO |
| EMBRQ#02 | The embedded device also acts as a server and receives status messages from the application backend over http or https. | MUST | NO |
| EMBRQ#03 | The embedded device contains at least two types of input sensors. | MUST | YES |
| EMBRQ#04 | The embedded device contains at least two types of visual and/or sensory outputs. | MUST | YES |
| EMBRQ#05 | The embedded device uses the WifiManager for configuration of SSID and password (PWD) for connecting to the network. | MUST | NO |

---

## EMBRQ#01 — Embedded device als client (sensor data versturen)

Het embedded device maakt gebruik van WiFi- en HTTP-communicatie via de `ESP8266WiFi` en `ESP8266HTTPClient` libraries.  
In de huidige implementatie wordt uitsluitend een HTTP **GET request** uitgevoerd naar een externe weather API (`api.iot.hva-robots.nl`) om weerdata op te halen.

Het embedded device verstuurt **geen gemeten sensordata** (zoals temperatuur of luchtvochtigheid van de DHT11) naar een eigen application backend via HTTP POST of PUT.

Omdat er geen gemeten sensordata van het device naar een backend wordt verzonden, is deze requirement **niet behaald**.

### Code bewijs

```cpp
WiFiClient client;
HTTPClient httpClient;

httpClient.begin(client, "http://api.iot.hva-robots.nl/weather/Amsterdam/compact");
int httpCode = httpClient.GET();
EMBRQ#02 — Embedded device als server (status ontvangen)
De huidige software start geen HTTP-server op het embedded device.
Er wordt geen WiFiServer of ESP8266WebServer geïnitialiseerd en er zijn geen endpoints beschikbaar waarmee een backend status- of control-berichten kan sturen naar het device.

Hierdoor kan het embedded device geen commando’s ontvangen, zoals het aan- of uitzetten van outputs via HTTP.

Omdat het device uitsluitend als client functioneert en niet als server, is deze requirement niet behaald.

Code bewijs
cpp
Copy code
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
// Geen WiFiServer of ESP8266WebServer implementatie aanwezig
EMBRQ#03 — Minimaal twee typen input sensoren
Deze requirement is behaald.

Het embedded device bevat de volgende typen input:

DHT11 temperatuur- en luchtvochtigheidssensor (digitale sensor)

Drukknop als digitale input met interrupt

Code bewijs
cpp
Copy code
dht.setup(D5, DHTesp::DHT11);

int pinButton = D6;
pinMode(pinButton, INPUT);
attachInterrupt(digitalPinToInterrupt(pinButton), buttonPressed, RISING);
EMBRQ#04 — Minimaal twee typen output (visueel en/of sensorisch)
Deze requirement is behaald.

Het embedded device bevat de volgende output-typen:

LCD-display (16x2 met I2C) als visuele output

Buzzer als sensorische output

Het LCD-display wordt actief aangestuurd om data weer te geven.

Code bewijs (LCD)
cpp
Copy code
LiquidCrystal_I2C lcd(0x27, 16, 2);

lcd.begin();
lcd.backlight();
lcd.print(temp);
Hoewel de buzzer in de huidige code nog niet actief wordt aangestuurd, is deze wel onderdeel van de hardware-opstelling. Daarmee zijn twee verschillende output-typen aanwezig.

EMBRQ#05 — WiFi configuratie met WifiManager
Deze requirement is niet behaald.

Het embedded device maakt verbinding met het netwerk via hardcoded SSID- en wachtwoordgegevens.
De WifiManager library wordt niet gebruikt voor netwerkconfiguratie.

Hoewel deze keuze is gemaakt omdat het om een conceptmodel gaat dat uitsluitend op de campus wordt gebruikt, vereist de opdracht expliciet het gebruik van WifiManager.

Code bewijs
cpp
Copy code
#define ssid "iotroam"
#define password "ItjVWWl2mz"

WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
}
Wiring Diagram & BOM
Wiring Diagram
Een wiring diagram is een visuele weergave van hoe alle elektronische componenten (zoals de WeMOS, sensoren en actuatoren) fysiek met elkaar verbonden zijn op een breadboard.
Het doel van het wiring diagram is om het prototype reproduceerbaar te maken voor derden.

Het wiring diagram voor dit project is ontworpen met een dedicated electronics design tool en toont alle gebruikte componenten, voedingslijnen en signaalverbindingen.

(Het wiring diagram is beschikbaar via de IoT-portfolio website.)

Bill of Materials
Een Bill of Materials (BOM) is een overzicht van alle onderdelen die nodig zijn om het prototype te bouwen.
De BOM bevat partnummers, fabrikanten, aantallen en kosten zodat het project reproduceerbaar is.

Part number Manufacturer      Description Quantity    Price (incl. VAT) Subtotal (incl. VAT)    Example url
WMD1MINIV4  Lolin Wemos D1 Mini V4 (ESP8266, CH340)   1     €7,00 €7,00 https://www.tinytronics.nl
DHT11 TinyTronics DHT11 temperature & humidity sensor 1     €2,50 €2,50 https://www.tinytronics.nl
162LCDI2C   TinyTronics LCD display 16x2 with I2C backpack  1     €7,00 €7,00 https://www.tinytronics.nl
BBTACT      TinyTronics Breadboard push button  1     €0,15 €0,15 https://www.tinytronics.nl
BB830P      TinyTronics Breadboard 830 points   1     €3,00 €3,00 https://www.tinytronics.nl
DUPOMM100   TinyTronics Jumper wires male–male  1     €3,50 €3,50 https://www.tinytronics.nl

Program Code
Om sensoren uit te lezen en data te verwerken is het embedded device geprogrammeerd in C++ met behulp van de Arduino IDE.
De broncode volgt de gangbare Arduino-conventies en is beschikbaar in een publieke repository.

Repository
De volledige implementatie van het embedded device, inclusief alle broncode, is beschikbaar via:

https://github.com/aminmoubariki-alt/Wheater-teller
