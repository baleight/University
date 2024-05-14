# Metodo dei coefficienti indeterminati

Dati, $(x_i, y_i), \; i= 0, \dots, n$ ossia $n+1$ punti si calcolano

$$
V=\begin{pmatrix}
1 & x_0 & \ldots & x_0^n \\
1 & x_1 & \ldots & x_1^n \\
\ldots &\ldots &\ldots & \ldots \\
1 & x_n & \ldots & x_n^n 
\end{pmatrix} \quad y =\begin{pmatrix}
y_0 \\ y_1 \\ \vdots \\y_n
\end{pmatrix}
$$

e si risolve il sistema lineare $V  \alpha = y$ 

Con $i = 0$ ho il seguente polinomio:

$$
a_0+a_1x_0+a_2x_0^2+\ldots+a_nx_0^n=y_0 = p_0(x_0)
$$

Quindi per ogni $i = 0, \dots, n$ avrò un’equazione, perciò in totale si hanno $n+1$ equazioni che devono valere contemporaneamente, quindi un sistema lineare dove le incognite sono le $a_i$ che hanno grado $1$:

$$
\begin{cases}
a_0+a_1x_0+a_2x_0^2+\dots+a_nx_0^n=y_0 = p_0(x_0)\\
a_0+a_1x_1+a_2x_1^2+\dots+a_nx_1^n=y_1  = p_1(x_1)\\
\dots \\
a_0+a_1x_n+a_2x_n^2+\dots+a_nx_n^n=y_n  = p_n(x_n)
\end{cases}
$$

$p_n(x)$  è costruito a partire dalla [base canonica.](Altro%20c4b2595a1fce481f9b1b7e2bb06558f5.md)

A questo punto chiamiamo:

- $y$ il vettore dei termini noti $y_i, \; i = 0, \dots , n$
- $\alpha$ il vettore delle incognite $a_i, \; i=0, \dots , n$
- $V$ la matrice *(di Vandermonde)* dei coefficienti di $a_i,$ quindi contenente tutti gli $x_i^j$ dove $i$ è il numero di riga e $j$ il numero di colonna

Allora posso riscrivere il sistema lineare in forma matriciale come → $V  \alpha = y$

Si dimostra che $\det V = \prod_{i>j}(x_i-x_j)$, pertanto se i punti di interpolazione sono distinti, $V$ è non singolare e il sistema $V\alpha =  y$ ha un’unica soluzione ([teorema fondamentale dell’algebra](Interpolazione%20di%20dati%20e%20funzioni%200418f9a9a37a43128414f76d4bf331a6.md)). 

## Risoluzione

Sappiamo che $V = L U$ allora:

$$
\begin{cases}
Lz = y \\
U \alpha = z
\end{cases}
$$

quindi determiniamo $\alpha$ ed indichiamo $\overline a_i$ come l’elemento di $\alpha$  che è stato determinato. Quindi la nostra equazione sarà:

$$
p_n(x) = y = \overline a_0 + \overline a_1 x + \dots + \overline a_n x^n
$$

dopodiché posso porre $x$ ad un valore noto e calcolare la $y$ nella rispettiva $x$ e passante per la funzione interpolante trovata.

**PRO**

- Una volta trovati i coefficienti $a_i$ essi rimangono tali
- I coefficienti $a_i$ non dipendono dal punto $\overline x$

**CONTRO**

- La matrice $V$ è, in generale, malcondizionata
- Il calcolo della soluzione di $V \alpha = y$ ha un costo di ordine $n^3$