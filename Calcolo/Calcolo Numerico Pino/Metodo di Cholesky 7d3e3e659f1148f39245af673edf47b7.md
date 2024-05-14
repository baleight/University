# Metodo di Cholesky

## Teorema

Una [matrice simmetrica](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md) $A \in \mathbb R^{n \times n}$ è [definita positiva](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md) se e solo se esiste una matrice triangolare inferiore $\mathcal{L}$ con elementi diagonali positivi tale che

$$
A = \mathcal{L}\mathcal{L}^T
$$

## 📜Dimostrazione

### Dimostrazione 1

**Ipotesi**

$\underset{n \times n}A$ è [simmetrica e definita positiva](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md)

**Tesi**

$\exist \underset{n \times n}{\mathcal L}$ triangolare inferiore ﻿

$\mathcal L$ ha elementi diagonali $\gt 0$

Abbiamo che $A = LDL^T$ e *(dalla definizione di [matrice simmetrica definita positiva](Definizioni%20nelle%20matrici%201aa26b01d660451c901dc7806c7cde8e.md))* che $x^TAx \gt 0$ sostituendo $A$ otteniamo:

$x^TLDL^Tx \gt 0$ → poniamo $y = L^Tx \Rightarrow y \ne 0$

$[y^T =(L^Tx)^T = x^T L](https://www.notion.so/fce0755497ed47de9bed372bf641a291?pvs=21)$ *([vedi proposizione](Operazioni%20matriciali%2086a15ebf49bc409da32db36d1aed062b.md))* che non è altro che la prima parte della disequazione 

Quindi la disuguaglianza diventa:

$$
y^TDy \gt 0 \quad \forall y \in \mathbb R^n \backslash \{0\}
$$

Allora $D$ è definita positiva e diagonale. *Siccome è definita positiva allora tutti i minori principali sono positivi.* Quindi possiamo dire che $d_{11} \gt 0, d_{11}d_{22} \gt 0 \Rightarrow d_{22} \gt 0$ e così via. Quindi $d_{ii} \gt 0$ $\forall i=1,...,n$

La tesi si può ottenere ponendo $\mathcal L = L \Delta$ dove $\Delta$ è la matrice diagonale con elementi $\sqrt{d_{ii}}$ poiché $\Delta \Delta = D$

È verificata anche la tesi per cui $\mathcal L$ ha elementi diagonali $\gt 0$ perché la radice di un numero positivo è sicuramente positiva e diversa da zero perché tutti i minori principali sono positivi diversi da zero.

Di conseguenza è verificata anche $A = L\Delta \underbrace{\Delta L^T}_{\mathcal L^T=(L \Delta)^T =\Delta^T L^T = \Delta L^T}= \mathcal L \mathcal L^T$

### Dimostrazione 2: ipotesi $A = \mathcal{L}\mathcal{L}^T$

**Ipotesi**

 $\exist \underset{n \times n}{\mathcal L}$ triangolare inferiore

$\mathcal L$ ha elementi diagonali $\gt 0$

$A = \mathcal L \mathcal L^T$

**Tesi**

$**\underset{n \times n}A$** è simmetrica e definita positivamente

Verifichiamo che A sia definita positivamente:

Sia $x \in \mathbb R^n$ abbiamo che $x^TAx = x^T \mathcal L \mathcal L^T x = y^T y \ge 0$ che corrisponde alla [norma 2](Norme%20vettoriali%20e%20matriciali%20c2013a0b8b284b44adb38a6b6d122217.md) di $y$ indicata con  $y_1^2 + y_2^2+ y_3^2 + ... + y_n^2 = \lVert y \lVert ^{2}_{2} \ge 0$

Quindi  $\lVert y \lVert^2_2 = 0 \Rightarrow y=L^Tx=0$ , siccome $L^T$ ha diagonale positiva, in particolare è non singolare allora $L^Tx=0 \Longleftrightarrow x = 0$.  

Verifichiamo che A sia simmetrica:

$$
A^T = (\mathcal L \mathcal L^T)^T = \mathcal L \mathcal L^T = A
$$

## Algoritmo

Dalla definizione $A = \mathcal{LL}^T$.

Chiamiamo $\ell_{jk}$ gli elementi di $\mathcal L$.

Dalla dimostrazione del teorema ($\Rightarrow$) sappiamo che $\mathcal L = L \Delta$, quindi ogni elemento sarà determinato nel modo seguente:

$$
\ell_{jj} = \sqrt{d_{jj}} \\
\ell_{jk} = l_{jk} \sqrt{d_{kk}}, \quad \forall k = 1, \dots ,j-1
$$

## Pseudocodice

for $j = 1, \dots , n$

$\ell_{jj} = \sqrt{a_{jj} - \sum_{k=1}^{j-1} {\ell_{jk}}^2}$

for $i = j+1, \dots , n$

$\ell_{ij} =(a_{ij} - \sum_{k=1}^{j-1}\ell_{ik}\,\ell_{jk}) / \ell_{jj}$

Costo computazionale: $\mathcal O(\frac{n^3}{6})$