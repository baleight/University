# Analisi degli errori

Gli algoritmi numerici vengono applicati per calcolare le soluzioni di problemi matematici. 

- Dati perturbati → i dati in input sono affetti dall’errore di rappresentazione
- Aritmetica di macchina → I risultati di ogni singola operazione sono affetti dall’errore di rappresentazione. Ogni risultato intermedio può esserne soggetto e influenzare i risultati di tutte le operazioni successive.

L’accumulo di questi errori viene chiamato propagazione degli errori. Bisognerà effettuare:

- Analisi del condizionamento dei problemi → capire quanto le soluzioni variano in presenza di perturbazione.
- Analisi della stabilità degli algoritmi → progettazione di algoritmi che risentano poco degli effetti dell’aritmetica di macchina.

*Esempio →* problema: $x+y+z$ algoritmo: $(x+y)+z$      ($fl(s)=s(1+\epsilon)$  con $|\epsilon|\leq u$)

Errori da considerare: 

- Uno per ogni dato → $\epsilon_x, \epsilon_y, \epsilon_z$
- Uno per ogni operazione di conversione floating point effettuata → $\epsilon_1, \epsilon_2$

Tutti gli $\epsilon$ sono maggiorati dalla precisione di macchina. 

Il calcolo risulta quindi essere

$$
\alpha^*=((x(1+\epsilon_x)+y(1+\epsilon_y))(1+\epsilon_1)+z(1+\epsilon_z))(1+\epsilon_2)
$$

Da cui l’errore relativo

$$
E_r = \frac{\alpha^*-\alpha}{\alpha} \simeq \frac{x}{x+y+z}\epsilon_x+\frac{y}{x+y+z}\epsilon_y+\frac{z}{x+y+z}\epsilon_z+\frac{x+y}{x+y+z}\epsilon_1+\epsilon_2
$$

Dove 

- $\frac{x}{x+y+z}\epsilon_x+\frac{y}{x+y+z}\epsilon_y+\frac{z}{x+y+z}\epsilon_z$ → errore inerente
- $\frac{x+y}{x+y+z}\epsilon_1+\epsilon_2$ → errore algoritmico

## Errore inerente e algoritmico

- **Errore inerente** → errore che si commetterebbe se le operazioni fossero eseguite in aritmetica esatta $\epsilon_x=\epsilon_y=\epsilon_z=0$, **non dipende dall’algoritmo ma da SOLO i dati.** Pertanto ci permette di capire se il problema è mal condizionato o meno
- **Errore algoritmico** → **parte sulla quale possiamo lavorare per migliorare la soluzione** (stabilità) del problema. Coincide quindi con l’errore che si commetterebbe se i dati fossero rappresentati esattamente ma le operazioni fossero eseguite in precisione finita.

## Condizionamento di un problema

Un problema si dice ben condizionato se a piccole perturbazioni dei dati corrispondono altrettanto piccole variazioni delle soluzioni. Viceversa, un problema si dice mal condizionato se a piccole perturbazioni dei dati corrispondono (relativamente) grandi variazioni delle soluzioni. Il condizionamento **è una proprietà della funzione che lega i dati alla soluzione di un problema,** non dipende da come queste vengano calcolate.

## Stabilità di un algoritmo

Un algoritmo si dice stabile se non è troppo sensibile agli errori di rappresentazione introdotti dalle operazioni in aritmetica finita. La stabilità dipende dal tipo, dall’ordine delle operazioni che costituiscono l’algoritmo.

## Valutazione degli algoritmi

I criteri su cui si valutano gli algoritmi numerici sono due: 

- Complessità computazionale → numero di operazioni aritmetiche necessarie per portare a termine l’algoritmo. Il tempo di calcolo è direttamente proporzionale alla complessità computazionale. Fornisce una valutazione dell’efficienza dell’algoritmo.
- Stabilità → capacità dell’algoritmo di non amplificare troppo gli errori dovuti alle operazioni di macchina