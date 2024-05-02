# <u>Calcolo Numerico</u>

# ARITMETICA DI MACCHINA

## 1. Rappresentazione dei numeri

- Entità Astratta "sette"

- Rappresentazione: 7, VII (111)2

<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-04-12-13-56-13-image.png" title="" alt="" width="391">

Il formato fixed point è utilizzato dal calcolatore per rappresentare gli interi, ma solo un sottoinsieme limitato di interi può essere rappresentato esattamente. Numeri troppo grandi o troppo piccoli possono causare overflow o underflow, risultando in una perdita di informazione e un errore di rappresentazione. Le operazioni aritmetiche tra numeri fixed point producono risultati che rientrano nell'intervallo [-2^t, 2^t - 1], dove \( t \) è il numero di bit riservati alla parte frazionaria. In caso di overflow o underflow, anche il risultato dell'operazione sarà rappresentato con un errore.

## 2. Numeri di macchina

Il concetto di numeri di macchina, o numeri fixed point, si riferisce alla rappresentazione di numeri interi su un calcolatore utilizzando un formato fisso, dove un certo numero di cifre è riservato per la parte intera e/o frazionaria. Ecco una spiegazione dettagliata basata sul testo che hai fornito:

1. **Rappresentazione Fixed Point**: In questo sistema, gli interi sono rappresentati utilizzando un numero fisso di cifre, con una parte dedicata alla parte intera e/o alla parte frazionaria.

2. **Precisione Limitata**: Poiché è allocato solo un numero finito di cifre per rappresentare gli interi, solo un sottoinsieme limitato di interi può essere rappresentato esattamente. Questo significa che alcuni numeri interi, soprattutto quelli troppo grandi o troppo piccoli, non possono essere rappresentati con precisione e possono portare a errori di rappresentazione.

3. **Overflow e Underflow**: Quando un calcolatore tenta di rappresentare un numero troppo grande (overflow) o troppo piccolo (underflow) per essere rappresentato con precisione nel formato fixed point, si verificano errori di rappresentazione. In caso di overflow, il numero risultante può essere rappresentato come un numero con un valore più vicino al limite massimo rappresentabile; mentre in caso di underflow, il numero risultante può essere rappresentato come zero o un valore più vicino al limite minimo rappresentabile.

4. **Risultati delle Operazioni Aritmetiche**: Quando vengono eseguite operazioni aritmetiche tra numeri fixed point, i risultati sono rappresentati all'interno di un intervallo specifico, che dipende dalla precisione dei numeri. Solitamente, i risultati sono rappresentati utilizzando un numero finito di cifre meno significative, garantendo che rimangano all'interno dell'intervallo definito.

5. **Errore nei Risultati delle Operazioni**: Se durante l'esecuzione di operazioni aritmetiche si verificano overflow o underflow, anche il risultato dell'operazione può essere rappresentato con un errore, poiché potrebbe essere necessario approssimare il risultato per farlo rientrare nell'intervallo consentito.

## 3. Numeri di macchina , Floating point

I numeri floating point sono una rappresentazione dei numeri reali su un calcolatore, che impiegano una mantissa finita e un'esponente limitato. Questo permette di approssimare un insieme infinito di numeri reali in modo discreto e finito. 

Partendo dal concetto di numeri floating point definito nel testo, possiamo astrarre i seguenti punti chiave:

1. **Rappresentazione Generale**: Un numero floating point $a$ può essere scritto come  $± (0.a1a2 . . . at)_ββ^r$, dove $B$ è la base del sistema (ad esempio, 2 per la rappresentazione binaria), $ai$ sono le cifre della mantissa (limitate da $B$ - 1 ) e $r$ è l'esponente intero.

2. **Limitazioni**: Per ottenere un insieme finito di numeri floating point, si impone un limite al numero di cifre della mantissa (indicate con \( t \)) e si stabiliscono limiti inferiore e superiore per l'esponente (indicati con \( L \) e \( U \)).

3. **Insieme dei Numeri Floating Point**: $F(B, t, L, U) $ è l'insieme dei numeri floating point definiti con le limitazioni sopra descritte.

4. **Rappresentazione Binaria**: Per la rappresentazione binaria, l'insieme dei numeri floating point si scrive come \( F(2, t, L, U) \), dove le cifre della mantissa sono limitate a \( 0 \) o \( 1 \) (data la normalizzazione).

5. **Valori Massimi e Minimi**:
   Il numero positivo più grande dell’insieme (realmax in MATLAB) è
   $(1.1 . . . 1_22^U = (2 − 2^{t-1})2^U$
   Il numero positivo più piccolo dell’insieme (realmin in MATLAB) è
   $(1.0 . . . 0)_22^L = 2^L.$

Per rappresentare il numero \( $a$= 12.3125 \) in precisione singola, dobbiamo utilizzare il formato standard IEEE 754 per la rappresentazione floating point. Seguendo le indicazioni fornite, convertiamo prima il numero in binario:

$(12.3125)_{10} = (1100.0101)_2 = (1.1000101)_{2}2^3$

Dove \( $p = 3 $\) e quindi \($ p + bias = 130$ \), e \( $(130)_{10} = (10000010)_2$ \).

Le regole per la rappresentazione floating point dei reali ci dicono che dobbiamo approssimare il numero \( $a$) ad un elemento dell'insieme  $F(B, t, L, U)$. Se il numero non appartiene a tale insieme, deve essere rappresentato tramite arrotondamento o troncamento della mantissa alla \( t \)-esima cifra significativa.

In questo caso, $a$ non appartiene all'insieme $F(\beta, t, L, U) $ poiché la mantissa è di lunghezza superiore a \( t \). Quindi, dobbiamo arrotondare o troncare la mantissa a \( t \) cifre significative. 

Poiché $(a_{t+1} = 1) e (a_{t+2} = 0)$, la regola di arrotondamento ci indica di arrotondare verso l'alto. Quindi, la rappresentazione floating point di $a$ sarà:

$f_l(\alpha) = (1.100)_2^{130}$

In altre parole, il numero reale $a$ viene rappresentato in formato floating point con arrotondamento della mantissa e con l'esponente 130.

Se un numero reale $a$ viene rappresentato esattamente come un elemento dell'insieme \($F(B, t, L, U) $), allora si dice che $a$ è un numero di macchina.

<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-04-23-17-26-59-image.png" title="" alt="" width="504">
Gli errori assoluti ed errori relativi sono concetti fondamentali nel calcolo numerico che ci consentono di valutare l'accuratezza delle nostre approssimazioni rispetto ai valori reali.

1. **Errore Assoluto (Ea)**: Misura la discrepanza tra il valore vero \( $\alpha $\) e l'approssimazione \( $\alpha^*$ \) tramite la differenza assoluta  $ | \alpha - \alpha^* |$.  È una misura diretta della quantità di errore nella nostra approssimazione.

2. **Errore Relativo (Er)**: Esprime l'errore assoluto in rapporto al valore vero \( \alpha \), calcolato come \( $\frac{Ea}{|\alpha|}$ \) se \($ \alpha \neq 0 $\). Questo ci dà un'idea della precisione relativa della nostra approssimazione rispetto al valore vero.

La **precisione di macchina** è una misura della più piccola quantità positiva che può essere rappresentata in virgola mobile. È determinata dalla base \( \beta \) del sistema di numerazione, il numero di cifre di precisione per la mantissa \( t \) e dal metodo di approssimazione (troncamento o arrotondamento).

Il **Teorema dell'Errore di Rappresentazione** fornisce un limite superiore all'errore relativo commesso nell'approssimare un numero reale \( $\alpha$ \) con la sua rappresentazione in virgola mobile \($fl(\alpha$) \). Questo limite è dato da \( $k \beta^{1-t}$), dove \( k \) è 1 per il troncamento e \( $\frac{1}{2}$) per l'arrotondamento.

La precisione di macchina \( u \) è anche definita come il più piccolo numero positivo tale che \( $fl(1 + u) \neq 1$). In altre parole, è il più piccolo numero che, sommato a 1, produce una rappresentazione diversa da 1.

Nei tuoi esempi, assumendo \( $\beta = 2 $\) e \($ t = 3$ \) con troncamento e arrotondamento, la precisione di macchina è \( $u = 2^{-2}$ \) e \( u = 1 \) rispettivamente. Questo significa che, per il troncamento, il più piccolo numero rappresentabile dopo 1 è \( $1 + 0.01 = 1.01$ \), mentre per l'arrotondamento è \( $1 + 0.001 = 1.001$ \). In entrambi i casi, tentativi successivi di rappresentare numeri più piccoli comportano una perdita di informazione.

1. **Errore Assoluto (Ea)**:
   Misura la discrepanza tra il valore vero ( \alpha ) e l'approssimazione ( \alpha^* ) tramite la differenza assoluta ( | \alpha - \alpha^* | ). È una misura diretta della quantità di errore nella nostra approssimazione.
   
   $Ea = |a - a^*| $

2. **Errore Relativo (Er)**:
   Esprime l'errore assoluto in rapporto al valore vero ( \alpha ), calcolato come ( \frac{Ea}{|\alpha|} ) se ( \alpha \neq 0 ). Questo ci dà un'idea della precisione relativa della nostra approssimazione rispetto al valore vero.
   $Er = \frac{Ea}{|a|}$

3. **Precisione di Macchina (u)**:
   è una misura della più piccola quantità positiva che può essere rappresentata in virgola mobile. È determinata dalla base ( \beta ) del sistema di numerazione, il numero di cifre di precisione per la mantissa ( t ) e dal metodo di approssimazione (troncamento o arrotondamento).
   $u = k B^{1-t} $

4. **Teorema dell'Errore di Rappresentazione**:
   ![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-23-17-34-39-image.png)

5. **Proprietà della Precisione di Macchina**:
   $fl(1 + u) \neq 1$

Nei tuoi esempi:

6. **Precisione di Macchina con Troncamento**:![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-23-17-36-41-image.png)

7. **Precisione di Macchina con Arrotondamento**:![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-23-17-36-25-image.png)

## 4. Operazioni con i numeri floating point

### Somma algebrica (somma/differenza aritmetica):

1. **Denormalizzazione**: Porta entrambi gli addendi ad avere lo stesso esponente, che è il maggiore tra i due esponenti originali. Le mantisse vengono traslate verso destra e l'esponente viene incrementato di conseguenza.

2. **Somma delle mantisse**: Le mantisse normalizzate vengono sommate. Il risultato viene temporaneamente memorizzato in un registro che può contenere più cifre della rappresentazione finale.

3. **Troncamento o arrotondamento**: Si considerano solo le prime t cifre significative del risultato temporaneo. Questo può comportare un troncamento o un arrotondamento del risultato.

4. **Normalizzazione**: Il risultato viene portato nella forma normalizzata, modificando l'esponente di conseguenza. Se il risultato è maggiore o uguale a 1, viene fissato il bit più significativo a 1. L'esponente viene aggiornato di conseguenza.

### Prodotto:

1. Si esegue il prodotto tra le mantisse degli operandi, troncando o arrotondando il risultato a t cifre significative.

2. Se il risultato del prodotto ha uno zero a destra del punto radice, viene impostato un bit specifico a 1, altrimenti a 0.

3. L'esponente del risultato è la somma degli esponenti originali, meno il bit appena calcolato.

### Quoziente:

1. Si verifica se il dividendo è maggiore del divisore. Se lo è, viene impostato un bit specifico a 1, altrimenti a 0.

2. Si esegue la divisione normalizzata tra le mantisse, tenendo conto del bit calcolato al passo precedente. Si considerano solo le prime t cifre significative del risultato.

3. L'esponente del risultato è la differenza degli esponenti originali, più il bit appena calcolato.

In generale, queste operazioni mostrano come la rappresentazione dei numeri floating point possa introdurre errori nei calcoli, specialmente quando i risultati non appartengono all'insieme specificato e devono essere approssimati.

### Teorema dell'errore di rappresentazione del risultato delle operazioni:

Questo teorema afferma che l'errore relativo commesso nell'approssimare il risultato esatto di un'operazione aritmetica tra due numeri floating point con la loro rappresentazione floating point è limitato da una certa quantità, espressa come una costante k moltiplicata per β^(1-t), dove β è la base, t è il numero di cifre della mantissa e k può essere 1/2 o 1 a seconda se la rappresentazione è ottenuta per arrotondamento o troncamento rispettivamente. Questo teorema si basa sul teorema dell'errore di rappresentazione dei numeri reali, applicato specificamente al caso di una operazione aritmetica.

### Non validità di alcune proprietà delle operazioni aritmetiche:

- **Elemento neutro non unico**: A differenza delle operazioni usuali, l'elemento neutro rispetto alla somma nei numeri floating point potrebbe non essere unico a causa della rappresentazione limitata.
- **Proprietà associativa**: La somma non gode sempre della proprietà associativa a causa dei limiti di precisione e della rappresentazione finita dei numeri floating point.
- **Proprietà distributiva**: La somma potrebbe non godere della proprietà distributiva rispetto al prodotto, poiché i numeri floating point sono rappresentati con una precisione finita.
- **Legge di annullamento del prodotto**: Questa legge potrebbe non essere valida per i numeri floating point a causa della rappresentazione finita e della precisione limitata.

### Conclusioni:

- A causa della memoria finita del calcolatore e delle regole dell'aritmetica di macchina, le operazioni di macchina non soddisfano molte delle proprietà fondamentali delle operazioni usuali.
- Ogni assegnazione di un valore reale a una variabile e ogni operazione aritmetica eseguita sul calcolatore potrebbero comportare un potenziale errore a causa della rappresentazione finita dei numeri e della precisione di macchina.
- Gli algoritmi possono fornire risultati con errori diversi, quindi è importante valutarli per selezionare quelli che producono errori più piccoli.

In sostanza, questo testo mette in luce le sfide e le limitazioni dell'aritmetica di macchina e sottolinea l'importanza di comprendere e gestire gli errori associati alle operazioni aritmetiche sui numeri floating point.

## 5. Analisi del Errore

Gli errori di arrotondamento nelle operazioni e/o gli errori sui dati possono
“accumularsi” nella successione delle operazioni, determinando
un’amplificazione dell’errore sul risultato finale dell’algoritmo.

Comprendere il condizionamento di un problema è cruciale per valutare 
l'affidabilità dei risultati ottenuti mediante algoritmi numerici e per 
scegliere il metodo computazionale più appropriato per risolvere il 
problema in questione.

La valutazione di un algoritmo numerico deve tenere conto non solo
dell’efficienza (complessità computazionale), ma anche della stabilità.
Particolari cautele vanno adottate nell’interpretare i risultati di un algoritmo
numerico applicato ad un problema mal condizionato.

Nell’Analisi Numerica, lo studio della propagazione degli errori viene
condotto sotto due punti di vista differenti:

### 1_Stabilita degli algoritmi

![](C:\Users\baleo\AppData\Roaming\marktext\images\2024-04-12-13-30-18-image.png)

- La stabilità dipende dal numero, dal tipo e dall’ordine delle operazioni
  eseguite dall’algoritmo.

- Un algoritmo A è più stabile dell’algoritmo B se l’errore algoritmico di A è più
  piccolo dell’errore algoritmico di B.

### 2_Condizionamento dei problemi

![](C:\Users\baleo\AppData\Roaming\marktext\images\2024-04-12-13-28-52-image.png)<img title="" src="file:///C:/Users/baleo/AppData/Roaming/marktext/images/2024-04-12-13-33-53-image.png" alt="" data-align="center" width="402">In questo caso, una piccola perturbazione nel 
parametro c produce una variazione significativa nelle soluzioni, con la
 variazione sulla soluzione che è di tre ordini di grandezza superiore 
alla perturbazione sui dati stessi. Questo indica una notevole 
instabilità nel calcolo delle soluzioni quando il parametro c è prossimo
 a 4.

### Errore totale

![](C:\Users\baleo\AppData\Roaming\marktext\images\2024-04-12-13-35-34-image.png)

## 7. Errori numerici: la derivazione numerica in MATLAB

### Problema:

Il problema è quello di calcolare il valore approssimato della derivata di una funzione f in un punto utilizzando un approccio numerico.

### Approccio numerico:

Si utilizza un algoritmo che approssima la derivata utilizzando un rapporto incrementale:
\[ $f'(a) = \lim_{h \to 0} \frac{f(a+h) - f(a)}{h}$ \]

### Verifica sperimentale:

Si sceglie la funzione \( $f(x) = \sin(x)$ \) e si vuole calcolare numericamente la derivata prima in \( $a = 1$ \).

### Problema test:

Viene scritto un programma MATLAB per calcolare il valore approssimato della derivata utilizzando diverse scelte di \( h \), con \( h \) variante da \( $10^{-1}) a ( 10^{-16}$ \).

### Derivazione numerica:

Contrariamente alle aspettative, si trova un valore minimo dell'errore in corrispondenza di \( $h = 10^{-8}$ \), mentre per valori più piccoli di \( h \) l'errore è più grande.

### Analisi dell'errore:

Si suppone che gli errori di rappresentazione dei valori \( f(a) \) e \( f(a+h) \) siano maggiorati da una costante \( \delta \). Si analizza l'errore assoluto e si conclude che \( h \) non tende a zero all'aumentare di \( h \), bensì ad un valore minimo, spiegando il motivo per cui l'errore relativo minimo si ottiene proprio in corrispondenza di \( $h = 10^{-8}$ \).

# METODI PER I SISTEMI LINEARI

## Definizione di Matrice:

Una matrice è una tabella di elementi organizzata in righe e colonne. Formalmente, una matrice \( A \) di dimensioni \( m \times n \) è una funzione che associa ad ogni coppia di indici \( (i, j) \) un valore \( a_{ij} \), dove \( i \) rappresenta l'indice di riga e \( j \) l'indice di colonna.

### Elementi di una Matrice:

L'elemento generico di una matrice è indicato come \( a_{ij} \), dove \( i \) è l'indice di riga e \( j \) è l'indice di colonna. Gli elementi sulla diagonale principale, cioè quelli con \( i = j \), sono chiamati elementi diagonali.

### Tipi Speciali di Matrici:

- **Matrice Quadrata**: Una matrice è quadrata se ha lo stesso numero di righe e colonne (ossia \( m = n \)).
- **Vettore Colonna**: Una matrice con una singola colonna è detta vettore colonna.
- **Vettore Riga**: Una matrice con una singola riga è detta vettore riga.
- **Matrice Identità**: Una matrice diagonale con tutti gli elementi diagonali uguali a 1 e gli altri elementi nulli.
- **Matrice Diagonale**: Una matrice in cui tutti gli elementi al di fuori della diagonale principale sono nulli.
- **Matrice Triangolare Superiore**: Una matrice quadrata in cui tutti gli elementi al di sotto della diagonale principale sono nulli.
- **Matrice Triangolare Inferiore**: Una matrice quadrata in cui tutti gli elementi al di sopra della diagonale principale sono nulli.

### Trasposta di una Matrice:

La trasposta di una matrice \( A \), indicata come \( A^T \), è ottenuta scambiando le righe con le colonne di \( A \).

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-24-23-10-00-image.png)

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-24-23-10-40-image.png)

### Memorizzazione delle Matrici:

Conoscere la struttura di una matrice può ridurre l'occupazione di memoria. Ad esempio, le matrici diagonali e triangolari hanno molti elementi nulli che non devono essere memorizzati esplicitamente.

Le matrici e i vettori sono ampiamente utilizzati in vari contesti, inclusi sistemi lineari, trasformazioni geometriche, e analisi numerica. La comprensione dei concetti fondamentali delle matrici è essenziale per il calcolo numerico e l'analisi matematica.

# METODI PER EQUAZ. E SISTEMI NON LINEARI

Le operazioni matriciali sono fondamentali nell'ambito del calcolo numerico e trovano ampio utilizzo in numerosi campi, tra cui l'analisi numerica, l'ingegneria, la fisica, la statistica e molti altri. Ecco una panoramica delle operazioni matriciali più comuni:

1. **Somma Matriciale**: Date due matrici della stessa dimensione \( A \) e \( B \), la loro somma \( A + B \) è una matrice \( C \) ottenuta sommando elemento per elemento le corrispondenti entrate di \( A \) e \( B \).

2. **Prodotto di una Matrice per uno Scalare**: Il prodotto di una matrice \( A \) per uno scalare \( \lambda \) è ottenuto moltiplicando ogni elemento di \( A \) per \( \lambda \).

3. **Prodotto Matrice-Matrice**: Date due matrici \( A \) e \( B \), il loro prodotto \( AB \) è una nuova matrice \( C \) il cui elemento nella riga \( i \) e colonna \( j \) è dato dalla somma dei prodotti delle righe di \( A \) con le colonne di \( B \).

4. **Prodotto Matrice-Vettore**: Date una matrice \( A \) e un vettore \( x \), il prodotto \( Ax \) è un nuovo vettore \( y \) ottenuto moltiplicando ogni riga di \( A \) per il corrispondente elemento di \( x \) e sommando i risultati.

5. **Prodotto Scalare tra Vettori**: Il prodotto scalare tra due vettori \( u \) e \( v \) è ottenuto moltiplicando le loro componenti corrispondenti e sommando i risultati.

Queste operazioni sono regolate da alcune proprietà:

- **Proprietà Associativa**: Il prodotto tra matrici è associativo, cioè \( A(BC) = (AB)C \) per qualsiasi scelta di matrici \( A \), \( B \), e \( C \) compatibili.

- **Proprietà Distributiva**: Il prodotto di una matrice per la somma di due altre matrici è distributivo, cioè \( A(B + C) = AB + AC \).

- **Non Commutatività**: In generale, il prodotto di matrici non è commutativo, cioè \( AB \) può essere diverso da \( BA \).

- **Elemento Neutro del Prodotto Matrice-Matrice**: L'elemento neutro del prodotto matrice-matrice è la matrice identità \( I \), che mantiene invariata una matrice quando moltiplicata per essa.

- **Proprietà del Prodotto Scalare tra Vettori**: Il prodotto scalare tra due vettori soddisfa alcune proprietà analoghe al prodotto scalare tra numeri reali, come la commutatività e la linearità.

ARRIVATO BLAS

# APPROSSIMAZIONE DI DATI E DI FUNZIONI
