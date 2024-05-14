# Il problema dell’approssimazione

# Definizione del problema

Noti un certo numero di punti del piano $(x_i, y_i), \; i = 0, \dots , n$ sapendo che $y_i = f(x_i)$ dove $f : [a,b] \rightarrow \mathbb R$  è una funzione che può non essere nota in forma analitica, si tratta di definire una funzione $g$ che ‘assomigli’ il più possibile ad $f$.

Sappiamo che dati $n+1$ punti $(x_i, y_i), \; i = 0, \dots, n$ esistono 2 tipi di soluzioni per trovare $g$

- **analitica** → la funzione $g$ viene definita in modo esplicito
- **numerica** → tramite degli algoritmi è possibile calcolare la funzione $g$ in un qualsiasi punto $\in [a,b]$

*Cosa si intende per “‘assomigli’ il più possibile ad $f$” ?*

Con il termine ‘assomigli’ si intende che preso un qualsiasi punto di un grafico di una funzione, esso discosti di una certa soglia rispetto a quello del grafico dell’altra funzione.

Sarebbe quindi necessario definire una tolleranza, che però può variare da funzione a funzione, perciò non è il massimo.

La soluzione migliore è usare le **norme di funzioni**.

## Norme di funzioni

Sia $f : [a, b] \rightarrow \mathbb R$  una funzione continua. Allora la **norma infinito** di $f$ è definita come

$$
\lVert f \lVert _\infty = \max_{x \in [a,b]}| f(x) |
$$

La distanza in norma infinito tra $f$ e $g : [a,b] \rightarrow \mathbb R$ è definita come $\lVert f - g \lVert _\infty$.

---

$|f(x)|$ è la lunghezza nelle ordinate tra $0$ e $f(x)$.

La norma restituisce sempre uno scalare reale, quindi ci permette di parlare di distanza tra funzioni utilizzando numeri reali.

$\lVert f - g \lVert _\infty$ significa fare il $\max$ della funzione differenza ($f- g$) in $x \in [a,b]$:

$$
\lVert f - g \lVert _\infty = \max_{x \in [a,b]} |f(x) - g(x)| = r
$$

Dove $r$ identifica la distanza tra le due funzioni $f$ e $g$

![Untitled](Untitled%2013.png)

Se$\lVert f - g \lVert _\infty < \epsilon,$ con $\epsilon>0$ allora il grafico di $g$ si trova in un ‘canale’ di raggio $\epsilon$ centrato sul grafico di $f$

## Errore (o resto) di interpolazione

**Ipotesi**: $p_n(x)$ è il polinomio di interpolazione relativo a $(x_i, f(x_i))$ con $i=0, \ldots, n$

**Obiettivo**: studiare la funzione $R_n(x)=f(x)-p_n(x)$
 e in particolare $\lVert R_n \lVert _\infty = \max_{x \in [a,b]} |f(x) - p_n(x)| = r$ per individuare le condizioni per cui $p_n(x)$ si può considerare una buona approssimazione di $f(x)$ nell’intervallo $[a,b]$. Ci aspettiamo quindi che $\lim_{n\rightarrow \infty} ||f -p_n|| = 0$

### Teorema

Sia $f \in C^{n+1} ([a,b])$ con $x_i \in [a,b], \; i = 0, \dots, n$ e sia $p_n(x)$ il polinomio di interpolazione relativo a $(x_i, f(x_i)), i=0, \dots, n$. 

Allora si ha che

$$
R_n(x) = \frac{\omega_{x_{0}, \dots, x_n}(x)}{(n+1)!} f^{(n+1)}(\xi)
$$

**Commento**

$f \in C^{n+1} ([a,b])$ significa che fino alla $n+1$-esima derivata di $f$, la funzione derivata che si ottiene è continua.

Si può dividere in 3 parti:

- Denominatore → porta a zero velocemente poiché un numero molto alto
- $\xi$ è un determinato punto di $[a,b]$ che dipende dai nodi $x_i$ e dipende da $x$
- $\omega$ è il prodotto di tutte le differenze tra le variabili e i nodi:
    
    $$
    \omega_{x_{0}, \dots, x_n}(x) = (x - x_0)(x - x_1)\dots(x - x_n)
    $$
    

Il denominatore e la $f^{(n+1)}$ dipendono tutti da $n$, quindi se $n$ tende ad infinito abbiamo 2 casi possibili:

- Il denominatore ‘va più forte’ quindi domina e tende a $0$
- Il numeratore e $f^{(n+1)}(\xi)$ vanno ‘più forti’ quindi diverge

## Analisi del resto di interpolazione

Assumendo $|R_n(x)|$  come misura dell’accuratezza tale misura dipende da tre fattori: 

- il grado $n$ del polinomio
- la scelta dei punti di interpolazione implicitamente contenuta nel termine $\omega_{x_{0}, \dots, x_n}(x)$
- la regolarità della funzione $f$

Dalla formula del resto d’interpolazione per una funzione $f\in C^{n+1}([a,b])$ si può dedurre la seguente stima:

$$
|R_n(x)| \leq \frac{(b-a)^{n+1}}{(n+1)!}M_n, \qquad \forall x \in [a,b]
$$

Dove $M_n := \max_{x \in [a,b]} | f^{(n+1)} (x)|$ è una costante che dipende dal problema e non dalle scelte di interpolazione

### 📜Dimostrazione

Abbiamo:

$$
|R_n(x)| = \frac{\omega_{x_0, \dots, x_n}(x)}{(n+1)!}|f^{(n+1)}(\xi)|
$$

Ci interessa stimare 2 parti:

1)

$$
|\omega_{x_0, \dots, x_n}(x)| = |x- x_0| \cdot |x - x_1| \dots |x - x_n|
$$

voglio che $|x -x_i| \le b -a \quad \forall x_i, \; \forall x \in [a,b]$

ciascuno dei sottointervalli è più piccolo dell’intervallo grande quindi posso dire che

$$
|\omega_{x_0, \dots, x_n}(x)| = |x- x_0| \cdot |x - x_1| \dots |x - x_n| \le (b-a) (b-a) \dots (b-a ) = (b-a)^{n+1}
$$

2)

$$
M_n := \max_{x \in [a,b]} | f^{(n+1)} (x)| \Rightarrow | f^{(n+1)} (x)| \le M_n
$$

Quindi di conseguenza possiamo scrivere:

$$
|R_n(x)| = \frac{\omega_{x_0, \dots, x_n}(x)}{(n+1)!}|f^{(n+1)}(\xi)| \le \frac{(b-a)^{n+1}}{(n+1)!}M_n \quad \forall x \in [a,b]
$$

Allora cos’è $\lVert R_n(x) \lVert$ ?

Non è altro che

$$
\max_{x \in [a,b]} |R_n(x)| \le \max_{x \in [a,b]} \frac{(b-a)^{n+1}}{(n+1)!} M_n =  \frac{(b-a)^{n+1}}{(n+1)!}M_n
$$

<aside>
💡 **OSSERVAZIONE**

$$
\lim_{n \rightarrow \infty} \lVert R_n \lVert _\infty \le \lim_{n \rightarrow \infty} \frac{(b-a)^{n+1}}{(n+1)!}M_n = 0
$$

In generale $\frac{(b-a)^{n+1}}{(n+1)!}$ tende sempre a $0$, quindi la convergenza dipende da $M_n$ quindi:

- $M_n \lt + \infty$ allora $\lVert R_n \lVert _\infty \rightarrow 0$ ossia convergenza uniforme della successione di polinomi $\{p_n\}_{n\in \mathbb N}$ alla funzione $f$

La convergenza uniforme garantisce una crescente accuratezza del polinomio $p_n$
su tutto $[a, b]$ e non soltanto in corrispondenza dei singoli punti dell’intervallo.

NB: Tuttavia, senza l’equilimitatezza delle derivate, la convergenza uniforme della successione dei polinomi d’interpolazione non è più garantita. Es: funzione di rounge

</aside>

## Funzione di Rounge

Supponiamo di interpolare la funzione di Rounge $f:[-1,1] \rightarrow \mathbb R$

$$
f(x)=\frac{1}{1+25x^2}
$$

![Untitled](Untitled%2014.png)

su una partizione di $n+1$ punti equispaziati nell’intervallo $[-1,1]$

$$
x_i = -1 + \frac {2i} n, \; i = 0, \dots , n
$$

Aumentando la derivata il comportamento asintotico cresce

![Untitled](Untitled%2015.png)

Aumentare il numero dei punti significa aumentare il numeratore (del polinomio omega), quindi non è detto che si vada alla convergenza.

Per evitare questo problema un modo è usare i nodi di Chebychev.

## Nodi di Chebychev

I nodi di Chebychev si ottengono partizionando in modo uniforme la semicirconferenza goniometrica e proiettando i punti di questa partizione sul diametro.

![Untitled](Untitled%2016.png)

Chiamiamo un nodo $t_i$

$$
t_i = \cos\bigg(\frac{(2i +1) \pi}{2(n+1)} \bigg), \; i = 0, \dots , n
$$

dove $(n+1)$ al denominatore è il numero dei nodi.

- 🔍 formula adattata a MatLab visto che non si può rappresentare lo 0
    
    Se $m=n+1 \rightarrow n = m-1$
    
    $$
    t_i = \cos\bigg(\frac{(2i +1) \pi}{2(m)} \bigg), \; i = 0, \dots , m-1 \\
    \Downarrow
    \\
    t_i = \cos\bigg(\frac{2(j-1)+1}{2(m)} \pi \bigg), \; j = 1, \dots , m
    $$
    
- Esempio applicazione
    
    
    $n+1 = 2 \Rightarrow n =1$ 
    
    Ho la semicirconferenza goniometrica (con estremi -1 e 1). Avrò:
    
    - $t_0 = \cos \bigg( 
    \frac 1 4 \pi
    \bigg)$
    - $t_1 = \cos \bigg( 
    \frac 3 4 \pi
    \bigg)$
    
    $n+1 = 3 \Rightarrow n = 2$
    
    Avrò:
    
    - $t_0 = \cos \bigg( 
    \frac 1 6 \pi
    \bigg)$
    - $t_1 = \cos \bigg( 
    \frac 3 6 \pi
    \bigg) = \cos \bigg( 
    \frac 1 2 \pi
    \bigg)$
    - $t_2 = \cos \bigg( 
    \frac 5 6 \pi
    \bigg)$
    

I nodi di Chebychev sono compresi tra $-1$  e $1$, per estenderli a qualsiasi intervallo si usa la seguente formula:

$$
\mu(t) = \frac{b-a}{2}t + \frac{a+b} 2
$$

$t$ è la distanza tra $0$ e $t$, nella formula viene amplificato per metà dell’ampiezza dell’intervallo e sommato alla metà dell’intervallo, permettendo di mantenere le proporzioni.

## **Teorema di Bernstein**

Se $f \in C^1([a, b])$ e $p_n$ è il polinomio di interpolazione di $f$ relativo ai nodi di Chebychev $t_i, \; i = 0, \dots , n$, allora

$$
\lim_{n \rightarrow \infty} \lVert R_n \lVert _ \infty = \lim_{n \rightarrow \infty} \lVert f - p_n \lVert _\infty = 0
$$

il che equivale a dire che $\{ p_n \}_{n \in \mathbb N}$ converge uniformemente a $f$. Scelti i nodi di Chebychev $R_n$ converge.

Se $f \in C^2([a,b])$, si ha inoltre che 

$$
\lVert f- p_n \Vert _\infty = \mathcal O \bigg(\frac{1}{\sqrt{n}} \bigg)
$$

- 🔍 Esempio funzione di Rounge con $n=19$
    
    ![NB: la scala nei vari grafici è differente!!!](Untitled%2017.png)
    
    NB: la scala nei vari grafici è differente!!!