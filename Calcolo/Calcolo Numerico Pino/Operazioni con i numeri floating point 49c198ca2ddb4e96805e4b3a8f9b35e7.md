# Operazioni con i numeri floating point

Osservazione: l’insieme F non è chiuso rispetto alle operazioni aritmetiche, e si possono verificare  situazioni che non appartengono né all’underflow che all’overflow. L’aritmetica che si va ad impiegare dovrà essere quindi architettata in modo da far rientrare i valori all’interno di F.

Il risultato di un’operazione tra numeri dell’insieme F è un numero reale: il risultato dell’operazione di macchina corrispondente è la rappresentazione floating point di esso.

La conseguenza dell’ultimo passaggio che definisce le operazioni di macchina è l’introduzione di un potenziale errore che capita ogni votla che il risultato dell’operazione non appartiene ad F e deve essere quindi arrotondato o troncato alla t-esima cifra della mantissa. 

## Teorema: errore di rappresentazione dei numeri reali ($\alpha=x\bullet y)$

Siano $x,y \in F(\beta, t,L,U).$ Indichiamo genericamente con $\bullet$ una qualsiasi delle quattro operazioni aritmetiche. L’errore relativo commesso approssimando il risultato esatto dell’operazione $x \bullet y$ con la sua rappresentazione floating point soddisfa la disuguaglianza

$$
\frac{|fl(x \bullet y)-(x \bullet y)}{|x \bullet y|} \leq k\beta^{1-t}

$$

dove $k=1/2$ o $k=1$ a seconda che la rappresentazione sia ottenuta per arrotondamento o per troncamento, rispettivamente.

Oppure, equivalentemente

$$
{fl(x \bullet y)=(x \bullet y)}{(1+\epsilon) \space \space \space |\epsilon|} \leq k\beta^{1-t}
$$

- Il calcolatore ha a disposizione un insieme limitato e finito di numeri reali → ogni volta che viene assegnato un valore reale ad una variabile in semplice o doppia precisione si commette un potenziale errore
- Il calcolatore utilizza un’aritmetica diversa dalla nostra → ogni qualvolta che si esegue un’operazione aritmetica si commette un potenziale errore
- Entrambi questi errori sono maggiorati dalla precisione di macchina.

### Errore di incolonnamento

LA somma di due addendi entrambi non nulli può dare come risultato il più grande ($x+y=x$  con $y \neq 0$) in valore assoluto se

$$
|y|\leq \frac{u}{\beta}|x|
$$

dove u è la precisione di macchina. L’errore di incolonnamento significa che per la somma floating point non c’è un unico elemento neutro. 

Ricorda: le operazioni di macchina non godono delle proprietà fondamentali per le operazioni usuali. 

- L’elemento neutro della somma e prodotto non è unico
- l’opposto di un numero non è unico
- Non sono valide
    - proprietà associativa di somma e prodotto
    - distributiva
    - legge di annullamento del prodotto

## Osservazione

In generale il risultato del calcolo di un’espressione, intesa come successione di
operazioni aritmetiche, dipende dall’algoritmo usato per calcolarla.

Siccome il risultato di operazioni di macchina contiene un errore, l’errore nel
risultato finale dipende dall’algoritmo utilizzato.

Vogliamo quindi valutare gli algoritmi per poter selezionare quelli che danno gli errori più piccoli.