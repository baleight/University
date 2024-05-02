## Lezione 29/04 L&C Backend

#### Cos'e un loop?

Come si rappresentano nelle IR?

> nel CFG dell'IR, un loop viene rappresentato come un percorso ciclico di nodi e archi che consente al programma di eseguire ripetutamente le istruzioni all'interno del loop fino a quando non viene soddisfatta una condizione di uscita.
> 
> Nel Control Flow Graph (CFG) di una rappresentazione intermediaria (IR) di un programma, un loop viene rappresentato come un'area del grafico in cui si verifica un flusso di controllo ciclico. Questo significa che all'interno del CFG, ci saranno nodi che rappresentano gli instruction blocks (blocchi di istruzioni) all'interno del loop, e ci saranno archi che collegano questi nodi, creando un percorso ciclico che consente al programma di eseguire le istruzioni all'interno del loop più volte fino a quando non viene soddisfatta una condizione di uscita.



Definizione del prof formale?

Non vogliamo che ci sono due entry point, le proprieta fondamentali sono un singolo entry point e gli archi devono formare almeno un ciclo, quindi che l'arco ritorni ad un passo precedente.

 Come si codifica che l'arco ritorna indietro? Una noziona che ci aiutato per andare avanti e tornare idietro e' la dominanza-> DOMINITOR

Cose e'? un nodo che deve essere per forza visitato nel grafo.

Nle control flow graf ogni volta che incontriamo dei DOM possiamo Dominator Tre e' un grafo dove specifichiamo solo il percorso di dominanza.

CFG il nodo entry e' la radice, quindi per definizione questa e' la partenza nodo radice.

I figli del primo livelli saranno i dominatori del control flow grafh.

Nella definizine di dominiza ogni nodo domina se stesso, ci sono delle catene di dominnza.

Immediate dominator e' lultimo dominator. m domina immediatamente n (m dom n) se m dom n e m e' diverso da n.

Esercizi su IPAD



Header del loop domina tutti inodi del loop, e il singolo entry point, la radice.

Come facciamo a capire che il backedge, la testa domin la proprioa coda,un arco che torna indetro edomina la propria coda.



Come identificare i loop naturali?

#### 1.Trovare le relazioni di dominanza nel flow graph

Come trovare i dominatori? Un nodo d domina un nodo n in un grafo **d dom n**

La direzione e' forward e il meet operator e' lintersezione perche OGNI percorso.
Condizioni al contorno (quello che fa partire l'analisi)? fewgwg

Condizoini inziali out del basic blocj e' un insieme composto dal solo entry.

Funzione di trasferimento.

#### 2.Identificare i back edges

   Fare una ricerca depth first, parto dalla radice e visito i figli di ogni nodo non necessriamente da destra a sinistra, consumare la profondita. Visito prima i nodi piu distanti, piu profondi dalla radice.

- Advancing A edges

- Retreoating noi useremo questo

- Cross: 

non e' garantito che reatriting edges sia un back edges, serve obbligatoriamente Head domina tail

#### 3.Trovare il loop naturale associato al back edge.







Perche esiste il preheader? Mi serve dare ala garanzia che il block ci sia Ottimizazione sul loop




