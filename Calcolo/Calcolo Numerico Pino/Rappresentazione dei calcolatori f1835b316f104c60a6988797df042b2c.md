# Rappresentazione dei calcolatori

## Rappresentazione fixed point degli interi

Al momento della assegnazione di un valore intero, questo valore viene trasformato in una stringa di cifre binarie secondo le regole del formato fixed point (virgola fissa).

Il formato fixed point dipende da un parametro che indichiamo con $t$ 

- Viene riservato in memoria uno spazio di $t+1$ bit (formati standard  $t+1 = 16$,  $t+1 = 32$ )
- Indichiamo con $f_i(N)$ la stringa id cifre binarie ottenuta applicando le regole del formato all’interno N.

![Untitled](Untitled%204.png)

Per un generico $t$ l’intervallo corrispondente è $[-2^t,2^t-1]$ → intervallo di esatta rappresentazione degli interi.

- $N<-2^t$ → underflow intero, perdita di informazione a causa di un numero troppo piccolo
- $N>2^t-1$ → overflow intero, perdita di informazione a cuasa di un numero troppo grande

### Regole della rappresentazione fixed point degli interi

- Se $N \geq 0$ si memorizzano le $t+1$ cifre meno significative, $d_t, d_{t-1},\dots, d_0$ della sua rappresentazione binaria (eventuali zeri a sinistra compresi)
- Se $N<0$ si prendono $t+1$ cifre meno significative $d_t, d_{t-1}, \dots, d_0$  della rappresentazione binaria di $|N|$ (eventuali zeri a sinistra compresi) e si calcola la rappresentazione in complemento a 2 (inversione cifre, somma 1).

### Conclusioni

- Il calcolatore rappresenta gli interi in formato fixed point
- Solo un sottoinsieme limitato di interi è rappresentato esattamente al
calcolatore (se il numero è fuori da questo sottoinsieme → underflow/overflow)

## Rappresentazione dei numeri floating point

Fissata una base β, ogni numero reale α si può rappresentare in modo univoco nella forma

$$
α = ±mβ^p
$$

$$
a\in\mathbb{R} \Longleftrightarrow \alpha = \pm(0.a_1a_2\dots a_ta_{t+1}\dots)_\beta\beta^r

$$

Osserviamo che le cifre di rappresentazione  della mantissa potrebbero essere infinite e che l’esponente può essere qualsiasi intero, e l’insieme dei numeri floating point viene limitato ponendo limiti su numero di cifre di rappresentazione e sulla massima dimensione dell’esponente.

Questo insieme è definito con

$$
F(\beta, t, L, U) =\{\pm(0.a_1a_2 \dots a_t)_\beta \beta^r :a_i \in \{0,\dots,\beta -1\}, \forall i = 1,\dots, t, a_1 \neq 0 , r \in \mathbb{Z} , L \leq r \leq U  \} 
$$

Dove $\beta$  → base, $t$ → numeri cifre mantissa, $L:U$ è l’intervallo degli esponenti. 

- Insieme discreto e finito di numeri reali
- Simmetrico rispetto all’origine
- Sottoinsieme di R che dipende da beta
- Insieme normalizzato (prima cifra mantissa diversa da 0)
- l’insieme F è dato da tutti i reali che possono essere scritti con t cifre di precisione mantissa la cui prima cifra deve essere diversa da 0
    - Numero più grande dell’insieme → $(1.1\dots1)_2 2^U = (2-2^{1-t})2^U$
    - Numero più piccolo in valore assoluto → $(1.0\dots0)_2 2^L = 2^L$

### Osservazioni

- Attorno allo 0 c’è un intervallo $[-2^L, 2^L]$ di numeri reali che vengono rappresentati come 0 (underflow floating point)
- Per numeri più grandi di $(2-2^{1-t})2^U$ o più piccoli di $-(2-2^{1-t})2^U$ si incorre in overlfow floating point
    - con gli interi lo possiamo vedere come un anello in quanto viene fatto un troncamento
    - con i reali non ho un intervallo e valori troppo grandi sono memorizzati con una stringa di bit riservata appositamente per queste situazioni (solitamente Inf). Allo stesso modo, numeri troppo piccolo vengono rappresentati rispettivamente come 0 o -Inf.
- Numeri piccoli sono meglio rappresentati

### Formati standard

![Untitled](Untitled%205.png)

Nota bene  

- gli esponenti sono memorizzati in forma traslata. Nello speciifco, sommo una costante detto bias (127 o 1023) all’esponente in modo da avere solo esponenti positivi e non dover gestire i casi negativi.
- la prima cifra della mantissa è $a_2$ poichè $a_1$ è obbligatoriamente 1 e non viene memorizzata

### Problemi

- Esponente troppo grande → numero rappresentato in maniera univoca con una stringa di bit corrispondente all’infinito
- Esponente troppo piccolo → numero rappresentato con 0
- Numero di cifre della mantissa superiore rispetto a quello disponibile →  si arrotonda o si tronca la mantissa alla t-esima cifra significativa dove
    - arrotondamento → guardo la cifra significativa precedente a quelle da scartare
        - se è 1 sommo 1 alla cifra meno significativa di quelle che terrò
        - se è 0 non faccio nulla
    - troncamento → elimino le cifre in più

Esempio $\beta = 2, t = 3, L = -2 , U = 1$ 

$$
2.25=(1.001)*2^1 
$$

- Troncamento:  $1.00 *2^1$
- Arrotondamento:  $1.01 *2^1$

## Gli errori

Ogni volta che un numero reale viene rappresentato in virgola mobile con
precisione finita (t fissato), se questo non appartiene all’insieme $F(\beta, t, L, U)$ si
ha una perdita di informazione, ossia si commette un errore.

### Errore assoluto

Sia $\alpha$  un numero reale. L’errore assoluto commesso approssimando $\alpha$  con un altro numero reale $\alpha^*$ è definito come

$$
E_a = |\alpha - \alpha^*|
$$

### Errore relativo

Se $\alpha \neq0$ si definisce l’errore relativo come

$$
E_r = \frac{E_a}{|\alpha|}
$$

Effettivamente l’errore relativo ci dà un’idea di quanto stiamo sbagliando. 

## Teorema dell’errore di rappresentazione dei numeri reali

Sia $\alpha$ un numero reale e $fl(\alpha)$  la sua rappresentazione in virgola mobile in base $\beta$, con t cifre di precisione per la mantissa. L’errore relativo commesso approssimando $\alpha$ con $fl(\alpha)$  soddisfa la seguente disuguaglianza

$$
\frac{|fl(\alpha)-\alpha|}{|\alpha|} \leq k\beta^{1-t}
$$

dove $k=1/2$ o $k=1$ a seconda che la rappresentazione sia ottenuta per arrotondamento o per troncamento, rispettivamente.

- La quantità $u=k\beta^{1-t}$ che si trova al lato destro della disuguaglianza si chiama precisione di macchina (quantità che disitingue le operazioni sentite e non dal calcolatore).
- La precisione di macchina u può essere definita coe il più piccolo numero reale tale che $fl(1+u)\neq 1$