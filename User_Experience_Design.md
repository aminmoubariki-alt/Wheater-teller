# User Experience Design

## Introductie

In deze opdracht wordt het User Experience Design (UXD) van het Weather Station IoT-project uitgewerkt aan de hand van de beschikbare knowledgebase en beoordelingsrubrics.  
Het doel van deze sectie is om te beschrijven hoe gebruiksvriendelijkheid, duidelijkheid en interactie met de gebruiker zijn meegenomen in het ontwerp van het systeem.  
De focus ligt op de interactie tussen de gebruiker en het systeem, zowel op het embedded device als op de webinterface.

---

## Context en Doelgroep

Het Weather Station is ontworpen voor gebruikers die op een snelle en eenvoudige manier inzicht willen krijgen in weerinformatie, zonder technische complexiteit.  
De doelgroep bestaat uit studenten en niet-technische gebruikers die basisgegevens zoals temperatuur en luchtvochtigheid intuïtief willen kunnen aflezen.

Het systeem is bedoeld voor gebruik in een gecontroleerde omgeving (campus of thuis), waarbij betrouwbaarheid en eenvoud belangrijker zijn dan uitgebreide configuratiemogelijkheden.

---

## Gebruikersdoelen

De belangrijkste doelen van de gebruiker bij het gebruik van het systeem zijn:
- Snel actuele temperatuur- en luchtvochtigheidswaarden kunnen bekijken.
- De weergegeven informatie begrijpen zonder technische voorkennis.
- Met minimale fysieke interactie het systeem kunnen bedienen.
- Duidelijke feedback ontvangen bij interactie met het systeem.

---

## User Interface Ontwerp

### Embedded Device Interface

Het embedded device maakt gebruik van een 16x2 LCD-display als primaire gebruikersinterface.  
Op het display wordt alleen de meest relevante informatie (temperatuur en luchtvochtigheid) getoond, zodat de gebruiker niet wordt overspoeld met informatie.

Ontwerpkeuzes:
- Beperkte hoeveelheid informatie per scherm om cognitieve belasting te verminderen.
- Hoog contrast (witte tekst op blauwe achtergrond) voor goede leesbaarheid.
- Vaste tekst gecombineerd met dynamische sensorwaarden.

Een fysieke drukknop wordt gebruikt voor interactie met het display, bijvoorbeeld om het scherm aan of uit te zetten.  
Dit houdt de bediening eenvoudig en verkleint de kans op foutieve invoer.

Daarnaast is een buzzer toegevoegd als sensorische output, zodat gebruikers ook auditieve feedback kunnen krijgen bij interactie.

---

## Interactieflow

1. Het device start op en maakt automatisch verbinding met het netwerk.
2. Sensorwaarden worden op de achtergrond uitgelezen.
3. De weerinformatie wordt weergegeven op het LCD-display.
4. De gebruiker kan via de drukknop met het display interacteren (bijvoorbeeld het scherm aan- of uitzetten).
5. Feedback wordt gegeven via visuele (LCD) en sensorische (buzzer) outputs.

Deze flow is bewust kort en voorspelbaar gehouden om gebruikersfouten te minimaliseren.

---

## Consistentie en Eenvoud

Consistentie wordt bereikt door:
- Altijd dezelfde layout op het LCD-display te gebruiken.
- Slechts één vorm van fysieke interactie aan te bieden (de drukknop).
- Duidelijke labels en eenheden te gebruiken (°C, %).

Het systeem vermijdt onnodige menu’s of instellingen en sluit daarmee aan bij de behoeften van de doelgroep.

---

## Toegankelijkheid

Bij het ontwerp is rekening gehouden met basisprincipes van toegankelijkheid:
- Grote en goed leesbare tekens op het LCD-display.
- Een minimaal aantal interactiestappen.
- Zowel visuele als auditieve feedback.

Hoewel het systeem geen uitgebreide toegankelijkheidsopties biedt, zorgen deze keuzes voor een bruikbare ervaring voor een brede groep gebruikers.

---

## Evaluatie op Basis van de Rubric

Op basis van de UXD-rubric kan worden geconcludeerd dat:
- Het ontwerp is gericht op de gebruiker en diens doelen.
- De interactie eenvoudig en intuïtief is.
- Visuele en sensorische feedback consistent wordt toegepast.
- Het systeem voldoet aan het verwachte niveau voor User Experience Design.

---

## Conclusie

Het User Experience Design van het Weather Station is gericht op eenvoud, duidelijkheid en gebruiksgemak.  
Door de interactie bewust beperkt te houden en duidelijke feedback te geven via visuele en sensorische middelen, biedt het systeem een intuïtieve gebruikerservaring voor de beoogde doelgroep.