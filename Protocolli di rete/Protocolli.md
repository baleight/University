# Protocolli e architetture di rete









## Introduzione

### Rete

In una rete si trovano due componenti fondamentali: nodi(host, switch…) e link(wired(cavi coassiali, fibra ottica…) e wireless.

I collegamenti possono essere diretti, point-to-point o accesso multiplo, o indiretti, switched.

Una rete può essere definita ricorsivamente come due o più nodi connessi da un link oppure due o più reti connesse da due o più nodi.
Le reti possono essere LAN(local area network) di dimensione ridotta(10m,100m,1km),
oppure WAN(wide area network) più grandi(regioni, stato continente).

Le WAN possono essere realizzate tramite tecnologie dette:

* circuit switching

* packet switching

* frame relay

* asynchronous transfer mode(ATM)

Le LAN sono realizzate cablate(ethernet, token ring, apple talk) o wireless.

La comunicazione tra due host ha come obiettivo quello di trasferire un messaggio(insieme di bit) da un host all’altro garantendo massima velocità possibile (**prestazioni**), il superamento dei guasti (**affidabilità**) e la **sicurezza **della trasmissione. Si possono verificare problemi come:

* interferenze elettriche

* congestioni

* guasti link e nodi intermedi

* problemi software di nodi

* ritardi nei messaggi

* ascolto dei messaggi da parte di terzi

Le architetture di rete sono basate su livelli. Quando si parla di rete ci si sofferma su 4 concetti fondamentali

* architettura hardware: quali elementi consentono la comunicazione e dove viaggia l’informazione

* **schema di naming:** come sono identificati gli interlocutori

* **architetture software**: quali elementi software implementano la comunicazione

* **schema di comunicazione**: come avviene la comunicazione

### Protocollo

Il protocollo è l’insieme di regole e convenzioni seguite da entità, dislocate su nodi distinti, che intendono comunicare per svolgere un compito comune.

Gli elementi di un protocolli di comunicazione sono:

* **sintassi**: insieme e struttura dei comandi e delle risposte, formato dei messaggi

* **semantica**: significato dei comandi, delle azioni, delle risposte da effettuare al momento della trasmissione e ricezione dei messaggi

* **temporizzazione:** specifica delle possibili sequenze temporali di emissione dei comandi e dei messaggi, nonché delle eventuali risposte.

Un sistema non utilizza un singolo protocollo ma necessita di un insieme di protocolli tra loro cooperanti. I protocolli costituiscono i blocchi fondamentali del modello architetturale di rete basato su livelli → **protocol stack.**

<u>Ogni protocollo, ad un certo livello, ha due interfacce interne(verso il livello inferiore e superiore) e una interfaccia esterna verso il livello equivalente di un altro nodo.</u>

Le interfaccie interne sono dette **service interface**, ovvero le operazioni e servizi offerti al protocollo superirore, mentre le interfacce esterne sono dette **peer-to-peer interface**, ovvero i messaggi scambiati con un livello equivalente sull’altro nodo.

<u>Il termine protocollo si utilizza per indicare le specifiche delle interfacce</u>,<u> le regole di comunicazione e i moduli software che implementano le interfacce e i servizi.</u>

La comunicazione avviene tra peer entity, ovvero entità logiche che si trovano allo stesso livello. In realtà la comunicazione peer entity avviene in modo diretto solo a livello hardware, per gli altri livelli la comunicazione è indiretta.
A ciascun livello il messaggio si compone in due parti:
protocol control information PCI → header, e service data unit SDU → informazione.

> PCI + SDU = PDU = protocol data UNIT.

Il messaggio è composto dalla parte di dati (payload) e da N parti di header a seconda dal livello che parte.

Un processo è un programma in esecuzione su un host. Due processi <u>sullo stesso host</u> comunicano tramite **interprocess communication** gestiti dal sistema operativo. Processi in esecuzione <u>su host differendi</u> comunicano mediante protocolli di livello applicativo.

### Stack Protocol: ISO/OSI  &  TCP/IP

La comunicazione è basata su uno standard. I 2 standard che si utilizzano sono ISO/OSI e TCP/IP.

Lo standard ISO/OSI comprende i protocolli di comunicazione(network level): riguardano la comunicazione di messaggi tra nodi della rete in modo da nascondere le caratteristiche dei mezzi fisici, e i protocolli di elaborazione(application level): insieme di meccanismi per il controllo delle applicazioni.

#### Lo standard ISO/OSI è basato su 7 livelli:

1. Livello fisico: gestisce i particolari meccanici ed elettrici della trasmissione fisica di un flusso di bit

2. livello di collegamento dati: gestisce i frame o i pacchetti trasformando la semplice trasmissione in una linea di comunicazione priva di errori non rilevati

3. livello di rete: fornisce i collegamenti e l’instradamento dei pacchetti nella rete, comprese la gestione dell’indirizzo dei pacchetti in uscita, la decodifica dell’indirizzo dei pacchetti in ingresso e la gestione delle informazioni di instradamento.

4. Livello di trasporto: effettua il controllo end-to-end della sessione di comunicazione e garantisce l’affidabilità del trasporto

5. livello di sessione: consente a utenti su macchine eterogenee di stabilire sessioni, implementare funzioni di coordinamento, sincronizzazione e mantenimento dello stato(di sessione)

6. livello di presentazione: risolve le differenze di formato che possono presentarsi tra diversi nodi della rete, ma gestisce la compressione dei dati, la sicurezza e l’autenticità dei messaggi attraverso  tecniche di crittografia

7. livello di applicazione: fornisce un’interfaccia standard per i programmi applicativi che utilizzano la rete, mascherando le peculiarità e la complessità del sistema sottostante

Il messaggio PDU è formato da intestazione(header) e dati. Ogni livello aggiunge una propria intestazione in testa al messaggio, i dati sono in fondo.

#### Perchè TCP/IP prese il sopravvento sul ISO/OSI.

Il modello ISO/OSI non è riuscito a imporsi come standard perché nel frattempo il protocollo Stack TCP/IP ha preso il sopravvento.

#### Il protocollo TCP/IP ha 5 livelli:

1. host-to-network (inteso come 2 livelli):

2. Link: effettua i trasferimenti dei dati tra componenti della rete confinanti: PPP, Ethernet

3. Fisico: trasferisce bit sul cavo

4. internet: trasferisce pacchetti dal nodo mittente al destinatario: IP

5. transport: supporta trasferimenti TCP, UDP

6. application: supporta applicazioni FTP, HTTP, SMTP...

#### Difetti dei due modelli

|                                      |                                                               |
| ------------------------------------ | ------------------------------------------------------------- |
| ISO/OSI                              | TCI/IP                                                        |
| * Cattiva tempistica                 | * Poco generale                                               |
| * Cattiva tecnologia                 | * Meno concettuale e più orientato al funzionamento           |
| * Cattiva implementazione            | * Livelli host-to-network confusi e interdipendenti           |
| * Pessima politica (modello imposto) | * Protocolli sviluppati ad hoc invece che protocolli generali |



Il modello TCI/IP ha avuto successo perché dispone di una buona implementazione dello stack in versione open source e ha un buon insieme di API per sviluppare applicazioni di rete, non perfette, ma funzionanti.

## Internet

Internet: è un insieme di reti esteso in tutto il mondo, non è governata da un gruppo o da un ente, non è gestita in modo centralizzato perché le sottoreti che compongono internet hanno una gestione autonoma.

#### Principi di funzionamento di internet

L’architettura consiste nel connettere diversi host e diverse reti, le tecniche di trasmissione sono<u> Store-and-forward e packet switching</u>. Logicamente due host comunicano, in realtà il messaggio deve attraversare vari nodi intermedi (router) con un meccanismo di store and forward. In ogni nodo il messaggio attraversa tutti i livelli necessari (5 per gli host e 3 per i router).

#### Esistono 2 metodi per la trasmissione: circuit switching e packet switching.

##### Il circuit switching:

consiste nel avere un circuito virtuale dedicato per ogni comunicazione, idea alla base del sistema telefonico, necessità di riservare tutte le risorse (link e switch) end-to-end prima di trasmettere. PRO: prestazioni garantite rispetto alla tipologia di risorse riservate. CONTRO: non c’è la possibilità di condividere le risorse assegnate ed è necessaria una fase di setup per ogni chiamata.

##### Il Packet switching:

consiste nel suddividere i dati in parti ed inviarli attraverso la rete, idea alla base di internet, ogni comunicazione è suddivisa in pacchetti, le risorse sono utilizzate sulla base della necessità e non della prenotazione.

# TCP/IP

## Intro

Lo stack TCP/IP ha molti protocolli ma non su tutti i livelli.

##### I primi due livelli (host-to-network, quindi livello fisico e data link)

non sono separati,<u> ovvero che la connessione fisica e il protocollo data link sono interdipendenti</u>. Quindi è meglio parlare di un livello host-to-network(h2n) che comprende i primi due livelli.

##### Il livello 3 (network) è il protocollo per la consegna dei pacchetti da un host mittente ad un host destinatario.

Ha servizi aggiuntivi rispetto a h2n: ha un identificativo univoco di ciascun host(IP) e ha la comunicazione logica tra gli host. Ma:

* è privo di connessione: ogni pacchetto è trattato in modo indipendente da tutti gli altri

* non è affidabile: la consegna non è garantita (pacchetti persi, duplicati, ritardati o consegnati in ordine sparso)

* consegna con impengo: tentativo di consegnare ogni pacchetto

##### Il livello 4 estende il servizio di consegna con impegno proprio del protocollo IP tra i due host terminali ad un servizio di consegna a due processi applicativi in esecuzione sugli host.

Ha servizi aggiuntivi rispetto a IP: multiplazione e demultiplazione dei messaggi tra i processi e un rilevamento dell’errore tramite checksum. UDP è un tipo di protocollo transport che fornisce un livello di trasporto dell’informazione connectionless. TCP è un tipo di protocollo transport che fornisce un livello di trasporto affidabile e orientato alla connessione. Ha servizi aggiuntivi rispetto a UDP:

* comprende l’instaurazione, utilizzo e chiusura della connessione

* considera il flusso di dati dall’host mittente fino al destinatario

* i dati sono memorizzatti in buffer e poi inseriti in un pacchetto quando il buffer è pieno

* una volta instaurata una connessione è possibile il trasferimento bidirezionale contemporaneamente

##### Il livello 5 utilizza un livello di trasporto dell’informazione tra i processi in esecuzione su host terminali per realizzare applicazioni di rete: ftp, telnet, http, smtp, irc. NB: applicazioni di rete ≠ protocolli applicativi.

## 1&2_HOST TO NETWORK

Il livello h2n affronta le problematiche di interconnessione tra due o più host, trasmissione dati tra host direttamente connessi, connessione di host a internet. Solo nello stack TCP/IP la modalità di interconnessione, la relativa tecnologia e i protocolli per la trasmissione dati tra host sono tra loro strettamente dipendenti → la scelta dell’uno implica la scelta dell’altro.

I servizi offerti da differenti protocolli h2n possono essere diversi:

* livello fisico: connessione di host secondo diversi mezzi trasmissivi (doppino, cavo coassiale, fibra ottica, trasmissione radio, modem)

* livello data link:

* framing

* accesso multiplo al link

* recapito affidabile

* controllo di flusso

* ricerca di errori

* correzione degli errori

* half-duplex o full-duplex

Il livello h2n opera a livello di singolo link (host interconnessi, host-switch, switch-switch) mentre il livello trasporto opera a livello host end-to-end. Il livello data link consegna pacchetti solo all’interno di una stessa LAN o connessione diretta mentre il livello network (IP) consegna pacchettio ovunque su internet.

Il collegamento h2n connette solo 2 dispositivi fisicamente: host-router/switch, router/switch-router/switch, host-host e l’unità di dato trasmesso è il frame.

Si collegano host con host, router, modem, switch oppure router con switch o switch con router.

### Modalità di trasmissione:

* Unicast: comunicazione tra un singolo mittente e un singolo ricevente

* Multicast: comunicazione fra un singolo mittente e un gruppo di riceventi

* Anycast: comunicazione fra un singolo mittente ed almeno un ricevente in un gruppo

* Broadcast: comunicazione fra un singolo mittente e tutti gli altri nodi

Il collegamento broadcast comprende molti host connessi a uno stesso canale di comunicazione, è necessario un protocollo di accesso al mezzo per coordinare le trasmissioni e evitare le collisioni, ovvero per risolvere le eventuali collisioni. Il collegamento punto-punto è una comunicazione tra un  singolo trasmittente e un singolo ricevente, tipico collegamento tra due router.

Tecnologie per interconnessioni

Cablaggio: stesura dell’infrastruttura fisica della rete.

Mezzo trasmissivo: mezzo fisico utilizzato per la propagazione dei bit da host all’altro.

Mezzi guidati: doppini intrecciati, cavi coassiali, fibre ottiche.

Mezzi a onda libera: canali radio terrestri e canali radio satellitari.

Il doppino intrecciato è il più diffuso e economico, utilizzato da più di 100 anni. Consiste in due fili di rame isolati singolarmente con diametro di circa 1mm, avvolto a spirale. I fili sono avvolti insieme per ridurre le interferenze elettromagnetiche. Usato in sistemi 10/100/1000 base T (T=twisted pari). Il cavo di rete è un cavo formato da più doppini riuniti e avvolti in uno schermo protettivo. Il cavo coassiale è formato da due conduttori di rame concentrici. Esistono cavi coassiali spesso (thick ethernet) e cavi coassiali sottili (thin ethernet). Il cavo spesso ha un costo elevato, è difficile da posare essendo rigido e ha un buon isolamento dal modo esterno e dal rumore elettromagnetico, permette una distanza massima di 500 metri tra i ripetitori. Il cavo sottile ha maggiore flessibilità e un isolamento inferiore rispetto a quello spesso, ha una distanza massima di 185 metri tra i ripetitori.

La fibra ottica è realizzata in vetro o plastica, trasporta i dati sotto forma di luce, sono ideali per collegamenti a lungo raggio e intercontinentali e ha alto costo per trasmettitori, ricevitori e commutatori, quindi non è utilizzata per il trasporto a corto raggio.

Le connessioni wireless non utilizzano cavi:

* micro-onde: fino a 45 Mbps

* wireless LAN o WLAN: fino a 11 Mbps(b), 54 Mbps(a,g), 300 Mbps(n), 1 Gbps(ac)

* Wide-area

* Satellite: fino a 50 Mbps per un singolo canale, è possibile aggregare multipli canali, circa 200 msec di ritardo end-to-end.

Accessi residenziali

### Gli accessi residenziali sono point-to-point.

* Dial-up: l’accesso in dial-up non richiede infrastrutture addizionali in quanto utilizza la rete telefonica

* ISDN: Integrated Services Digital Network: evoluzione della telefonia analogica, sostituisce una linea analogica commutata con una linea digitale commutata

* xDSL: elimina le apparecchiature in banda fonica per utilizzare al meglio il doppino telefonico:

* ADSL: Asymmetric Digital Subscriber Line: tecnologia domestica e small office, più banda in download che in upload

* HDSL: High-Bit-Rate Digital Subscriber Line: tecnologia aziendale, banda simmetrica

* VHDSL: Very High Speed DSL: banda larga a bistanza breve (max 300m)

* Cable modem: HFC → reti di cavi coassiali e fibra collegano le case ai router ISP

ISP: Internet Service Provider → uno o più server attivi e collegati ad Internet in modo permanente, una batteria di modem collegati a numeri di telefono. Offrono accesso a internet, emal, sito web, chat-line, blog…

### Protocollo Data Link: PPP

PPP → point to point protocol

Tipico collegamento punto-punto, un mittente → un destinatario → un link. Più semplice da gestire di un link broadcast. Il PPP non è accessibile tramite MAC esplicito. È un protocollo di livello 2(datalink). Molto usato dagli ISP e per gestire le connessioni xDSL. È un supporto multiprotocollo, rileva gli errori(senza risolverli), supporta IP dinamico. Principi del PPP:

* packet framing: incapsulamento di un datagramma di livello rete in un pacchetto PPP a livello data link

* bit transaprency: il PPP non deve porre alcuna restrizione ai dati che appaiono nel datagramma a livello di rete

* error detection: il ricevente deve poter rilevare errori

* connection liveness: individua problemi o guasti a livello di link e segnala errore a livello 3(network)

* network layer address negotiation: il PPP deve fornire un supporto ai diversi protocolli di rete comunicanti per apprendere o configurare gli indirizzi di rete

* network layer multiple protocols: supporto ai vari protocolli di rete operanti sul collegamento fisico

* multiple connection link: supporto per una vasta tipologia di collegamenti

* simplicity: semplicità, primo e più importante requisito

Il PPP non deve implementare:

* error correction: deve rilevare gli errori, ma non correggerli

* flow control: un ricevente PPP deve essere in grado di ottenere pacchetti del livello fisico sottostante

* sequence: accetta la consegna di pacchetti out-of-order

Queste funzioni sono delegate ai protocolli di livello più alto. Non ha la necessità di supportare link multipoint poiché opera su collegamenti punto-punto.

Fasi di una connessione PPP:

1. Definizione della connessione

2. Autenticazione

3. Configurazione del protocollo di rete che si utilizzerà

4. Terminazione della connessione

Prima di scambiarsi dati, i peer di livello data link devono stabilire la connessione: configurare il link PPP e apprendere/configurare le informazioni del livello network.

Il PPP crea un’interfaccia per il livello network, che a differenza dell’interfaccia ethernet, non è legata ad un solo dispositivo fisico.

Data Frame del PPP:

1. Flag: delimitatori di frame PPP

2. Address: non ha ruolo

3. Control: non ha ruolo, previsto per i futuri campi di controllo multipli

4. Protocol: protocollo di livello superiore a cui il frame viene passato

5. Info: messaggio di livello superiore

6. Check: byte di controllo correttezza → usa un codice a ridondanza ciclica
   
   

![](https://lh7-us.googleusercontent.com/VolM2SUDdk7ZadjQym3loKxgdbbFvwEakq4R1EnZCDeJRb5z7GkwS5U-z1obX3xfXYPw9e_Xo_mz7o9e4g7ZM7oBB3xsLUOJBbEVF5vaaiddnKHJEg0gUDuZyRtyjKnH154-swNz-fLFv2JziDjbPAJCx6PO1V0)  



### Tecnologie per interconnetere host alla rete

Il protocollo h2n è implementato all’interno della scheda adattatrice. Tutti i dispositivi, per poter essere utilizzati in una rete LAN devono avere una scheda di rete.

NIC→ network interface card → scheda di rete, costituita da RAM, è un entità semi automatica rispetto all’host in cui risiede.

LAN → rete di host collegati tra loro all’interno di un’area fisica limitata e proprietaria che non superi la distanza di qualche km. È basata su un rete di trasmissione condivisa a bit rate elevato. La LAN dell’università o aziendale è collegata a internet mediante uno o più dispositivi di rete(bridge e switch) e segmenti di rete che arrivano al border router. Per le LAN è utilizzato il collegamento ethernet →costa poco, funziona bene con i protocollo IP e TCP, è flessibile. Il collegamento ethernet usa un canale di broadcast(non punto-punto) → molti host connessi ad uno stesso canale di comunicazione e la trasmissione è broadcast → comunicazione fra un singolo emittente e tutti gli altri nodi.

Indirizzi ethernet: MAC

A livello ethernet gli host utilizzano un indirizzo hardware o indirizzo MAC. In realtà il MAC non si riferisce all’host ma alla sua NIC. Ogni NIC ha un indirizzo LAN univoco a 48 bit, tipicamente rappresentato da 6 coppie di numeri esadecimali. L’indirizzo broadcasta è FF-FF-FF-FF-FF-FF(tutti i bit a 1). L’indirizzo MAC di un NIC dovrebbe essere univoco e permanente. Ciascun host in una LAN ha un indirizzo IP e il NIC di ogni host ha un indirizzo MAC. Quando un host vuole trasmettere, inserisce nel frame l’indirizzo MAC del destinatario e lo immette nella LAN. Se l’indirizzo di destinazione del frame corrisponde all’indirizzo MAC del ricevente, il NIC dell’host accetta il frame e lo passa al sistema operativo che gestisce gli altri livelli dello stack TCP/IP. Se il MAC non corrisponde, il NIC scarta il pacchetto senza coinvolgere il sistema operativo. Oltre all’IP il MAC è necessario, altrimenti gli host non sarebbero in grado di supportare altri protocolli oltre all’IP e gli indirizzi IP dovrebbero essere registrati nella memoria del NIC.



Frame Ethernet

I pacchetti scambiati a livello h2n sono detti frame. Tutte le tecnologie Ethernet fanno uso dello stesso formato per il frame che trasmettono.

![](https://lh7-us.googleusercontent.com/zGHVM3MtIfRNB0LL6yoECJ6mdc2U9196AtT5NFzy2_Z0T8eMxE1TpHobQcbl7WjC3dnviycE8udWsvpMDFEIPNRjySUcCfLuxYwTQE1sgWbUqeqVAT1UDmQIz8ZSuGs4WoqJllBHlXKS_HdF9gGMJDVI56Jalps)  



Il preambolo è un campo a 8 byte, il primi 7 byte hanno valore 10101010, mentre l’ultimo ha valore  10101011. I primi 7 byte servono per attivare gli adattatori riceventi e sincronizzare i loro orologi con quello del mittente, mentre i due 1 consecutivi nell’ultimo byte avvisano l’adattatore del ricevente che la fase di sincronizzazione è terminata e che sta arrivando il frame. I campi di indirizzo di destinazione e sorgente sono a 6 byte e contengono gli indirizzi MAC della NIC del sorgente e della NIC destinazione. Il campo tipo è a 2 byte, permette a ethernet di multiplexare i protocolli del livello di rete, serve all’adattatore per sapere a quale dei protocolli dello strato di rete debba essere passato il campo dati di ciascun frame. Il campo dati contiene i dati reali da trasmettere, l’unità massima trasferibile(MTU-maximum transfer unit) è di 1500 byte, se i dati sono maggiori di 1500 byte, devono essere frammentati. La dimensione minima trasferibile è di 46 byte, se il dato è più piccolo di 46 byte, il campo dati deve essere completato(stuffing). Il campo CRC(controllo a ridondanza ciclica) è di 4 byte, il suo scopo è quello di permettere all’adattatore che riceve i dati di relavare la presenza di un errore nei bit del frame ricevuto. Quando un frame è trasmesso, l’host calcola il CRC e l’host destinatario lo torna a calcolare utilizzando la stessa funzione, poi confronta il risultato. Se sono diversi, allora c’è stato un errore, altrimenti assume che sia corretto.

### Protocollo ARP

È il protocollo per la risoluzione degli indirizzi. Se conosciamo l’indirizzo IP di un host, come si può determinare il suo corrispondente indirizzo MAC? Si utilizza il protocollo ARP(address resolution protocol) che si occupa di individuare l’indirizzo MAC di un host della stessa LAN di cui conosce l’indirizzo IP. Il protocollo ARP è incluso nella suite di protocolli TCP/IP.

Il protocollo ARP utilizza due tipi di messaggi: richiesta di connettersi all’indirizzo IP del destinatario e la risposta contenente il corrispondente indirizzo MAC. ARP utilizza il broadcast della richiesta. Il protocollo ARP dispone di una cache per ridurre il traffico sulla rete, ogni host effettua un caching temporaneo di IP/MAC nella sua tabella di instradamento.

Il RARP (reverse ARP) esegue una funzione opposta al protocollo ARP → dato un MAC ricava l’indirizzo IP. Stesso meccanismo dell’ARP. RARP è reso obsoleto da protocolli più moderni per la configurazione dinamica di indirizzi IP, in grado di supportare molteplici funzionalità aggiuntive. Le reti moderne si basano su DHCP.

I frame ethernet vengono trasmessi dagli host collegati allo stesso segmento di LAN su un canale condiviso broadcast a bit rate elevato. La spedizione contemporanea di più frame causa rischi di collisione. È necessario un protocollo di accesso al mezzo per coordinare le trasmissioni sul canale condiviso e evitare, se possibile, collisioni. Il protocollo CSMA/CD(carrier sense multiple access with collision detection) è un protocollo ad accesso casuale decentralizzato, quando un host deve trasmettere, ascolta il canale e trasmette alla massima velocità consentita dal canale. Quando un host rileva un collisione, ritrasmette il suo frame fino a quando la trasmissione non ha successo. La ritrasmissione non è immediata, ma l’host attende un periodo di tempo calcolato in modo pseudo-casuale. Ogni host che deve trasmettere ascolta il bus e decide di trasmettere solo se lo trova libero. Due frame consecutivi sono sempre distanziati da un tempo necessario a trasmettere il pacchetto dati più piccolo, questo intervallo è detto IFG(inter frame gap) → serve a garantire agli host in ascolto la fine di una trasmissione con quella successiva. Nonostante questa funzione, due host potrebbero decidere di trasmettere in contemporanea, essendo il tempo di propagazione del segnale sulla rete non nullo, un host può presumere che il mezzo sia libero anche se un altro ha già iniziato a trasmettere. Se si verifica una sovrapposizione di trasmissioni si ha una collisione. Per rilevare una collisione, ogni host mentre trasmette ascolta anche i segnali sul mezzo, confrontandoli con quelli da esso generati. Se viene rilevata una collisione, l’host interrompe la trasmissione. A seguito di una collisione, ogni host sospende la trasmissione e trasmette un segnale di jamming(disturbo), per avvisare della collisione tutti gli altri host. Un disturbo è generalmente a 48 bit. Il segnale di jamming assicura la rilevazione della collisione anche se essa è di breve durata. Gli host ripetono il tentativo di trasmissione dopo un ritardo pseudo-casuale, calcolato tramite l’algoritmo di exponential back-off.

### Architetture per LAN

Le LAN utilizzano tecnologie e architetture ormai ben consolidate e poco costose. Le LAN che costituiscono gli elementi fondamentali per l’accesso ad internet sono dette back end LAN e possono essere collegate mediante backbone LAN. Le back end LAN realizzano sistemi di medie dimensioni, interconnettendo server, dispositivi di storage, PC ecc, con le seguenti caratteristiche:

* media alta capacità di traffico (100Mbps – 1 Gbps)

* accessi distribuiti

* distanza limitata tra i componenti

* costi ridotti

Le backbone LAN devono garantire affidabilità ed elevata capacità di traffico(1Gbps – 10 Gbps – 100 Gbps).

Topologie di rete:

* ethernet 10BaseT → doppino in rame, rate a 10Mbps

* ethernet 10BaseF → fibra ottica, rate a 10Mbps

* Ethernet 100BaseT o Fast Ethernet → doppibo in rame, rate fino a 100 Mbps

#### Topologie per LAN e interconnessioni di LAN:

* Albero

* Bus

* Anello

* Stella

##### La topologia a bus:

è il metodo più semplice di connettere in rete degli host → singolo cavo, chiamato dorsale o segmento, che connette in modo lineare tutti gli host. I messaggi sono inviati a tutti gli host ma vengono letti solo da quello con indirizzo MAC corretto. I dati trasmessi, se non vengono interrotti, viaggiano da un capo all’altro del cavo, rimbalzando e tornando indietro impedendo ad altri host di inviare segnali. Ciascuna estremità del cavo è connessa ad un terminatore che assorbe i dati liberi rendendo disponibile il cavo per l’invio di altri dati. Se un cavo viene tagliato o scollegato, quindi privi di terminatore, i dati rimbalzeranno interrompendo l’attività su tutta la rete(rete inattiva).

##### La topologia ad anello(ring):

prevede un unico cavo circolare privo di terminatori. I segnali sono inviati dentro il circuito chiuso e ciascun host funge da ripetitore e ritrasmette il segnale, se non è il mittente. Il mittente al ritorno del frame trasmesso, lo riassorbe e lo toglie dalla rete.

La topologia a rete prevede una connessione di tutti gli host ad un dispositivo di rete centrale, che smista i vari messaggi nella rete. Quasi la totalità delle reti ethernet moderne sono progettate con topologia a stella. Nel caso di interruzione di uno dei cavi di connessione di un host al dispositivo centrale, solo quell’host sarà isolato dalla rete. In caso guasto del dispositivo centrale, tutti gli host saranno sconnessi dalla rete. Questa rete è molto flessibile e diminuisce l’interferenza di traffico ma ha un traffico molto elevato sul dispositivo centrale.

## I dispositivi centrali possono essere → hub, bridge, switch(livello 2), switch di livello 3.

Un hub è un dispositivo di livello fisico dotato di due o più interfacce. È un ripetitore che opera a livello di singoli bit → ripete i bit ricevuti su una interfaccia a tutte le altre interfacce. Ogni noto connesso fa parte dello stesso segmento di LAN. Sono dispositivi semplici ed economici. È la tipologia migliore per le piccole LAN con poco traffico. Estende la distanza massima tra due noti da 100m a 200m. Gli hub non isolano il dominio delle collisioni → il traffico di un host può collidere con il traffico di ogni altro host. In pratica una LAN con hub equivale a una topologia a bus.

#### Il bridge:

è un dispositivo di livello 2(link layer). Opera a livello di frame ehternet, esaminando l’header dei frame e inoltrando i frame selettivamente sulla base dell’indirizzo MAC. Il bridge utilizza il protocollo CSMA/CD. Il bridge isola i domini di collisione producendo un aumento del massimo traffico totale gestibile e non limita il numero degli host.

#### Gli switch:

sono in pratica dei bridge ad alte prestazioni con molte interfacce → inoltro di frame a livello 2 e filtraggio utilizzando indirizzi MAC. Tipicamente è utilizzato come centro della stella. Consente una architettura senza collisioni. Uno switch è più intelligente di un hub perché è in grado di leggere l’indirizzo del destinatario all’interno del frame che gli arriva. Uno switch può svolgere funzioni di filtraggio poiché può leggere il MAC e inoltra il frame al solo host destinazione.

Il filtraggio dei frame consiste nel non inoltrare i frame destinati ad un host agli altri host. Come si fa a sapere a quale segmento LAN deve essere inoltrato un frame? Si utilizza il MAC.

Gli switch imparano hanno una tabella di filtraggio automatica che identifica gli host con le interfacce, in modo da sapere a chi inoltrare i frame.

Tipi di commutazione per switch:

* store and forward → quando un frame è instradato attraverso un commutatore store and forward, il frame è immagazzinato nella sua totalià prima di essere messo sulla linea di uscita

* cut-through → il frame è inoltrato in uscita senza aspettare che tutto il frame sia arrivato, è sufficiente arrivo del frame che contiene l’indirizzo di destinazione → più veloce ma con possibile inoltro di frame difettosi.

Interconnesione di LAN

Ciascuna tecnlogia Ethernet ha limitazioni relative al numero massimo di host, massima distanza fra due host e massimo numero di livelli in uno schema multi-livello. Gli switch sono utilizzati per interconnettere LAN multi-livello o LAN diverse.

Per aumentare l’affidabilità di una rete, è necessario avere ridondanza, ovvero collegamenti alternativi dalla sorgente alla destinazione → avendo cammini multipli si possono creare cicli e gli switch potrebbero moltiplicare i frame → soluzione → routing secondo principi di spanning tree riconfigurabile dinamicamente a livello software. Lo spanning tree è un sottoinsieme della topologia originaria che non contiene cicli. Si può organizzare l’architettura di switch in uno spanning tree disabilitando un sottoinsieme di interfacce.

Cablaggio strutturato

L’elaborazione e la trasmissione delle informazioni sono diventate il centro delle attività economiche delle imprese. Il cablaggio strutturato prevede l’integrazione dei diversi servizi in un’unica infrastruttura polivalente.  

## Virtual LAN

Una rete fisica non deve corrispondere necessariamente alla rete logica, almeno oggi(in passato si), grazie all’uso delle Virtual LAN.

In una LAN tradizionale gli host sono aggregati fisicamente mediante dispositivi di rete(hub, switch, router). Un hub non differenzia il dominio di collisione ne il dominio di broadcast, uno switch differenzia il dominio di collisione ma non quello di broadcast mentre un router differenzia sia quello di collisione che quello di broadcast.

Un dominio di collisioni influisce sulla trasmissione, ovvero una rete di trasmissione un solo dominio di collisione equivale ad una rete dove gli host concorrono per accedere al mezzo trasmissivo e poi trasmettere(se uno trasmette, tutti gli altri non possono trasmettere).

Un dominio di broadcast è un dominio in cui se un host invia, tutti gli altri ascoltano la trasmissione.

Quindi una LAN con hub è una rete con un solo dominio di collisione e di broadcast, quindi un solo host trasmette e tutti ascoltano.

Una LAN con switch è una rete con un dominio di broadcast e N domini di collisione(N=numero host), quindi tutti possono trasmettere contemporaneamente e tutti ascoltano contemporaneamente.

Una LAN con router è una rete con N domini di broadcast e N di collisione, quindi tutti possono trasmettere e uno host non può ascoltare una trasmissione non destinata a lui.

La sicurezza di una LAN consiste nel sapere che se due host sono collegati a livello fisico abbiano la possibilità di condividere le stesse informazioni, mentre per la gestione ricablare e ri-indirizzare e riconfigurare una LAN fisica sono operazioni costose.

Per questo motivo si utilizzano le Virtual LAN(VLAN). Mediante una VLAN gli host possono essere raggruppati “logicamente” in base al dipartimento di appartenenza, tipo di applicazioni da utilizzare, alle funzioni nell’ambito dell’azienda e al livello di riservatezza.

Tecnicamente una VLAN equivale alla creazione di un dominio di broadcast virtuale indipendente dalla struttura fisica della rete. Gli host che si trovano all’interno di una VLAN possono comunicare direttamente. Gli host che si trovano in VLAN differenti possono comunicare solo mediante l’intermediazione di un dispositivo di rete. Una VLAN segmenta gli host in sottoreti differenti(domini di broadcast). Ciascuna VLAN è realizzata mediante switch di fascia medio-alta e porte di switching private. La comunicazione tra domini di broadcast differenti è bloccata perche il protocllo ARP individua l’indirizzo di destinazione MAC mediante broadcast(su un solo dominio). Per far comunicare host di VLAN differenti bisogna salire di livello, utilizzando un router o uno switch con funzionalità a livello 3.

Una VLAN può essere statica o dinamica. Una VLAN può assegnare sulla base di porta, indirizzo o  tipo di protocollo(SOLO NELLE STATICHE, più facie da configurare e da monitorare, funziona bene in reti dove i movimenti sono limitati o controllati). Nelle VLAN dinamiche le porte dello switch posso determinare in modo automatico l’assegnazione di una VLAN di un utente basandosi su MAC, indirizzo IP o tipo di protocollo, è più difficile da configurare e da gestire.

È possibile realizzare VLAN anche tra host che sono collegati a diversi switch.

Poichè le VLAN definiscono domini di broadcast differenti, i router sono fondamentali per ricostruire un pacchetto con indirizzi MAC della VLAN di destinazione. Ciascun dispositivo di livello 3 si può occupare della funzionalità di routing.

## 3_NETWORK

Livello IP

Il protocollo iP è un protocollo antico, sviluppato nel 1981. È un protocollo di livello 3:

1. si garantisce l’indirizzamento univoco degli host → tutti gli host collegati a internet devono essere identificati ed in modo esclusivo → indirizzo IP

2. si definisce l’unita di trasferimento dati → definisce l’unità informatica utilizzata da internet per trasferire dati → datagram(da 64 a 1500 byte)

3. si chiarisce l’architettura di internet → definisce i componenti fondamentali di una rete distribuita su scala geografica

4. si illustrano le diverse funzioni di routing

Packet switching vs circuit switching

2 modalità per trasferire dati: packed o circuit switching.

Circuit switching(C.S) → un circuito virtuale dedicato per ogni comunicazione → idea alla base del sistema telefonico.

Packet switching(P.S) → i dati sono suddivisi in parti e inviati attraverso la rete → idea alla base di internet.

Il circuit switching ha la necessità di riservare tutte le risorse(link e switch) end-to-end prima di trasmettere e deve avere risorse dedicate → CONTRO: non c’è possibilità di condividere le risorse assegnate, necessaria una fase di setup per ogni chiamata. PRO: prestazioni garantite rispetto alla tipologia di risorse riservate. Il multiplexing(condivisione) di risorse è indispensabile per ottimizzare il loro utilizzo. Nel C.S è deterministico mentre nel P.S è probabilistico.

Nel C.S le risorse di rete(ad esempio la banda) non sono completamente dedicate, ma suddivise in parti. Le parti sono assegnate alle chiamate e sono riservate alla chiamata, ovvero non sono utilizzabili dagli altri anche se la chiamata che le possiede non le sta usando(non c’è possibilità di condividione). È possibile suddividere una risorsa in due modi: basati sulla frequenza(FDM) o basati sul tempo(TDM).

Nel P.S ogni comunicazione è suddivisa in pacchetti, le risorse sono utilizzate sulla base della necessità e non della prenotazione. Il P.S utilizza un multiplexing statico a suddivisone di tempo, ma su richiesta invece che a intervalli prefissati. Pacchetti provenienti da diverse sorgenti sono mescolati sullo stesso link. Poiché che non c’è garanzia di avere una risorsa disponibile, ci può essere conflitto. I pacchetti in conflitto per lo stesso link sono inseriti in un buffer del router. Il buffer determina una coda di pacchetti che può essere processata in ordine FIFO, ma non necessariamente. La congestione equivale al riempimento del buffer. La comunicazione è di tipo store and forward, ovvero i pacchetti vengono trasmessi su un link, arrivano ad un router, aspettano(presso il router) il loro turno per poter essere trasmessi sul successivo.

Non essendoci prenotazioni, si possono creare congestione impreviste, i pacchetti rimangono accodati, se c’è spazio, in attesa di poter utilizzare il link. Se la coda è piena, il pacchetto viene perduto(senza avvisi). PRO del P.S: c’è condivisione di risorse, non c’è la necessita di prenotare risorse end-to-end, è ottimo per dati che arrivano in gruppi. CONTRO del P.S: rischi di congestione, ci possono essere ritardi e perdita di pacchetti, oltre al livello IP, è necessario un protocollo che garantisca almeno due proprietà: trasferimento dei dati affidabile e il controllo della congestione.

Per misurare le prestazioni si utilizza il valore del bandwidth(banda di trasmissione): quantità di dati trasmessi per unità di tempo. Quindi le metriche sono:

* Kbps o Kbit/s → Kilo-bit per secondo

* Mbps o Mbit/s → Megabit per secondo

* Gbps o Gbit/s → Gigabit per secondo

Servizi del livello IP

* indirizzamento univoco degli host

* unità di trasferimento dati → definisce l’unità base di informazione utilizzata da Internet per trasferire dati

* Funzione di routing → sceglie il percorso della rete attraverso il quale consegnare i pacchetti.

* Consegna non affidabile dei pacchetti:

* consegna priva di connessione: ogni pacchetto è trattato in modo indipendente da tutti gli altri

* consegna con impengo: tentativo di riconsegnare ogni pacchetto

* consegna non garantita: i pacchetti possono essere persi, duplicati, ritardati, o cosegnati senza ordine

Tutto il traffico Internet consiste in pacchetti. Ogni pacchetto è lungo fino a 64 Kbyte. Il datagram del livello IP è diviso in 2 parti: header e dati. Nell’header sono immagazzinati informazione per la trasmissione, come ad esempio indirizzo sorgente e destinazione. Nella parte di dati è immagazzinato il payload, ovvero i dati da consegnare.

FORMATO DEL DATAGRAM IP

0     4                  8                                     16                19                  24                          31 bit

|                                |      |              |                 |
| ------------------------------ | ---- | ------------ | --------------- |
| VERS                           | HLEN | SERVICE TYPE | TOTAL LENGHT    |
| IDENTIFICATION                 |      |              | FLAGS           |
| TIME TO LIVE                   |      | PROTOCOL     | HEADER CHECKSUM |
| SOURCE IP ADDRESS(32 BIT)      |      |              |                 |
| DESTINATION IP ADDRESS(32 BIT) |      |              |                 |
| IP OPTIONS                     |      |              |                 |
| DATI                           |      |              |                 |

* VERS: versione del protocollo IP usata per creare il datagram

* HLEN: lunghezza dell’header del datagram(in parole da 32 bit); in generale uguale a 5 (20 byte)

* TOTAL LENGHT: lunghezza del datagram IP(in byte); max dimensione 216= 65536 byte(64Kbyte)

* TYOE OF SERVICE(TOS): specifica come si richiede che sia trattato il datagram

* IDENTIFICATION: intero che identifica il datagram

* FLAGS: controllo della frammentazione

* FRAGMENT OFFSET: la posizione del frammento nel datagram originale

* TIME TO LIVE: indica per quanto tempo il datagram può circolare in internet. È decrementato da ciascun router che gestisce il datagram, quando diventa 0, è eliminato dal router corrispondente

* PROTOCOL: indica quale protocollo applicativo può utilizzare i dati contenuti nel datagram

* HEADER CHECKSUM: serve per controllare l’integrità dei dati trasportati nell’header

* SOURCE IP ADDRESS: indirizzo IP del mittente del datagram

* DESTINATION IP ADDRESS: indirizzo IP del destinatario del datagram

* IP OPTIONS: campo opzionale di lunghezza variabile, serve per il testing e il debugging della rete

* PADDING: campo opzionale che serve per fare in modo che l’header abbia lunghezza multipla di 32 bit, è presente soltanto se il campo IP options denota una lunghezza variabile.

INDIRIZZAMENTO

Per fornire un servizio di comunicazione universale occorre un metodo che permette di identificare univocamente ogni nodo. Ad ogni nodo è assegnato un unico indirizzo interent(IP) formato da 32 bit. L’indirizzo IP è suddiviso in 4 campi, ogni campo è a 8 bit, i campi sono separati da un punto(dotted notation). Ogni indirizzo IP è strutturato in una coppia <netid,hostid> dove netid indica la rete e hostid identifica un host di quella rete. Gli host che si trovano sulla stessa rete condividono lo stesso network ID. Gli indirizzi sono suddivisi in classi:

* classe a → 7 bit per la net e 24 per l’host → da 0.1.0.0 a 127.255.255.255

* classe b → 14 bit per la net e 16 bit per l’host → da 128.0.0.0 a 191.255.255.255

* classe c → 21 bit per la rete e 8 per l’host → da 192.0.0.0 a 223.255.255.255

* classe d → da 224.0.0.0 a 239.255.255.255

* classe e → da 240.0.0.0 a 255.255.255.255

### Indirizzi speciali:

* “questohost” : 0.0.0.0 → 00000000 00000000 00000000 00000000

* un host di questa rete: zeri nel campo rete seguiti dal campo host

* broadcast su questa rete: 255.255.255.255 → 11111111 11111111 11111111 11111111

* broadcast su una rete remota: identificatore della rete seguito da 1 nel campo host

Gli indirizzi IP sono indirizzi logici(non fisici). Ogni host deve essere identificato da un indirizzo IP, che può essere assegnato permanentemente oppure dinamicamente al momento del boot di un host. L’indirizzo IP è configurato in maniera manuale dall’amministratore di sistema oppure in maniera dinamica(DHCP). In realtà l’indirizzo IP(host address) viene assegnato all’interfaccia di rete, quindi un host dotato di più interfacce di rete può avere più host address.

### INDIRIZZI SPECIALI NON ASSEGNABILI A HOST

* network address: hostid con tutti i bit uguali a zero(ad esempio 128.211.0.0 indica la rete di classe B avente netid 128.211) → denota il netid(prefisso) assegnato ad una rete

* directed broadcast address: hostid con tutti i bit uguali a 1(ad esempip 128.211.255.255 indica il broadcast per la rete di classe B avente netid 128.211) → permette il broadcast a tutti gli host su una certa rete

* limited broadcast addres: tutti i bit uguali a 1(ovvero 255.255.255.255) → permette il broadcast sulla rete fisica locale

* this host on this network: tutti i bit uguali a 0(ovvero 0.0.0.0) → usato per il boot dell’host

* loopback address: la classe A con netid pari a 127(ad esempio 127.0.0.1) → è un indirizzo software virtuale senza corrispettivo hardware e senza connessioni di rete → è usato per il testing di applicazioni di rete.

Subnetting e supernetting

Subnetting → sottoclassi di indirizzi ip, sopratutto per organizzazioni con indirizzi di classe B.

Supernetting → sopraclassi di indirizzi ip, per organizzazioni grandi con più indirizzi di classe C

Subnetting

Un organizzazione può suddividere il suo spazio di host address on gruppi detti subnet. Il subnet ID è tipicamente utilizzato per raggruppare host basati sulla topologia fisica della rete.

|        |           |         |
| ------ | --------- | ------- |
| Net ID | Subnet ID | Host ID |

Ad esempio data la rete 128.213.x.x, è possibile suddividerla in 3 subnet:

* 128.213.1.x

* 128.213.2.x

* 128.213.3.x

Ad ogni rete fisica è assegnato un unico indirizzo di sottorete e ogni host appartenente a questa rete ha come netid l’indirizzo di sottorete → ovvero per la subnet 128.10.1.0, gli indirizzi ip degli host di questa rete saranno 128.10.1.x.

Il subnetting permette la massima flessibilità → è possibile avere uno stesso segmento di rete fisico suddiviso in più subnet logiche.

Network mask → usata per definire i bit dedicati al netid → 4 byte. La network mask permette di indiduare due dati mediante un AND logico con l’indirizzo IP:

* quale parte di un indirizzo IP è riservata per il netid(parte di 1)

* quale parte è disponibile per gli hostid(parte di 0)

esempio

Dato l’indirizzo ip 156.154.81.56 con network mask 255.255.255.240, a quale sottorete appartiene?

Metto in AND indirizzo ip e subnet mask:

10011100 10011010 01010001 00111000

11111111  11111111  11111111  11110000

--------------------------------------------------

subnet:  10011100 10011010 01010001 11110000

Il range degli host della sottorete è calcolato con questa formula → 2^n – 2 dove n è il numero degli ultimi 0 consecutivi della subnet mask, nel nostro caso diventa 2^4 – 2 = 14, ovvero da 156.154.81.49 a 156.154.81.62, 156.154.81.63 è usato per il broadcast della sottorete.

Esempio di subnetting

Abbiamo un indirizzo universitario di classe B: 150.100 e si assume che ogni dipartimento abbia meno di 100 host. Quanti bit servono per identificare gli host di una sottorete? Qual’è la network mask?

Con 6 bit, tramite la formula ottengo 2^6 – 2 = 62 host, mentre con 7 bit ottengo 2^7 -2 = 122. Quindi ipotizzando di avere meno di 100 host per ogni dipartimento, con 7 bit sono sicuro di prenderli tutti.

La network mask diventa 11111111 11111111 11111111 10000000 → 255.255.255.128

Le subnet servono soprattutto per facilitare il routing dei pacchetti all’interno della rete amministrata.

Il subnet addressing modifica l’interpretazione degli indirizzi IP: l’indirizzo IP è composto da una porzione di rete e una locale, si ottiene un routing gerarchico.

Esempio di subnet gerarchico con cinque reti fisiche suddivise in tre livelli:

rete di classe B(16 bit per parte locale), 5 reti fisiche(occorrono 3 bit, essendo 5 < 2^3 = 8, per identificarle, ad ognuna delle 5 reti fisiche è possibile collegare 2^13 = 8192 host.

Supernetting

Problema → esaurimento dello spazio di indirizzamento all’interno di una stessa classe di indirizzi.

Soluzione → un’organizzazione può richiedere più indirizzi della stessa classe per la sua rete.

Come gestirli?

Gestione mediante supernet addressing → approccio opposto al subnet addressing, in pratica si utilizzano meno bit di un intero byte per identificare il net. Nei router si utilizza il meccanismo Classless inter-domain routing (CIDR) in cui network addres è il più piccolo indirizzo(in bit) nel blocco di indirizzdi di classe B o C assegnati, il count è il numero di blocchi di indirizzi di classe B o C contigui.

Aumentare il numero di indirizzi

Attualmente ciascun indirizzo IPv4 consiste di 4 byte(32 bit). In IPv4 vi sono 3758096384 indirizzi IP utilizzabili per l’indirizzamento degli host, ma ci sono un miliardo di host connessi. Gli indirizzi IP stanno quasi finendo, perché?

1. Evoluzione della tecnologia e dei dispositivi che consentono connessione a internet, siamo partiti da un singolo computer(quindi un indirizzo IP) per molte persone e siamo arrivati a avere più di un indirizzo a persona.

2. Gli indirizzi IP non sono e non possono essere distribuiti uniformemente.

Le possibili soluzioni sono il DHCP per l’immediato presente, e per il futuro il passaggio allo standard ipv6.

Per alcune organizzazioni è importante avere reti private in senso stretto → nessun pacchetto esce e nessun pacchetto entra nella rete. Per altre organizzazioni si preferiscono reti semiprivate con tre categorie di host:

* nessun accesso da/a host fuori dall’organizzazione

* accesso parziale(host che possono raggiungere l’esterno ma non sono raggiungibili dall’esterno)

* accesso completo

NATting per reti semi-private

Il NATting è una funzionalità attivabile sul router “al bordo” della rete dell’organizzazione, ovvero il router che collega l’organizzazione con il dominio esterno. Poiché per molte organizzazioni non è necessario che tutti i loro indirizzi siano visibili globalmente, per evitare lo spreco di indirizzi, la IANA ha definito delle reti private,ossia:

* non uniche a livello mondiale

* con indirizzi IANA privati

* gli indirizzi “non routable” si possono utilizzare senza richiedere autorizzazione, purché si garantisca che il traffico e gli indirizzi siano limitati alla rete interna

Indirizzi per NAT

* classe A: [10.0.0.0 – 10.255.255.255)

* classe B: [172.16.0.0 – 172.31.255.255]

* classe C: [192.168.0.0 – 192.168.255.255]

In questo modo un’organizzazione ha la possibilità di progettare una rete che include host visibili(pubblici) e host non visibili(privati).

Gli host privati possono scambiare pacchetti solo con gli altri host privati all’interno della stessa rete senza intermediari o con host pubblici tramite proxy o NAT.

Il NAT router si interpone tra la rete locale e internet, e svolge i seguenti compiti:

* mappa gli indirizzi IP tra due domini(interno-esterno)

* garantisce la trasparenza del router tra gli end system

* moltiplica le possibilità in interconnessioni di host di una organizzazione

* aumenta la sicurezza evitando di rendere visibili all’esterno alcuni computer di una organizzazione

In realtà ha due funzionalità: natting e switching. Il router gestisce una corrispondenza tra gli indirizzi dei due domini tramite una Tabella che mantiene una riga per ciascuna connessione aperta:

* binding statico: la corrispondenza viene configurata manualmente con l’indirizzo IP del router o con uno degli indirizzi pubblici di un pool di indirizzi

* binding dinamico: la corrispondenza indirizzo privato-pubblico viene calcolata dinamicamente a seconda del traffico e dell’host che fa richiesta.

Lo svantaggio del Natting è che distrugge la semantica della comunicazione end-to-end in quanto gli host interni non possono essere raggiunti dall’esterno, in questo modo però aumenta la sicurezza(quindi è uno svantaggio-vantaggio).

Architettura di Internet

Internet è un insieme di componenti fisici(host, link di comunicazione e router). Il suo obiettivo globale è quello di connettere un qualsiasi numero di reti indipendenti ed eterogenee.

Principi funzionali di progetto:

* survivability → se tra due host esiste un qualsiasi percorso, la comunicazione deve poter avvenire

* forma a clessidra su più livelli → IP effettua minime assunzioni si mezzi di trasporto sottostanti e deve funzionare per tutti i tipi di applicazioni di rete

* mancanza di stato → l’intelligenza è mantenuta ai bordi della rete(host) e non all’interno(router). Si facilitano la survivability del sistema e le prestazioni di trasmissione

* net neutrality →ogni pacchetto con qualsiasi mittente e destinazione è tratta nello stesso modo

* autonomous system → ogni rete è posseduta e gestita da un ente diverso

### Organizzazione interna di internet

Gli host terminali sono connessi a ISP locali(ISP = internet service provider), gli ISP locali sono collegati a ISP regonali, gli ISP regionali sono connessi a ISP internazionali detti NBP(national backbone provider) o NSP(national service provider).

Internet è un insieme di oltre 50000 Autonomous System, almeno a livello organizzativo.

### Un Autonomous System(AS)

è un insieme di reti, indirizzi IP e di router sotto controllo di una organizzazione(o consorzio) nell’ambito del quale si utilizza una politica di interior routing. Gli AS sono le unità delle politiche di exterior routing, come nel caso del BGP.

Non tutti i router sono uguali per potenza e configurazione, tuttavia tutti i router all’interno dello stesso AS usano lo stesso algoritmo di instradamento dei messaggi(routing) e si scambiano continue informazioni con gli altri router. Gli ISP regionali(nazionali) e internazionali sono collegati tra di loro tramite peering point(privati) o Internet Exchange point(ex NAP). Nel peering point ogni rete è connessa alle altre, mentre nelle IXP le reti sono connesse ad un unico punto di scambio(stella).

Poiche trasferiscono enormi quantità di traffico, gli IXP sono costituiti da elementi di routing/switching molto potenti e replicati. La tecnologia tipica di un IXP consiste in uno o più centri stella ai quali vengono collegati i router dei vari partecipanti.

### In sintesi cos’è internet:

* dal punto di vista delle applicazioni di rete → un entità trasparente, nella maggior parte dei casi

* dal punto di vista fisico → un insieme di componenti interne(host,link,router) in cui ciascun nodo è caratterizzato da un indirizzo IP strutturato in 4 byte

* dal punto di vista funzionale → rete operante mediante packet switching con intelligenza sugli end point e non sui router, dove le soluzioni sono fornite a diversi livelli(a clessidra)

* dal punto di vista organizzativo → un insieme di Autonomous System(guardando ai router) o un insieme di nomi e domini(guardando gli host)
  
  

Basi Teoriche per il routing

Tre servizi principali del livello IP:

* Indirizzamento univoco degli host

* Unità di trasferimento dati

* Architettura di Internet

Funzione di routing → Consegna i pacchetti da un host ad un altro, ma in modo best effort, privo di connesione e quindi non garantito; sceglie il percorso nella rete attraverso il quale consegnare i pacchetti; ogni router ha una tabella in cui ciascuna riga fornisce il next-hop per ogni possibile destinazione.

Ciascun host fa riferimento a un router di default, detto anche first hop router. Quando un host invia un pacchetto, questo router prende il nome di source router. Analogamente quando in host riceve un pacchetto, il suo router di default prende il nome di destination router.

Quindi il problema del routing da host a host è in realtà un problema tra source router e destination router.

Algoritmo di routing → dato un insieme di router interconnessi, determinare il cammino ottimale dal source router al destination router. Per cammino ottimale si intende quello con costo minimo.

Per costo si intende tutta una serie di fattori:

* fattori statici: topologia della rete, banda del link(senza tener conto del traffico)

* fattori dinamici: traffico di rete, guasti, carico dei router.

* Costi economici: accordi tra Autonomous System

La rete è modellata tramite un grafo pesato G(N,E) dove:

* i nodi N rappresentano i router(oppure gli AS)

* gli archi rappresentano le connessioni tra i router

* le etichette E degli archi rappresentano il “costo” delle connessioni tra i router

Esistono due classi di algoritmi di routing→ gli algoritmi di routing globale e algoritmi di routing locale. Nei primi ogni nodo offre a tutti gli altri nodi la sua visione sui link della rete, nel secondo ogni nodo comunica ai suoi vicini la sua visione del costo di trasmissione dei link.

Algoritmi routing globale – Link state protocol

Gli algoritmi Link State(LS) sono globali, ovvero prevedono che la topologia di rete e i costi di ogni link siano noti a tutti:

1. ciascun nodo calcola lo stato dei link ad esso connessi

2. ciascun nodo periodicamente trasmette identità e costi dei suoi link a tutti

3. ciascun nodo calcola i cammini di costo minimo verso gli altri noti della rete tramite l’algoritmo di Dijkstra

Periodicamente vengono inviati in broadcast, su tutti i link del nodo, dei pacchetti LSP che contengono le informazio di:

* ID del nodo

* Lista dei vicini e costo dei rispettivi link

* Informazioni aggiuntive → numero di sequenza per accorgersi di errori e time-to-live(TTL) per evitare di usare informazioni vecchie e quindi non affidabili

Propagazione dei pacchetti LSP

Quando il nodo i riceve un pacchetto LSP dal nodo j, se il pacchetto LSP proveniente da j è valido(TTL non scaduto e numero di sequenza successivo all’ultimo ricevuto) salva il valore nella tabella di routing e inoltra una copia di questo pacchetto a tutti i link connessi al nodo i(ad eccezione del link da cui ha ricevuto il pacchetto), altrimenti scarta il pacchetto.

Forward search algorithm di Dijkstra

È un algoritmo iterativo, alla k-esima iterazione, il nodo i conosce il cammino di costo minore verso k nodi destinazione. Si definiscono:

* c(i,j) costo del link tra nodo i e nodo j

* D(v) costo minimo del cammino verso il nodo v(minimo relativo alla iterazione corrente). D(v) = ∞ se il costo del link non è noto.

* p(v) immediato predecessore di v lungo il cammino a costo minimo verso v

* N gruppo di nodi il cui cammino di costo minore è noto definitivamente

L’algoritmo consiste in una fase di inizializzazione seguito da un ciclo eseguito una volta per ogni nodo del grafo. Al termine saranno stati calcolati i cammini minimi dal nodo u verso tutti gli altri nodi

pseudocodice dell’algoritmo

Inizializzazione

N={u}

per tutti i nodi v

se v è adiacente a u /* conosco il costo */

D(v)=c(u,v)

altrimenti D(v)=∞



Il ciclo è strutturato in 3 fasi:

1. calcola il costo D(i) per tutti i nodi i adiacenti non presenti in N

2. aggiunge a N il nodo w con il minimo costo D(w)

3. aggiorna D(v) per ciascun nodo v adiacente a w, non in N: D(v)=min{D(v),D(w)+c(w,v)}

4. questo ciclo viene fatto finché tutti i nodi del grafo sono nell’insieme N

D(v)=min{D(v),D(w)+c(w,v)}  → il nuovo costo verso v è il vecchio costo verso v oppure è il costo del cammino verso w più il costo da w a v.

Esempio funzionamento algoritmo

![](https://lh7-us.googleusercontent.com/Doo7999a3lozLTgFY9S0huO7ulSQuG2g70pVrfHNeiPGNXocb_yV3F4HXNRyhIOBRBXqBsjjNgWP5qOZ_7U-gxaXjwhkbcMsQKToMufx45AVgkeZLk3E8XjBCdz2glkK1tiWiDz-vhtQhxPlAMG3CMrePx3jxeM)  







|       |     |            |            |            |           |           |
| ----- | --- | ---------- | ---------- | ---------- | --------- | --------- |
| Ciclo | N   | D(B), p(B) | D(C), p(C) | D(D), p(D) | D(E),p(E) | D(F),p(F) |
| 0     | A   | 3,A        | 5,A        | 1,A        | ∞         | ∞         |

Al primo passo sono sul nodo A e cerco il percorso diretto per arrivate agli altri nodi, e per ogni nodo segno il peso e nodo da cui parto. I nodi E e F non sono raggiungibili direttamente tramite A, quindi segno ∞ in modo da sapere che il percorso ha costo massimo/non è raggiungibile.



![](https://lh7-us.googleusercontent.com/GfCY8N1HV48dmp4BZvfK3Dw8IcGOGAlz8l6mp8Z9qPB2JqAIf_TfzBFP5MtgykX2XxdnBbE0xaN-FTT0s4BEOqs46xqShMy-DIlMQCERPVoMFfnfZNbSoTHefXV5w7nawoDObkpjij-YCjRWTHWHtxggiKgFFRg)  







![](https://lh7-us.googleusercontent.com/SNtD3cqkbwbC0tvwzjWEHFHVMpiNRP_3a0x7BYNm12zz3sl8hUHEsyDdaG5ed86NCNg6RPAoakp70DZOvxTKqzt4K2cr3oTL72TYaEg8hry8alKwtWwUomKhp6KMUomfjr-dAhwD03XzF1VwdcVxpe_rd_ilAEs)  







|       |     |            |            |            |           |           |
| ----- | --- | ---------- | ---------- | ---------- | --------- | --------- |
| Ciclo | N   | D(B), p(B) | D(C), p(C) | D(D), p(D) | D(E),p(E) | D(F),p(F) |
| 0     | A   | 3,A        | 5,A        | 1,A        | ∞         | ∞         |
| 1     | AD  | 3,A        | 4,D        | <br>       | 2,D       | ∞         |

Al secondo ciclo provo ad arrivare sugli altri nodi passando attraverso D. Il percorso per raggiungere B dal nodo D ha lo stesso peso, ma bisogna contare anche il peso per raggiungere D dal nodo A, quindi il totale sarebbe 4, mentre dal nodo A il peso è 3, che è minore quindi si tiene quello. Per raggiungere il nodo C partendo da A si peso uguale a 5, mentre partendo da D si ha peso 3 + 1(peso per raggiungere D da A), quindi il totale è 4, quindi lo aggiorno e tengo quello. Il nodo E ora è raggiungibile, peso 1 + 1(peso per raggiungere D da A).

![](https://lh7-us.googleusercontent.com/veRXHvH0Hi1F3_6b90IoGezZOI_r3SgKE9itY9qL0a4aAACyLj_A9Q0HqjzwqesCte9KfqtxV41AZemUovVA9TUZnB4GvqvQxn5an_XT7CxAT5Te-GNXUnPqEwE5Fa_pU-VQQMHPvN76urIoCaVW9AmXg5umZ9c)  







|       |     |            |            |            |           |           |
| ----- | --- | ---------- | ---------- | ---------- | --------- | --------- |
| Ciclo | N   | D(B), p(B) | D(C), p(C) | D(D), p(D) | D(E),p(E) | D(F),p(F) |
| 0     | A   | 3,A        | 5,A        | 1,A        | ∞         | ∞         |
| 1     | AD  | 3,A        | 4,D        | <br>       | 2,D       | ∞         |
| 2     | ADE | 3,A        | 3,E        | <br>       | <br>      | 4,E       |

Provo a raggiungere gli altri nodi attraverso il nodo E. Per raggiungere A non c’è un percorso migliore di quello salvato, quindi tengo quello. Per raggiungere C ho un percorso migliore 1 + 1 (per arrivare ad E da D) + 1 (per raggiungere D da A), quindi lo aggiorno. Ora posso raggiungere anche il nodo F.

![](https://lh7-us.googleusercontent.com/NufxQy0d7-Yq-KZVf7jsKMd9EgHmtETBy5_QOsiL7lwsciRm61FfI_oEdHmN1e3h_e9jH2jh986kukqZyLH-biooB8XbctbR17y2WNqKSgXOcBdAbmHTx-hKcCSngLkZ2nLACx34Q2E_40H_bqSo3qukhGSp4Lg)  







|       |      |            |            |            |           |           |
| ----- | ---- | ---------- | ---------- | ---------- | --------- | --------- |
| Ciclo | N    | D(B), p(B) | D(C), p(C) | D(D), p(D) | D(E),p(E) | D(F),p(F) |
| 0     | A    | 3,A        | 5,A        | 1,A        | ∞         | ∞         |
| 1     | AD   | 3,A        | 4,D        | <br>       | 2,D       | ∞         |
| 2     | ADE  | 3,A        | 3,E        | <br>       | <br>      | 4,E       |
| 3     | ADEB | <br>       | 3,E        | <br>       | <br>      | <br>      |

Provo a raggiungere gli altri nodi attraverso B. Tutti i percorsi sono peggiori di quelli già trovati quindi non ne salvo neanche uno.

![](https://lh7-us.googleusercontent.com/O4w8ffK7LXHKyuigNItwWrazfkZQzKSGaVXb9yocvB1HDoQrqF1jACxjkS60TR77cqmXgO30mIiC9JkO-5t3V59dIKyl6Ab1XLk8-0Gy1rmyUv8o8myc4lahLbkwygQzOE4NWGtQt89Zz5GaCQUomn8c_j3YSvI)  







|       |       |            |            |            |           |           |
| ----- | ----- | ---------- | ---------- | ---------- | --------- | --------- |
| Ciclo | N     | D(B), p(B) | D(C), p(C) | D(D), p(D) | D(E),p(E) | D(F),p(F) |
| 0     | A     | 3,A        | 5,A        | 1,A        | ∞         | ∞         |
| 1     | AD    | 3,A        | 4,D        | <br>       | 2,D       | ∞         |
| 2     | ADE   | 3,A        | 3,E        | <br>       | <br>      | 4,E       |
| 3     | ADEB  | <br>       | 3,E        | <br>       | <br>      | <br>      |
| 4     | ADEBC | <br>       | <br>       | <br>       | <br>      | 4,E       |

Ora mi sposto sul nodo C e provo a raggiungere gli altri, ma nessun percorso è migliore di quelli già trovati.



![](https://lh7-us.googleusercontent.com/rD1EXcFYKJmMF4Vf3HdqNMLaR8V1b97fqnuk0X3FebtkElZK0ufE_syad6H-lFIhe5rcNkK0uWCzPpJQ64lG_muQdSVzhMXGh5Pj7cEfpkt6Qdh16lR7CD5V5SnfsCicmauNZ89u-nEGUm0tTfJQ0fqs4TaDsLY)  







|       |        |            |            |            |           |           |
| ----- | ------ | ---------- | ---------- | ---------- | --------- | --------- |
| Ciclo | N      | D(B), p(B) | D(C), p(C) | D(D), p(D) | D(E),p(E) | D(F),p(F) |
| 0     | A      | 3,A        | 5,A        | 1,A        | ∞         | ∞         |
| 1     | AD     | 3,A        | 4,D        | <br>       | 2,D       | ∞         |
| 2     | ADE    | 3,A        | 3,E        | <br>       | <br>      | 4,E       |
| 3     | ADEB   | <br>       | 3,E        | <br>       | <br>      | <br>      |
| 4     | ADEBC  | <br>       | <br>       | <br>       | <br>      | 4,E       |
| 5     | ADEBCF | <br>       | <br>       | <br>       | <br>      | <br>      |

Infine mi sposto sul nodo F e provo a raggiungere gli altri nodi ma sono i percorsi non sono ottimali.













![](https://lh7-us.googleusercontent.com/rD1EXcFYKJmMF4Vf3HdqNMLaR8V1b97fqnuk0X3FebtkElZK0ufE_syad6H-lFIhe5rcNkK0uWCzPpJQ64lG_muQdSVzhMXGh5Pj7cEfpkt6Qdh16lR7CD5V5SnfsCicmauNZ89u-nEGUm0tTfJQ0fqs4TaDsLY)  





|               |     |        |     |     |        |     |
| ------------- | --- | ------ | --- | --- | ------ | --- |
| Tabella per A | A   | B      | C   | D   | E      | F   |
| X             | 3,A | 3,E(D) | 1,A | 2,D | 4,E(D) |     |

Alla fine del ciclo, ottengo un tabella con il percorso ottimale per raggiungere tutti i nodi partendo da A. Per raggiungere il nodo C e il nodo F devo passare attraverso il nodo E, e di conseguenza attraverso il nodo D. Questo ragionamento va fatto per ogni nodo. La tabella vale solo per il nodo A.

Algoritmi distance vector – algoritmo Bellman-Ford

Sono algoritmi usati nel primo periodo di internet(ARPANET). È un algoritmo adattivo rispetto ai cambiamenti di stato della rete, iterativo e asincrono. Distance → costo delle varie destinazioni, vector → per ogni destinazione c’è una direzione.

Per calcolare il costo minimo tra x e y si utilizza la formula di Bellman-Ford→

Dx(y)=minv{c(x,v)+Dv(y)}, dove minv è calcolato tra tutti i nodi vicini v del nodo x.

La formula può essere tradotta → tra tutti i nodi v adiacenti al nodo x, il percorso da scegliere per andare a y è quello che mi porta con il minor costo da v a y, a meno che(da cui la considerazione del primo addendo) il costo tra x e v sia talmente alto che mi conviene percorrere altre strade.

Come si calcola il cammino minimo da A a C?![](https://lh7-us.googleusercontent.com/DhE2_eIqZGT8hnp7YYSQmuJsdfA3sd5cDN7tpgh_frwo3un6Gv5KbXbEUFpb-4kbgx8gCq6WcKmeJeG2OzyyO-qmOX-1oj_UvuuqS6vH4n1716oLOPadrl6RrCLZqiK5H8qYSt5k2SLiHz6yT8F5AWWthwy3q7Q)

Ogni nodo x:

* aggiorna il proprio vettore(di distanze e direzioni) in risposta a variazioni di costi sui link adiacenti

* invia un aggiornamento ai nodi adiacenti se il proprio vettore cambia
  
  
  
  

Ogni nodo x mantiene una tabella di routing con i seguenti dati:

* c(x,v) → costo del link tra nodo x e nodo v in N

* c(x,v) = ∞ → se non c’è link tra nodo x e nodo v in N

* Dx=[Dx(y):y in N] → distanze e direzioni del nodo x verso tutti i nodi y nella rete N

* Dv=[Dv(y):y in N] → distanze e direzioni dei vicini v di x

Pseudocodice dell’algoritmo:

Start

per tutte le destinazioni yN:

Dx(y) = c(x,y) se y è adiacente

Dx(y) = ∞ se y non è adiacente

invia il vettore Dx=[Dx(y) | yN] a ogni vicino v

Loop

Attendi(finchè il costo di un collegamento verso qualche vicino v cambia o ricevi un nuovo vettore da un vicino v)

per ogni destinazione y in N:

Dx(y)=minv{c(x,v)+Dv(y)}

se Dx(y) è cambiato per qualche destinazione y

invia il vettore Dx=[Dx(y) | yN] a tutti i vicini → poi torna a inizio loop



Esempio – Come si aggiorna lo stato

Le immagini sono numerate da 1 a 8 da destra a sinistra.



![](https://lh7-us.googleusercontent.com/ed6_DdBbxfmdDLot1MXD5m3oB5OcT_Gi_OHZSEtGmryN8v7E7Diyokm6u-x_TTtuvOWf1DPnAgYKEJO5QwYX4sU_jadExKejLPJhrqwiuEdG6DWtVQkz6_JWNO13fGa5hWkTNhxQO8ckWSi3mLfZC0r4Qn9JBqw)![](https://lh7-us.googleusercontent.com/C1NaAWc_idZflBu3YMpWsax3iqvnhEfIldZnHIYtLXF2g8n2enahdAHzxZQDwGZRQ6UjsT2RKhXWKFG2fxt8Lzjr7vt9wol5zQ_twKQHfdmccIsyltHxYyb1xAGvhbGeEES4Ce2vzzx2g8AKngkclKpiF40HK5E)  

![](https://lh7-us.googleusercontent.com/aGKE9b8ip3sDJTohVdiI-3bbnffRLymayPW3ogjD12MstkwwjBdlabIRZqEF751mJNGvrEVhKbVI6ms-ilL5UIJ1qFCdJaL9ezfxkd97QWQOWUWOsXPpjj8UulgSAs_ag5pkNQ5glmA65_nhC4r6YfbKCkO0HXc)![](https://lh7-us.googleusercontent.com/4VSvG-1bMuNoZiBbLoXQV8rZMEex_k_c8fDsLl7SHjeCIR-kRGODJG8U27tZrBbJv3lZ8S5OxxB8Sl6yHlAp_HBxPN1Arknx1bYVdan-X-EZHduC77qrfh2-ubRqpy5gfN2D96ocg9w-f3p8ZdhRyh1ohix7Cwg)![](https://lh7-us.googleusercontent.com/uPBfsyBgIBRT-vhRzu0repwnpoWOw1g5NAl_-Z6nzP11JyNUXxVDvITv0aklt73ppLmotMIHB6Pmp6nWSWZ1R_L6_0J_CY8mIx5XdT_rWcBokAH-atb5rftLg8QUxjpHYgVKEDQu-D5bmQRXspWQkczGouJgQLA)![](https://lh7-us.googleusercontent.com/KDy6tHKAd7FeptYa4Fr4ltd67W4svzfyu8KLUP8WTvwWj3enc9z6r-WYn0p8n5QLlzCrlxyYPlsTlAHL2wPBNkvq-BQk1J_cwVAVTW6kgB24Rf9u0d2lW8HRjXYb7ZPB7nF1kl9mk1xVid3mn7ilRZZdRTZA6YM)![](https://lh7-us.googleusercontent.com/eQho1h2P8bD4_qN7IFXNiX3wnyGJv_cWTvQDln6rxKrnvxv7negLaepEIMW5kpKWer27XagBF-Z3U0jhyMb7tVwFKM1n0BDNTjersoEa0-Frkk1zORR-CBuArkF-49iwKxrLJh9wPhA8bW2goku0POFb4HldOKQ)![](https://lh7-us.googleusercontent.com/ZdZRO3TT9uYJG48y0qcH_KghA8zDvbplptUZLElJ8Zhpn3gJcVE5Gbn8rFW-L6BgDCm8ee_VoWr8nmXfrYfRB9rY5FECUpIROhZ6wos_MYFmX4TiPZom7PMaZhe3lDevV_dhvv9otIn1knJb5cx-1xMvFxxwg3k)  







L’immagine numero 1 contiene le distanze di partenza. Ipotiziamo di iniziare dal nodo D. il nodo D dice “ i nodi A e B non sono raggiungibili direttamente da me, mentre i nodi C D E li posso raggiungere”, salva i costi dei percorsi verso gli altri nodi nel vettore e spedisce il vettore a E. Il nodo E riceve il vettore e scopre che può raggiungere il nodo C passando attraverso D, quindi aggiorna il suo percorso verso C, passando da ∞ a 4(2 per andare a D e 2 per andare a C).

Il nodo A riceve il vettore di distanze da B e aggiorna il costo solo per il nodo C(immagine 4 e 5). A riceve il vettore di distanze da E e aggiorna i costi di C e D(immagini 6 e 7). Questo procedimento viene eseguito finché tutti i nodi non hanno il costo verso tutti gli altri nodi, ovvero finché nel vettore delle distanze di ogni nodo contiene ancora ∞.



L’algoritmo di Bellman-Ford ha un immediata ricaduta pratica. Serve a calcolare i valori della tabella di routing di ciascun router(nodo).

La tabella di routing del nodo x ha:

* una riga per ogni nodo destinazione della rete(router o AS)

* tante colonne quanti sono i nodi adiacenti al nodo x

* i costi di cammino come elementi della tabella e la conseguente direzione

Grazie alla tabella di routing, nel momento in cui arriva un pacchetto con un indirizzo destinazione, il router può subito decidere verso quale link inoltrarlo.

Tabella di routing del nodo E. Partendo da E, le righe indicano la destinazione mentre le colonne indicano il prossimo nodo da toccare prima di arrivare a destinazione. Ad esempio prima riga-seconda colonna → partendo dal nodo E voglio arrivare al nodo A ma passando da B, esistono 2 percorsi → EBA, con costo 8(EB)+7(BA) = 15, mentre il secondo percorso EBCDA, con costo 8(EB)+1(BC)+2(CD)+2(DE)+1(EA) = 14. Di conseguenza il secondo percorso ha costo minore, anche se tocca più nodi, e si salva quello.![](https://lh7-us.googleusercontent.com/YOZIImEaaYB2GgvlLakCOMH9DHbfmv4h7H-PLhfhjfLKd9VOpulODQcjiv1QjD3Du6WPavoUZnuPmpCF_Qu04-JAYIe0Bda6rigqcc23GG6qKSj5dt2j6krq8qRNbYgPmql-8ilTBCNyH6Lk-IoXRKD5m7aF-S8)

Cosa succede se un link si degrada, ovvero aumenta il suo costo? I nodi che vertono su quel link ricalcolano il loro vettore con il nuovo costo del link, aggiornano la propria tabella di routing e trasmettono il nuovo vettore ai vicini, ciascun nodo ricalcolerò il proprio vettore, e iterativaemente lo invierà ai nodi vicini.

Nella realtà esistono più di 1 miliardo di host e milioni di router, è possibile creare una tabella che contenga tutti i router di internet come destinazione? No, infatti si utilizzano tecniche di aggregazione indirizzi classless.

Il terzo problema consiste nel effetto rimbalzo. Consideriamo una rete con A B C, con A collegato a B e C, B collegato a A e C, C collegato a A e B. il link tra A e B ha un problema e aumenta il proprio costo. Di conseguenza B aggiorna le distanze per A e manda il vettore aggiornato a C, C aggiorna(se necessario) e manda il vettore a B. In questo modo si ha un rimbalzo tra B e C.

L’effetto rimbalzo si crea, in questo esempio, quando la distanza da B a A cresce molto, quindi B sceglie C come prossimo hop per A, ma il percorso implicito da C verso A include B. Le tabelle di B e C si aggiornano gradualmente, ma si crea un loop che proseguirà fino a quando C decide di considerare gli altri percorsi. Un pacchetto che arrivi a B o C durante questo loop rimbalzerà tra questi nodi(almeno se non si azzera per il TTL).

Per evitare questo problema si devono selezionare percorsi senza cicli, un modo per farlo è → ogni aggiornamento del cammino minimo verso un nodo riporta l’intero percorso, se un router vede se stesso nel percorso, lo scarta.

Differenze tra i due tipi di algoritmi – Link State(LS) vs Distance Vector(DC)

LS → piccola dimensione dei messaggi ma il numero di messaggi è molto grande

DV → dimensione dei messaggi molto grande ma il numero di messaggi è molto piccolo.

LS risulta più robusto in quando calcola i percorsi in maniera indipendente da ogni altro nodo, protezione dai guasti ai router, mentre DV si basa sugli altri router, quindi in caso di calcolo sbagliato, l’errore si propaga in tutta la rete. Non esiste un vincitore, i LS(globali) tendono ad essere utilizzati all’interno degli AS menre i DV(distribuiti) sono utilizzati per il routing tra i diversi AS.

Router

Il router ha come compito quello di instradare i pacchetti da un qualsiasi host ad un qualsiasi altro host → MOLTO COMPLESSO.

Il problema viene diviso in due sottoproblemi:

1. ad ogni pacchetto in ingresso, determinare il link di uscita in modo che il pacchetto si avvicini alla destinazione(IP forwarding).

2. Mantenere informazioni aggiornate per risolvere il primo problema(protocollo di routing)

I router si passano i pacchetti come una “patata bollente” → bisogna conoscere solo l’indirizzo del prossimo salto(hop). Il routing non ha sempre successo → router sovraccarichi scartano pacchetti(limite fisico) o ci possono essere errori di routing(errore logico).

L’architettura di un router è formata da 4 componenti fondamentali:

* porta d’ingresso

* commutatore

* processore di routing

* porta di uscita

IP Forwarding → meccanismo con cui un router trasferisce i datagram da un’interfaccia d’ingresso a quella in uscita, è eseguito da ogni router. Il next-hop router appartiene a una rete alla quale il router è collegato direttamente.

Per l’inoltro dei pacchetti, l’indirizzo di destinazione è estratto dall’header del datagram ed è usato come indice nella tabella routing.

Ogni host e ogni router ha una tabella di routing in cui ogni riga fornisce il next-hop per ogni possibile destinazione. In realtà una riga della tabella di routing fornisce informazioni per molte destinazioni con l’utilizzo di tecniche di aggregazione. Tipicamente un tabella non ha più di 50000/60000 righe.

Tecniche di aggregazione:

1. utilizzo dello stesso netid per un insieme di indirizzi IP di destinazione che condividono lo stesso next-hop, cioè le reti per le quali il next-hop è rappresentato dallo stesso router.

2. Nel caso in cui gli indirizzi di rete che possono essere aggregati non condividano lo steso next-hop, si aggregano gli indirizzi aggregabili con prefissi diversi e seguendo il principio del longest prefix matching

3. si organizzano le tabelle creando un’organizzazione gerarchica che riflette l’architettura di internet

4. è possibile sfruttare il routing geografico, sapendo che le classi di indirizzi IP vengono assegnati in funzione della posizione geografica continentale

5. utilizzo del router di default: si definisce un router di default comune a più indirizzi di destinazione.

Notazione Classless(CIDR)

Con questa notazione di elimina il concetto di indirizzamento a classi fisse A-B-C-D, l’indirizzo IP non ha più confine fisso tra netid e hostid. Si utilizza la notazione slash per indicare il numero di bit usati per netid a.b.c.d/x → 197.8.3.0/24

Per memorizzare le maschere si utilizza un binary tree:

1. si crea una tabella con due colonne, nella prima compare la maschera, nella seconda un codice univoco per la maschera

2. le righe sono messe in ordine crescente di maschera e viene associato il prefisso più piccolo che rende univoca la n-esima bit mask

3. l’albero è realizzato in forma binaria ponendo come figli sinistri i biit a 0 e figli desti i bit a 1

Esempio

con un prefisso 111 si scende a destra 3 volte, partendo da root. Mentre con un prefisso 101 si scende a destra poi a sinitra poi a destra sempre partendo da root.

Se esiste il percorso esiste anche la maschera e posso instradare il datagram, in quanto su ogni foglia è presente l’indirizzo di rete associato a quel prefisso univoco.

Il routing può essere statico → la tabella non è modificata dal router, spetta all’amministratore di rete inserire o modificare la tabella, si utilizza per reti piccole e con pochi cambiamenti, in quanto la rete non reagisce automaticamente ai cambiamenti.

Routin dinamico → la tabella è modificata dal router al variare delle condizioni sulla rete, utilizzando protocolli come RIP, OSPF, BGP.

Caratteristiche del forwarding IP

* Indipendenza dal mittente → il next-hop routing non dipende dal mittente del pacchetto o dal cammino che il pacchetto ha attraversato fino a quel momento.

* Routing universale → la tabella di routing deve contenere un next-hop router per ciascuna destinazione

* Routing ottimo → il next-hop router è scelto in modo da minimizzare il cammino verso la destinazione → utilizzo degli algoritmi di routing

Funzionamento del router

Estrae l’indirizzo IP del destinatario D dall’header del pacchetto e determina il suo netid N, poi:

1. Se N corrisponde ad una rete connessa direttamente al router, consegna il pacchetto al destinatario D sulla rete

2. Se la tabella contiene un router per la rete N, invia il pacchetto al next-hop router specificato nella tabella

3. Se la tabella contiene un router di default, invia il pacchetto a quel router

4. Altrimenti, si verifica un errore di routing.

Next-hop forwarding → il router possiede l’informazione sul salto successivo(next-hop) che il pacchetto deve compiere per giungere a destinazione. Il next-hop router appartiene a una rete alla quale il router è collegato direttamente.

Le subnet mask servono soprattutto per facilitare il routing dei pacchetti all’interno della rete amministrativa.

Nella realtà i router non eseguono lo stesso algoritmo di routing, per diversi motivi:

* scalabilità → all’aumentare del numero di router, se tutti dovessero essere considerati per il router, il costo degli algoritmi diventerebbe proibitivo

* autonomia amministrativa → un’organizzazione definita AS dovrebbe/vorrebbe scegliere autonomamente come amministrare il traffico tra i propri router e le proprie reti.

I router vengono aggregati in regioni o AS. In pratica un AS è un insieme di nodi e di router gestiti da un’unica entità di controllo centrale(stesso ISP). Ciascun AS ha un numero identificativo tra 1 e 64511. I numeri compresi tra 64512 e 65535 sono riservati.

Per il routing all’interno(Intra-AS) degli AS, i router utilizzano qualche Interior Gateway Protocol(IGP), dove i router di un AS possono possedere un’informazione completa su tutti gli altri router. Per il routing verso altri AS(Inter-AS) viene utilizzato qualche Exterior Gateway Protocol(prima EGP, poi BGP).

Le politiche di routing sono le regole per decidere come instradare il traffico. Ogni AS vuole poter decidere le proprie politiche e magari non farle conoscere agli altri.

Protocolli Intra-AS: RIP(distance vector, distribuito), OSPF(link state, centralizzato), Enhanced Inerior Gateway Routing Protocol(algoritmo proprietario CISCO, distribuito).

Protocollo Inter-AS: BGP(distribuito), standard utilizzato per il routing tra diversi AS.

Protocollo RIP

È un protocollo distribuito basato sul Distance Vector → propago quello che so su tutta la rete solo ai vicini.

Per il calcolo dei costi dei percorsi si utilizza il numero di salti da fare per raggiungere un certo nodo, ovvero ogni salto verso un’altro router costa 1. Il costo massimo di un percorso è di 16 salti, ovvero il limite massido del diametro di un AS.

I router adiacenti si scambiano i vettori distanze ogni 30 seondi. Un router può anche chiedere informazioni sul vettore distanze dei router adiacenti tramite un messaggio RIP request.

Se un router non riceve messaggi da un suo vicino dopo 180 secondi lo considera irraggiungibile.

I percorsi verso questo router vengono marcati con il flag U(unreacheable) e vengono ricalcolati e modificati i vettori distanze e tabelle di routing.

Il protocollo RIP funziona bene con reti non molto grandi, stabili e veloci.

È utilizzato in AS piccoli.

Protocollo OSPF

OSPF → Open Short Path First

È un algoritmo globale di tipo link state. Ha funzioni migliorative rispetto a RIP e quindi è adatto a reti più grandi e in cui lo stato della rete tende a cambiare dinamicamente.

È utilizzato in AS medio grandi.

Essendo basato sul Link State centralizzato, la sua idea di base è “tell the world about the neighbors”, ovvero fai sapere a tutti le informazioni dei vicini.

La topologia e costi sono noti a ogni nodo, calcola l’albero dei cammini di costo minimo mediante Dijkstra, memorizza l’albero nel database e lo distribuisce a tutti i router, invia in broadcast eventuali aggiornamenti di costo con i vicini ai router di tutto l’AS, i messaggi OSPF viaggiano su IP, il database che contiene l’albero viene inviato ogni 30 minuti anche se non viene cambiato.

Caratteristiche del OSPF:

* Sicurezza → può crittografare i messaggi

* Percorsi multipli con costo uguale → possibilità di usare più percorsi per instradare il traffico(nel RIP si usa un percorso solo)

* Supporto integrate instradamento unicast e multicast

* Struttura gerarchica degli AS → possibilità di strutturare grandi domini di instradamento in gerarchie di AS.

Protocollo BGP

Viene introdotto per sostituire EGP. È un protocollo per la comunicazione tra AS.

BGP → Border Gateway Protocol. È complesso ma fondamentale per il funzionamento di Internet, in quanto è il protocollo delle dorsali Internet per muoversi da un AS a un altro AS in modo completamente decentralizzato. È utilizzato dagli ISP. Utilizza un algoritmo Path Vector(non usa distance vector ne link state). Con il Path Vector ogni routing update contiene informazioni sull’intero cammino verso la destinazione attraverso gli AS.

Utilizza il protocollo TCP per connetterei i router perr(porta 179).

Funzionalità principali del BGP:

* Scambiare informazioni di raggiungibilità tra AS confinanti, detti peer.

* Propagare le informazioni di raggiungibilità a tutti i router all’interno di un AS → meccanismo distribuito basato su Path Vector

* Determinare i percorsi migliori in base a informazioni di raggiungibilità.

Il BGP utilizza due sessioni, una esterna(E-BGP) tra router di AS diversi, una interna(I-BGP)  tra router dello steso AS.

I Transit router gestiscono il traffico I-BGP, mentre i Border Router gestiscono il traffico E-BGP.

I BGP implementa le politiche scegliendo percorsi tra diverse alternative e controlloando l’invio di advertisement ad altri AS.

“Annunciare un prefiso”(prefix advertisement) da parte di un AS equivale alla “promessa” di questo AS di inoltrare i pacchetti su un percorso verso il prefisso di destinazione.

I border router hanno la responsabilità di inoltrare i pacchetti a destinazioni esterne all’AS.

Un router può venire a conoscenza di più di un percorso verso un prefisso, ma deve selezionarne uno. Quando un border router riceve un prefix advertisement utilizza le policy locali per decidere se accettare o scartare l’annuncio.

Gestione dei guasti

Guasto di un link E-BGP → se viene interrotto i link tra due AS, viene interrotta la connessione E-BGP e i percorsi che utilizzano quel link sono rimossi dalle tabelle di routing.

Guasto di un link I-BGP → se viene interrotto un link tra due router all’interno dello stesso AS, i due router possono comunicare attraverso gli altri router in modo indiretto.

### Altri protocolli a livello 3

Oltre al livello 3 esistono altri protocolli che operano a quel livello:

* IPv6

* ICMP → protocollo accessorio per la gestione del routing

* IGMP → è un protocollo per la gestione dei gruppi multicast

* IPSec → per realizzare Virtual Private Network (VPN), ovvero connessioni cifrate su scala geografica

ICMP → Internet Control Message Protocol → servizio per la gestione di reti, è il protocollo alla base di ping e traceroute. È utilizzato da host, router e gateway per comunicare informazioni riguardanti il livello di rete, in particolare errori.



Gestione indirizzi IP

IANA → gruppo di Jon Postel → giurisdizione degli IP. La distribuzione era effettuata da INTERNIC. Dal 1998 si fondono e nasce ICANN.

Un network ID, corrispondente a un insieme di indirizzi IP, è assegnato a organizzazioni e tipicamente agli ISP da IANA/ICANN. Gli host ID sono assegnati localmente a ciascun host dall’amministratore di rete della organizzazione.

## 4_Livello di trasporto

Livello Trasporto – servizi del livello trasporto e protocollo UDP

Livello 4 → trasport

Il livello trasporto estende il servizio di consegna con impegno proprio del protocollo IP tra due host terminali ad un servizio di consegna a due processi applicativi in esecuzione sugli host.

IL TCP NON È UN PROTOCOLLO DI TRASPORTO. È un controsenso rispetto a quello scritto sopra ma è così. Il TCP è solo un componente del livello di trasporto della suite TCP/IP. L’altro componente  è costituito dal protocollo UDP.

Rispetto all’IP aggiunge la multiplazione e demltiplazione dei messaggi tra i procesi e il rilevamento dell’errore mediante checksum(comuni sia a UDP che TCP)

Il rilevamento dell’errore non comprende la correzione.

TCP aggiunge in più il trasferimento affidabile dei dati e il controllo di congestione.

Multiplazione e Demultiplazione

Il protocollo IP non consegna i dati tra i processi applicativi in esecuzione sui nodi terminali → ci pensa il protocollo di trasporto.

Ogni segmento dello strato di trasporto possiede un campo contenente l’informazione usata per determinare a quale processo deve essere consegnato il segmento → demultiplazione → la demultiplazione avviene al late del nodo destinatario.

La creazione sei segmenti provenienti dai messaggi di diversi processi applicativi → multiplazione → la multiplazione avviene dal lato del nodo mittente.

### UDC e TCP

includono due campi speciali nell’header del segmento → numero di porta del mittente e numero di porta del destinatario. Permettono di identificare in modo univoco i due processi applicativi, residenti su due nodi terminali e comunicanti tra loro.

I numeri di porta sono a 16 bit compresi tra 0 e 65535.

### HTTP → 80, Telnet → 23, SMTP → 25, DNS → 53

Quando si realizza un servizio di rete ad ampia diffusione è necessario assegnarli un nuovo numero di porta. Occorre sia il numero di porta del mittente sia quello del destinatario per distinguere processi dello stesso tipo ed in esecuzione negli stessi istanti.

Le porte tra:

* 0-1023 → well known port → NON DEVONO essere usate senza una precedente autorizzazione da IANA. Possono essere utilizzate solo da processi con privilegi di root o simili.

* 1023-49151 → register ports → l’uso di queste porte è registrato a beneficio degli utenti della rete, ma non esistono vincoli restittivi. Tuttavia NON DEVONO essere utilizzate senza una precedente autorizzazione da IANA. Possono essere utilizzate da qualsiasi processo.

* 49152 -65535 → dynamic or private ports → NON è applicato alcun controllo per cui possono essere utilizzate liberamente.

Assegnazione dei numeri di porta nel modello client/server

1. Numero di porta destinatario nel pacchetto inviato dal client al serrver corrisponde al numero di porta del servizio richiesto(ad esempio 80 per HTTP)

2. Numero di porta del mittente nel pacchetto inviato dal client al server corrisponde ad un numero di porta scelto tra quelli non in uso sul client

3. Numero di porta del mittente del pacchetto inviato dal server al client corrisponde al numero di porta del servizio richiesto

4. Numero di porta del destinatario del pacchetto inviato dal server al clinet corrisponde al numero di porta indicato dal client nel messaggio precedentemente inviato

Due processi client su host diversi che comunicano con lo stesso servizio applicativo(Server) sono sempre distinti dall’indirizzo IP e dalla porta sorgente.

Due processi client su host diversi che comunicano con lo stesso servizio applicativo(Server) ed eventualmente utilizzano la stessa porta sorgente, sono distinti in base al loro indirizzo IP.

Due processi client sullo stesso host che comunicano con lo stesso servizio applicativo(Server), non essendo distinti in base al loro indirizzo IP(stessa macchina, stesso indirizzo) useranno diversi numeri di porta sorgente, assegnati univocamente dal sistema operativo.

Gli indirizzi a livello IP consistono in una coppia di indirizzi, sorgente e destinazione, mentre per il livello trasorto(UDP,TCP) la coppia è distinta dalle porte sorgente e destinazione. L’univocità di ciascun pacchetto in Internet è data dalla quadrupla [(IP sorg, porta sorg),(IP dest, porta dest)].

Protocollo UDP

UDP = User Data Protocol, è un protocollo leggero dotato delle funzionalità minime del trasporto:

* servizio di multiplazione/demultiplazione → aggiunge al messaggio proveniente dal livello applicativo il numero di porta del mittente e del destinatario

* controllo di errore → include nell’header un campo di checksum

Il servizio UDP non ha:

* Servizio di consegna garantito → i pacchetti possono essere persi, duplicati, consegnati senza ordine

* servizio senza connessione

Il pacchetto UDP o user datagram (32 bit), è incapsulato in un datagramma IP, nella parte di dati.

|                                    |                           |
| ---------------------------------- | ------------------------- |
| Numero porta mittente              | Numero porta destinatario |
| Lunghezza                          | Checksum                  |
| Dati dell’applicazione (messaggio) |                           |

* Numero di porta mittente (16 bit)

* Numero di porta destinatario (16 bit)

* Lunghezza (16 bit) → dimensione in byte del pacchetto

* lunghezza = header + dati

* header: dimensione pari a 8 byte

* checksum

* dati → contiene il messaggio fornito dal livello applicativo

### Checksum

Scopo → individuare errori nel pacchetto trasmesso

Mittente → tratta i contenuti del pacchetto come sequenza di numeri interi a 16 bit. Il checksum è la somma dei contenuti del pacchetto con complemento a 1. Il mittente invia il valore del checksum nel campo checksum del pacchetto UDP.

Destinatario → calcola il checksum del pacchetto ricevuto. Controlla se il valore checksum calcolato è uguale a quello ricevuto nel pacchetto → NO = errori, SI = non si individua un errore, ma potrebbe esserci lo stesso.

Livello trasporto – Fondamenti teorici del trasporto affidabile

Il livello trasporto estende il servizio di consegna del protocollo IP tra due host collegati ad un servizio di consegna tra due processi applicativi in esecuzione sugli host. Offre un livello di trasporto affidabile e orientato alla connessione utilizzando un canale trasmissivo inaffidabile come internet.

Il livello di inaffidabilità del canale di comunicazione determina la complessità del protocollo che deve gestire questa inaffidabilità.

Protocollo rdt1.0 → trasferimento su canale completamente affidabile.

Protocollo rdt2.x → trasferimento su un canale con possibili errori sui bit:

* 2.0 → versione base

* 2.1 → risolve i problemi di duplicazione

* 2.2 → evita due tipi di ACK

Protocollo rdt3.0 → trasferimento su un canale con possibili errori sui bit e perdita di pacchetti.

Protocolli su canale affidabile

Vengono utilizzate macchine a stati finiti(FMS) per modellare il comportamento del mittente e del destinatario. Lo stato successivo è determinato in modo unico dallo stato attuale e dall’evento che si verifica.

Le ipotesi sono un trasferimento unidirezionale anche se la comunicazione può viaggiare in modo bidirezionale, utilizzo di un meccanismo STOP-AND-WAIT → il mettente invia un pacchetto e si mette in attesa della risposta prima di inviare un altro pacchetto.

Essendo sul canale rdt1.0, quindi affidabile, non ci sono errori ne perdita di pacchetti. Viene definito un automa per il mittente e uno per i destinatario. Il mittente invia dati sul canale e il destinatario legge dal canale.

Protocolli su canale con possibili errori sui bit

Trasferimento su canale con protocollo rdt2.0. Il canale trasmissivo può modificare il valore di un bit. C’è la possibilità di recuperare l’errore:

* ACK: acknowledgement → il destinatario comunica esplicitamente al mittente che il pacchetto ricevuto è OK

* NAK:  acknowledgement negativo → il destinatario comunica esplicitamente al mittente che il pacchetto ricevuto ha un errore.

In caso di ricezione di un NAK da parte del mittente, il pacchetto viene ritrasmesso.

Questo protocollo introduce un rilevamento dell’errore → checksum e un feedback da parte del destinatario → ACK/NAK.

Cosa succede se i messaggi di ACK/NAK sono danneggati? 2 soluzioni:

1. ritrasmettere il pacchetto quando si ha un messaggio ACK/NAK difettoso → non funziona perché vi è la possibilità di duplicazione dei pacchetti e il protocollo rdt2.0 non gestisce i pacchetti duplicati.

2. Inviare ACK/NAK in risposta al ACK/NAK del destinatario → non funziona perché se ACK/NAK di risposta di danneggia, si rischia una trasmissione continua.

Viene introdotto il protocollo rdt2.1 → introduce la gestione dei numero di sequenza. Il mittente aggiunge il numero di sequenza a ciascun pacchetto. Il mittente ritrasmette il pacchetto se il messaggio ACK/NAK è danneggiato. Il destinatario scarta(nel senso che non consegna) i pacchetti duplicati.

Nell’ipotesi di una comunicazione STOP-AND-WAIT è sufficiente un bit come numero di sequenza. Se il numero di sequenza è lo stesso → il mittente ha rispedito un pacchetto. Se il numero di sequenza è incrementato di 1 → il mittente ha spedito un nuovo pacchetto.

Nel protocollo rdt2.1, per ogni pacchetto ricevuto, il destinatario deve inviare sempre un pacchetto di ACK/NAK al mittente. Possibile miglioramento → inviare solo messaggi di ACK per l’ultimo pacchetto ricevuto correttamente → protocollo rdt2.2.

Destinatario → se il pacchetto i (etichetta/numero sequenza) ricevuto è corretto, inviare un ACK con etichetta i. Se il pacchetto i non è corretto e il pacchetto i-1 era corretto, inviare un ACK con etichetta i-1.

Mittente → se il mittente riceve due ACK per il pacchetto i-1 può dedurre che il destinatario non ha ricevuto correttamente il pacchetto i e quindi deve agire come se fosse un NAK del pacchetto i → ritrasmette il paccheto i.

Protocolli su canale con errori a livello di bit e perdita di pacchetti

Il canale può causare errori sui bit e perdita di pacchetti(sia dati che ACK), come si crea una trasmissione affidabile? DOPO AVER SPEDITO IL PACCHETTO i, IL MITTENTE ATTENDE (AKC,i) PER UN INTERVALLO DI TEMPO “RAGIONEVOLE”; POI SE NON HA RICEVUTO L’ACK, RITRASMETTE IL PACCHETTO → protocollo rdt3.0.

Se il pacchetto(messaggio o ACK) è in ritardo ma non perso, il pacchetto ritrasmesso viene duplicato → questo caso è già risolto dall’uso dei numeri di sequenza. È necessario l’utilizzo di countdown timer.

### Protocollo TCP

TCP -> offre un livello di trasporto affidabile e orientato alla connessione utilizzando un canale inaffidabile come Internet.

Il livello di inaffidabilità del canale di comunicazione determina la complessità del protocollo che deve gestire tale inaffidabilità.

Rispetto a UDP offre:

* Orientamento alla connessione

* Orientamento al flusso di dati

* Trasferimento con buffer: i dati sono messi in un buffer e poi inseriti nel pacchetto quando il buffer è pieno

* Connessione full duplex(bidirezionale): una volta instaurata la connessione è possibile comunicare in entrambe le connessioni simultaneamente

Non garantisce una comunicazione in tempo reale, la disponibilità di banda tra mittente e destinatario e un multicast(un mittente e tanti destinatari) affidabile.

Orientamento alle connessioni

Viene creata una connessione tra due processi su host prima del trasferimento di qualunque dato e viene chiusa dopo il completamento del trasferimento-> Instauro della connessione, utilizzo e chiusura. Il processo applicativo viene avvisato solo se non si riesce a stabilire la connessione o se la connessione viene interrotta.

Trasmissione byte stream

La connessione viene trattata come un flusso di byte continuo dal mittente al destinatario:

1. Il processo applicativo mittente scrive i byte

2. Il livello TCP, accorpa i byte in un segmento TCP

3. Il livello IP incapsula ogni segmento TCP in un datagram IP

4. Il processo applicativo destinatario legge i byte

Connessioni full duplex

Può effettuare trasferimenti contemporanei in entrambe le direzioni nell’ambito della stessa sessione. I router non gestiscono il livello TCP

Affidabilità

Ogni trasmissione andata a buon fine viene notificata dall’host ricevente. Se l’host mittente non riceve la notifica di ricezione avvenuta, dopo un time-out, ritrasmette i dati.

Trasferimento con buffer

Il buffer consente di ovviare a: asincronia dell’invio dati, tempi di trasmissione differenti, capacità di invio e di ricezione differenti, segmenti persi o fuori ordine.

Segmento TCP

È l’insieme dei dati che il livello TCP chiede di trasferire al livello IP. Ogni segmento contiene un payload(dati del byte stream) e un header(informazioni di controllo per identificare i byte dati).



![](https://lh7-us.googleusercontent.com/wvtT1RdEAX-437Z4FcHUFN3A52d7VW7IwRyjPCFXXRcI5xI_w66dVZJCYylCYBdkoYHsrQ8wjnz-QSBqJxDUr1m7PCzxx0DxZugCFpNxGaPvxUaf-U6vFH5LSgLxmJA9Zv4zpWnh0Ve84M8ZaqnZa1o2-7fy3Y8)

* Source/destination port: porte mittente/destinatario

* Sequence number: numero di sequenza relativo al flusso di byte

* Acknowledgement number: ACK relativo ad un numero di sequenza che si sta ricevendo

* Hlen: lunghezza header TCP

* Reserved: per usi futuri

* Code bit: scopo e contenuto del segmento

Il checksum è usato per la rilevazione di errori nei dati trasportati, è calcolato usando il maggior numero di informazioni di quelle presenti nell’header TCP.

L’uso del numero di sequenza è quello di rendere praticamente nulla la possibilità che sia presente un segmento identificato con lo stesso numero appartenente a una connessione precedente con identici numeri di porta.

Il campo code bit serve a distinguere i due tipi di segmento (dati e ack) che viaggiano nella stessa direzione.

Piggybacking

Gestione del ack migliorata. Nello stesso messaggio metto sia i dati che voglio trasferire, sia gli ack dei pacchetti precedenti -> riduco il numero di pacchetti inviati

Instaurare e chiudere una connessione TCP

Modello client/server. Il client inizia la connessione, il server deve essere già attivo.

Segmento SYN -> pacchetto che invia il client al server per instaurare la connessione. Il client deve sapere solo la porta del server, non ha bisogno dell’indirizzo IP.

Per accettare la connessione, il server deve essere già in attesa di ricevere connessioni.

Il segmento SYN include:

* ISN: numero pseudo casuale usato per il primo pacchetto come numero di sequenza

* MRW: max numero di byte che il client è in grado di ricevere nel suo buffer

* MSS: massima dimensione del segmento

Il segmento SYN non ha il payload, ma ha solo il TCP header.

Il SYN del server ha in più rispetto a quello del client l’ACK= ISN_client +1

In riassunto: il client invia al server il SYN con anche il suo numero di sequenza, il server riceve il SYN, se accetta invia al client un segmento con SYN e ACK=ISN_client+1 e il proprio numero di sequenza, il client sengala l’apertura definitiva della connessione inviando un SYN, l’ACK=ISN_server+1 e il numero di sequenza ISN_client+1.

Quando si chiude la connessione, va chiusa da entrambe le parti, essendo full duplex.

Client invia richiesta di chiusura al server, server la riceve e invia ACK e chiude il suo lato connessione inviando la richiesta di chiusura al client, il client riceve e invia ACK al server che la riceve, il client attende il timeout ACK e chiude il suo lato connessione.

Il trasferimento dati tra host avviene in 3 fasi: handshaking(setup in cui ci si prepara al trasferimento), trasmissione, chiusura connessione.

Affidabilità del TCP

Affidabilità: uso dell’ACK con ritrasmissione -> il destinatario, quando riceve i dati, invia un ACK al mittente che attende di ricevere un ACK prima di inviare il segmento successivo.

Se il mittente non ha ricevuto ACK di un segmento dopo un certo periodo(timeout), ritrasmette il segmento.

Un timeout troppo breve comporta delle ritrasmissioni non necessarie, uno troppo lungo una reazione lenta alla perdita di segmenti.

Come si migliorano le prestazioni di questo protocollo? Si introduce una tecnica di pipelining-> il mittente invia più segmenti prima di ricevere un ACK. Questo comporta un buffer del mittente per mantenere i dati inviati e di cui non ha ancora ricevuto ACK e un buffer lato destinatario per mantenere le sequenze di dati dove non tutti i dati sono arrivati.

Sliding window

Denota il numero massimo di dati che il mittente può inviare senza aver ricevuto un ACK dal destinatario.









Algoritmi per l’affidabilità del pipelining

Go-Back-N

Impostata la sliding window a N, si ha un timeout per ogni singolo segmento. In caso di timeout del segmento i, viene rimandato il segmento i e tutti i segmenti con numero sequenza maggiore di i.

 Ritrasmissione selettiva![](https://lh7-us.googleusercontent.com/lKKlZcKPR_6ObnmE2o5fFKYQchG1E_OhRX1Lx0Tm0-ge9nM9tNbrXPufUx6cX9h5MQ15CItVP2vXB316_dmOmaSBUuTBd0tdSAU4mAiK9vSWKpcU3-SJIlbMmFPIIFuHYt0Ya7MxNpgDxT5M8ci10rxDVLsB3pw)

Il destinatario invia un ACK relativo a ciascun segmento ricevuto correttamente, il mittente ritrasmette soltanto i segmenti per i quali non ha ricevuto ACK dal destinatario entro il time-out.

Sia il mittente che il destinatario gestiscono la propria sliding window.



Nel protocollo TCP la dimensione della sliding window è calcolato in modo dinamico e il protocollo TCP non usa ne il Go-Back-N ne la ritrasmissione selettiva.

Utilizza “ACK cumulativi” da parte del destinatario. Un ACK cumulativo conferma che sono arrivati correttamente i primi n byte(come in Go-Back-N). Per i segmenti arrivati fuori ordine, vengono salvati nel buffer ricezione(come nella ritrasmissione selettiva).

Con questo algoritmo si evita la ritrasmissione di segmenti ricevuto correttamente, che si verifica nel Go-Back-N.

Il TCP deve evitare di spedire più segmenti di quanti il destinatario sia in grado di ricevere(controllo di flusso) e deve evitare di spedire più segmenti di quanti la rete è in grado di assorbire(controllo di congestione).

Entrambi gli obbiettivi vengono raggiunti determinando come adattare dinamicamente la dimensione della sliding window.

Per il controllo di flusso la dimensione della sliding window è calcolata a partire dalla dimensione massine della finestra di ricezione comunicata dal destinatario, quella effettiva è sempre minore di questa.

Controllo di congestione end-to-end: la situazione di congestione è determinato analizzando le perdite di pacchetti ed i ritardi nei nodi terminali-> utilizzato da TCP.

TCP: soluzione ai problemi

Durante la comunicazione può capitare che il mittente metta a 0 la dimensione della window, ad esempio se deve liberare un buffer pieno. Cosa succede se la sliding window ha dimensione 0? Se la window ha dimensione 0 il mittente non può inviare dati e non può conoscere se la finestra di ricezione è aumentata. La soluzione è: TCP continua a inviare periodicamente un segmento di dimensione 1 anche se la window ha dimensione 0.

UDP vs TCP

Perché usare UDP? TCP usa un meccanismo three-way handshaking prima di iniziare il trasferimento dei dati, mentre UDP non introduce un ritardo per instaurare la connessione. TCP mantiene lo stato della connessione tra i nodi terminali, mentre in UDP un server può supportare un maggior numero di connessioni attive. UDP ha un segmento più piccolo rispetto a TCP(8vs20 byte).

Il controllo di congestione TCP può rallentare le applicazioni di rete real-time.

Si tende ad usare UDP quando si opera su rete locale, quando l’applicazione mette tutti i dati in un singolo pacchetto, quando non è importante l’arrivo di tutti i pacchetti(streaming), quando l’applicazione gestisce meccanismi di ritrasmissione.

## 5_Livello Applicativo

DNS

Introduce un altro livello di naming in internet, più user-friendly rispetto agli indirizzi IP.

Identificatori degli host

Tutti i dispositivi collegati ad internet possono avere due o più identificatori: indirizzo IP e Hostname.

L’hostname è una sequenza di label separate da punti, ogni label può avere max 63 caratteri e l’hostname può essere max 255 caratteri.

Il binding tra hostname e indirizzo IP è fatto a tempo di esecuzione. Se la rete ha pochi nomi si preferisce una soluzione centralizzata con uno spazio piatto dei nomi, se la rete ha tanti nodi(milioni) si preferisce una distribuzione con uno spazio gerarchico dei nomi, utilizzando anche DNS. Il DNS permette una traduzione tra indirizzo IP e hostname e viceversa.

Organizzazione logica dello spazio dei nomi

TLD-> top level domain-> dominio: .com, .edu, .org, .it, .uk, …

Dal 2013 è possibile usare qualsiasi tipo di parola e di linga per la scelta del TLD. Il costo di un dominio è di 185.000$. SLD-> second level domain -> rappresenta il nome vero e proprio del brand(amazon, google, facebook…).

Name server

Ogni dominio internet finisce con il punto, anche se non è richiesto quando ci si connette. Il punto finale rappresenta il dominio radice(DNS root zone). Tutti i domini, primo e secondo livello, appartengono a quel dominio. Root name server -> server DNS che prende in carico la risoluzione dei nomi del dominio radice nei vari domini di primo e secondo livello. Nel mondo sono presenti solo 13 root name server.

Il server A root name ha la copia ufficiale del file root zone. Gli altri dodici lo vanno a prendere da A.

Il servizio DNS supporta gli indirizzi anycast: è un indirizzo IP associato a indirizzi IP di più host. Quando un pacchetto è diretto ad un indirizzo anycast, viene recapitato a uno qualsiasi degli indirizzi IP associati all’indirizzo. La risposta si ottiene dal primo host che viene raggiunto.

I TLD devono essere registrati presso i root name server.

I name server non hanno i dati di tutti i nomi. In generale ciascun name server deve conoscere almeno il name server della zona immediatamente superiore e viceversa, è tipo una gerarchia.

La gerarchia dei name server risulta più irregolare rispetto a quella dei nomi di dominio.

Authoritative name server e Zone

Authoritative name server = server che risponde alle richieste di nomi in una zona.

Domain name per un host = sequenza di label che va dall’hostname (label più a sinistra) fino al top (label più a destra).

Dominio (riferito alla struttura gerarchica dei nomi) = TLD,SLD

Zona (riferito all’organizzazione dei server) = dati relativi ai nomi di un dominio.

Zona e dominio possono coincidere. Gli amministratori di un sistema inseriscono i dati relativi ad una Zona in un master file, che è l’unica sorgente di dati autoritativi per quella zona. I master server (o primary) leggono i dati di una zona direttamente dal master file. I secondary server scaricano i dati di una zona dal rispettivo server primario. Per ogni zona c’è sempre un server primario e almeno uno secondario, che ha una copia del database hostname-indirizziIP.

I server secondari comunicano periodicamente con il primario per verificare che i dati siano uguali. Se una copia di dati del secondario non è aggiornata, il primario invia l’ultima versione.

Per garantire una tolleranza ai guasti, le specifiche DNS richiedono che ogni zona debba essere replicata su due server autoritativi che siano diversi tra loro (macchine diverse e reti diverse).

NB:

* name server primario = ha i dati della zona

* name server secondario = ha una copia dei dati della zona

* authoritative name server = autoritativo relativamente ai dati di una zona

Local name server

Ogni organizzazione e ogni provider gestisce uno o più name server locali (sono configurati dal client ed è fornito in un contesto DHCP).

Possibilità di local name server

1. client di organizzazioni senza dominio: utenze SO-HO, piccoli uffici, non appartengono ad un dominio registrato e delegano le funzioni di local name server al proprio ISP(come nelle reti domestiche). Ha DHCP e non c’è authoritative name server

2. client di organizzazioni con dominio delegato: hanno un dominio con contratto indiretto mediante un provider. Delegano al provider la gestione dell’authoritative name server per il proprio dominio. La società può gestire il local name server oppure delegare tale funzione al proprio ISP

3. client di organizzazioni con dominio gestito direttamente: hanno un proprio name server autoritativo e uno o più local name server

Il local name server è configurabile da parte di ciascun utente e si può fare riferimento a name server pubblici (Google, OpenDNS…).

Dati del DNS: Resource Record(RR)

I DNS sono praticamente dei database che contengono record di zone, indirizzi, …

Tipi di RR:

* A: record di host address e indirizzo IP

* NS: descrive il name server autoritativo per una certa zona, indica il server primario e le informazioni sui server secondari

* SOA: start of authority: parametri relativi alla gestione della zona così come sono stati configurati (tutto numerico in secondi)

* MX: Mail eXchanger: record relative ad un server mail

* CNAME: Canonical NAME per un alias, un host può avere più hostname di cui uno canonico e altri alias

* PTR: PoinTeR to another node

* HINFO: Host information(CPU, SO)

* TXT: TeXT file

* AAAA-IPv6 Address: identico a un record A, ma che gestice indirizzi IPv6

Tutti i nodi terminali hanno un RR, i nodi non terminali possono avere un RR. Ogni RR contiene il nome del dominio, valore del RR, TTL, classe del RR, tipo del RR.

Esempio di RR tipo A di [www.unimore.it](http://www.unimore.it/):

* Nome dominio: [www.unimore.it](http://www.unimore.it/)

* TTL: 86400

* RR class: IN(internet)

* RR type: A(address)

* RR value: 134.56.26.68 (ip address)

Meccanismo distribuito di risoluzione dei nomi

Nessun name server ha tutte le corrispondenze hostname e indirizzo IP. Il DNS è un sistema client/server. I resolver sono i primi client del sistema DNS che sottomettono query al loro local name server per risolvere indirizzi su hostname e IP per conto delle applicazioni internet.

Il resolver è di solito una piccola libreria compilata in ogni programma che richiede i servizi DNS.

Ogni resolver deve conoscere il riferimento ad almeno un name server locale. In UNIX esiste il file /etc/resolv.conf che contiene informazioni sulla Zona Locale.

Nella risoluzione di un nome, un DNS può rispondere in due modi, a seconda di come è configurato:

* Query ricorsiva: il server, contattato e non in grado di risolvere il nome, assume un ruolo di client nei confronti si un altro server -> fa la richiesta ad un altro server e poi restituisce quella all’host

* Query iterativa: il server, contattato e non in grado di risolvere il nome, risponde con i nomi di uno o più server da contattare.

I root name server sono di tipo query interative mentre i local sono a query ricorsiva.

Esempio di ciclo di richiesta: vogliamo connetterci a [www.unixwiz.net](http://www.unixwiz.net/)

1. Il resolver(PC utente) contatta un root name server(ISP local)

2. ISP local contatta un root name server, con una query ricorsiva (in questo esempio) di tipo A relativa a [www.unixwiz.net](http://www.unixwiz.net/).

3. Il root server non ha un RR per unixwiz.net ma conosce il server Global Top Level Domani (GTLD) che è responsabile del dominio .net, la risposta è di tipo NS (quindi da info a chi chiedere). Il RR NS restituito comprendere anche indirizzi IP, in questo modo risparmio tempo evitando un'altra richiesta degli indirizzi.

4. Il name server locale (quello contattato al punto 1) sceglie un server autoritativo presente nel RR NS e invia la stessa query iniziale

5. Il server GTLD non conosce la specifica risposta ma conosce l’insieme dei server che devono dare risposta perché autoritativi sul dominio unixwiz.net

6. Ancora una volta il name server locale sceglie uno dei server autoritativi e gli invia la stessa query

7. Questo server ha la risposta e la restituisce a local name server

8. Esso si salva in cache la risposta (per eventuali usi futuri) e la restituisce al PC utente

I server DNS utilizzano un servizio di caching per ridurre i tempi di risposta. I client che ricevono dati dalle cache dei server sanno che il dato viene dalla cache e che non è autoritativo (quindi potrebbe essere sbagliato). I dati in cache hanno un TTL, il name server fornisce il dato in cache solo se il TTL non è scaduto. Se è scaduto il name server contatta il server autoritativo e controlla che il dato sia valido.

             Pacchetti del DNS

Formato richiesta messaggio DNS![](https://lh7-us.googleusercontent.com/wgIuswubMzveLspkPYj-tNHgKRcLAt5KxbkiFTnOJyzMxt7oR8M-1M3CLXdciu9vVRY-Vkp5RZqKMreO2-ECsWWp6Boz2ydHM5AMmUfo-nDn0iDzZ5mViK3TeY704dyZrtW5pDjErxRdZBz81baSK28_sQ0c-yU)![](https://lh7-us.googleusercontent.com/UDlTC2InqkDwKn_s-Y-nsFOOM40tejascqLCs7zGiQMZUQ2XYNsp9u-95jjTdL9iPpq_ugMWue3-k-eoPpw-nEKgASLuBKOXT7k2Dfz0qd0sKZXVwin42bXwqJ_bqdeaNWSFEbiOT_KrXLvB1Ip6rKJPdiqIVwY)

Il Query ID p un identificativo che server al server per sapere se il pacchetto è una query(0) o una risposta(1).

AA: settato a 1 per una risposta authoritative.

Efficienza del DNS

Il DNS utilizza sia il protocollo UDP che il TCP.  Il TCP viene usato per il trasferimento di interi database da server primari ai secondari, mentre l’UDP per il lookup di pochi nomi. Se il lookup la risposta supera i 512 byte, si utilizza il TCP.

Aspetti gestionali e legali

Regole sintattiche di naming: i nomi possono contenere solo lettere e numeri e il simbolo “-“. I nomi non possono iniziare o finire con “-“. Non si possono registrare nomi in cui la prima stringa contiene i caratteri xn--. Il nome può andare da 3 a 63 caratteri.

Parte 7

Servizi di rete

Applicazione di rete  Protocolli applicativi

Un servizio di rete, o applicazione di rete, è un servizio che ha: un software client(spesso con interfaccia utente, un software server, un protocollo di livello applicativo).

Per protocollo di livello applicativo si intende ftp, telnet, http, smtp, irc…

Noi vedremo i servizi DNS, SMTP, Telnet, FTP, WWW.

Posta elettronica

Un indirizzo di posta è formato da local_username@domain. Il domain è di max 255 caratteri mentre lo username di max 64.

Il servizio di posta elettronica utilizza:

* Mail transfer agent(MTA): mail server per la gestione e il trasferimento della posta

* SMTP: protocollo per il trasferimento della posta

* DNS: resource record MX

* Mail User Agent(MUA): processo per la gestione posta lato utente

Mail server

È il MTA. Al suo interno ha un User mailbox con i messaggi in ingresso, ancora de leggere, dell’utente, una coda di messaggi di posta in uscita(da inviare), gestione protocollo SMTP tra mail server per inviare messaggi.

Un mail server è sia client sia server di altri mail server. L’MTA è il processo principale che trasferisce messaggi da un PC all’altro. Il trasferimento può essere diretto(dall’MTA sending all’MTA receiving) o relay(dall’MTA sending ad un server intermendio).

Durante la trasmissione via email la prima informazione da conoscere è il mail server che gestisce il domino di posta destinatario, ovvero il DNS gestisce un RR MX(Mail eXchanger) che specifica come deve essere inoltrato il messaggio. In questo RR sono presenti la lista di server che sono abilitati alla ricezione dell’email per quel dominio e la priorità di ogni server. L’MTA prova a stabilire una connessione TCP con il server a priorità più alta, in caso di fallimento passa al secondo e così via.

Un server SMTP gestisce il trasferimento dei messaggi inviati dall’interno del domino, interagisce direttamente con i client di posta, deve essere veloce e gestisce code relativamente piccole.

Un server MX gestisce la ricezione dei messaggi che arrivano dall’esterno del dominio, gestisce code di messaggi in arrivo molto lunghe e richiede molta potenza computazionale.

Il server DNS fa da intermediario tra i server MTA del mittente e destinatario, ovvero dice al mittente a quale server MTA mandare la mail.

Alcuni sistemi utilizzano più di un server oltre al MTA. Usano MSA, mail submission agent, e MDA, mail delivery agent. Questo tipo di organizzazione sta diventando la norma per i sistemi di gestione mail delle organizzazioni molto grandi → organizzazione multi livello.

La consegna tramite TCP garantisce che quando il messaggio è rimosso dallo spool del mittente è già stato recapitato con successio al ricevitore. Se si utilizzano server intermediari, si ha la garanzia solo fino al primo server, dopo si perdono le tracce.

Spesso la consegna di un messaggio avviene tramite MDA, che è invocato da un MTA. L’MDA è un filtro che elabora le email e può eseguire operazioni come filterign, sorting, auto-reply…

L’MSA è un processo che riceve un messaggio da un MUA e contatta un MTA per inviarlo. Oggi si tende a separare usanto MSA, MUA e MTA. In alcuni casi l’MSA può segnalare all’utente alcuni errori prima di passare al MTA.

Protocollo SMTP

SMTP→ Simple Mail Transfer Protocol

Usa un paradigma client-server, dove il client è MTA del mittente e il server è MTA del destinatario. Usa un protocollo di trasporto TCP per il trasferimento affidabile dei messaggi tra client e server.

La comunicazione sender/receiver avviene sulla porta 25.

Le fasi del trasferimento sono 3: Handshaking(diverso da quello TCP), trasferimento messaggi e chiusura. SMTP usa connessioni TCP persistenti per trasferire più messaggi(se esistono) in una sola volta.

Il formato di un messaggio SMTP consiste in un header e in un body.

Nell’header ci sono le informazioni sul destinatario, mittente e altri info, alcune di queste sono obbligatorie. Nel campo body invece c’è il messaggio.

La differenza tra SMTP e HTTP sta che SMTP è un protocollo push, quindi da al server, mentre HTTP è un protocollo pull, quindi chiede al server.

Mail User Agent

È l’applicazione lato utente che prevede varie funzionalità(interfaccia, editing, invio…).

Protocollo POP3→ protocollo di accesso alla posta:

* instaura una connessione → TCP sulla porta 110

* autorizzazione → user agent invia login e pwd al server

* transazione → user agent recupera i messaggi

* aggiornamento → dopo il quit, vengono eliminati eventuali messaggi dalla mailbox

Protocollo IMAP → ha più funzionalità ed è più complesso rispetto a POP3, deve essere in grado di gestire una gerarchia di mailbox per ogni utente. Ha una fase di instaurazione, una fase di autorizzazione e una di transazione.



### MIME

SMTP tratta correttamente solo caratteri ASCII a 7 bit. Per i messaggi con caratteri a 8 bit o binari si utilizza Multipurpose Internet Mail Extension(MIME). MIME si inserisce tra applicazione utente e mail server, automatizzando la procedura di conversione effettuata dai client.

Viene esteso l’header SMTP con 5 campi dedicati a MIME: versione, content-type, codifica usata, ID, descrizione. Il content type descrive il tipo di dato trasmesso(testo, jpeg, gif, mpeg, …).

# World Wide Web

Componenti alla base del web: Protocollo TCP/IP, DNS, client-server, URL, HTML, HTTP.

### Standard del WWW

URI: uniform resource Identifiers, standard di naming delle risorse. Comprende:

* URL: Uniform Resource Locator, specifica la locazione fisica e le modalità di accesso

* URN: Uniform Resource Name, proposta per la rappresentazione univoca dei nomi delle risorse in modo da garantire persistenza e disponibilitò

* URC: Uniform Resource Characteristics, proposta per la descrizione delle risorse basata su coppie attributo-valore.

Con URL si può fare riferimento a tutto(pagine, immagini, programmi, suoni, video). Un URL è formato da schema://host.domain/pathname.

Lo schema indica il modo con cui accedere alla risorsa, ovvero il protocollo da usare(HTTP è il più comune). Host.domain è l’hostname del nodo nel quale risiede la risorsa Web. Pathname identifica la risorsa.

### HTTP: HyperText Trasmission Protocol

è il protocollo che permette il reperimento delle risorse Web. È un protocollo applicativo di tipo request/reply, basato TCP/IP. Tutti i client e server web devono poter scambiare richieste e risposte. HTTP usa il TCP come protocollo di trasporto, il client inizia la connessione TCP verso il server sulla porta 80. HTTP è un protocollo stateless(senza stato), ovvero il server non conserva alcuna informazione riguardante le richieste dei client passati, anche se tramite l’utilizzo dei cookies si può rimediare a questo problema.

Differenza tra HTTP/1.0 e HTTP/1.1: la versione 1.0 esegue una richiesta per volta, mentre nella versione 1.1 è presente il pipelining.

Poiché TCP non conosce la banda effettiva di una connessione, comincia con una window size piccola(throughput basso) e aggiusta la dimensione della window size in base alla frequenza degli ACK ricevuti. 

Linguaggio HTML: linguaggio del web. Le istruzioni HTML sono racchiuse all’interno di tag: <tag> per iniziarlo e </tag> per chiuderlo. 

#### WWW- Lato Client HTTP

Il browser è un software che interfaccia l’utente e il WWW. Il browser ha il compito di richiedere la risorsa al server Web, ricevere il file con la codifica della risorsa in HTML, decodificare e interpretare il file HTML e farlo visualizzare all’utente.



Azioni di un browser:

1. Fase iniziale: browser analizza URL, controlla se la risorsa richiesta è contenuta nella cache del browser(se è valida carica quella, altrimenti effettua richiesta).

2. Fase di lookup: browser acquisisce la componente hostname dall’URL, invoca il resolver per conoscere l’indirizzo IP tramite DNS, se esiste il DNS restituisce IP

3. Fase di richiesta: individuato IP, browser stabilisce la connessione TCP con host, richiede tramite HTTP la risorse specificata, il server Web invia il file di testo

4. Fase di valutazione: una volta inviati tutti gli oggetti, il server chiude la connessione TCP, appena il browser riceve il primo file lo visualizza.

Il browser gestisce uno spazio disco in cui memorizza file dei server Web: cache. L’utente può forzare il prelievo da server Web, evitando la cache. 



#### WWW- Lato server e servizi

Servizi Web basati su contenuti statici

Il sito web è basato su file. L’organizzazione è gerarchica, sia delle pagine che dei file. L’albero delle pagine web è implementato in modo simile a un file system gerarchico con una radice e directory che contengono altre directory o file. Ogni pagina web ha un nome univoco. La classificazione delle pagine può essere fatta in base al contenuto delle pagine(HMTL, immagini, codice…) oppure funzionale(statiche, volatili, dinamiche, attive…).

Servizi Web basati su contenuti dinamici

Non sono più basati su file ma su database. Utilizzando il Common Gateway Interface(CGI), standard proposta dalla NCSA, si fa in modo che due software diversi possano interagire in modo corretto. Questo standard specifica come gli script devono essere invocati e come devono essere passati i dati dal server allo script e viceversa. Uno script è un generico programma eseguito dal server.

Servizi di rete di qualsiasi tipo usufruibili mediante tecnologie Web

Ad oggi, quasi tutto è interagibile tramite Web. Per questo motivo è necessario che la qualità dei servizi sia ottimale, in termini di prestazioni, scalabilità, affidabilità, sicurezza e usabilità.

In un servizio si possono distinguere 4 livelli logici:

* Interfaccia utente

* Logica di presentazione: cosa accade quando l’utente interagisce con l’interfaccia

* Logica dell’applicazione: 

* Logica dei dati: gestione fisica dei dati

Un livello logico è diverso da un processo. Quindi i processi realizzano i livelli logici e i processi sono eseguiti dai computer. 

I 4 livelli logici si possono mappare sui processi in 4 modi diversi:

* Tutti su un solo processo, solo a livello teorico

* Con due processi distinti, uno client che gestisce interfaccia, e 3 server

* Con tre processi distinti, client che gestisce interfaccia, uno server che gestisce presentazione e applicazione e uno server che gestisce dati

* Con quattro processi distinti, client che gestisce interfaccia, i restati 3 livelli logici sono divisi su 3 processi server

Il livello di presentazione agisce con un’interfaccia tra il livello applicazione e il livello interfaccia, utilizzando server HTTP.

Il livello dati gestisce i database(oracle, mysql, postress, …). 



# HTTP: HyperText Transfer Protocol

È un protocollo applicativo orientato ai sistemi ipermediali, è un protocollo senza stato e generale e supporta la tipizzazione dei dati. È un protocollo creato per il WWW, prevede uno scambio di messaggi tra client e server, utilizza il protocollo TCP.

Il server è un programma che accetta connessioni e che attende richieste, il client è un programma che stabilisce una connessione e formula una o più richieste. 

L’obiettivo di una richiesta HTTP è denominato “risorsa” ed ogni risorsa è denominata da un URI.

Tutti i messaggi HTTP sono composti da un header e un playload. Header è organizzato per linee, la prima indica se è richiesta o risposta.

 Un messaggio di richiesta HTTP inizia con una request-line, che contiene metodo, URI della risorsa e la versione del protocollo.![](https://lh7-us.googleusercontent.com/FT5__3KsuHHdvYJnOTzSmOiAMQgFqrQOYpfizZ-p-m4JENu4hXpFNC9AnbRu6BkJQ_Ea-bmqWLo3uLZdGijQT66ABafa0tIsD7g0wxx8vKU2R8VldGP4qojgUj4TVOqkFd9u3GIz3-qYpeRcmwkAm3ZORLwpR-g)

Poi ci sono i campi header(info del client, metadati,…), segue una linea vuota, che rappresenta la fine dell’intestazione,  e poi se presente il contenuto del messaggio.



Un messaggio di risposta inizia con una status-line che contiene versione del protocollo, un codice di ritorno e una ragione testuale. Seguono poi gli header, una linea vuota e il corpo della risposta se presente. 

Lo schema di comunicazione è in realtà più complesso del semplice client-server. Sono presenti intermediari come proxy, gateway e tunnel.

Un proxy è selezionato dal client in base a regole e policy configurate localmente, può applicare delle trasformazioni ai messaggi. Generalmente sono usati per funzioni di sicurezza e performance.

Un gateway impersona l’origin server per una connessione in ingresso, utile per nascondere sistemi legacy o untrusted, effettuare caching o load balancing.

Un tunnel agisce come forwarder tra due connessioni di trasporto senza interpretare i dati e cessa di esistere quando le connessioni sono chiuse da entrambe le parti.

In ogni punto del percorso è permessa la presenza di cache per garantire performance elevate, ogni client o server può utilizzare cache, tranne il tunnel. Una risposta è cacheable se ne è permessa la memorizzazione in una cache. 

Ogni richiesta richiede una connessione separata, per evitare lo slow start TCP, il server non chiude subito la connessione dopo aver inviato la riposta, ma attende per un certo periodo, in modo da poter usare ancora la connessione, eventualmente.

Un client può accodare(concorrenza) più richieste su un’unica connessione e può aprire molteplici connessioni verso lo stesso server(pipelining).

Identificazione delle risorse

Una risorsa è una qualsiasi cosa che possa essere identificata con un URI. La sintassi è schema”:”hier-part[“?”quey][“#”fragment]. Lo schema stabilisce una specifica per identificare la risorsa(HTTP, file, ftp, …). Autority è sempre preceduto da // ed è seguito da /, ?, # o dalla fine dell’URI.

![](https://lh7-us.googleusercontent.com/A3Dzu4xSztrfod3NQ8OY0vGMv5yAv3a8IO4En2ocjsDfKkb4gTIaBLbS1s7e8A-8TR28lOZv_OUVRWCV09WDEhsJVvAvRMj0xdDLpkLGU52jVdk7tOr9zIbyr3W8SSGfWkhVUzP3TKNVxrpJVy5E1v5QG9Z515w)  



Messaggi

HTTP supporta solo due tipi di messaggi: richiesta e risposta. All’interno dei messaggi vengono utilizzati riferimenti alle risorse, implementati via URI. 

La request line HTTP è “method SP request-target SP http-version CRLF”, dove method rappresenta l’operazione da invocare, request-target è l’URI oggetto della richiesta e http-version è la versione supportata dal client.

I metodi sono

* GET: richiede il trasferimento di una risorsa

* HEAD: come GET ma solo la sezione di intestazione, serve ad ottenere gli stessi metadati che si ottengono con GET ad eccezione di quelli relativi al payload

* POST: eseguire una gestione specificata dalla risorsa sul payload della richiesta

* PUT: sostituire tutte le rappresentazioni attuali della risorsa con quelle presenti nel payload

* DELETE: rimuovere tutte le rappresentazioni correnti della risorsa

* PATCH: modifica di una risorsa

* OPTIONS: richiede al server quali operazioni sono permesse su una risorsa

* TRACE: chiede al server di inviare la richiesta come ricevuta

* CONNECT: richiede al server di stabilire un tunnel verso un origin server

Un metodo è safe quando la sua semantica è fondamentalmente read-only, ovvero il client non si aspetta di cambiare lo stato della risorsa(GET, HEAD, OPTIONS, TRACE). Un metodo è idempotente quando multiple richieste identiche avranno lo stesso effetto(metodi safe, PUT, DELETE). Un metodo è cacheable se le risposte possono essere riutilizzate(GET, HEAD, POST).

Il request target è derivato dall’URI e può essere in diverse forme: 

* Origin-name: versione standard è inizia sempre con /

* Absolute-form: si invia tutto l’URI

* Authority-form: si usa solo con i tunnel ed è formato da host:porta

* Asterisk-form: usato solo per una richiesta OPTIONS valida per tutto il sito

La response line HTTP è “http-version SP status-code SP reason-phrase CRLF”, dove http-version è la versione del protocollo supportata dal server, status-code è un intero a 3 cifre decimali che descrive il risultato del tentativo del server di capire e soddisfare la richiesta del client e reason-phrase fornisce una descrizione testuale associata al codice di ritorno numerico e dovrebbe essere ignorata.

Lo status code è diviso in classi:

* 1xx: richiesta ricevuta e il processing continua

* 2xx: richiesta ricevuta, interpretata e accettata

* 3xx: sono necessarie ulteriori azioni al fine di completare la richiesta

* 4xx: la richiesta ha una sintassi errata o non può essere soddisfatta

* 5xx: il server non è riuscito a soddisfare una richiesta apparentemente valida

Gestione della richiesta

* Proattiva: il server seleziona la rappresentazione basandosi sulle preferenze espresse dallo user agent

* Reattiva: il server fornisce al client una lista di rappresentazioni tra le quali scegliere

Header della richiesta

Gli header permettono alle parti di specificare meta-informazioni. 

L’header host: fornisce l’host e la porta relativi alla risorsa richiesta. Esistono header di controllo che specificano come gestire la richiesta stessa:

* Expect: indica un insieme di comportamenti attesi da parte del cliente.

* Max-forwards: indica il numero massimo di inoltri da parte dei proxy in una richiesta con metodo TRACE

* Range: serve se un client ottiene solo una rappresentazione parziale della risorsa e vuole chiedere la parte rimanente

Esistono header relativi alla negoziazione, ovvero inviati dallo user agent ed utilizzati per la negoziazione proattiva:

* Accept: lo user agent specifica quali media type sono accettabili

* Accept-charset: indica la preferenza rispetto al set di caratteri da usare(iso, unicode, …)

* Accept-encoding: indica quali content-coding sono accettabili nelle risposte

* Accept-language: indica le lingue naturali preferite per la risposta 

Gli header di conteso forniscono informazioni sull’utente, lo user agent e la risorsa che ha generato la richiesta:

* From: contiene l’indirizzo email dell’utente che controlla lo user agent

* Referer: permette allo user agent di specificare dove è stato ottenuto l’URI per la risorsa richiesta

* User-agent: informazioni riguardanti il programma che ha generato la richiesta

Header della risposta

Ci sono header che descrivono il payload:

* Content-lenght: dimensione payload in byte

* Content-type: tipo della rappresentazione della risorsa ritornata

* Content-range

* Transfer-encoding: elenca le modifiche che sono state(o verranno) applicate al corpo del messaggio

* Chunked trasnfer encoding: il corpo del messaggio può essere spezzato in più parti, rappresenta il numero della parte

Header di rappresentazione sono campi che accompagnano la rappresentazione stessa(GET) o soli(HEAD):

* Content-type: tipo di contenuto del messaggio

* Content-encoding: trasformazioni applicate alla rappresentazione(zip, compress, …)

* Content-language: descrive i linguaggi 

* Content-location

Header control data, supplementano lo status code:

* Date: data e ora della generazione messaggio risposta

* Location: riferimento ad una risorsa correlata

* Retry-after: quanto un client dovrebbe attendere prima di effettuare una nuova richiesta

* Vary

* Last-Modified: timerstamp ultima modifica

* Etag

* Allow: elenca i metodi permessi sulla risorsa obiettivo

* Server: fornisce informazioni sul software utilizzato dall’origin server per gestire la richiesta

Caching

Lo scopo del caching è quello di migliorare le performance riutilizzando risposte ottenute precedentemente. Se una risposta può essere riutilizzata senza ulteriore validazione allora è considerata fresh. Le richieste condizionali sono richieste che includono uno o più header che specificano delle condizioni che devono essere verificate prima di applicare la richiesta alla risorsa e servono principalmente per implementare l’aggiornamento delle cache:

* If-mach: la richiesta si applica solo se la risorsa ha un etag compreso in quelli specificati dal client

* If-none-mach: solo se la risorsa ha un etag che non è compreso in quelli specificati dal client

* If-modified-since: solo se la risorsa è stata modificata da una certa data

* If-unmodified-since: usato per evitare sovrascritture

* If-range: ignora il range se l’etag(o la data) specificata non corrisponde

Le cache possono essere condivise o private. Una cache condivisa è una cache che memorizza le risposte che possono essere utilizzate da più utenti, mentre una cache privata memorizza le risposte che sono inviate ad un utente. Le prime sono implementate negli intermediari mentre le seconde dallo user agent.

Gestione dello stato

HTTP è senza stato, non è possibile collegare tra loro richieste HTTP. Utilizzando header aggiuntivi è possibile avere uno stato. Gli header “cookie” e “set-cookie” implementano questa funzionalità. Un cookie si presenta come una coppia nome-valore. Un cookie HTTP (web cookie, cookie del browser) è un piccolo pezzo di dati che il server invia al browser dell'utente. Il browser può memorizzarlo e inviarlo allo stesso server nelle richieste successive. Tipicamente è utilizzato per stabilire se due richieste provengono dallo stesso browser, mantenendo ad esempio un utente loggato. Fornisce quindi informazioni stateful sopra al protocollo [stateless](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview#HTTP_is_stateless_but_not_sessionless) HTTP.

Autenticazione

Il protocollo HTTP mette a disposizione un framework generico per l’autenticazione: il client richiede una risorsa protetta e il server risponde richiedendo delle credenziali. La risposta contiene l’header WWW-Authenticate. Il client che invia le credenziali le include nell’header Authorization delle richieste. 

Basic Authentication: modello di base per autenticazione. Il client utilizza l’header per mandare username e password, ma queste non sono cifrate.
