# Norme vettoriali e matriciali

Il valore assoluto determina la grandezza di un numero, se volessimo fare la stessa cosa con un vettore di numeri bisogna definire uno strumento in grado di restituire un valore che, seguendo qualche criterio, ci dia un’idea sulla situazione complessiva degli elementi del vettore. Se applicato a due vettori che vogliamo confrontare, sempre seguendo un criterio, lo strumento indicherà qual è il maggiore. 

## Norma vettoriale

La funzione $||\cdot|| : \mathbb R^{n+m} \rightarrow \mathbb R$ è una **norma vettoriale** se soddisfa le seguenti proprietà:

- $||x|| \ge 0, \forall x \in \mathbb R^{n}, e ||x|| = 0 \Leftrightarrow$ $x = 0$
- $||\lambda x || = |\lambda | ||x || , \forall x \in \mathbb R^{n} , \lambda \in \mathbb R$
- Proprietà triangolare: $||x+y|| \le ||x|| + ||y||, \forall x,y \in \mathbb R^{n}$

**Norma infinito**

$$
||x|| _{\infty} =\max_{i=1,...,n}  |x_{i}|
$$

**Norma 1**

$$
||x|| _1 = \sum^{n}_{i=1} |x_{i}|
$$

**Norma 2 (o Euclidea)**

$$
||x||_2 = \sqrt{\sum^{n}_{i=1}x^2}
$$

### Osservazioni

- Una norma vettoriale associa ad ogni vettore un numero che esprime la sua misura e viene calcolata tenendo conto di tutte le sue componenti
- E’ un’informazione utile per poter confrontare tra loro i vettori.
- Per la norma Euclida vale la seguente uguaglianza

$$
||x||_2^2=x_1^2+x_2^2+\dots + x_n^2=x^Tx
$$

- Le norme vettoriali sono equivalenti, nel senso che prese due qualsiasi norme $||.||_*, ||.||_\bullet$ con $*, \bullet \in \{\infty, 1, 2\}$  esistono due costanti positive $m,M$ tali che

$$
m||x||_*\leq ||x||_\bullet \leq M||x||_*, \forall x \in \mathbb{R}^n
$$

## Norma matriciale

La funzione $||\cdot|| : \mathbb R^{n+m} \rightarrow \mathbb R$ è una **norma matriciale** se soddisfa le seguenti proprietà:

- $||A|| \ge 0, \forall A \in \mathbb R^{nxm}, e ||A|| = 0 \Leftrightarrow$ $A = 0$
- $||\lambda A || = |\lambda | || A || , \forall A \in \mathbb R^{nxm} , \lambda \in \mathbb R$
- Proprietà triangolare: $||A+B|| \le ||A|| + ||B||, \forall A,B \in \mathbb R^{n+m}$

**Norma infinito**

$$
||A|| _{\infty} =\max_{i=1,...,n}  \sum^{n}_{j=1} |a_{ij}|
$$

**Norma 1**

$$
||A|| _1 = \max_{j=1,...,n}  \sum^{n}_{i=1} |a_{ij}|
$$

**Norma 2 (o Euclidea)**

$$
||A||_2 = \sqrt{\rho (A^T A)}
$$

### Norme matriciali indotte

A partire da una norma vettoriale $||.||$ è possibile definire formalmente una norma matriciale indotta nel modo seguente

$$
||A||= \sup_{x\in \mathbb{R}^n, x \neq 0} \frac{||Ax||}{||x||}
$$

Si può dimostrare che

**Norma infinito**

$$
||A|| _{\infty} = \max_{i=1,...,n}  \sum^{n}_{j=1} |a_{ij}|
$$

**Norma 1**

$$
||A|| _1 = \max_{j=1,...,n}  \sum^{n}_{i=1} |a_{ij}|
$$

**Norma 2 (o Euclidea)**

$$
||A||_2 = \sqrt{\rho (A^T A)}
$$

### Proprietà delle norme matriciali

Sia $\bullet\in\{\infty, 1, 2\}$

**Proprietà submoltiplicativa**

Siano $A, B \in \mathbb R^{n \times n}:$

$$
\lVert AB \lVert \le \lVert A \lVert \cdot \lVert B \lVert
$$

**Compatibilità con le norme vettoriali**

Siano $A \in \mathbb{R}^{n \times n }, x \in \mathbb{R}^n$

$$
||Ax||_\bullet \leq ||A||_\bullet||x||_\bullet
$$

## Significato delle norme

- Le norme esprimono l’idea di una misura
- Hanno lo stesso ruolo che ha il valore assoluto per gli scalari
- Se $x,y \in \mathbb{R}^n$ il numero $||x-y||$ esprime il concetto della distanza tra $x$ e $y$
- Per valutare l’errore relativo (la distanza relativa) tra due vettori $x$ e $y$ si utilizzano le norme:

$$
\frac{\Vert x - y \Vert}{\lVert  x \lVert}
$$

- Le stesse condizioni valgono anche per le matrici