# Metodo di Lagrange

## Verso una nuova rappresentazione…

Prendiamo $n=1$, quindi abbiamo $2$ punti → $(x_0, y_0), (x_1, y_1)$

Sappiamo che l’equazione della retta passante per $2$ punti è la seguente:

$$
\frac{y-y_0}{x - x_0}=\frac{y_1-y_0}{x_1 - x_0}
$$

![Untitled](Untitled%2010.png)

Se $y = p_1(x)$ allora si può riscrivere come:

$$
p_1(x) = y_0 + \frac{x - x_0}{x_1 - x_0} (y_1 - y_0)
$$

Risolviamo il prodotto e raccogliamo 

$$
p_1(x) = y_0 + y_1 \frac{x - x_0}{x_1 - x_0} - y_0 \frac{x - x_0}{x_1 - x_0}\\
p_1(x) = y_0(1- \frac{x-x_0}{x_1 - x_0}) + y_1 \frac{x- x_0}{x_1 - x_0}
$$

Risolviamo la differenza e, dopo aver cambiato di segno a numeratore e denominatore, otteniamo la seguente equazione:

$$
p_1(x) = y_0 \frac{x - x_1}{x_0 - x_1} + y_1\frac{x- x_0}{x_1 - x_0}
$$

A questo punto definiamo

$$
\green{L_0(x)} = \frac{x-x_1}{x_0 - x_1} \qquad \red{L_1(x)} = \frac{x-x_0}{x_1 - x_0}
$$

![Untitled](Untitled%2011.png)

che sono $2$ funzioni di grado $1$.

Abbiamo scritto il polinomio di interpolazione di grado 1 come combinazione lineare di polinomi di grado 1

$$
p_1(x) = y_0 L_0(x) + y_1L_1(x)
$$

I coefficienti della combinazione lineare sono esattamente le ordinate dei punti di interpolazione $y_0,y_1$

Poniamo un intervallo $x \in [x_0, x_1]$ e possiamo dire che i polinomi $L_0(x), L_1(x)$ hanno le seguenti proprietà:

$$
\begin{cases}
L_0(x_0) = 1 \\ L_0(x_1) = 0
\end{cases}
\qquad \qquad
\begin{cases}
L_1(x_0) = 0 \\ L_1(x_1) = 1
\end{cases}
$$

## Generalizzazione al grado $n$

Con $n+1$ punti avremo $n+1$ ordinate $: y_0, \dots , y_n$ e ognuna sarà accompagnata dalla propria funzione della base di Lagrange $L_i(x)$. Si vuole quindi scrivere il polinomio di interpolazione come

$$
p_n(x)=y_0L_0(x)+y_1L_1(x)+\ldots+y_nL_n(x)
$$

Vogliamo che in un nodo $k$:

- $L_k(x_k) = 1$
- $L_k(x_j) = 0 \quad \forall j = 0,1,\dots , n \;,j \ne k %\in \{ 0, 1, \dots , i-1, i+1,\dots , n \}$

I polinomi $L_k(x)$ di grado $n$ si annullano in tutti i punti di interpolazione tranne uno in cui valgono 1. 

Da cui

$$

L_k(x) : \begin{cases}
L_k(x_k) = 1 \\
L_k(x_j) = 0 & j \ne k
\end{cases}

$$

La forma esplicita dei polinomi è:

$$
L_k(x) = \frac{(x - x_0) \cdot \, \dots \, \cdot (x - x_{k-1})(x - x_{k+1}) \cdot \, \dots \, \cdot(x - x_n)}{(x_k - x_0) \cdot \, \dots \, \cdot (x_k - x_{k-1}) (x_k - x_{k+1}) \cdot \, \dots \,\cdot (x_k - x_n)} = \prod_{i=0, i\neq k}^{n}\frac{x-x_i}{x_k-x_i}, \quad k=0, \ldots, n
$$

Vogliamo che il numeratore valga $0$  per tutte le $x_j$ con $j \ne k$, quindi non inseriamo tra i prodotti $(x - x_k)$ altrimenti con $x = x_k$ avremmo $0$  al numeratore.

Vogliamo invece che il denominatore sia uguale al numeratore (per ottenere $1$) quando $x = x_k$ quindi compiamo il numeratore sostituendo già $x$ con $x_k$.

## La base di lagrange

L’insieme dei polinomi

$$
\{ L_k \}_{k=0,\dots, n}
$$

viene detto **base di Lagrange**.

A differenza della base di monomi $1, x , x^2, \dots, x^n$ la base di Lagrange dipende dai nodi.

## Teorema

La base di Lagrange è un insieme linearmente indipendente.

Di conseguenza qualsiasi polinomio può essere riscritto  attraverso la combinazione lineare di elementi nella base di Lagrange. 

### 📜Dimostrazione

Siano $\lambda_0, \dots , \lambda_n$  $n+1$ coefficienti tali che $\sum_{k=0}^n \lambda_k L_k = 0$

$$
0 = \lambda_0L_0(x) + \lambda_1L_1(x) + \dots + \lambda_nL_n(x) \; \forall x \in \mathbb R
$$

In particolare l’uguaglianza deve valere per i punti di interpolazione, ossia $x=x_k$

$$
0 = \lambda_0L_0(x_k) + \lambda_1L_1(x_k) + \dots + \lambda_nL_n(x_k) = \lambda_kL_k(x_k) = \lambda_k
$$

Quindi si ha che $\lambda_k = 0$ per ogni $k = 0, \dots , n$ e quindi, per definizione, segue la lineare indipendenza della base di Lagrange.

<aside>
💡 TIP
Non stiamo facendo altro che, dopo aver considerato un’opportuna combinazione lineare, la poniamo uguale a $0$. Dimostriamo che tutti i $\lambda_k$ devono essere uguali a $0$ per far valere l’uguaglianza.

</aside>

## Metodo di Lagrange per il calcolo del polinomio di interpolazione

**INPUT** $n +1$  punti $:$ $(x_i, y_i), \; i= 0, \dots, n$ $$$\quad \text e\quad \overline x \ne x_i$

**OUTPUT** $p_n(\overline x)$

1. Calcolare i valori $L_k(\overline x), \; k = 0, \dots, n$
2. Calcolare la combinazione lineare  $p_n(\overline x) = y_0L_0(\overline x) + y_1L_1(\overline x) + \ldots + 
y_nL_n(\overline x)$

### Calcolare i valori $L_k(\overline x), \; k = 0, \dots, n$

Nel metodo di Lagrange si utilizza la base di Lagrange in $\overline x$, che è anche la parte computazionalmente più costosa, poiché ogni $L_k(\overline x)$ viene calcolato facendo

$$
L_k(\overline x) = \prod_{i=0, i \ne k} \frac{\overline x - x_i}{x_k -x_i} , \; k = 0, \dots, n
$$

Per evitare di ripetere più volte le stesse operazioni nel calcolo dei numeratori, si
può procedere calcolando inizialmente la quantità

$$
\omega_n(\overline x) = (\overline x - x_0) \cdot \ldots \cdot (\overline x - x_n)
$$

che sarà il numeratore.

Al denominatore dobbiamo mantenere la produttoria, ma dobbiamo anche semplificare il componente $(\overline x - x_k)$ che abbiamo al numeratore, quindi avremo qualcosa del tipo

$$
L_k(\overline x) = \frac{\omega_k(\overline x)}{(\overline x - x_k) \cdot \prod_{i=0, i \ne k} (x_k - x_i)}
$$

## Calcolo la combinazione lineare $p_n(\overline x)$

### Pseudocodice

$$
\begin{cases}
L_k(\overline x) = \prod_{i=0, i \ne k} \frac{\overline x - x_i}{x_k -x_i}
\\
\blue{\omega_n(\overline x) = (\overline x - x_0) \cdot \ldots \cdot (\overline x - x_n)}
\end{cases}
\Rightarrow L_k(\overline x) =\frac{\blue{\omega_k(\overline x)}}{(\overline x - x_k) \cdot \red{\prod_{i=0, i \ne k} (x_k - x_i)}} \\ 
\green{p_n(\overline x) = y_0L_0(\overline x) + y_1L_1(\overline x) + \ldots + 
y_nL_n(\overline x)}
$$

<aside>
💡 PSEUDOCODICE

![Untitled](Untitled%2012.png)

</aside>

Il principale svantaggio di tale rappresentazione è che, nel caso in cui si voglia aggiungere un punto di interpolazione e, di conseguenza, aumentare il grado modificare tutta la base di Lagrange