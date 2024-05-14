# Metodi iterativi

Un metodo iterativo consiste in una formula ricorsiva che, dato $x^{(k)}$, permette di calcolare $x ^{(k+1)}$. Permettono quindi di generare una [successione di vettor](Altro%20c4b2595a1fce481f9b1b7e2bb06558f5.md)i $\{ x^{(k)}\}_{k \in \mathbb N} \sub \mathbb R^n$

$$

x^{(k)} = \begin{pmatrix}
x^{(k)}_1 \\
x^{(k)}_2 \\
\vdots \\
x^{(k)}_n \\
\end{pmatrix}
$$

che, per un certo $k \rightarrow \infty$ , converge ad $x^*$ che è soluzione del problema.

Risulta utile far notare che **nella maggior parte dei casi non si arriva mai alla soluzione esatta**, ma ci si avvicina quanto basta per soddisfare l’errore di macchina.

## Successione convergente

La successione $\{ x^{(k)}\}_{k \in \mathbb N} \quad x^{(k)} \in \mathbb R^n \;\forall k$ converge ad un punto $x^* \in \mathbb R^n$ se

$$
\lim_{k \rightarrow \infty} \lVert x^{(k)} - x^* \lVert = 0 \qquad \text{ per qualche norma vettoriale } \lVert \cdot \lVert
$$

In questo caso possiamo dire che:

$$
\lim_{k \rightarrow \infty} x^{(k)} = x^*
$$

**Commento**

L’obiettivo è determinare un criterio per verificare se un vettore casuale può essere soluzione del sistema $Ax=b$. Questo criterio corrisponderà a un metodo iterativo attraverso il quale sostituisco ogni volta un vettore $x$ differente in modo da avvicinarmi sempre di più alla soluzione $x^*$ che non sarà mai esatta considerando la precisione di macchina.  

## Riformulazione di un sistema lineare

Per riformulare un sistema lineare $Ax = b$ prendiamo:

- $M$ una matrice $n\times n$ **nonsingolare** che prende il nome di **matrice del metodo**
    - sommiamo $Mx$ ad entrambi i membri e portiamo $Ax$ dall’altra parte → $Mx = Mx - Ax + b$
    - raccogliamo $x$ → $Mx = (M - A) x + b$
    - voglio isolare la $x$ a sinistra, quindi moltiplico per $M^{-1}$ (**dato che $M$ è nonsingolare**) → $M^{-1}Mx = M^{-1}[(M-A)x + b]$
        - $x = M^{-1}(M-A)x + M^{-1}b = (I - M^{-1}A)x + M^{-1}b$

*da cui:*

- $G = I-M^{-1}A$ una matrice $n \times n$ che prende il nome di **matrice di iterazione**
- $c = M^{-1}b$ un vettore $n \times 1$

$$
x =(\underbrace{I - M^{-1}A}_G)x + \underbrace{M^{-1}b}_c \Rightarrow x = Gx+c
$$

Siccome la utilizziamo in un algoritmo iterativo vogliamo che la $x$ a sinistra sia quella da trovare (*successiva*), mentre la $x$ di destra sia quella che abbiamo (*attuale*). Perciò possiamo riscrivere il sistema utilizzando una notazione più comoda:

$$
x^{(k+1)} = Gx^{(k)} + c, \quad \text{ad un certo punto avremo } x^* = Gx^{(k+i)} +c
$$

- Per innescare il procedimento occorre fornire il punto iniziale $x^{(0)} \in \mathbb R ^n$
- Diverse scelte di $M$ corrispondono a diversi metodi iterativi
- Un metodo iterativo si dice convergente se per ogni scelta del punto iniziale $x^{(0)} \in \mathbb R^n$ la successione generata converge alla soluzione del sistema
- La convergenza di un metodo dipende dalla scelta di $M$

## Condizioni di convergenza

### **Teorema (condizione sufficiente)**

Se $\lVert G \lVert \lt 1$, allora il metodo iterativo:

$$
x^{(k+1)} = Gx^{(k)}+c,\space k=0,1,2,\dots
$$

è **convergente.**

*In modo equivalente:*

$$
\lVert G \lVert \lt 1 \Rightarrow \text{converge}
$$

### 📜Dimostrazione commentata

Prendiamo $e^{(k)} = x^{(k)} - x^*$ che è la differenza tra soluzione esatta e dove sono attualmente

$$
\lim_{k \rightarrow \infty} x^{(k) } = x^* \Leftrightarrow \lim_{k \rightarrow \infty} x^{(k)} - x^* = 0 \Leftrightarrow \lim_{k \rightarrow \infty} e^{(k)} = 0
$$

*Come può essere riscritto $e^{(k)}$ ?*

- Sostituiamo $x^{(k)}$  e $x^*$ con i rispettivi sistemi $Gx+c$ → $e^{(k)} = Gx^{(k-1)} +c - Gx^* -c$
- Raccolgo $G$ e semplifico le $c$ → $e^{(k)} = G(x^{(k-1)} - x^*)$
- $(x^{(k-1)} - x^*)$ non è altro che $e^{(k-1)}$ → $e^{(k)} = G e^{(k-1)}$
- $e^{(k-1)}$ sarà quindi uguale a $Ge^{(k-2)}$ → $e^{(k)} = G\cdot G e^{(k-2)} = G^2 e^{(k-2)}$
- Proseguendo fino al passo $0$ ottengo → $e^{(k)} = G^k e^{(0)}$

Abbiamo quindi

$$
\lim_{k \rightarrow \infty} e^{(k)} = \lim_{k \rightarrow \infty} x^{(k)} - x^* = \lim_{k \rightarrow \infty} G^k e^{(0)}
$$

Utilizzando la [proprietà submoltiplicativa](Norme%20vettoriali%20e%20matriciali%20c2013a0b8b284b44adb38a6b6d122217.md) otteniamo:

$$
\lim_{k \rightarrow \infty} \lVert x^{(k)}-x^*\lVert\le \lim_{k \rightarrow \infty} \lVert G^k \lVert \space \lVert e^{(0)} \lVert \le \lim_{k \rightarrow \infty} \lVert G \lVert^k \space \lVert e^{(0)} \lVert \leq (\lim_{k \rightarrow \infty}\lVert G \lVert^k )\lVert e^{(0)} \lVert
$$

Siccome $\lVert e^{(0)} \lVert$ non utilizza $k$ possiamo riscriverlo come $\lVert e^{(0)} \lVert \cdot \lim_{k \rightarrow \infty} \lVert G \lVert^k$ 

Per **HP:** $\lVert G \lVert \le 1$ allora:

$$
\lim_{k \rightarrow \infty} \lVert G \lVert^k =0
$$

<aside>
💡 $\lVert G \lVert$ mi dice quanto $x^{(k+1)}$  si allontana da $x^{(k)}$.

</aside>

### Commento

La norma matriciale prende in ingresso una matrice e restituisce un numero reale $\lVert \space \cdot \space \lVert: \mathbb R^{n \times n} \rightarrow R$

Consideriamo $\lVert G^k \lVert = \lVert G \cdot G \cdot G \dots\lVert = \lVert G^{k-1} \cdot G \lVert \le \lVert G^{k-1} \lVert \cdot \lVert G \lVert = \lVert G^{k-2} G \lVert \cdot \lVert G \lVert \le \lVert G^{k-2} \lVert \cdot \lVert G \lVert^2$

Dopo $k-2$ volte avremo $\lVert G \lVert \le \lVert G \lVert^k$

### **Teorema (condizione necessaria e sufficiente)**

Il metodo iterativo $x^{(k+1)} = Gx^{(k)} +c, \; k = 1,2,\dots$ è convergente se e solo se $\rho(G) \lt 1$.

**Commento**

$\rho$ indica la [velocità di convergenza](Altro%20c4b2595a1fce481f9b1b7e2bb06558f5.md)

## Criteri di arresto

Occorre individuare una condizione per cui dopo $k$ passi l’algoritmo si deve arrestare.

A livello teorico vorremmo, dato un $\epsilon$, individuare per quale $k$ si ha:

$$
\lVert x^{(k)} - x^* \lVert \le \epsilon
$$

Occorre stimare l’errore $\lVert x^{(k)} - x^* \lVert$ in base a quantità calcolabili. 

## Stima dell’errore

### Proposizione

Sia $\tau \gt 0$. **Se** per un certo $k$ si ha che

$$
\lVert x^{(k+1)} - x^{(k)} \lVert \le \tau
$$

allora

$$
\lVert x^{(k)} - x^* \lVert \le \epsilon \text{ con } \epsilon = \tau \lVert (G - I) ^{-1}\lVert
$$

### 📜Dimostrazione

Sappiamo che $x^*$  è la soluzione del sistema, quindi $x^* = Gx^* + c \Rightarrow c = x^* - Gx^*$

Prendiamo la differenza tra due iterate successive $k$ e $k+1$

$$
x^{(k+1)} - x^{(k)} = Gx^{(k)} + c - x^{(k)} = Gx^{(k)} - Gx^* +x^* - x^{(k)}
$$

Raccogliamo $G$ → $G (x^{(k)} - x^*) - (x^{(k)} - x^*)$

Raccogliamo $(x^{(k)} - x^*)$ → $(G - I)(x^{(k)} - x^*)$

Quindi:

$$
(x^{(k+1)} - x^{(k)}) = (G - I)(x^{(k)} - x^*) \quad \forall \, k = 0, \dots , n
$$

Vorremmo isolare $(x^{(k)} - x^*)$, per farlo dobbiamo moltiplicare per $(G-I)^{-1}$. Possiamo?

> Dobbiamo verificare che $(G - I)$ sia nonsingolare:
> 
> 
> $G-I = I-M^{-1}A - I = -M^{-1} A$ → siccome $M$ ed $A$ sono nonsingolari, la proprietà viene mantenuta col prodotto, allora $G$ è nonsingolare.
> 

$$
(x^{(k)} - x^*) = (G - I)^{-1} (x^{(k+1)} - x^{(k)})
$$

Passo alla norma e applico la proprità submoltiplicativa:

$$
\lVert x^{(k)} - x^* \lVert = \lVert (G - I)^{-1} (x^{(k+1)} -x^{(k)}) \lVert \le \lVert (G-I)^{-1} \lVert \cdot \lVert x^{(k+1)} - x^{(k)} \lVert 
$$

A questo punto poniamo:

- $\tau = \lVert x^{(k+1)}- x^{(k)} \lVert$
- $\epsilon = \lVert (G - I)^{-1} \lVert \, \tau$

## Calcolo del residuo

Al passo $k$ il residuo è un **vettore** definito come:

$$
r^{(k)} = b - Ax^{(k)}
$$

$*r^{(k)} = 0 \Leftrightarrow x^{(k)} = x^*$, cioè il residuo è nullo in corrispondenza della soluzione.*

## **Proposizione**

Sia $\tau \gt 0$. Se per un certo $k$ si ha

$$
\frac{\lVert r^{(k)} \lVert}{\lVert b \lVert} \le \tau, \text{ allora } \frac{\lVert x^{(k)} - x^* \lVert}{\lVert x^* \lVert} \le k(A)\tau
$$

dove $k(A)$ è il [numero di condizionamento](Sistemi%20Lineari%20403427f308cc40a1ba490979eaaec75e.md) della matrice $A$

---

**Commento**

Più il numero di condizionamento è piccolo meno il sistema è malcondizionato. Più il sistema è malcondizionato, maggiore è l’errore sulla soluzione. 

La dimostrazione si basa tutta sulla definizione di [numero di condizionamento](Sistemi%20Lineari%20403427f308cc40a1ba490979eaaec75e.md)

# Pseudocodice

<aside>
<img src="https://www.notion.so/icons/snippet_green.svg" alt="https://www.notion.so/icons/snippet_green.svg" width="40px" /> **Pseudocodice**

**INPUT → $x^{corr}, A, b, G, c, \tau, N_{max}$**

for $k=0, 1, \dots, N_{max}$

$r \leftarrow b - Ax^{corr}$

$x^{next} \leftarrow Gx^{corr}+c$

if  $\frac{\lVert x^{next} - x^{corr} \lVert}{\lVert x^{next}\lVert} \lt \tau$ AND $\frac{\lVert r \lVert}{\lVert b  \lVert} \lt \tau$

return $x^{corr}$

else

$x^{corr} \leftarrow x^{next}$

endif

if $k == N_{max}$

print warning message

endif

</aside>

Costo computazionale per iterazione → $\mathcal O(n^2)$

Il costo computazionale complessivo dipende da quante iterazioni vengono fatte, e a priori non è possibile saperlo; per cui i metodi iterativi entrano in competizione con i diretti quando la soluzione del sistema richiede poche iterazioni. 

Risulta utile fare 2 precisazioni:

1. Con i vettori $x^{corr}$ e $x^{next}$ si evita di memorizzare l’intera successione in memoria, permettendo l’utilizzo solo dei vettori necessari.
2. Dato che il numero di iterazioni dipendono dal condizionamento del problema, risulta comodo inserire un paramentro di salvaguardia $N_{max}$, che non è altro che il numero massimo di iterazioni che può fare l’algoritmo.

# Metodi di decomposizione

Questa tipologia di metodi si basa su una decomposizione di $A$ nella differenza di due matrici $M$ e $N$. 

$$
A = M-N
$$

scegliendo $M$ come matrice del metodo in modo che la soluzione del sistema si possa ottenere a basso costo. Da cui

$$
Ax =(M-N)x=b \Rightarrow b=Mx-Nx
\Rightarrow 
Mx=Nx+b\\ \text{da cui}\\ \qquad 
\begin{matrix} 
Mx^{(k+1)} =Nx^{(k)}+b\\
p=Nx^{(k)}+b

\end{matrix}
$$

La nuova iterata $x^{(k+1)}$ è la soluzione del sistema $Mv=p$ dove $p=Nx^{(k)} +b$ è il termine noto che dipende dai dati $(N,b)$ e dall’iterato corrente $x^{(k)}$.

$$
A=\begin{pmatrix}
\red{a_{11}} & \green{a_{12}} & \green{a_{13}} & \green{a_{14}} & \ldots & \ldots & \green{a_{1n}} \\

\blue{a_{21}} & \red{a_{22}} & \green{a_{23}} & \green{a_{24}} & \ldots & \ldots & \green{a_{2n}} \\

\blue{a_{31}} & \blue{a_{32}} & \red{a_{33}} & \green{a_{34}} & \ldots & \ldots & \green{a_{3n}} \\

\ldots & \ldots && \ddots& \ldots & \ldots & \\

\blue{a_{i1}} & \ldots && \blue{a_{ii-1}} & \red{a_{ii}}   & \green{a_{ii+1}}   & \green{a_{in}} \\

\ldots & \ldots && \ldots& \ldots & \ddots & \\

\blue{a_{n-11}} & \ldots & \ldots &\ldots & \blue{a_{n-1n-2}} & \red{a_{n-1n-1}}   & \green{a_{n-1n}} \\
\blue{a_{n1}} &\ldots & \ldots & \ldots &\ldots & \blue{a_{nn-1}} & \red{a_{nn}}   \\
\end{pmatrix}
$$

$$
E=\begin{cases} e_{ij} = -\blue{a{ij}} & i > j \\ 0 & i \leq j\end{cases}

\quad F = \begin{cases} f_{ij} = -\green{a{ij}} & i < j \\ 0 & i \geq j\end{cases}

\quad D = \begin{cases} d_{ij} = \red{a{ij}} \\ d_{ij} =0 & i \neq j\end{cases} \\
A = D - E - F

$$

## Metodo di Jacobi e di Gauss-Seidel

Da questa decomposizione ricaviamo due metodi iterativi 

---

[Metodo di Jacobi](Metodo%20di%20Jacobi%20a41e717489224dbabe581cd218bdb4c7.md)

**Dove $M = D, N = E + F$.**

Oppure partendo da $A = M-N$ per definizione e $M=D$  si può ricavare $N = M-A=D-(D-E-F)=E+F$

---

[Metodo di Gauss-Seidel](Metodo%20di%20Gauss-Seidel%20e35b5b00247c45d8a04dabca7d250c6b.md)

**Dove $M=D-E,N=F$**

Oppure partendo da $A= M-N$  per definizione e $M=D-E$ si può ricavare $N=M-A=D-E-(D-E-F)=F$.

---

## Teorema

Se $A$ è strettamente diagonale dominante per righe, allora entrambi i metodi di
Jacobi e di Gauss-Seidel convergono.

## Osservazioni

- Una singola iterazione costa, in generale $n^2$ operazioni
- Se la matrice $A$ è sparsa, la complessità è proporzionale al numero di elementi non nulli.
- La complessità dell’intero metodo dipende dalla tolleranza e dalla velocità con cui le iterate si avvicinano alla soluzione.
- Quanto più è piccolo il raggio spettrale della matrice del metodo, tanto più veloce la successione converge
- Si può dire che $\rho(\mathcal G ) \leq \rho(\mathcal J ) \Rightarrow$ il metodo di Gauss-Seidel è non meno veloce di Jacobi.