\# Research to Market  

\## Business \& Sustainability  

\### IoT Wheaterstation  

\*\*Auteur:\*\* Amin Moubariki  



---



\## Introduction / context  



Tijdens het ontwikkelen van mijn IoT Wheaterstation heb ik vooral gefocust op het technisch werkend krijgen van het systeem: sensoren uitlezen, data tonen en werken met een microcontroller. Het resultaat is een functionerend prototype dat geschikt is om te leren hoe embedded systemen en IoT-oplossingen zijn opgebouwd. Tegelijkertijd werd duidelijk dat dit prototype nog ver verwijderd is van een product dat daadwerkelijk verkocht zou kunnen worden.



Een concreet voorbeeld hiervan is het gebruik in het onderwijs. Wanneer een docent bijvoorbeeld twintig van deze weerstations zou willen inzetten in een practicum, ontstaat al snel een probleem. De huidige opbouw met breadboards en jumper wires is foutgevoelig, lastig te onderhouden en moeilijk te repareren. Als één sensor defect raakt, is het vaak eenvoudiger om het hele systeem te vervangen dan om het te herstellen. Dit is niet alleen kostbaar, maar ook niet duurzaam.



Dit onderzoek richt zich daarom op de vraag hoe dit prototype verbeterd kan worden zodat het dichter bij een marktwaardig product komt. De primaire doelgroep bestaat uit onderwijsinstellingen (MBO/HBO) en makers die een leerzaam, transparant en duurzaam IoT-product zoeken. Voor deze doelgroep is niet alleen functionaliteit belangrijk, maar ook levensduur, repareerbaarheid en inzicht in hoe het systeem is opgebouwd.



Voor de lezer is dit onderzoek relevant omdat het laat zien dat technische keuzes directe gevolgen hebben voor kosten, duurzaamheid en haalbaarheid. Een werkend prototype is niet automatisch een goed product, en juist in IoT-projecten wordt deze stap vaak onderschat.



---



\## Research question  



\*\*Hoe kan het IoT Wheaterstation worden doorontwikkeld tot een duurzaam en economisch haalbaar marktproduct, rekening houdend met productiekosten, verzending, belastingen, productverlies en structurele bedrijfskosten?\*\*



\### Deelvragen

1\. Welke onderdelen van het huidige prototype zijn ongeschikt voor marktintroductie en waarom?  

2\. Wat is een realistische kostprijs per geleverd product wanneer rekening wordt gehouden met verzending en 10% productverlies?  

3\. Welke verkoopprijs is nodig om duurzaamheid, ondersteuning en doorontwikkeling mogelijk te maken?



---



\## Research method  



Voor dit onderzoek is gekozen voor praktijkgerichte desk research. Deze methode past bij de onderzoeksvraag, omdat het doel niet is om gebruikersgedrag te meten, maar om de economische en logistieke haalbaarheid van het product te analyseren.



Allereerst is de bestaande Bill of Materials (BOM) geactualiseerd op basis van actuele prijzen bij Nederlandse leveranciers zoals TinyTronics en GAMMA. Deze BOM is bewust gebruikt als analyse-instrument en niet als eindoplossing.



Vervolgens zijn verzendkosten onderzocht aan de hand van officiële PostNL-tarieven voor nationale en internationale verzending. In alle berekeningen is expliciet rekening gehouden met het gegeven uit de opdracht dat 10% van de zendingen niet geleverd wordt. Deze aanname is consequent meegenomen in de effectieve kostprijs per geleverd product.



Daarnaast zijn relevante wetten en regels onderzocht, zoals btw-tarieven binnen Nederland en de EU, en Europese regelgeving rondom e-waste (WEEE/EPR). Ook zijn platformkosten (zoals Kickstarter-fees) meegenomen om een realistisch beeld te krijgen van de totale kostenstructuur.



---



\## Results  



\### Analyse van het prototype  



Uit de geactualiseerde BOM blijkt dat het huidige prototype ongeveer €32 tot €33 kost wanneer alle onderdelen los worden ingekocht. Deze prijs geeft een vertekend beeld, omdat arbeid, assemblage, kwaliteitscontrole, verpakking en verzending hierin niet zijn meegenomen. Daarnaast bevat het prototype onderdelen die ongeschikt zijn voor schaalbare productie, zoals breadboards, jumper wires en volledige weerstandensets.



Deze keuzes zijn logisch in een leercontext, maar problematisch bij herhaalbare productie. Ze verhogen de kans op fouten, maken reparatie lastig en leiden sneller tot vervanging in plaats van herstel.



\### Van prototype naar marktversie  



Om deze problemen op te lossen is gekeken naar een conceptuele marktversie van het product. In deze versie wordt het breadboard vervangen door één PCB met alleen de noodzakelijke componenten. Sensoren blijven modulair zodat ze afzonderlijk vervangen kunnen worden. De behuizing wordt repareerbaar ontworpen, bijvoorbeeld met schroefverbindingen in plaats van lijm.



Deze ontwerpkeuzes verlagen de kans op defecten en retouren en sluiten beter aan bij duurzaamheidsprincipes (European Commission, 2022).



\### Kostprijs, verkoopprijs en marge  



\*\*Tabel 1 – Kostprijs en marge (excl. btw)\*\*



| Component | Bedrag (€) |

|---------|------------|

| Productie (PCB, assemblage, behuizing, verpakking) | 25,50 |

| Opslag en kwaliteitscontrole | 1,50 |

| Productverlies (10%) | 2,80 |

| \*\*Effectieve kostprijs per geleverd product\*\* | \*\*28,00\*\* |

| \*\*Verkoopprijs (direct-to-consumer)\*\* | \*\*79,00\*\* |

| \*\*Brutomarge per product\*\* | \*\*51,00\*\* |



Deze tabel maakt duidelijk dat een verkoopprijs van €79 noodzakelijk is om ruimte te houden voor ondersteuning, retouren en verdere ontwikkeling.



---



\## Verzending, btw en internationale verkoop  



Verzending binnen Nederland kost gemiddeld €6 tot €7 per pakket, terwijl verzending binnen Europa varieert tussen €9 en €13 (PostNL, 2025). Verzending buiten de EU is aanzienlijk duurder en brengt extra administratieve lasten met zich mee.



Binnen Nederland geldt een btw-tarief van 21% (Belastingdienst, 2024). Binnen de EU verschillen btw-tarieven per land. Buiten de EU worden import-btw en inklaringskosten meestal door de consument betaald.



---



\## Implementation (koppeling met prototype)  



Foto’s van het huidige prototype zijn toegevoegd aan deze repository en tonen duidelijk waarom de huidige opbouw geschikt is als leerobject, maar niet als marktproduct. De zichtbare beperkingen van het prototype vormen de basis voor de voorgestelde verbeteringen.



Hoewel de marktversie in dit project nog niet fysiek is gerealiseerd, zijn de verbeteringen concreet uitgewerkt in ontwerpkeuzes, schema’s en kostenberekeningen. De implementatie is daarmee conceptueel afgerond en direct toepasbaar in een volgende ontwikkelfase.



---



\## Conclusion  



Het IoT Wheaterstation kan alleen marktwaardig en duurzaam worden wanneer technische en zakelijke keuzes samen worden bekeken. Door over te stappen van een breadboard-opzet naar een PCB-gebaseerde, modulaire marktversie worden fouten, retouren en e-waste verminderd. Tegelijkertijd ontstaat ruimte voor een gezonde marge die nodig is om het product te ondersteunen en verder te ontwikkelen.



Duurzaamheid blijkt in dit onderzoek geen losstaand thema, maar een voorwaarde voor economische haalbaarheid.



---



\## Recommendations  



Aanbevolen wordt om het prototype door te ontwikkelen naar een PCB-gebaseerde marktversie met modulaire sensoren en een repareerbare behuizing. Verzendkosten en belastingen moeten transparant worden gecommuniceerd en apart worden geprijsd.



Voor toekomstig onderzoek kan worden onderzocht hoe kostprijs en duurzaamheid veranderen bij grotere productieseries, bijvoorbeeld bij aantallen van 5.000 stuks of meer.



---



\## Begrippenlijst  



\*\*Bill of Materials (BOM)\*\*  

Overzicht van alle onderdelen die nodig zijn om een product te bouwen, inclusief aantallen en kosten.



\*\*Breadboard\*\*  

Testbord voor elektronische prototypes zonder solderen; ongeschikt voor marktproducten.



\*\*Brutomarge\*\*  

Verschil tussen verkoopprijs en kostprijs van een product.



\*\*COGS (Cost of Goods Sold)\*\*  

Directe kosten om één product te maken en te leveren.



\*\*Desk research\*\*  

Onderzoeksmethode gebaseerd op bestaande bronnen zoals documentatie en rapporten.



\*\*ESP8266\*\*  

Microcontroller met ingebouwde wifi-functionaliteit, gebruikt in dit project via de Wemos D1 mini.



\*\*IoT (Internet of Things)\*\*  

Netwerk van fysieke apparaten die data verzamelen en uitwisselen via het internet.



\*\*Modulair ontwerp\*\*  

Ontwerp waarbij onderdelen afzonderlijk vervangen kunnen worden.



\*\*PCB (Printed Circuit Board)\*\*  

Printplaat waarop elektronische componenten permanent zijn gemonteerd.



\*\*WEEE / EPR\*\*  

Europese regelgeving voor inzameling en verwerking van elektronisch afval.



---



\## References  



Baldé, C. P., Forti, V., Gray, V., Kuehr, R., \& Stegmann, P. (2020). \*The global e-waste monitor 2020\*. United Nations University.  

https://www.globalewaste.org  



Belastingdienst. (2024). \*Btw-tarieven\*.  

https://www.belastingdienst.nl  



European Commission. (2022). \*Sustainable products and circular economy\*.  

https://environment.ec.europa.eu  



Gartner. (2023). \*Why IoT projects fail to scale\*.  

https://www.gartner.com  



Kickstarter. (n.d.). \*Fees and pricing\*.  

https://www.kickstarter.com/help/fees  



PostNL. (2025). \*Tarieven pakketten Nederland en buitenland\*.  

https://www.postnl.nl  



Your Europe – Business. (2024). \*Waste electrical and electronic equipment (WEEE)\*.  

https://europa.eu/youreurope/business  

