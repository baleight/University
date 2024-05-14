# Interpolazione polinomiale a tratti

# Problemi del polinomio di interpolazione

I principali problemi e svantaggi del polinomio di interpolazione sono:

- dipende da (e si costruisce su) i punti di interpolazione, che devono essere noti a priori;
- con molti dati si ottiene un polinomio di grado alto;
- solitamente non è possibile scegliere la distribuzione dei nodi (che quasi sempre è uniforme), quindi rischia di presentarsi il fenomeno di Runge.

Invece di costruire una funzione interpolante che sia un globalmente un polinomio, si considerano funzioni polinomiali a tratti, che sono polinomi di un grado fissato se ristrette a ciascun sottointervallo $[x_i, x_{i+1}]$

$$
s(x)=\begin{cases}
s_0(x) & x \in [x_0,x_1]\\
\vdots\\
s_m(x) & x \in [x_m,x_{m+1}]
\end{cases}
$$

La funzione $s$ sarà sicuramente continua ma non derivabile ($C^0$).

## Interpolante lineare a tratti

Fissati $m+2$ punti di interpolazione $(x_i, y_i), \; i =0, \dots, m+1$ si definisce la funzione lineare a tratti $s_i(x)$ che interpola i punti come:

$$
s_i(x) =\underbrace{ y_i + \frac{y_{i+1} -y_i}{x_{i+1}-x_i}(x-x_i)}_{s_i(x)} \qquad \text{se} \space x\in[x_i,x_{i+1}], i = 0, \ldots, m
$$

- Esempio
    
    ![Untitled](Untitled%2018.png)
    
- se $y_i  \ne y_{i+1}$
    
    $$
    \frac{s_i(x) - y_i}{y_{i+1} - y_i} = \frac{x - x_i}{x_{i+1} - x_i} \Rightarrow s_i(x) = \frac{x - x_i}{x_{i+1} - x_i} (y_{i+1} - y_i) + y_i = \\
    \underbrace{\frac{y_{i+1}-y_i}{x_{i+1}-x_i}}_{m}x \underbrace{ - \frac{y_{i+1}-y_i}{x_{i+1}-x_i}x_i +y_i}_{q}
    $$
    
    quindi poniamo
    
    $$
    \begin{matrix}
    m = \frac{y_{i+1} - y_i}{x_{n+1} - x_i} \\
    q = y_i - x_i \frac{y_{i+1} - y_i}{x_{i+1} - x_i}
    \end{matrix}
    \Rightarrow
    s_i(x) = x \, m + q
    $$
    
- se $y_i = y_{i+1}$
    
    $$
    s_i(x) = y_i
    $$
    

In generale abbiamo $s(x) = s_i(x) \quad x \in [x_i, x_{i+1}]$

$$
s(x) = \begin{cases}
s_0(x) & x \in [x_0, x_1] \\
s_1(x) & x \in [x_1, x_2] \\
s_2(x) & x \in [x_2, x_3] \\
\vdots \\
s_m(x) & x \in [x_m, x_{m+1}] \\
\end{cases}
$$

## Errore nell’interpolazione

- Supponiamo che $y_i = f(x_i), i = 0, \ldots, m+1$
- Obiettivo: vogliamo studiare la funzione resto $R^s(x) = f(x) - s_(x)$
- Ipotesi: $f \in C^2 ([x_0, x_{m+1}])$
- Conviene considerare la funzione resto $R^s(x)$ restringendosi a $[x_i, x_{i+1}]$

Prendiamo un intervallo con estremi $x_i$ e $x_{i+1}$, quindi nell’intervallo abbiamo $2$ nodi di interpolazione e si distinguono:

- $f(x)$
- $s_i(x)$

con $x \in [x_i, x_{i+1}]$

Siccome il grado del polinomio interpolante è $n=1$, il resto vale:

$$
R(x) = f(x) -s_i(x) = \frac{\omega_{x_0, \dots, x_n}(x)}{(n+1)!}|f^{(n+1)}(\xi)| = \frac{(x- x_i)(x - x_{i+1})}{2 !} f''(\xi) , \quad \text {con } \xi \in [x_i, x_{i+1}]
$$

- **denominatore**
    
    Al denominatore abbiamo $2!$ che essendo una costante, non può essere maggiorata.
    
- **numeratore**
    
    Il numeratore può essere diviso in $2$ parti:
    
    - $f''(\xi) \rightarrow M$
        
        Vogliamo massimizzare (cioè prendere il valore più grande) della derivata seconda di $x$ in tutti l’intervallo $[a,b]$. Per evitare problemi di massimo/minimo conviene usare il valore assoluto:
        
        $$
        M = \max_{x \in [a, b]} |f''(x)|
        $$
        
    - $(x- x_i) (x- x_{i+1}) \rightarrow \frac{h^2}{4}$
        
        Vogliamo trovare:
        
        $$
        \max_{x \in [x_i, x_{i+1}]} \vert (x- x_i) (x - x_{i+1}) \vert
        $$
        
        Chiamiamo $q(x) = (x-x_i)(x-x_{i+1})$ e risolviamolo. Otteniamo $q(x) = x^2 - x(x_i+x_{i+1}) + x_i \,x_{i+1}$
        
        Siccome voglio il punto di massimo di $q(x)$ calcolo $q'(x)$ e trovo il valore delle ascisse per il quale la funzione è massima:
        
        $$
        q'(x) = 2x - (x_i + x_{i+1}) = 0 \Leftrightarrow x = \frac{x_i + x_{i+1}}{2}
        $$
        
        Quindi possiamo scrivere la seguente equivalenza
        
        $$
        \max_{x \in [x_i, x_{i+1}]} \vert (x- x_i) (x - x_{i+1}) \vert = \bigg\vert q \bigg(\frac{x_i + x_{i+1}}{ 2 }\bigg)\bigg\vert 
        \\=
        \bigg\vert \bigg(\frac{x_i + x_{i+1}}{ 2 }-x_i\bigg) * \bigg(\frac{x_i + x_{i+1}}{ 2 }-x_{i+1}\bigg) \bigg\vert
        = \\
        = \bigg\vert -\bigg(-\frac{x_{i+1}}{2}+\frac{x_1}{2}\bigg)^2 \bigg\vert \\= 
        
        \bigg\vert \frac {(-x_i + x_{i+1})^2}{4}\bigg\vert
        $$
        
        A questo punto definiamo $h$ come
        
        $$
        h = (-x_i+x_{i+1}) \quad \rightarrow \quad \text {cioè l'ampiezza dell'intervallo}
        $$
        
        Allora abbiamo massimizzato il valore di $(x- x_i) (x- x_{i+1})$  come $\frac{h^2}{4}$ 
        
    
    Quindi abbiamo la seguente disuguaglianza:
    
    $$
    \vert R(x) \vert \le \frac M 8 h^2
    $$
    
    Dalla definizione di [norma di funzioni](Il%20problema%20dell%E2%80%99approssimazione%206ea484fabefb4f078a4debdfe443ca79.md) vale anche la seguente disuguaglianza
    
    $$
    \Vert f - s \Vert \le \frac M 8 h^2
    $$
    
- **caso particolare:** **nodi equispaziati**
    
    Nel caso in cui i nodi siano equsipaziati si ha che
    
    $$
    h = \frac {b- a}{m+1} \Rightarrow \Vert R(x) \Vert _\infty \le \frac M 8 \frac{(b-a)^2}{(m+1)^2}
    $$
    
    - Quindi con $m \rightarrow \infty$ si ha che la norma converge a $0$.
    - Con l’interpolazione a tratti NON si verifica il fenomeno di Runge

## Teorema

Sia $f \in C^2 ([a,b])$ e siano $x_0, \ldots, x_{m+1} \in [a,b]$. Indichiamo con $M_2^f$ il massimo di $|f''(y)|$ in $[a,b]$ e con $h$ la seguente quantità:

$$
h = \max_{i \in \{0,\ldots,m\}} (x_{i+1}-x_{i})
$$

Se $s(x)$ è il polinomio lineare a tratti tale che $s(x_i) = f(x_i), i = 0, \ldots, m+1$ allora si ha 

$$
\lVert R(x)\lVert_\infty= \max_{i \in[a,b]} |f(x)-s(x)| \leq \max _{i\in[a,b]} \frac{M_2^f}{8}h^2=\frac{M_2^f}{8}h^2
$$

## Svantaggi dell’interpolazione lineare a tratti

La funzione $s(x)$ è continua ma non derivabile. Si perde una caratteristica importante della funzione $f$. 

Si definisce una classe di funzioni polinomiali a tratti molto regolari: lo spazio delle funzioni spline. 

## Funzioni spline

I punti vengono uniti con delle parabole (non con le rette), tutte le funzioni che uniscono i punti si chiamano funzioni di spline.

### Definizione

Sia $[a,b]$ un intervallo e $x_0, \dots, x_{m+1}$ una partizione di esso tale che $x_0 = a$ e $x_{m+1} = b$. Si definisce spline di grado $n$ relativa alla partizione $x_0, \dots, x_{m+1}$ ogni funzione $s(x)$ tale che :

1. la funzione $s(x)$ ristretta all’intervallo $[x_i, x_{i+1}]$ è un polinomio $s_i(x)$ di grado al più $n$, per $i = 0, \dots, m$
2. la funzione $s(x)$ e tutte le sue derivate fino all’ordine $n-1$ sono continue nell’intervallo $[a,b]$:
    
    $$
    s \in C^{(n-1)}([a,b])
    $$
    

Si tratta di una funzione che deve essere derivabile $n-1$ volte con continuità. Si tratta di una generalizzazione di quella a tratti perchè se $n=1$ allora $C^0$ → $s$ è continua.

- La funzione $s$ ristretta ad ogni intervallo $[x_i,x_{i+1}]$  è $C^{(n-1)}$ perchè è un polinomio
- La seconda condizione equivale a richiedere che i polinomi $s_i(x)$
 soddisfino le seguenti condizioni
    
    $$
    s_i^{(k)}(x_{i+1}) =s_{i+1}^{(k)}(x_{i+1}),k=0, \ldots, n-1, i = 0, \ldots, m-1
    $$
    
    Ossia tutte le derivate sono continue
    

Per esempio prendendo $5$ punti $x_0, x_1, x_2, x_3, x_4$ ($b = x_4 \rightarrow x_{m+1} = b \rightarrow m = 3$) abbiamo che:

- $a = x_0$
- $b = x_4$

$s: [a,b] \rightarrow \mathbb R$

$$
s(x) = \begin{cases}
s_0 (x) & x \in [x_0, x_1]\\
s_1 (x) & x \in [x_1, x_2]\\
s_2 (x) & x \in [x_2, x_3]\\
s_3 (x) & x \in [x_3, x_4]\\
\end{cases}
$$

Quindi le $s_i(x)$ saranno così definite:

$$
s_0 (x) = a_0x^2 + b_0x +c_0 \quad : \quad  s_0(x_0) = y_0 \;\blue{\square} , s_0(x_1) = y_1 \;\blue{\square} \\
s_1 (x) = a_1x^2 + b_1x +c_1 \quad  : \quad  s_1(x_1) = y_1 \;\blue{\square} , s_1(x_2) = y_2 \; \blue{\square} \\
s_2 (x) = a_2x^2 + b_2x +c_2 \quad  : \quad  s_2(x_2) = y_2 \;\blue{\square} , s_2(x_3) = y_3 \; \blue{\square} \\
s_3 (x) = a_3x^2 + b_3x +c_3 \quad  : \quad  s_3(x_3) = y_3 \;\blue{\square} , s_3(x_4) = y_4 \; \blue{\square} \\
s_i(x) \longrightarrow \text{polinomio di grado 2} \longrightarrow n = 2
$$

Se noi vogliamo che $s \in C^1[a,b]$ deve succedere che nei punti $x_i$ (con $i\ne a,b$) la derivata destra deve essere uguale alla derivata sinistra. Cioé:

$$
s_0'(x_1) = s_1'(x_1)  \; \blue{\square} \\
s_1'(x_2) = s_2'(x_2)  \; \blue{\square} \\
s_2'(x_3) = s_3'(x_3)  \; \blue{\square} \\

$$

Gli $11$  $\;\blue{\square}$  sono le condizioni: passaggio per i punti (prime 8) e continuità delle derivate (ultime 3)

+1 parametro libero.

Le variabili sono i coefficienti dei polinomi.

Con $n=3$ si hanno delle parabole che possono cambiare concavità, permettono quindi di avere dei flessi.

### In generale…

- Ogni pezzo di spline $s_i(x)$ è un polinomio di grado $n$, e dipende da $n+1$ parametri, nonché i suoi coefficienti.
    
    $$
    s_i(x)= a_{0i}+a_{1i}x+ \ldots + a_{ni}x^n, \quad i = 0, \ldots, m
    $$
    
- In tutto ci sono $m+1$ pezzi
- In totale una spline dipende da $(n+1)(m+1)$ parametri

Le condizioni di regolarità

$$
s_i^{(k)}(x_{i+1}) =s_{i+1}^{(k)},k=0, \ldots, n-1, i = 0, \ldots, m-1
$$

sono $nm$ uguaglianze che fissano altrettanti parametri. 

> **Determinare una spline singnifica risolvere un sistema lineare per determinare i parametri della spline**
> 

## Gradi di libertà delle spline di grado $n$

Una spline di grado $n$ dipende da $(n+1)(m+1)$ parametri, di cui

sono liberi. Questo numero corrisponde ai gradi di libertà (o dimensione dello spazio) delle spline di grado $n$ relative ad $m+2$ punti.

$$
(n+1)(m+1)-nm=n+m+1
$$

Le condizioni di interpolazioni sono $m+2$ pertanto fissano altrettanti parametri. I gradi di libertà rimanenti sono quindi

$$
n+m+1-(m+2)=n-1
$$

Eccetto per il caso lineare ($n=1$) fissati i punti esistono infinite spline di grado $n$ che li interpolano al variare di $n-1$ parametri liberi.