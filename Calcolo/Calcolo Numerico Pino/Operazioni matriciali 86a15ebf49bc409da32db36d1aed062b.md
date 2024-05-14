# Operazioni matriciali

## Somma matriciale

Date due matrici della stessa dimensione $A, B \in \mathbb{R}^{m\times n}$ la somma $A+B$ è una matrice delle stesse dimensioni $C\in\mathbb{R}^{m\times n}$ i cui elementi si ottengono facendo la somma elemento per elemento di A e B

$$
c_{ij} = a_{ij} + b_{ij}, \space \space \space i = 1,\dots, m, \space j = 1,\dots, n
$$

## Moltiplicazioni per uno scalare

Data una matrice $A\in\mathbb{R}^{m\times n}$ e un numero reale $\lambda$, si definisce la matrice $\lambda A$ come la matrice $C\in\mathbb{R}^{m\times n}$  i cui elementi si ottengono moltplicando i corrispondenti elementi di a per $\lambda$ 

$$
c_{ij}=\lambda a_{ij} \space \space \space i = 1,\dots, m, \space j = 1,\dots, n
$$

## Prodotto tra matrici

Date due matrici $A\in\mathbb{R}^{m\times n}, B \in\mathbb{R}^{n\times p}$ si definisce la matrice prodotto $AB$ come la matrice $C\in\mathbb{R}^{m\times p}$ i cui elementi sono definiti dalla formula seguente:

$$
c_{ij} = \sum_{k=1}^{n} a_{ik}b_{kj}, \space \space \space i = 1,\dots, m, \space j = 1,\dots, p
$$

$$
\begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn} \\
\end{pmatrix}
\times
\begin{pmatrix}
b_{11} & b_{12} & \cdots & b_{1p} \\
b_{21} & b_{22} & \cdots & b_{2p} \\
\vdots & \vdots & \ddots & \vdots \\
b_{n1} & b_{n2} & \cdots & b_{np} \\
\end{pmatrix}
=
\begin{pmatrix}
c_{11} & c_{12} & \cdots & c_{1p} \\
c_{21} & c_{22} & \cdots & c_{2p} \\
\vdots & \vdots & \ddots & \vdots \\
c_{m1} & c_{m2} & \cdots & c_{mp} \\
\end{pmatrix}
$$

Dove ad esempio $c_{11} =a_{11} \cdot b_{11} + a_{12} \cdot b_{21}+\dots +a_{1n}\cdot a_{m1}$

In generale, l'elemento nella riga i e colonna j di C è ottenuto moltiplicando la riga i della matrice A per la colonna j della matrice B e sommando i prodotti corrispondenti. 

Ricorda: il numero di colonne di A deve essere uguale al numero di righe di B.

### Proprietà del prodotto matriciale

- Valgono proprietà associativa e distributiva rispetto alla somma matriciale
- Non vale la proprità commutativa, nemmeno se le matrici sono quadrate
- L’elemento neutro $AI_n = I_m A$
- $(AB)^T=B^TA^T$

## Prodotto matrice-vettore

E’ un caso particolare del prodotto matriciale in cui $A\in\mathbb{R}^{m\times n}$, $x\in \mathbb{R}^n$ e $y = Ax\in \mathbb{R}^n$ è definito come

$$
y_i = \sum_{k=1}^{n} a_{ik}x_k \space \space \space i=1,\dots, m
$$

$$

\begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn} \\
\end{pmatrix}
\times
\begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n} \\
\end{pmatrix}
=
\begin{pmatrix}
a_{11} \cdot x_{1} + a_{12} \cdot x_{2} + \ldots + a_{1n} \cdot x_{n} \\
a_{21} \cdot x_{1} + a_{22} \cdot x_{2} + \ldots + a_{2n} \cdot x_{n} \\
\vdots \\
a_{m1} \cdot x_{1} + a_{m2} \cdot x_{2} + \ldots + a_{mn} \cdot x_{n} \\
\end{pmatrix}=\begin{pmatrix}
y_{1} \\
y_{2} \\
\vdots \\
y_{m} \\
\end{pmatrix}

$$

## Prodotto scalare tra due vettori

Dati due vettori $u,v \in \mathbb{R}^n$ si definisce prodotto scalare di $u$ e $v$  il numero $s$ dato da

$$
s = u^Tv=\sum_{k=1}^n u_kv_k
$$

## Inversa di una matrice

Una matrice quadrata $A$ di oridine $n$ si dice invertibile o non singolare se esiste una matrice $X \in \mathbb{R}^{n \times n}$ tale che 

$$
AX=XA=I
$$

La matrice $X$ viene detta inversa di $A$ e si indica come $X=A^{-1}$

### Proprietà dell’inversa

- $(A^{-1})^{-1}=A$
- $(A^T)^{-1}=(A^{-1})^T = A^{-T}$
- Se $A$ e $B$ sono invertibili, allora anche $AB$ lo è e $(AB)^-1=B^{-1}A^{-1}$

## Determinante di una matrice (laplace)

Sia $A \in \mathbb{R}^{n \times n}$ il determinante di $A$ è un numero denotato con $det(A)$ che si puà definire in modo ricorsivo:

$$
det(A)=\begin{cases} a_{11} & se &n=1 \\ \sum_{j=1}^n a_{ij}det(A_{ij}) &se & n> 1\end{cases}
$$

dove: 

- $i$  è un qualsiase indice $i \in \{ {1,\dots, n} \}$
- $A_{ij}$  è la matrice di ordine $n-1$ che si ottiene eliminando la riga $i$ e la colonna $j$ di $A$

### Proprietà del determinante

- $det(A)=det(A^T)$
- $det(AB)=det(A)det(B)$
- $det(A^{-1})=\frac{1}{det(A)}$
- $det(\lambda A)=\lambda ^n det(A)$
- Se $B$  è una matrice ottenuta scambiando due righe (o due colonne) di $A$ allora $det(B)=-det(A)$
- Una matrice $A$ è non singolare (nonsingolare $\Longleftrightarrow$ invertibile) se e solo se $det(A)\neq0$