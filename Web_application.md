# Web Application – Wheater Station IoT


**Project:** Wheater Station
**Repository:** https://github.com/aminmoubariki-alt/Wheater-teller

---

## 1. Introductie

Dit document beschrijft de huidige status van de webapplicatie binnen het Wheater Station IoT-project.
De webapplicatie is bedoeld als centrale toegang tot sensordata die wordt verzameld door een embedded device (WeMOS D1).

Op dit moment ligt de focus van het project op het embedded device en de systeemarchitectuur. De webapplicatie bevindt zich nog in een vroege fase en bestaat voornamelijk uit **ontwerpkeuzes en voorbereidende documentatie**. Verdere implementatie (front-end, REST API en database) volgt in een latere iteratie.

---

## 2. Rol van de Web Application binnen het systeem

Binnen de totale systeemarchitectuur vervult de webapplicatie de volgende rollen:

- Ontvangen van sensordata via een API
- Opslaan van data in een database
- Beschikbaar stellen van data aan een front-end voor visualisatie

De webapplicatie fungeert als **enige toegangspunt tot de data**. Het embedded device communiceert niet rechtstreeks met de database.

---

## 3. Architectuurkeuzes (huidige stand)

### 3.1 Gelaagde opzet
De webapplicatie is conceptueel opgebouwd uit drie lagen:

1. **Back-end (REST API)**
Verantwoordelijk voor validatie, verwerking en opslag van data.

2. **Database**
Persistente opslag van sensormetingen met tijdstempels.

3. **Front-end (SPA)**
Visualisatie van actuele en historische meetwaarden.

Deze scheiding zorgt voor duidelijke verantwoordelijkheden en maakt het systeem uitbreidbaar.

### 3.2 Communicatie
- Embedded device → API: HTTP (JSON)
- Front-end → API: HTTP (JSON)
- API → Database: SQL

---

## 4. Technische documentatie

### 4.1 Gebruikte technologieën (voorlopig)

De volgende technologieën zijn gekozen of voorbereid:

- **HTTP + JSON**
Voor eenvoudige en platformonafhankelijke communicatie.
- **REST-architectuur**
Duidelijke endpoints, schaalbaar en goed testbaar.
- **Relationele database (MySQL)**
Geschikt voor gestructureerde tijdsgebonden data en eenvoudig te modelleren in MySQL Workbench.

Concrete implementaties van back-end en front-end zijn op dit moment nog niet aanwezig in de repository.

### 4.2 Ontwerpkeuzes

- Sensorwaarden worden altijd opgeslagen met een timestamp om historische analyse mogelijk te maken.
- De database wordt zo ontworpen dat nieuwe sensortypes toegevoegd kunnen worden zonder het schema aan te passen.
- De API wordt het enige toegangspunt tot de data (geen directe database-toegang).

### 4.3 Bekende beperkingen

- Er is nog geen geïmplementeerde REST API.
- Er is nog geen front-end applicatie beschikbaar.
- Er is nog geen database-schema of ERD toegevoegd.

Deze onderdelen vallen buiten de huidige scope en worden later uitgewerkt.

---

## 5. API Reference (conceptueel)

De API is nog niet geïmplementeerd. Onderstaande beschrijving geeft het **bedoelde ontwerp** weer.

### POST `/measurements`
Ontvangt sensordata van het embedded device.

**Voorbeeld payload:**
```json
{
"device_id": "wemos-d1-01",
"timestamp": "2025-12-19T21:30:00Z",
"values": [
{ "type": "temperature", "value": 21.4 },
{ "type": "humidity", "value": 48 }
]
}
