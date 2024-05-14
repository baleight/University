# Metodo di Gauss

## Introduzione

### Sistemi facili: diagonali

Problema $IX=b$

$$
A=\begin{pmatrix} d_1&&& \\ &d_2&& \\ &&\ddots& \\ &&& d_n \end{pmatrix},  \det (A) = d_1 \cdot d_2 \cdot \ldots \cdot d_n
$$

Sistema in forma esplciita

$$
d_ix_i=b_i, i=1, \ldots,n \Rightarrow x_i = \frac{b_i}{d_i},i=1, \ldots,n \Rightarrow x_i
$$

Costo computazionale: $n$ quozienti

### Sistemi facili: triangolari

Si risolvono eseguendo sostituzione all’avanti e all’indietro

Ci sono due casi a seconda che la matrice del sistema sia [triangolare inferiore o superiore](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md)

***Sostituzione in avanti con matrice triangolare inferiore***

$$
R=\begin{pmatrix}
r_{11} & 0 & \cdots & 0 \\
r_{21} & r_{22} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
r_{n1} & r_{n2} & \cdots & r_{nn} \\
\end{pmatrix}
$$

$$
for \space j = 1,\ldots,n \\  \space \space \space \space \space \space \qquad \lfloor \space \space\space x_j = \frac{b_j-\sum_{i=1}^{j-1}r_{ji}x_i}{r_{jj}}
$$

***Sostituzione all’indietro con matrice triangolare inferiore***

$$
R =\begin{pmatrix}
r_{11} & r_{12} & \cdots & r_{1n} \\
0 & r_{22} & \cdots & r_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & r_{nn} \\
\end{pmatrix}
$$

$$
for \space \space \space \space j=n,\ldots,1 \\  \space \space \space \space \qquad \lfloor \space \space x_j=\frac{b_j-\sum_{i=j+1}^{n}r_{ji}x_i}{r_{jj}}
$$

In entrambi i casi il costo computazionale è pari a $\frac{n^2}{2}$

Gli algoritmi di sostituzione possono diventare instabili quando gli elementi del
triangolo inferiore sono molto grandi rispetto agli elementi diagonali.

## Descrizione

Il metodo di Gauss per la risoluzione di un sistema lineare è un algoritmo che viene diviso in 2 fasi:

1. **Fattorizzazione di Gauss** → si calcolano una matrice triangolare inferiore ($L$) e una superiore ($U$) tali che:
    
    $$
    A = LU
    $$
    
2. Costruzione di un **sistema lineare equivalente a quello iniziale**, quindi si riscrive:
    
    $$
    Ax = b \rightarrow LUx=b \Rightarrow \begin{cases}
    Ly = b \\
    Ux = y
    \end{cases}
    $$
    

La soluzione del sistema si ottiene in due passi: 

- Soluzione del sistema triangolare inferiore $Ly=b$ per sostituzione all’avanti
- Soluzione del sistema triangolare superiore $Ux=y$ per sostituzione all’indietro

# Fattorizzazione di Gauss (generico)

## Teorema di fattorizzazione di Gauss

Se tutti i minori principali di $A$ sono diversi da zero, tranne al più l’ultimo, ($A^{(k)} \ne 0, \; k=1,\dots , n-1$) allora esistono una matrice triangolare inferiore $L$ con diagonale unitaria e una matrice triangolare superiore $U$ tali che:

$$
A = LU
$$

dove $A^{(k)} = u_{11} \cdot u_{22} \cdot \, \dots \, \cdot u_{kk} \; \forall k = 1, \dots , n-1$

*Se una matrice è* [strettamente a diagonale dominante](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md) *allora soddisfa le ipotesi del teorema.*

## Descrizione

Data una matrice $A \in \mathbb R^{n \times n}$  vogliamo ottenere le matrici $L$ e $U$. Possiamo trarre alcune informazioni:

- Per come è composto il metodo si compiranno $n-1$ passi di **eliminazione gaussiana**
- Ad ogni passo $k$ si ottiene una nuova matrice $A_{k+1}$ mediante opportune combinazioni lineari delle righe di $A_k$ (quindi al passo $1$ avremo $A_1 = A$ e troveremo $A_2$) in modo che gli elementi con indice compresi tra $1$ e $k$ di $A_{k+1}$ che si trovano sotto alla diagonale principale siano nulli.
- Ad ogni passo ci interesseranno i seguenti elementi:
    - Pivot
    - Ipotesi
    - Moltiplicatori
    - Combinazioni lineari

### Passo 1

**Pivot** → $a_{11}$

**Ipotesi** → $a_{11} \ne 0$

**Moltiplicatori**:

$$
m_{i1} = \frac{a_{i1}}{a_{11}}, \; i=2,\dots,n
$$

**Combinazioni lineari** → riga $i$ con riga $1$ e coefficiente $-m_{i1}, \; i=2,\dots , n$ 

Ogni riga della matrice $A_2$ sarà così composta:

$$
a_{ij}^{(2)} = a_{ij}- m_{i1} \cdot a_{1j} \quad i,j= 2,\dots,n
$$

$$
L_1A_1=\begin{pmatrix} 1 &&&& \\ -m_{21} &1 &&& \\ -m_{31} &0&1&&\\ \vdots & && \ddots & \\ -m_{n1} & 0 & \ldots & 0 & 1 \end{pmatrix} \begin{pmatrix} a_{11} & a_{12} & a_{13}&\dots & a_{1n} \\
    a_{21} & a_{22} & a_{23}& \dots & a_{2n} \\ a_{31} & a_{32} & a_{33}&\dots & a_{3n} \\
    \vdots & \vdots & \ddots & \vdots \\
    a_{n1} & a_{n2} & a_{n3}&\dots & a_{nn} \\\end{pmatrix} = \begin{pmatrix} a_{11}^{(2)} & a_{12}^{(2)} & a_{13}^{(2)}&\dots & a_{1n}^{(2)} \\
    0 & a_{22} ^{(2)}& a_{23}^{(2)}& \dots & a_{2n}^{(2)} \\ 0 & a_{32}^{(2)} & a_{33}^{(2)}&\dots & a_{3n}^{(2)} \\
    \vdots & \vdots & \ddots & \vdots \\
    0 & a_{n2}^{(2)} & a_{n3}^{(2)}&\dots & a_{nn} ^{(2)}\\\end{pmatrix} = A_2
$$

Dove la matrice $L_1$ equivale alla matrice identità con i moltiplicatori cambiati di segno sotto la diagonale principale alla colonna $1$

### Passo 2

**Pivot → $a_{22}^{(2)}$**

**Ipotesi** → $a_{22}^{(2)} \ne 0$

**Moltiplicatori**:

$$
m_{i2} = \frac{a_{i2}^{(2)}}{a_{22}^{(2)}}, \; i = 3, \dots,n
$$

**Combinazioni lineari** → riga $i$ con riga $2$ e coefficiente $- m_{i2}, \; i = 3, \dots,n$ 

Ogni riga della matrice $A_3$ sarà così composta:

$$
a_{ij}^{(3)} = a_{ij}^{(2)} - m_{i2} \cdot a_{2j}^{(2)} \quad i,j = 3,\dots,n
$$

$$
L_2A_2=\begin{pmatrix} 1 &&& \\ 0&1 & && \\ 0&-m_{32} &1&&\\ \vdots & && \ddots  \\ 0&-m_{n2} & 0 & \ldots &  1 \end{pmatrix}  \begin{pmatrix} a_{11}^{(2)} & a_{12}^{(2)} & a_{13}^{(2)}&\dots & a_{1n}^{(2)} \\
    0 & a_{22} ^{(2)}& a_{23}^{(2)}& \dots & a_{2n}^{(2)} \\ 0 & a_{32}^{(2)} & a_{33}^{(2)}&\dots & a_{3n}^{(2)} \\
    \vdots & \vdots & \ddots & \vdots \\
    0 & a_{n2}^{(2)} & a_{n3}^{(2)}&\dots & a_{nn} ^{(2)}\\\end{pmatrix} =\begin{pmatrix} a_{11}^{(3)} & a_{12}^{(3)} & a_{13}^{(3)}&\dots & a_{1n}^{(3)} \\
    0 & a_{22} ^{(3)}& a_{23}^{(3)}& \dots & a_{2n}^{(3)} \\ 0 & 0 & a_{33}^{(3)}&\dots & a_{3n}^{(3)} \\
    \vdots & \vdots & \ddots & \vdots \\
    0 & 0 & a_{n3}^{(3)}&\dots & a_{nn} ^{(3)}\\\end{pmatrix} =A_3
$$

### Passo k

**Pivot** → $a_{kk}^{(k)}$

**Ipotesi** → $a_{kk}^{(k)} \ne 0$

**Moltiplicatori**:

$$
m_{ik} = \frac{a_{ik}^{(k)}}{a_{kk}^{(k)}}, \; i = k+1, \dots , n
$$

**Combinazioni lineari** → riga $i$ con riga $k$ e coefficiente $-m_{ik}, \; i= k+1, \dots , n$

Ogni riga della matrice $A_{k+1}$  sarà così composta:

$$
a_{ij}^{(k+1)} = a_{ij}^{(k)} -m_{ik} \cdot a_{kj}^{(k)} \quad i,j = k+1, \dots , n
$$

$$
A_{k+1}=L_kA_k=\begin{pmatrix} 1 &&&& \\ 0 & 1 &&&& \\ 0 & 0 & 1 &&& \\ \vdots & & & & & \\ &&& 1 && \\ &&& -m_{k+1,k} & 1 & \\ & && \vdots && \\ 0 & 0 && -m_{n,k} &&1\end{pmatrix} \begin{pmatrix} a_{11}^{} & a_{12}^{} &a_{13}^{} & \dots &a_{1k}^{} & \dots &a_{1n}^{}\\ & a_{22}^{(2)} & a_{23}^{(2)} & \dots &a_{2k}^{(2)} & \dots &a_{2n}^{(2)}\\&  & a_{33}^{(3)} & \dots &a_{3k}^{(3)} & \dots &a_{3n}^{(3)}\\&&& \ddots&&& \\ &&&&a_{kk}^{(k)} &\dots & a_{kk}^{(k)}\\ &&&&a_{nk}^{(k)} &\dots & a_{nk}^{(k)}\end{pmatrix}
$$

### Passo n-1

Al passo $n-1$ otteniamo la **matrice triangolare superiore** $U$ → $U = A_n =L_{n-1}A_{n-1}$

Siccome $A_{n-1} = L_{n-2} A_{n-2}$ se sostituiamo all’uguaglianza tutte le $A_k$ otteniamo:

$$
U = L_{n-1} \, L_{n-2} \, \dots \,L_{2} \, L_{1} \, A
$$

Il procedimento di eliminazione equivale ad una successione di prodotti matriciali.

L’elemento $L_k$ prende il nome di $**k$-esima trasformazione elementare di Gauss**

NB: il procedimento è ben posto solo se $a_{kk} \neq 0$  per $k=1,\ldots, n-1$

## Algoritmo di eliminazione gaussiana

Regole di aggiornamento

$$
a_{ij}^{(k+1)} = a_{ij}^{(k)} - a_{kj}^{(k)} \cdot\frac{a_{ik}^{(k)}}{a_{kk}^{(k)}} \space \space k=1,\ldots,n-1, \space \space i,j=k+1,\ldots,n
$$

Osservazione: un’ implementazione che ottimizza l’occupazione di memoria si ottiene
sovrascrivendo gli elementi della matrice aggiornata e i moltiplicatori nelle stesse
locazioni inizialmente occupate dagli elementi di A.

<aside>
<img src="https://www.notion.so/icons/snippet_green.svg" alt="https://www.notion.so/icons/snippet_green.svg" width="40px" /> **pseudo-code  $\mathcal O(\frac {n^3} 3)$**

for $k=1, n-1$

for $i=k+1,n$

$a_{ik} \leftarrow a_{ik}/a_{kk}$

for $j = k+1, n$

$a_{ij} \leftarrow a_{ij}-a_{ik}a_{kj}$

</aside>

Dopo gli $n-1$ passi del metodo nelle locazioni in cui inizialmente erano memorizzati gli elementi di A si avrà una matrice dove gli elementi della diagonale superiore e superiori saranno la matrice U mentre, al di sotto della diagonale, ci saranno i moltiplicatori. 

## Definizione di L

Sappiamo che $U = L_{n-1} \, L_{n-2} \, \dots \,L_{2} \, L_{1} \, A$ di conseguenza, possiamo isolare $A$ siccome tutte le trasformazioni elementari di Gauss $L_k$ sono [nonsingolari](Sistemi%20Lineari%20403427f308cc40a1ba490979eaaec75e.md) otteniamo la seguente uguaglianza:

$$
A = L^{-1}_{n-1} \, L^{-1}_{n-2} \, \dots \, L^{-1}_{2} \,L^{-1}_{1} \, U \\ L= L^{-1}_{n-1} \, L^{-1}_{n-2} \, \dots \, L^{-1}_{2} \, L^{-1}_{1} \\ A = L \, U
$$

Dove $L$ è una matrice triangolare inferiore nonsingolare, dato che è ottenuta dal prodotto di matrici con le medesime proprietà.

## 📜Proprietà delle trasformazioni elementari di Gauss

Posta una trasformazione $L_k$ definita come:

$$
L_k = \begin{pmatrix} 
1 \\
0 & 1 \\
\vdots \\
 & & & 1 \\
 & & & -m_{k+1, k} & 1 \\
 & & & \vdots \\
0 & 0 & & -m_{n, k} & & & 1 
\end{pmatrix}
$$

si possono definire le seguenti proprietà con annesse dimostrazioni:

- $L_k$ è triangolare con diagonale unitaria $\Rightarrow \; \det(L_k) = 1 \Rightarrow L_k$ è nonsingolare
    
    Si verifica con il principio di induzione
    
    1. Supponiamo per vero che il determinante di una certa matrice quadrata di dimensione $k$ sia uguale a 1
        
        $$
        \det
        \begin{pmatrix} 
        1 & 0 & 0 & 0 \\
        l_{21} & 1 & 0 & 0 \\
        l_{31} & l_{32} & 1 & 0 \\
        &\vdots&\vdots&\\
        l_{k1} & l_{k2} & \dots & 1
        \end{pmatrix} = 1
        $$
        
    2. E’ vero per $n=k+1$ ?
    
    $$
    \det
    \begin{pmatrix} 
    1 & 0 & 0 & 0 &0 \\
    l_{21} & 1 & 0 & 0&0  \\
    l_{31} & l_{32} & 1 & 0&0  \\
    &&\vdots&&\\
    l_{k1} & l_{k2} & \dots & 1 & 0 \\
    l_{k+1_1} & l_{k+1_2} &\dots  & &1
    \end{pmatrix} = 1
    $$
    
    1. Verificato
- Trasformazione *k-*esima: $L_k = I - m^{(k)}e^T_k$
    1. Concentrandosi sul prodotto $m^{(k)} e_k^T$, possiamo scriverlo in modo esteso:
        
        $$
        \underbrace{
        \begin{pmatrix}
        0 \\
        \cdots \\
        0 \\
        m_{k+1,k} \\
        \cdots \\
        m_{n,k}
        \end{pmatrix}}_{m^{(k)}}
        \underbrace{
        \begin{pmatrix}
        0 & \cdots & 1 & & 0 & \cdots & 0 
        \end{pmatrix}}_{e^T_k}
        
        =
        
        \begin{pmatrix} 
        0 \\
        0 & 0 \\
        \vdots \\
         & & & 0 \\
         & & & m_{k+1, k} & 0 \\
         & & & \vdots \\
        0 & 0 & & m_{n, k} & & & 0 
        \end{pmatrix}
        $$
        
    2. Facciamo la differenza tra la matrice $I$ e quello ottenuto al punto (1) 
        
        $$
        \underset{n \times n}{\begin{pmatrix} 
        1 \\
        0 & 1 \\
        \vdots \\
         & & & 1 \\
         & & & & 1 \\
        0 & 0 & &  & & 1 
        \end{pmatrix}}
        -
        \underset{n \times n}{\begin{pmatrix} 
        0 \\
        0 & 0 \\
        \vdots \\
         & & & 0 \\
         & & & m_{k+1, k} & 0 \\
         & & & \vdots \\
        0 & 0 & & m_{n, k} & & & 0 
        \end{pmatrix}}
        
        = 
        
        \underset{n \times n}{\begin{pmatrix} 
        1 \\
        0 & 1 \\
        \vdots \\
         & & & 1 \\
         & & & -m_{k+1, k} & 1 \\
         & & & \vdots \\
        0 & 0 & & -m_{n, k} & & & 1 
        \end{pmatrix}}
        $$
        
- Inversa della trasformazione *k-*esima:  $L_k^{-1} = I + m^{(k)} e^T_k$
    
    Nella dimostrazione ci si basa sul fatto che $L_k \, L_k^{-1} = I$ quindi riscrivendo per esteso la trasformazione elementare e la sua inversa si ottiene:
    
    $$
    (I - m^{(k)} e_k^T) \cdot (I + m^{(k)} e_k^T) = I\cdot I - m^{(k)} e_k^T \cdot I + I \cdot m^{(k)} e_k^T - m^{(k)} e_k^T \cdot m^{(k)} e_k^T
    $$
    
    Che possiamo riscrivere come:
    
    $$
    I- m^{(k)} e_k^T + m^{(k)} e_k^T - m^{(k)} e_k^T \cdot m^{(k)} e_k^T = I
    $$
    
    Nell’ultimo prodotto, se si risolve prima $e^T_k \cdot m^{(k)}$, siccome è un prodotto tra vettore colonna e vettore riga si ottiene uno scalare $: 0$
    
    Quindi siccome il secondo e il terzo membro si annullano rimane solamente $I$
    
    $$
    L_k^{-1} = \begin{pmatrix} 
    1 \\
    0 & 1 \\
    \vdots \\
     & & & 1 \\
     & & & m_{k+1, k} & 1 \\
     & & & \vdots \\
    0 & 0 & & m_{n, k} & & & 1 
    \end{pmatrix}
    $$
    
- Prodotto delle inverse di due trasformazioni elementari di Gauss: $L_k^{-1} L_j^{-1} = I + m^{(k)}e^T_k + m^{(j)}e^T_j$
    
    Nella dimostrazione innanzitutto scriviamo per esteso il prodotto basandoci sulla proprietà precedente:
    
    $$
    L_k^{-1} L_j^{-1} = (I + m^{(k)}e^T_k) (I + m^{(j)}e^T_j)
    $$
    
    Risolviamo il prodotto ed otteniamo:
    
    $$
    I + m^{(k)}e^T_k + m^{(j)}e_j^T + m^{(k)}e^T_k \; m^{(j)}e_j^T
    $$
    
    Anche qua, come nella dimostrazione precedente, si risolver prima il prodotto centrale $e^T_k \, m^{(j)}$ che dà come risultato $0$, annullando l’ultimo fattore della somma.
    
    Perciò abbiamo che:
    
    $$
    L_k^{-1} L_j^{-1} = I + m^{(k)}e^T_k + m^{(j)}e^T_j
    $$
    

## Unicità della fattorizzazione di Gauss

Se $A$ è nonsingolare, allora la fattorizzazione $A = LU$ è **unica**.

### 📜Dimostrazione

Supponiamo per assurdo che esistano 2 coppie di matrici $(L_1,U_1 \text{ e } L_2,U_2)$ con le proprietà enunciate nel teorema. Perciò:

$$
A = L_1U_1 \; \text{ e } \; A=L_2U_2
$$

Abbiamo che $L_1$  e $L_2$ sono nonsingolari e siccome $A$ è nonsingolare allora anche $U_1$ e $U_2$ sono nonsingolari (il prodotto di due non singolari restituisce una non singolare), quindi possiamo scrivere:

$$
L_1 U_1 = L_2U_2 \Rightarrow L_1^{-1}L_2 = U_1 U_2^{-1}
$$

Ci ricordiamo che il prodotto a sinistra, tra matrici triangolari inferiori, dà come risultato una matrice triangolare inferiore. Analogamente il prodotto a destra, tra matrici triangolari superiori, dà come risultato una matrice triangolare superiore. L’unico modo per far valere l’uguaglianza è quindi che entrambi i prodotti diano come risultato una matrice diagonale.

Dato che $L_1^{-1}L_2$ ha diagonale unitaria, la matrice risultante è $I$, quindi risulta che:

$$
L_1^{-1} L_2 = I \Rightarrow L_2 = L_1 \\
U_1 U_2^{-1} = I \Rightarrow U_1 = U_2
$$

## Soluzione sistema lineare

$$
Ax = b \\
L Ux = b \rightarrow Ux = y \\
\begin{cases}
Ly = b \\
Ux = y
\end{cases}
$$

NB: bisogna risolvere prima il sistema $Ly=b$ trovando $y$ con una sostituzione in avanti e, solo dopo, si può risolvere il 2° sistema. 

## Condizione necessaria e sufficiente

Affinchè tutti i perni siano diversi da zero (e quindi l’algoritmo di Gauss sia ben
posto) è che i minori principali di $A$  siano tutti diversi da zero eccetto al più
l’ultimo ($\det A$ può essere nullo ma l’algoritmo potrebbe essere ugualmente
portato a termine).

Se l’ipotesi del teorema di fattorizzazione di Gauss non è soddisfatta, l’algoritmo
non può essere portato a termine.

Osservazioni: non tutte le matrici invertibili hanno tutti i minori principali diversi da zero.

*Esempio*

$$
A=
\begin{pmatrix} 
0 & 1 \\
1 & 0

\end{pmatrix}
$$

Introduciamo una modifica dell’algoritmo di Gauss che possa essere applicata a
tutte le matrici non singolari.

# Fattorizzazione di Gauss (con scambio di righe)

L’idea è quella di scambiare le righe della matrice durante il procedimento di fattorizzazione; ciò equivale a scambiare due equazioni del sistema $Ax=b$

Al passo $k$, se l’elemento $a_{kk} = 0$, si scambiano la riga $k$ con una riga $r$ tale che $a_{rk} \neq 0$della matrice $A_k$. Deve essere $r \geq k$ per non distruggere la struttura triangolare che si sta costruendo.

$$

\begin{pmatrix}
a_{11} & \dots &&&&& \\
& a_{22} &&&&& \\
&& \dots &&&& \\
&&& \color{red}a_{kk}^{(k)} & \color{red}\dots & \color{red}a_{kn}^{(k)} & \color{red}b_k^{(k)} \\

&&& \dots  & \dots & \dots&\dots \\
&&& \color{red}a_{rk}^{(k)} & \color{red}\dots & \color{red}a_{rn}^{(k)} & \color{red}b_r^{(k)} \\
&&& \dots  & \dots & \dots&\dots \\
&&& a_{nk}^{(k)} & \dots & a_{nk}^{(k)} & b_n^{(k)} \\

\end{pmatrix}
$$

Dopo lo scambio delle righe, si procede con il calcolo dei moltiplicatori e della
corrispondente trasformazione elementare di Gauss.

## Matrici di permutazioni elementari

Lo scambio di due righe di una matrice può essere espresso come un prodotto
matriciale tramite opportune matrici di permutazione elementari.

> **Cos’è una matrice di permutazioni elementari?**
> 
> 
> È una matrice ottenuta dalla matrice identità con due righe (o colonne) invertite.
> 
> ---
> 
> **Cos’è una matrice di permutazione?**
> 
> È il prodotto di un numero finito di matrici di permutazioni elementari.
> 
> *Esempio*
> 
> $$
> \begin{pmatrix}
> 1 & 0 & 0 \\
> 0 & 0 & 1\\
> 0 & 1 & 0\\
> \end{pmatrix}
> \begin{pmatrix}
> a_{11} & a_{12}  & a_{13}  \\
> a_{21} & a_{22} & a_{23}\\
> a_{31} & a_{32} & a_{33}\\
> \end{pmatrix}= 
> \begin{pmatrix}
> a_{11} & a_{12}  & a_{13}  \\
> a_{31} & a_{32} & a_{33}\\
> a_{21} & a_{22} & a_{23}\\
> \end{pmatrix}
> $$
> 

Quindi per scambiare 2 righe della matrice $A$ è possibile moltiplicarla per la matrice identità $I$ con le due righe invertite.

Chiamiamo $P_{ij}$ la matrice identità con le righe $i$ e $j$ invertite. Avremo che: 

- $P_{ij} A$  sarà la matrice $A$ con le righe $i$ e $j$ invertite
- $AP_{ij}$ sarà la matrice $A$  con le colonne $i$ e $j$ invertite

### Proprietà delle matrici di permutazioni elementari

1. Sono matrici nonsingolari → $\det (P_{ij}) = -\det (I) = -1$
2. Sono matrici simmetriche: *sono uguali alla loro **trasposta → $P_{ij} = P_{ij}^T$***
3. Sono matrici ortogonali: *il prodotto tra la matrice e la sua trasposta dà **l’identità** quindi l’inversa è uguale alla trasposta **→** $P_{ij} P_{ij}^T = P_{ij} P_{ij} = I$*

## Primo passo

Dall’ipotesi di nonsingolarità segue che esiste almeno un elemento diverso da zero
nella prima colonna di A (poichè una colonna composta da soli 0 è sinonimo di singolarità).

1. Si definisce la matrice di permutazione elementare $P_1$ che scambia la riga $1$ con una qualsiasi riga $r$ tale che $a_{r1} \neq 0$.  Se $a_{11} \neq 0$ allora è possibile scegliere $P_1 = I$ in modo da non effettuare nessuno scambio.
2. Si calcolano i moltiplicatori associati alla prima colonna della matrice permutata $P_1A$ e di definisce la matrice elementare di Gauss $L_1$ corrispondente che non agirà più da sola su $A$ ma anche assieme alla matrice di permutazione.
3. Si aggiornano gli elementi della matrice: $A_2 = L_1P_1A.$

## Secondo passo

$$
A_2 = L_1P_1A=
\begin{pmatrix}
a_{11}^{(2)}& a_{12}^{(2)} & \dots & a_{1n}^{(2)} \\
0 & a_{22}^{(2)} & \dots & a_{2n}^{(2)} \\
\dots &&& \\
0 & a_{n2}^{(2)} & \dots & a_{nn}^{(2)}
\end{pmatrix}
$$

Definiamo la matrice $\tilde{A}_2$ come la sottomatrice di $A_2$ formata dalle sue ultime $n-1$ righe e colonne

$$
\tilde{A}_2= \begin{pmatrix}
 a_{22}^{(2)} & \dots & a_{2n}^{(2)} \\
\dots&&& \\
 a_{n2}^{(2)} & \dots & a_{nn}^{(2)}
\end{pmatrix}
$$

Esiste almeno un elemento $a_{i2}^{(2)} \neq 0$ per almeno un indice compreso tra $i= 2, \dots , n$ (in caso contrario vorrebbe dire che $\tilde{A}_2$ è singolare ossia non invertibile ossia  
$\det(\tilde{A}_2) = 0$ ) perchè osserviamo che:   

- $A_2$ è non singolare perchè prodotto di matrici non singolari
- Per il teorema di Laplace $\det(A_2) = a_{11}^{(2)} \det (\tilde{A}_2)$

Dato che $\det(A_2) \neq 0$ (non singolare) e $a_{11}^{(2)} \neq 0$ (per il metodo di Gauss) allora questo implica che $\det(\tilde{A}_2) \neq 0$ e quindi esiste almeno un $a_{i2}^{(2)} \neq 0$ per almeno un indice compreso tra $i= 2, \dots , n$.

## Passo k

$$
A_k = L_{k-1}P_{k-1}\cdot \ldots \cdot L_2P_2L_1 P_1 A = 
\begin{pmatrix}
a_{11}^{(2)} & & & & a_{1n}^{(2)}\\
& \ddots & & & \\
& & a_{kk}^{(k)} & \dots &a_{kn}^{(k)} \\
&& \vdots && \vdots \\
&& a_{nk}^{(k)} & \dots & a_{nn}^{(k)}

\end{pmatrix}
$$

Si definisce 

$$
\tilde{A}_k= \begin{pmatrix}
 a_{kk}^{(k)} & \dots & a_{kn}^{(k)} \\
\dots&&& \\
 a_{nk}^{(k)} & \dots & a_{nn}^{(k)}
\end{pmatrix}
$$

Si ha: 

- Dal teorema di Laplace $\det (A_k) = a_{11}^{(2)} \cdot a_{22}^{(3)} \cdot \, \dots \, \cdot a_{k-1\:k-1}^{(k)} \cdot \det (\tilde A_k)$
- $\det (A_k) \neq 0$  e $a_{jj}^{(j+1)} \neq 0 \space \space \forall j=1, \ldots, k-1$

implicano che

- $\det (\tilde A_k) \ne 0$ → $\tilde A_k$  nonsingolare → esiste almeno un elemento diverso da 0 nella sua prima colonna

## Dopo n-1 passi

$$
A_k = L_{n-1}P_{n-1}\cdot \ldots \cdot L_2P_2L_1 P_1 A = 
\begin{pmatrix}
a_{11}^{(2)} & & & & a_{1n}^{(2)}\\
& \ddots & & & \\
& & a_{kk}^{(k+1)} & \dots &a_{kn}^{(n+1)} \\
&& & \ddots & \vdots \\
&&  &  & a_{nn}^{(n)}

\end{pmatrix}
$$

## Teorema di fattorizzazione di Gauss con scambio di righe

Se $A$ è nonsingolare, allora esiste una matrice di permutazione $P$, una matrice triangolare superiore $U$, una matrice triangolare inferiore $L$ con diagonale unitaria $PA = LU$

Osservazione:

Si ha che

$$
U = L_{n-1}P_{n-1} \cdot \, \dots \, \cdot L_{2}P_{2}L_{1}P_{1} A
$$

- $P = P_{n-1} \cdot \, \dots \, \cdot P_{1}$
- $L = \prod_{k=1}^{n-1} P_{n-1} \cdot \, \dots \, \cdot P_{(k+1)}L_k^{-1}$ → *la $k$-esima colonna di $L$ contiene i moltiplicatori definiti al passo $k$ permutati secondo gli scambi di righe fatti nei passi successivi.*

## Soluzione sistema lineare

$$
\textit{Il problema è risolvere } \\
Ax = b \\
\textit{Ho trovato P, quindi moltiplico} \\
PAx = Pb\\
\textit{Riscrivo PA come LU}\\
L Ux = Pb \\
\begin{cases}
Ly = Pb \\
Ux = y
\end{cases}
$$

## Non unicità

La fattorizzazione $PA=LU$ non è unica poichè ad ogni passo si può scegliere quale scambio di righe effettuare con l’unica condizione di portare in posizione perno un elemento diverso da zero.

- Dal punto di vista teorico, qualsiasi elemento perno diverso da zero permette
di calcolare i moltiplicatori e quindi di portare a termine l’algoritmo.
- Dal punto di vista numerico esistono scelte più vantaggiose

NB: La scelta del perno influisce sugli elementi della matrice L. Gli algoritmi di
sostituzione possono diventare instabili quando gli elementi del triangolo sono
molto grandi rispetto alla diagonale.

### Pivoting parziale

La scelta di un perno molto piccolo e quindi, di conseguenza, un moltiplicatore molto grande causa l’instabilità dell’algoritmo. 

La strategia del pivoting parziale prevede, al passo $k$, la scelta dell’elemnto più grande in valore assoluto come perno della prima colonna della matrice $\tilde{A}_k$

$$
|a_{rk}^{(k)}|=\max_{i \in \{k,\dots, n\}}|a_{ik}^{(k)}|
$$

La conseguenza del pivoting

$$
|m_{ik}| \leq 1, \space \forall k =1,\dots,n-1, \forall i = k+1, \dots, n
$$

In generale l’introduzione della strategia di pivoting parziale rende l’algoritmo di soluzione del
sistema mediante fattorizzazione di Gauss più stabile.

# Fattorizzazione di Gauss per matrici simmetriche

Se $A$ è [simmetrica](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md) e tutti i suoi minori principali sono diversi da zero, allora esistono una matrice $L$ triangolare inferiore con diagonale unitaria e una matrice diagonale $D$ con elementi diagonali diversi da zero

Quindi:

$$
A = LDL^T
$$

## 📜Dimostrazione

Sappiamo che $A$ è nonsingolare ($\det(A) \ne 0$), di conseguenza anche $U$ è nonsingolare (poiché hanno le diagonali uguali).

$A = LU$ e $D = \text{diagonale di }U$ quindi $A = LDD^{-1}U$

Devo verificare che $D^{-1}U = L^T$

definisco $R := D^{-1}U$

$$
R = \begin{pmatrix}
\frac{1}{u_{11}} & & &\\ 
& \frac{1}{u_{22}} &  &\\
& & ... &\\
& & & \frac{1}{u_{nn}} \\
\end{pmatrix}
\begin{pmatrix}
u_{11} & u_{12} & \dots & u_{1n}\\ 
0 & u_{22} & \dots & u_{2n}\\
\vdots &  & \ddots  & \\
0 & 0 & \dots & u_{nn}\\
\end{pmatrix}
=
\begin{pmatrix}
1 & \frac{u_{12}}{u_{11}} & \dots & \frac{u_{1n}}{u_{11}}\\ 
0 & 1 & \dots & \frac{u_{1n}}{u_{22}}\\
0 & 0 & \ddots & \\
0 & 0 & 0 & 1\\
\end{pmatrix}
$$

L’obiettivo è dimostrare $R = L^T$

Abbiamo che $A = LDR$, ma essendo $A$ **[simmetrica](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md)** allora $A = A^T$ quindi

$A ^ T = (LDR)^T = R^TD^TL^T$ e siccome $D=D^T$, poichè D è diagonale, possiamo scrivere $R^TDL^T$

Allora → $LDR = R^TDL^T$ 

moltiplichiamo a destra per $(L^T)^{-1}$ 

otteniamo $LDR(L^T)^{-1} = R^TD$

moltiplichiamo a sinistra per $L^{-1}$

otteniamo $DR(L^T)^{-1} = L^{-1}R^TD$

$D, R, (L^T)^{-1}$ sono tutte matrici triangolari **superiori** quindi il prodotto darà una matrice triangolare superiore

$L^{-1},R^T,D$ sono tutte matrici triangolari **inferiori** quindi il prodotto darà una matrice triangolare inferiore

Quindi per poter rispettare l’uguaglianza entrambe le matrici devono essere diagonali

Soffermandoci sul prodotto a sinistra dell’uguale possiamo dire che $R(L^T)^{-1}$ è una matrice diagonale poiché, siccome $D$ è diagonale, per risultare diagonale il loro prodotto deve essere tra due matrici diagonali.

Sia $R$  che $(L^T)^{-1}$ hanno diagonale unitaria quindi il loro prodotto sarà una matrice a diagonale unitaria, in particolare l’**identità**.

Abbiamo $R(L^T)^{-1} = I$

moltiplichiamo a destra per $L^T$

otteniamo $R(L^T)^{-1}L^T = I L^T$ 

Siccome $(L^T)^{-1}L^T = I$ allora:

$$
R = L^T
$$

## Metodo di pavimentazione

Il teorema di fattorizzazione di Gauss per matrici simmetriche implica che gli
elementi da calcolare sono solo quelli della matrice $L$ e della diagonale di $D$.

In modo più esplicito abbiamo:

$$
\begin{pmatrix}
a_{11} & a_{12} & a_{13} & \dots & a_{1n} \\
a_{21} & a_{22} & a_{23} & \dots & a_{2n} \\
\vdots \\
a_{n1} & a_{n2} & a_{n3} & \dots & a_{nn} \\
\end{pmatrix} 
=
\begin{pmatrix}
1\\
l_{21} & 1 \\
\vdots \\
l_{n1} & l_{n2} & \dots & 1 \\
\end{pmatrix}

\begin{pmatrix}
d_{11}\\
 & d_{22} \\
 & & \ddots \\
 &  &   & d_{nn} \\
\end{pmatrix}

\begin{pmatrix}
1 & l_{21} & \dots & l_{n1} \\
 & 1  & \dots & l_{n2} \\
 \\
 & & & 1 \\
\end{pmatrix}
$$

$$
a_{ij}=(l_{i1}, l_{i2},...l_{ij},...,l_{ii-1}, 1, 0,0)
\begin{pmatrix}
d_{11}l_{j1} \\
d_{22}l_{j2} \\
\vdots \\
d_{j-1j-1}l_{jj-1} \\
d_{jj}\\
0 \\
\vdots \\
0
\end{pmatrix}
=\\
d_{jj}l_{ij}+\sum^{j-1}_{k=1}l_{ik}d_{kk}l_{jk}, 
\begin{matrix}
j=1,\dots,n\\
i=j,\dots,n
\end{matrix}
$$

## Primo passo j=1

$$
\begin{cases}
a_{11} = d_{11} \Rightarrow \red{d_{11}} =a_{11} & \text{se } i = 1 \\
a_{i1} = \red{d_{11}}\,l_{i1}\Rightarrow \red{l_{i1}} = \frac{a_{i1}}{d_{11}} 
 & \text{se } i \gt 1
\end{cases}
$$

$$
\begin{pmatrix}
1 & & & & \\
\red{l_{21}} & 1 & & & \\
\red{l_{31}} & l_{32} & 1 && \\
\dots & & & & \\
\red{l_{n1}} & l_{n2} & l_{n3} & \dots & 1 
\end{pmatrix}
\begin{pmatrix}
\red{d_{11}}\\
 & d_{22} \\
 & & \ddots \\
 &  &   & d_{nn} \\
\end{pmatrix}

\begin{pmatrix}
1 & \red{l_{21}} & \red{l_{31}}& \dots & \red{l_{n1}} \\
 & 1  & l_{32} & \dots & l_{n2} \\ 
&&1 & \dots & l_{n3}
 \\ \\
 & & && 1 \\
\end{pmatrix}

$$

## Secondo passo j=2

$$
\begin{cases}
a_{22} = d_{22} + d_{11}l_{21}^{2} \Rightarrow d_{22} = a_{22} - d_{11}l_{21}^{2} & \text{se } i = 2 \\
a_{i2} = d_{22}l_{i2}+l_{i1}d_{11}l_{21}\Rightarrow l_{i2} = \frac{(a_{i2}-l_{i1}d_{11}l_{21})}{d_{22}} 
 & \text{se } i \gt 2
\end{cases}
$$

$$
\begin{pmatrix}
1 & & & & \\
l_{21} & 1 & & & \\
l_{31} & l_{32} & 1 && \\
\dots & & & & \\
l_{n1} & l_{n2} & l_{n3} & \dots & 1 
\end{pmatrix}
\begin{pmatrix}
d_{11}\\
 & d_{22} \\
 & & \ddots \\
 &  &   & d_{nn} \\
\end{pmatrix}

\begin{pmatrix}
1 & l_{21} & l_{31}& \dots & l_{n1} \\
 & 1  & l_{32} & \dots & l_{n2} \\ 
&&1 & \dots & l_{n3}
 \\ \\
 & & && 1 \\
\end{pmatrix}

$$

## Passo j

Al passo $j$ sono già stati calcolati gli elementi

$$
d_{kk},l_{ik} \space \space k=1,\ldots, j-1, i=k+1,\ldots,n 
$$

Si vogliono calcolare $d_{jj}$ e $l_{kj}$, $k=j+1,\ldots, n$ dalle relazioni

- $i = j$
    
    $$
    a_{jj} = d_{jj} + \sum_{k = 1}^{j-1}{l_{jk}}^2 \, d_{kk} \Rightarrow d_{jj} = a_{jj} - \sum_{k=1}^{j-1}{l_{jk}}^2 \, d_{kk}
    $$
    
- $i > j$
    
    $$
    a_{ij} = d_{jj} \, l_{ij} + \sum_{k=1}^{j-1} l_{ik} \, d_{kk} \, l_{jk} \Rightarrow l_{ij} = \frac{(a_{ij} - \sum_{k=1}^{j-1}l_{ik} \, d_{kk} \, l_{jk})}{d_{jj}}
    $$
    
    <aside>
    <img src="https://www.notion.so/icons/snippet_green.svg" alt="https://www.notion.so/icons/snippet_green.svg" width="40px" /> **pseudo-code  $\mathcal O(\frac {n^3} 6)$**
    
    for $k = 1,\dots, n$
    
    for $j = 1,\dots,k-1$
    
    $p_{kj} = l_{kj} d_{jj}$
    
    $d_{kk} = a_{kk} - \sum_{j=1}^{k-1}l_{kj} \; p_{kj}$
    
    for $i = k+1 , \dots ,n$
    
    $l_{ik} = (a_{ik} - \sum_{j=1}^{k-1}l_{ij} \, p_{kj} ) \; / \; d_{kk}$
    
    </aside>
    
    ## Soluzione sistema lineare
    
    $$
    Ax = b \Leftrightarrow L D L^T x = b \\
    z = DL^Tx
    $$
    
    $$
    \begin{cases}
    Lz & = & b \\
    Dy & = & z \\
    L^T x & =  & y
    \end{cases}
    $$