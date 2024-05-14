# Fattorizzazione QR

## Teorema

Sia $A$ una matrice quadrata di dimensione $n$ nonsingolare. 

Allora esistono:

- $Q \in \mathbb R^{n \times n}$ una [matrice ortogonale](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md)
- $R \in \mathbb R^{n \times n}$ una matrice triangolare superiore [nonsingolare](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md)

tali che:

$$
A = Q R
$$

Gli algoritmi per il calcolo delle matrici $Q$ e $R$ sono:

- **Trasformazioni elementari di Householder**
- **Trasformazioni elementari di Givens**
- **Procedimento di Gram-Schmidt**
- **Pavimentazione**

## Trasformazione elementare di Householder

Dato un vettore $v \in \mathbb R^n, v \ne 0$ si definisce trasformazione elementare di Householder associata a $v$ la matrice

$$
U = I - \frac{1}{\alpha}vv^T, \text{ dove } \alpha = \frac{1}{2}\lVert v \lVert ^2 _ 2
$$

Dove  $\lVert v \lVert^{2}_{2} = v^Tv$ è la [norma euclidea](Norme%20vettoriali%20e%20matriciali%20c2013a0b8b284b44adb38a6b6d122217.md) (non si considera il $\rho$)

### Descrizione & Proprietà

Per definire una matrice di Householder abbiamo bisogno di un vettore $v$ non nullo. 

Cos’è $vv^T$?

È una matrice $n \times n$ perché $v$ è un vettore (*colonna*) di dimensione $n\times 1$.

$$
\begin{pmatrix}
v_1^2 & v_1v_2 & ... & v_1v_n \\
v_1v_2 & v_2^2 & ... & v_2v_n \\
... & & & \\
v_1v_n & v_2v_n & ... & v_n^2 \\
\end{pmatrix}
$$

$\frac{1}{\alpha}$ è uno scalare, quindi la matrice sopra viene moltiplicata per lo scalare siccome la norma di $v$ al quadrato corrisponde a: 
$\lVert v \lVert ^ 2 = v_1^2+v_2^2+ ...+ v_n^2$

Proprietà:

1. **Simmetria**
    
    $U^T = (I - \frac{1}{\alpha}vv^T)^T = I - \frac{1}{\alpha} (vv^T)^T = I - \frac{1}{\alpha} vv^T = U$
    
    È possibile passare da $(vv^T)^T$  a $vv^T$ perché la matrice $vv^T$ è simmetrica (*[trasposta prodotto di matrici](Operazioni%20matriciali%2086a15ebf49bc409da32db36d1aed062b.md)*)
    
2. **Ortogonalità**
    
    $U^TU = UU$ per simmetria *(punto 1)* 
    
    Esplicitiamo $UU$ quindi diventa: $(I - \frac{1}{\alpha} vv^T) (I - \frac{1}{\alpha} vv^T)$
    
    che, dopo i calcoli, diventa: $I - \frac{1}{\alpha} vv^T - \frac{1}{\alpha} vv^T + \frac{1}{\alpha ^2} v \quad v^T v \quad v^T$
    
    abbiamo che $v^Tv = \lVert v \lVert^2$ (*[dalla def. di norma 2](Norme%20vettoriali%20e%20matriciali%20c2013a0b8b284b44adb38a6b6d122217.md)*) che a sua volta corrisponde a $\lVert v \lVert ^2 = 2 \alpha$
    
    Semplificando, all’ultimo membro otteniamo $\frac{2}{\alpha} vv^T$
    
    Quindi da $I - \frac{2}{\alpha}vv^T + \frac{2}{\alpha}vv^T$ otteniamo $I = I$
    
    Quindi $U^TU=I \Rightarrow U^T=U^{-1}$
    
3. **Proprietà $\sigma$** 
    
    Dato $z \in \mathbb R^n, z \ne 0$ e definita $U$ come la trasformazione di Householder associata al vettore $v = z+ \sigma e_1$ dove $e_1$ è la prima colonna della matrice identità di ordine $n$ e $\sigma = \lVert z \lVert$, si ha che
    

$$
Uz = -\sigma e_1 = \begin{pmatrix}-\sigma \\ 0 \\ ... \\0\end{pmatrix}
$$

     **📜Dimostrazione**

Dato $z$ voglio trovare $v$ tale che $U$ abbia la proprietà dell’annullamento, quindi se definiamo $v = z + \sigma e_1$

Specifichiamo che $\sigma = \lVert z \lVert _2 = \sqrt{z_1^2+z_2^2+...+z_n^2}$

$$
\alpha=\frac{1}{2}\lVert v\lVert^2=\frac{1}{2}(z+\sigma e_1 )^T(z+\sigma e_1)=\frac{1}{2}(\red{z^Tz}+2\sigma \blue{z^Te_1}+\sigma^2)=\frac{1}{2}(\red{\sigma^2}+2\sigma \blue{z_1}+\sigma^2)=\sigma^2+\sigma z_1
$$

$$
Uz = (I-\frac{1}{\alpha}vv^T)z=z-\frac{1}{\alpha}(z+\sigma e_1)(z+\sigma e_1)^Tz\\=z-\frac{1}{\alpha}(z+\sigma e_1)(z^Tz+\sigma e_1^Tz)\\=z-\frac{1}{\alpha}(z+\sigma e_1)\underbrace{(\sigma^2+\sigma z_1)}_{=\alpha}\\ = z-z-\sigma e_1 = -\sigma e_1
$$

### Procedimento di fattorizzazione

L’idea è quella di utilizzare le trasformazioni elementari di Householder per eliminare gli elementi del triangolo inferiore della matrice A definendo la matrice triangolare superiore $R$ come:

$$
R =U_{n-1} \cdot \, \dots \, \cdot U_1 A
$$

dove, al passo $k$, la matrice $U_k$ è definita in modo che nel prodotto vengano eliminati tutti gli elementi della colonna $k$, sulle righe dalla $k+1$-esima fino alla $n$-esima, della matrice $A$.

**Come si ottiene la matrice $U_k$ ?**

Sfruttiamo la proprietà $\sigma$, quindi definiamo il vettore $v_k = z_k - \sigma_k e_k$.

Nell’algoritmo:

- il vettore $z_k$ sarà il vettore colonna $a_k$
- $\sigma_k$ invece sarà la norma di $a_k$ → $\sigma_k = \lVert a_k \lVert$

Quindi una volta calcolato il vettore $v_k$ è possibile trovare la matrice di Householder associata 

### Passo 1

- $z_1 = a_1$ dove $a_1$ è il vettore colonna $1$ della matrice $A$
- $\sigma_1 = \lVert a_1 \lVert = \sqrt {a_{11}^2+a_{21}^2+...+a_{n1}^2}$
- $v_1 = z_1 + \sigma_1 e_1$

Definiamo $U_1$ come la trasformazione elementare di Householder associata al vettore $v_1$

$$
U_1 = I - \frac 1 \alpha v_1 v_1^T 
$$

Una volta trovato $U_1$ possiamo costruire la matrice $A_2$

$$
A_2 = U_1 \cdot A= (U_1a_ \space U_1a_2 \ldots U_1a_n)=
\underbrace{
\begin{pmatrix}
-\sigma_1 & {u_1}_1 \cdot a_2 & \dots & {u_1}_1\cdot a_n\\
0 & {u_1}_2\cdot a_2 & \dots & {u_1}_2 \cdot a_n\\
\vdots \\
0 & {u_1}_n\cdot a_2 & \dots & {u_1}_n\cdot a_n
\end{pmatrix}
}_{=U_1\cdot a_1 \; \; \; \; \; \; =U_2a_2\; \;\;\;\; \; \; \; \; \;\; \;\; \;\; \; \; \; \; =U_n\cdot a_n}

\qquad \text{ dove } \qquad

\begin{matrix}
u_i \rightarrow \text{vettore riga } i \text{ matrice }U_1 \\

a_i \rightarrow \text{vettore colonna } i \text{ matrice }A
\end{matrix}
$$

## Passo 2

Al passo $2$ “congeliamo” riga $1$ e colonna $1$ della matrice $A_2$ e chiamiamo $\tilde A_2$ la matrice $n-1 \times n-1$ senza riga $1$ e colonna $1$.

$$
A_2=\begin{pmatrix}
-\sigma_1 & a_{12}^{(2)} &
\ldots & a_{1n}^{(2)} \\

0 & a_{22}^{(2)} & \ldots &a_{2n}^{(2)} \\

\vdots & \ldots && \\
0 & a_{n2}^{(2)} & \ldots & a_{nn}^{(2)}
 
\end{pmatrix}
$$

$$
\underset{n-1\times n-1}{\tilde A_{2}}=
A_2=\begin{pmatrix}

 a_{22}^{(2)} & \ldots &a_{2n}^{(2)} \\

\vdots & \ldots && \\
a_{n2}^{(2)} & \ldots & a_{nn}^{(2)}
 
\end{pmatrix}
$$

Allo stesso modo chiameremo $U_2$ la matrice $n \times n$ con tutti i valori della riga $1$ e colonna $1$ a $0$, ad eccezione del pivot che ha valore $1$. Con $\tilde U_2$ invece intendiamo la matrice $U_2$ senza riga $1$ e colonna $1$.

$$
\underset{n-1 \times n-1}{\tilde U_2}=I_{n-1} - \frac 1 \alpha_2 v_2 {v_2}^T   = \begin{pmatrix}
 
  \tilde u_{11} & \tilde u_{12} & ... & \tilde u_{1\:n-1} \\
  \tilde u_{21} & \tilde u_{22} & ... & \tilde u_{2\:n-1} \\
... \\
 \tilde u_{n-1\, 1} & \tilde u_{n-1\, 2} & ... & \tilde u_{n-1\:n-1}\\
\end{pmatrix}
$$

$$
\underset{n \times n}{U_2} = \begin{pmatrix}
1 & 0 & 0 & ... & 0 \\
0 & \tilde u_{11} & \tilde u_{12} & ... & \tilde u_{1\:n-1} \\
0 & \tilde u_{21} & \tilde u_{22} & ... & \tilde u_{2\:n-1} \\
... \\
0 & \tilde u_{n-1\, 1} & \tilde u_{n-1\, 2} & ... & \tilde u_{n-1\:n-1}\\
\end{pmatrix}
$$

- $z_2 = \tilde a_1$ dove $\tilde a_1$ è il vettore colonna $1$ della matrice $\tilde A_2$
- $\sigma_2 = \lVert \tilde a_1 \lVert =\sqrt{(a_{22}^{(2)})^2 + (a_{32}^{(2)})^2 + \dots + (a_{n2}^{(2)})^2}$
- $v_2 = z_2  + \sigma_2e_2$ → con $z_2, e_2$ di dimensione $n-1 \times 1$

Una volta trovato $\tilde U_2$, quindi $U_2$ possiamo definire $A_3$

$$
A_3 = U_2A_2 = \begin{pmatrix}
- \sigma_1 & a_{12}^{(2)} & a_{13}^{(2)} & ... & a_{1n}^{(2)} \\
0 & -\sigma_2 & a_{23}^{(3)} & ... & a_{2n}^{(3)} \\
0 & 0 & a_{33}^{(3)} & ... & a_{3n}^{(3)} \\
... \\
0 & 0 & a_{n3}^{(3)} & ... & a_{nn}^{(3)} \\
\end{pmatrix}

$$

## Passo k

Al passo $k$ definiamo:

- $\tilde A_k$ come la matrice $A_k$ di dimensione $(n - k + 1 \times n - k + 1)$
- $z_k = \tilde a_1$ dove $\tilde a_1$ è il vettore colonna $1$ della matrice $\tilde A_k$
- $\sigma_k = \lVert \tilde a_1 \lVert =\sqrt{(a_{kk}^{(k)})^2 + (a_{k+1k}^{(k)})^2 + \dots + (a_{nk}^{(k)})^2}$
- $v_k = z_k  + \sigma_ke_k$ → con $z_k, e_k$ di dimensione $n - k + 1 \times 1$

$$
\tilde U_k = I_{n-k+1} - \frac 1 \alpha v_k {v_k}^T
$$

$$
U_k=\begin{pmatrix}
1 &&&&\\
&&\ddots&&\\
&&&& \tilde U_k\\
\end{pmatrix}
$$

$$
A_k= \begin{pmatrix}
-\sigma_1 & a_{12}^{(2)} && \ldots & a_{1n}^{(2)} \\

& \ddots & \ldots & \ldots & \\

&& a_{kk}^{(k)} & \ldots & a_{kn}^{(k)} \\

&& \vdots & \ldots & \ldots \\
&& a_{nk}^{(k)} & \ldots & a_{nn}^{(k)} 
\end{pmatrix}
$$

Una volta trovato $\tilde U_k$, quindi $U_k$ possiamo definire $A_{k+1}$

$$
A_{k+1} = U_kA_k = \begin{pmatrix}

- \sigma_1 & a_{12}^{(2)} & a_{13}^{(2)} & a_{14}^{(2)} & ... & a_{1n}^{(2)} \\

0 & -\sigma_2 & a_{23}^{(3)} &a_{24}^{(3)} &  ... & a_{2n}^{(3)} \\

\vdots &  & & \\

0 & 0 & 0 & -\sigma_k & ... & a_{kn}^{(k+1)} \\

\vdots  \\

0 & 0 & 0 & 0 & ... & a_{nn}^{(k+1)} \\

\end{pmatrix}

$$

## Passo n-1

All’ultimo passo avremo:

$$
R = U_{n-1}\,A_{n-1} = U_{n-1}\, U_{n-2} \, A_{n-2} = \underbrace{U_{n-1} \, U_{n-2} \dots U_{2} \, U_{1}}_{\underset{essendo \space ortognale }{Q^{-1} \Rightarrow Q^T}} \, A
$$

Tutte le $U_i$ sono simmetriche ed ortogonali quindi poniamo il loro prodotto uguale a $Q^{-1}$. Siccome l’ortogonalità è una proprietà che si conserva nella moltiplicazione allora anche $Q^{-1}$ è ortogonale.

Concludiamo isolando la $A$:

$$
R = Q^{-1}A \rightarrow QR = QQ^{-1}A \rightarrow QR = IA \rightarrow QR=A
$$

## Soluzione sistema lineare

$$
Ax = b \Leftrightarrow QRx = b
$$

Chiamiamo $Rx = y$ quindi avremo che:

$$
\begin{cases}
y = Q^Tb \\
Rx = y
\end{cases}
$$

Non sarebbe più corretto questo?

$$
\begin{cases}
Qy = b \\
Rx = y
\end{cases}
$$

## Costo computazionale

Il costo computazionale è $\mathcal O(\frac{2 n^3}{3})$ ed è quindi più costoso della fattorizzazione di Gauss. Il suo utilizzo è giustificato in casi particolari: 

- per problemi di approssimazione di dati sperimentali
- quando è necessaria una maggiore stabilità