# Metodo di Jacobi

- $M = D$
- $N = E+ F$

Quindi andiamo a sostituire $M$ ed $N$ a $Mx^{(k+1)} = Nx^{(k)} +b$ e otteniamo in forma matriciale:

$$
Dx^{(k+1)} = (E + F)x^{(k)} + b
$$

Vogliamo isolare $x^{(k+1)}$, ma prima definiamo $D$ più comodamente:

> $D$ è una matrice diagonale, quindi chiamiamo $d$ il vettore colonna composto dalle componenti della diagonale (principale) di $D$
> 

La forma matriciale trasformata ottenuta è la seguente:

$$
x^{(k+1)} = \frac{(\blue{E} + \red{F})x^{(k)} + b} D 
$$

Ogni componente della nuova iterata $x^{(k+1)}$ si calcola in funzione solo dell’iterata precedente $x^{(k)}$

L’ordine con cui si calcolano le componenti della nuova iterata successiva è indifferente: *metodo degli spostamenti simultanei.* 

$$

\begin{pmatrix}
x_1^{(k+1)} \\
x_2^{(k+1)} \\
\vdots \\
x_n^{(k+1)} \\
\end{pmatrix} 
= 
\begin{pmatrix}
\begin{pmatrix} 
0 & \red{-a_{12}} & \dots & \red{-a_{1n}} \\
\blue{-a_{21}} & 0 & \dots & \red{-a_{2n}} \\
\vdots \\
\blue{-a_{n1}} & \blue{-a_{n2}} & \dots & 0\\
\end{pmatrix} 
\begin{pmatrix}
x_1^{(k)} \\
x_2^{(k)} \\
\vdots \\
x_n^{(k)} \\
\end{pmatrix} 
+
\begin{pmatrix}
b_1 \\
b_2\\
\vdots \\
b_n \\
\end{pmatrix} 
\end{pmatrix}
/
\begin{pmatrix}
a_{11} \\
a_{22} \\
\vdots \\
a_{nn} \\
\end{pmatrix} 
$$

**COMPONENTE $1$**

$$
x_1^{(k+1)} = \frac{-(a_{12}x_2^{(k)} + a_{13}x_3^{(k)} + \dots + a_{1n}x_n^{(k)}) + b_1} {a_{11}}
$$

**COMPONENTE $i$**

$$
x_i^{(k+1)} = \Bigg ( - \sum^{n}_{j=1, j\ne i} a_{ij} x_{j}^{k} + b_i \Bigg ) / a_{ii}, \space i = 1, \dots , n
$$

**FORMALMENTE**

$$
x^{(k+1)} = D^{-1}(E+F)x^{(k)} +D^{-1} b \Rightarrow x^{(k+1)} = \mathcal Jx^{(k)} + c
$$

Con:

$\mathcal J = D^{-1} (E+F) = \begin{pmatrix} 
0 & -\frac{a_{12}}{a_{11}} & \dots & -\frac{a_{1n}}{a_{11}} \\
-\frac{a_{21}}{a_{22}} & 0 & \dots & -\frac{a_{2n}}{a_{22}} \\
\vdots \\
-\frac{a_{n1}}{a_{nn}} & -\frac{a_{n2}}{a_{nn}} & \dots & 0\\
\end{pmatrix}$ 

$c = D^{-1}b=\begin{pmatrix} \frac{b_1}{a_{11}} \\ \vdots \\  \frac{b_n}{a_{nn}}\end{pmatrix}$ siccome $M = D$

## Teorema di convergenza del metodo di Jacobi

Dimostriamo che $\lVert \mathcal J \lVert < 1$ 

| HP | TH |
| --- | --- |
| $|a_{ii}| > \sum_{j=1,j\neq i}^{n}|a_{ij}| \quad \forall i = 1, \ldots, n $ | $\lVert \mathcal J \lVert_{\infty} <1$  |

Dividendo entrambi i membri per $|a_{ii}|$

$$
\lVert \mathcal J \lVert_{\infty} = \max_{i \in \{ 1,\ldots,n\}}\sum_{j=1,j\neq1}^{n}\frac{|a_{ij}|}{|a_{ii}|}<1 
$$

NB:

- Non è detto che la dimostrazione vada bene per qualunque criterio di arresto
- Per ogni riga, divido la somma dei valori della riga, escluso l’elemento della diagonale, in valore assoluto per il valore assoluto dell’elemento della diagonale appartenente a tale riga.