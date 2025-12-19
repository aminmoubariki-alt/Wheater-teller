### SAD#06 — Embedded system (subsystem)

**Doel**  
Meten en tonen van waarden en het doorsturen van meetgegevens via WiFi.

**Componenten**
- **[HW] WeMOS D1 (ESP8266)**  
  Microcontroller met ingebouwde WiFi-functionaliteit.
- **(SW) C/C++ firmware**  
  De hoofdapplicatie die draait op de WeMOS.
- **(SW) Arduino libraries**  
  Gebruikte libraries zijn onder andere:
  - `ESP8266WiFi`
  - `HTTPClient`
  - `ArduinoJson`
  - `DHTesp`
- **[HW] Sensoren**  
  - DHT11 sensor voor temperatuur- en luchtvochtigheidsmetingen.
- **[HW] LCD 16x2 + I2C backpack**  
  Display voor het tonen van meetwaarden.
- **[HW] Arduino UNO R3**  
  Niet gebruikt in dit project en daarom geen onderdeel van de werkende opstelling.

**Communicatie**
- **I2C** tussen de WeMOS en het LCD-scherm.
- **WiFi** voor communicatie met het netwerk en de webserver.

---

### SAD#07 — Webserver (subsystem)

**Doel**  
Ontvangen en afhandelen van HTTP-verzoeken en het uitvoeren van PHP-code.

**Componenten**
- **(SW) Nginx**  
  Webserver die luistert op **HTTP poort 80**.
- **(SW) PHP-FPM 8.1**  
  Verwerkt PHP-code en is gekoppeld aan Nginx via **FastCGI poort 9000** (intern).

**Bijzonderheden**
- phpMyAdmin is bereikbaar via de Nginx reverse proxy op:  
  `http://localhost/phpmyadmin/`

---

### SAD#07A — Frontend (subsystem)

**Doel**  
Het aanbieden van een gebruikersinterface in de webbrowser.

**Componenten**
- **(SW) HTML-bestanden**
- **(SW) CSS-bestanden**
- **(SW) JavaScript-bestanden**
- **(SW) Frontend PHP-bestanden**  
  PHP-bestanden die HTML-pagina’s renderen.
- **(SW) Frontend libraries**  
  Indien gebruikt; niet projectspecifiek vastgelegd.

**Communicatie**
- Webbrowser → Nginx via **HTTP poort 80**.

---

### SAD#07B — Backend (subsystem)

**Doel**  
Server-side verwerking van meetgegevens en communicatie met de database.

**Componenten**
- **(SW) API PHP-bestanden**  
  Onder andere `database.php`, dat meetgegevens ontvangt.
- **(SW) Backend libraries**  
  De `mysqli` extensie voor communicatie met MariaDB.

**Communicatie**
- **WeMOS → Nginx** via **HTTP poort 80** (GET-requests met queryparameters).
- **Backend → MariaDB** via **MySQL protocol poort 3306**.

**Toelichting**
De exacte `INSERT`-implementatie is niet opgenomen omdat de PHP-file met database-logica niet teruggevonden kon worden. Uit de WeMOS-code blijkt wel dat `database.php` wordt aangeroepen voor het opslaan van meetgegevens.

---

### SAD#08 — Database system (subsystem)

**Doel**  
Persistente opslag van meetgegevens.

**Componenten**
- **(SW) MariaDB**  
  Databaseserver die luistert op **TCP poort 3306**.
- **[[DATA]] Database**  
  Logische database (schema).
- **[[DATA]] Database instance**  
  Tabellen en records met meetdata.

**Beheertool**
- **(SW) phpMyAdmin**  
  Wordt gebruikt voor inspectie en beheer van de database.

---

### SAD#09 — Docker registry (external system)

**Doel**  
Aanbieden van Docker images die door het systeem worden gebruikt.

**Componenten**
- **{EXT} Docker registry**  
  Bijvoorbeeld Docker Hub.
- **[[DATA]] Docker images**  
  Onder andere:
  - `nginx:latest`
  - `mariadb:latest`
  - `phpmyadmin/phpmyadmin:latest`

---

### SAD#10 — Docker host (subsystem)

**Doel**  
Het draaien van containers en het faciliteren van onderlinge communicatie.

**Componenten**
- **[HW] Docker network (virtueel)**  
  Virtueel netwerk voor containercommunicatie.
- **[HW] Docker containers (virtueel)**  
  - nginx  
  - php-fpm  
  - mariadb  
  - phpMyAdmin  
  - localhost-run  

**Belangrijke poorten**
- Host → Nginx: **80:80**
- Host → MariaDB: **3306:3306** (lokaal, voornamelijk voor development)

---

### SAD#11 — Host System (subsystem)

**Doel**  
Fysieke machine waarop Docker draait.

**Componenten**
- **[HW] Windows laptop**
- **(SW) Windows OS**
- **(SW) Docker (native)**

---

### SAD#12 — Mobile Device (external system)

**Doel**  
Client voor het bekijken van de webinterface.

**Componenten**
- **{EXT} [HW] Smartphone**
- **{EXT} (SW) Android of iOS**
- **{EXT} (SW) Webbrowser**

---

### SAD#13 — Network Access Point (external system)

**Doel**  
Verzorgen van WiFi-connectiviteit voor het embedded device.

**Component**
- **{EXT} [HW] WiFi access point**  
  SSID: `iotroam`

---

### SAD#14 — Git repository (external system)

**Doel**  
Versiebeheer en opslag van de projectbroncode.

**Component**
- **{EXT} (SW) Git repository**  
  Bijvoorbeeld GitHub of GitLab.

---

### SAD#15 — Internet / Intranet (abstraction)

**Doel**  
Abstractie voor externe netwerkcommunicatie.

**Voorbeelden**
- WeMOS → externe weather API via **HTTP**.
- WeMOS → publiek tunnel-adres (`*.lhr.life`) richting het lokale systeem.

---

### SAD#16 — SSH-tunnel (subsystem)

**Status**  
Niet gebruikt.

Publieke toegang tot de lokale webomgeving verloopt via de `localhost-run` / `lhr.life` tunnelservice (HTTP). Er wordt geen SSH-tunnel toegepast.

---

### Conclusie

De systeemarchitectuur beschrijft de volledige keten van **sensor → embedded device → netwerk → webserver/backend → database**. Alle componenten zijn logisch gegroepeerd in subsystemen, hiërarchisch genest en gekoppeld via duidelijk gedefinieerde protocollen en poorten.