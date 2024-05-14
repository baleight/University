# Definizioni nelle matrici

Considerando

$$
A=\begin{pmatrix} a_{11} & a_{12} & a_{13} & \dots & a_{1n}\\ a_{21} & a_{22} & a_{23} & \dots & a_{2n}\\ \dots \\  a_{m1} & a_{m2} & a_{m3} & \dots & a_{mn}\end{pmatrix} \in \mathbb{R}^{m\times n}
$$

## Matrice trasposta

Se $A\in \mathbb{R}^{m\times n}$ la sua trasposta è una matrice $\mathbb{R}^{n\times m}$ che si indica con $A^T$ ed è definita come

$$
A^T=\begin{pmatrix} a_{11} & a_{21} & a_{31} & \dots & a_{m1}\\ a_{12} & a_{22} & a_{31} & \dots & a_{m2}\\ \dots \\  a_{1n} & a_{2n} & a_{3n} & \dots & a_{mn}\end{pmatrix} \in \mathbb{R}^{m\times n}
$$

## Matrice simmetrica

Una matrice quadrata $A$ è simmetrica se e solo se $A = A^T$. In questo caso $a_{ij} = a{ji} \space \space \forall i,j$

## Matrice simmetrica definita positiva

Una matrice simmetrica si dice definita positiva se gode delle seguenti proprietà:

- $x^T Ax \ge 0$ $\forall x \in \mathbb R^n$ e $x^T Ax = 0 \Leftrightarrow$ $x =0$
    
    Si considera $x \in \mathbb R^n$ come un vettore colonna di dimensione $1\times n$ dove $x_i \in \mathbb R$. Quindi la disequazione $x^T A x \ge 0$ non è altro che:
    
    $$
    \underset{1 \times n}{\begin{pmatrix}
    x_1 & x_2 & \dots & x_n
    \end{pmatrix}} \underset{n \times n}{A}
    \underset{n \times 1}{\begin{pmatrix}
    x_1 \\ x_2 \\ \vdots \\ x_n
    \end{pmatrix}}
    $$
    
    $Ax$ dà come risultato un vettore $n\times1$ che moltiplicato a $x^T$ (che ha dimensione $1 \times n$) darà come risultato uno **scalare** che chiamiamo $p$ il quale deve essere $\ge 0$
    
    Nella seconda condizione possiamo dedurre che il prodotto $x^TAx = 0$ solamente se il vettore $x$ è il vettore nullo.
    
    > **N.B.**
    > 
    > 
    > Lo $0$ della prima uguaglianza ($x^TAx = 0$) è lo 0 scalare, mentre lo $0$ della seconda uguaglianza ($x=0$) è un vettore (nullo).
    > 
    
    Se vale solo la prima proprietà la matrice prende il nome di semi definite positive *(che noi non faremo)*.
    

Ossia:

- tutti i minori principali sono positivi
- tutti gli autovalori sono reali postivi

## Matrice identità

La matrice di ordine $n$ ha elementi diagonali unitari, mentre tutti gli altri elementi sono nulli è la matrice identità di ordine $n$ e si indica con $I_n$

$$
I_n=\begin{pmatrix}
1 & 0 & \cdots & 0 \\
0 & 1 & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & 1 \\
\end{pmatrix}
$$

## Matrice diagonale

Una matrice quadrata $D$ di ordine $n$ si dice diagonale se $d_ij = 0$ per $i\neq j \space \space i,j = 1,\dots,n$

$$
D = \begin{pmatrix}
d_1 & 0 & \cdots & 0 \\
0 & d_2 & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & d_n \\
\end{pmatrix}
$$

## Matrice triangolare superiore e inferiore

Una matrice quadrata $U$ di ordine $n$ si dice traingolare superiore se $u_{ij} = 0$ per $i> j$. Una matrice quadra $L$ di ordine $n$ si dice triangolare inferiore se $l_{ij}=0$ per $i<j$

$$
U =\begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
0 & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & a_{nn} \\
\end{pmatrix} L=\begin{pmatrix}
a_{11} & 0 & \cdots & 0 \\
a_{21} & a_{22} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & \cdots & a_{nn} \\
\end{pmatrix}
$$

**Osservazione:** conoscere la struttura di una matrice (diagonale, triangolare) permette di ridurre l’occupazione di memoria poichè non è necessario memorizzare esplicitamente gli elementi nulli.

## Matrice strettamente a diagonale dominante

Una matrice quadrata $A$ si dice

**strettamente a diagonale dominante per righe** se:

$$
\sum_{j=1, \; j \ne i}^n |a_{ij}| \lt |a_{ii}|, \; \forall i = 1, \dots , n
$$

*in ogni riga, l’elemento della diagonale è strettamente maggiore alla somma di tutti gli altri elementi della riga.*

**strettamente a diagonale dominante per colonne** se :

$$
\sum_{i=1, \; i \ne j}^n |a_{ij}| \lt |a_{jj}|, \; \forall j = 1, \dots , n
$$

*in ogni colonna, l’elemento della diagonale è strettamente maggiore alla somma di tutti gli altri elementi della colonna.*

## Matrice ortogonale

Una matrice quadrata $A$ è ortogonale se e solo se $A A^{T} = I \Rightarrow A^T = A^{-1}$ 

## Matrice singolare e non singolare

- Una matrice quadrata $A$ è non singolare se il suo determinante $\det{A} = 0$
- Una matrice quadra $A$ èsingolare se il suo determinante $\det{A} \neq 0$

NB: la singolarità o meno della matrice quadrata è un indizio per capire se la matrice quadrata è una matrice invertibile oppure no. Una matrice quadrata è invertibile se e soltanto se la matrice non è singolare.