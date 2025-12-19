# System Architecture

## Introductie

In dit document beschrijf ik de systeemarchitectuur van mijn IoT-project. Het doel van deze architectuur is om in één overzicht te laten zien welke hardware- en softwarecomponenten worden gebruikt, hoe deze zijn gegroepeerd in subsystemen en via welke protocollen data door het systeem stroomt. Door deze structuur expliciet vast te leggen, wordt het systeem beter te begrijpen, eenvoudiger te onderhouden en makkelijker uit te breiden in een latere fase.

De oplossing bestaat uit een embedded device (WeMOS D1), een lokaal gehoste webomgeving (Docker op een Windows laptop), een database en meerdere externe systemen zoals het internet, een tunnelservice en een Git-repository.

---

## Legenda

- **[HW]** = Hardware component  
- **(SW)** = Software component  
- **[[DATA]]** = Data / opslag  
- **{EXT}** = Extern systeem  

Pijlen geven de **richting van de datastroom** aan.  
Elke pijl bevat:
- het gebruikte **protocol** (bijv. HTTP, I2C, MySQL)
- de **TCP/IP-poort** (indien van toepassing)

---

## System Architecture Diagram

```mermaid
flowchart TB

subgraph NET["SAD#15 {EXT} Internet / Intranet"]
  WEATHER_API["(SW) Externe Weather API\nHTTP :80\napi.iot.hva-robots.nl"]
  LHR_ADDR["(SW) Publiek tunnel-adres\n*.lhr.life"]
end

subgraph AP["SAD#13 {EXT} Network Access Point"]
  WIFI["[HW] WiFi Access Point (iotroam)"]
end

subgraph EMB["SAD#06 Embedded System"]
  WEMOS["[HW] WeMOS D1 (ESP8266)"]
  FW["(SW) C/C++ Firmware"]
  LIBS["(SW) Arduino Libraries\nESP8266WiFi, HTTPClient,\nArduinoJson, DHTesp"]
  DHT11["[HW] DHT11 Sensor"]
  LCD["[HW] LCD 16x2 + I2C Backpack"]

  WEMOS --> FW
  FW --> LIBS
  DHT11 -->|GPIO| WEMOS
  WEMOS -->|I2C| LCD
end

subgraph HOST["SAD#11 Host System"]
  OS["(SW) Windows OS"]

  subgraph DOCKER["SAD#10 Docker Host"]
    NETW["[HW] Docker Network (virtueel)"]

    subgraph WEB["SAD#07 Webserver"]
      NGINX["(SW) Nginx\nHTTP :80"]
      PHPFPM["(SW) PHP-FPM 8.1\nFastCGI :9000"]
    end

    subgraph FRONT["SAD#07A Frontend"]
      FE_FILES["(SW) HTML / CSS / JavaScript"]
      FE_PHP["(SW) Frontend PHP-bestanden"]
    end

    subgraph BACK["SAD#07B Backend"]
      API_PHP["(SW) API PHP-bestanden\n(database.php)"]
      BACK_LIBS["(SW) PHP libraries\n(mysqli)"]
    end

    subgraph DB["SAD#08 Database"]
      MARIADB["(SW) MariaDB\nTCP :3306"]
      DBINST["[[DATA]] Database instance"]
    end

    PMA["(SW) phpMyAdmin"]
    LHR["(SW) localhost-run service\nHTTP :8000"]

    NETW --- NGINX
    NETW --- PHPFPM
    NETW --- MARIADB
    NETW --- PMA
    NETW --- LHR

    NGINX -->|FastCGI :9000| PHPFPM
    PHPFPM --> FE_FILES
    PHPFPM --> FE_PHP
    PHPFPM --> API_PHP
    API_PHP -->|MySQL :3306| MARIADB
    MARIADB --> DBINST
    PMA -->|MySQL :3306| MARIADB
    NGINX -->|HTTP :80 /phpmyadmin| PMA
  end
end

subgraph CLIENT["SAD#12 {EXT} Mobiel apparaat"]
  PHONE["[HW] Smartphone"]
  OS_M["(SW) Android / iOS"]
  BROWSER["(SW) Webbrowser"]

  PHONE --> OS_M --> BROWSER
end

WEMOS -->|WiFi| WIFI
WIFI -->|HTTP :80 (GET)| WEATHER_API
WEMOS -->|HTTP :80 (GET sensor-data)| LHR_ADDR
LHR_ADDR -->|HTTP :80| NGINX
BROWSER -->|HTTP :80| NGINX