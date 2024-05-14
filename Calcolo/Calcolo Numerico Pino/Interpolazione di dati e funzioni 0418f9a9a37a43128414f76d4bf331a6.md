# Interpolazione di dati e funzioni

# Problema di interpolazione

Siano $(x_i,y_i), \, i = 0, \dots , n$ punti fissati nel piano cartesiano, con $x_i \in [a,b]$. Il problema dell’interpolazione consiste nel costruire una funzione $g :  [a,b] \rightarrow \mathbb R$ il cui grafico passa per i punti dati, ossia che soddisfa le condizioni di interpolazione

$$
g(x_i) = y_i, \; \forall i = 0 , \dots , n
$$

La funzione $g$ si dice **interpolante** rispetto ai punti di intersezione $(x_i,y_i)$.

Le ascisse dei punti di interpolazione si chiamano **nodi**.

Quando le ordinate dei punti di interpolazione sono le immagini dei nodi tramite una funzione $f : [a,b] \rightarrow \mathbb R$, allora si dice che $g$ **interpola la funzione $f$**

- SI hanno $n+1$ punti $(x_i,y_i)$ del piano cartesiano.
- Siccome fissati i punti da interpolare, esistono infinite funzioni interpolanti, il problema sussiste perché vogliamo avere **unicità** della soluzione.
- Quindi vedremo metodi possibili per scegliere la funzione corretta.

# Polinomio di interpolazione

## Teorema fondamentale dell’algebra

Dati $n+1$ punti del piano $(x_i,y_i), \, i= 0, \dots , n,$ esiste un unico polinomio di grado al più $n$, denotato con $p_n(x)$, che li interpola, ossia tale che:

$$
p_n(x_i) = y_i \; i = 0,\dots ,n
$$

Il polinomio $p_n(x)$ viene detto **polinomio di interpolazione** dei punti $(x_i,y_i), i = 0 , \; \dots , n$

- Per esempio, prendendo $2$ punti per interpolarli devo utilizzare un polinomio di grado $1$Invece prendendo $3$ punti non allineati devo utilizzare un polinomio di grado $2$, ossia una parabola.
- Nel caso in cui i $3$ punti siano allineati posso usare una retta cioè un polinomio di grado $1$.
- Con molti punti il processo di interpolazione può risultare molto costoso.

Dal punto di vista numericoequivale ad un algoritmo che, dati in inputo i punti di interpolazione $(x_i, y_i)$ con $i = 0 , \; \dots , n$ e un punto $\overline{x} \in \mathbb R$  restituisce il valore $p_n(\overline x)$

## Rappresentazione in forma canonica

Un generico polinomio di grado $n$ si rappresenta in forma canonica come combinazione lineare delle funzioni

$$
1,x,x^2,\ldots,x^n
$$

e si scrive come

$$

p_n(x) = a_nx^n+a_{n-1}x^{n-1}+\dots + a_1x^1+a_0x^0
$$

<aside>
💡 NB
Per essere di grado $n$ il coefficiente dell’incognita di grado $n$ dovrà essere $0$. Consideriamo comunque infinite funzioni in cui i coefficienti delle incognite di grado > $n$ sono tutti $0$.

</aside>

Le condizioni di interpolazione $p_n(x_i)=y_i,i=0,\ldots,n$ si possono quindi scrivere come 

$$
\begin{cases}
a_0+a_1x_0+a_2x_0^2+\dots+a_nx_0^n=y_0 = p_0(x_0)\\
a_0+a_1x_1+a_2x_1^2+\dots+a_nx_1^n=y_1  = p_1(x_1)\\
\dots \\
a_0+a_1x_n+a_2x_n^2+\dots+a_nx_n^n=y_n  = p_n(x_n)
\end{cases}
$$

che si può interpretare come un sistema lineare di $n+1$ equazioni di primo grado che devono valere contemporaneamente dove le incognite sono le $a_i$

$$

V  \alpha = y \\
\underset{n+1 \times n+1}{V}=
\underbrace{
\begin{pmatrix}
1 & x_0 & \ldots & x_0^n \\
1 & x_1 & \ldots & x_1^n \\
\ldots &\ldots &\ldots & \ldots \\
1 & x_n & \ldots & x_n^n 
\end{pmatrix}}_{\text{matrice dei coefficienti}}
\quad
\alpha =
\underbrace{ 
\begin{pmatrix}
a_0 \\ a_1 \\ \vdots \\ a_n
\end{pmatrix}}_{\text{incognite}}
\quad
y =
\underbrace{ 
\begin{pmatrix}
y_0 \\ y_1 \\ \vdots \\y_n
\end{pmatrix}}_{\text{termine noto}}
$$

## Metodi

---

[Metodo dei coefficienti indeterminati](Metodo%20dei%20coefficienti%20indeterminati%20851d6f10442a4e65a730939f8e172e39.md)

Risoluzione del sistema $V\alpha=y$ col metodo di Gauss

I vantaggi sono che una volta trovati i coefficienti $a_i$ essi rimangono tali e i coefficienti $a_i$ non dipendono dal punto $\overline x$

Gli svantaggi sono che la matrice $V$ è, in generale, malcondizionata e i calcolo della soluzione di $V \alpha = y$ ha un costo di ordine $n^3$

---

[Metodo di Lagrange](Metodo%20di%20Lagrange%200cd183d97abe478bae1dd4c9ffe79723.md)

Si introduce il metodo di Lagrange dalla formula della retta passante per due punti ($n=1$) in cui si dimostra come si ottengono le funzioni della base di lagrange per poi generalizzarla al grado n. 

Teorema della lineare indipendenza della base con dimostrazione. 

Poi si passa al metodo di lagrange per il polinomio di interpolazione dove si mostra come poter ridurre i calcoli al fine di ridurre l’errore. 

Il principale svantaggio di tale rappresentazione è che, nel caso in cui si voglia aggiungere un punto di interpolazione e, di conseguenza, aumentare il grado, occorre modificare tutta la base di Lagrange

---

[Il problema dell’approssimazione](Il%20problema%20dell%E2%80%99approssimazione%206ea484fabefb4f078a4debdfe443ca79.md)

Si cerca di definire un polinomio $p_n$ che assomigli il più possibile ad $f$. Per farlo si usano le norme di funzioni. Dalle norme viene definito l’errore (o resto di interpolazione) che viene analizzato e maggiorato (con dimostrazione). Da qui si verifica che la convergenza uniforme del resto avviene per un parametro $M_n<\infty$; si analizza il caso del fenomeno di Rounge per cui, aumentando il numero di nodi, $M_n$ tende a infinito (non avviene convergenza uniforme del resto). Si introducono i nodi di chebychev che non saranno più equispaziati e risolveranno il problema del fenomeno di Rounge. 

---

[Interpolazione polinomiale a tratti](Interpolazione%20polinomiale%20a%20tratti%20e9bc4fc67f8948fb8b699fc0162c5664.md)

Partendo dai problemi del polinomio di interpolazione si introduce l’interpolazione polinomiale a tratti, ossia ristretta a sotto intervalli, dove ogni tratto è una retta. La funzione totale sarà sicuramente continua ma non derivabile. Formula della funzione interpolante in un sottointervallo. 

Errore nell’interpolazione con dimostrazione di maggiorazione con caso particolare di nodi equispaziati. Lo svantaggio è la non derivabilità. Si introducono le funzioni spline, i punti vengono uniti con parabole e non rette. La funzione totale è un polinomio di grado al più $n$ derivabile con continuità $n-1$ volte. Una spline di grado $n$ dipende da $(n+1)(m+1)$ parametri, di cui $n+m+1$ liberi. I parametri liberi indicano i gradi di libertà delle spline.

---

[Criterio dei minimi quadrati](Criterio%20dei%20minimi%20quadrati%20c6d5fbeb9d6141689cc3a69767d14a37.md)

In alcune situazione si vuole definire un modello matematico che descriva un fenomeno. Interpolare quindi con delle parabole a volta risulta sbagliato. Si vuole trovare la retta migliore che descriva il fenomeno. La retta deve avere distanza cumulativa minore da tutti i punti da interpolare. La retta viene riscritta in forma matriciale con una Q per poi, dopo aver definito u come differenza tra q e y (q → valtuazione della retta di regressione, y → ordinate dei punti), si riscrive Q con la definizione di norma 2.

m: numero dei punti

n: grado del polinomio 

Caso degenere: m > n, tutte le colonne sono linearmente indipendenti → soluzione unica

Caso generale: m > n, alcune colonne sono linearmente indipendenti → infinite soluzioni → si trova quella con norma euclidea minore