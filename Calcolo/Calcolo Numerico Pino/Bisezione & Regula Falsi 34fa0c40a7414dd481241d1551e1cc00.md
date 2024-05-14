# Bisezione & Regula Falsi

# Metodo di bisezione

**Dati**

Intervallo di ricerca $[a, b]$

**Ipotesi**

Funzione continua con $f(a) \cdot f(b) \lt 0$

**Descrizione**

Si applica ripetutamente il teorema del valor medio, generando una successione di intervalli di ampiezza decrescente i cui punti medi convergono ad una radice di $f$

## Passo 1

Chiamiamo:

$a_1 := a$

$b_1 := b$

1. Calcoliamo il punto medio $c_1 = \frac{a_1+b_1}{2}$ dell’intervallo $[a_1, b_1]$
2. Definiamo il nuovo intervallo $[a_2, b_2]$ come quell’intervallo tra $[a_1, c_1]$ e $[c_1, b_1]$ che rispetta le ipotesi del teorema del valor medio:
    
    $$
    [a_2, b_2] = \begin{cases}
    [a_1, c_1] & \text{se } f(c_1) \cdot f(a_1) \lt 0 \\
    [c_1, b_1] & \text{se } f(c_1) \cdot f(b_1) \lt 0 \\
    \end{cases}
    $$
    
    ![Untitled](Untitled%206.png)
    

## Passo 2

1. Calcoliamo il punto medio $c_2$ dell’intervallo $[a_2, b_2]$
2. Definiamo il nuovo intervallo $[a_3, b_3]$ come quell’intervallo tra $[a_2, c_2]$ e $[c_2, b_2]$ che rispetta le ipotesi del teorema del valor medio

$$
[a_3, b_3] = \begin{cases}
[a_2, c_2] & \text{se } f(c_2) \cdot f(a_2) \lt 0 \\
[c_2, b_2] & \text{se } f(c_2) \cdot f(b_2) \lt 0 \\
\end{cases}
$$

![Untitled](Untitled%207.png)

## Passo k

1. Calcoliamo il punto medio $c_k$ dell’intervallo $[a_k, b_k]$
2. Definiamo il nuovo intervallo $[a_{k+1}, b_{k+1}]$ come quell’intervallo tra $[a_k, c_k]$ e $[c_k, b_k]$ che rispetta le ipotesi del teorema del valor medio:

$$
[a_{k+1}, b_{k+1}] = \begin{cases}
[a_k, c_k] & \text{se } f(c_k) \cdot f(a_k) \lt 0 \\
[c_k, b_k] & \text{se } f(c_k) \cdot f(b_k) \lt 0 \\
\end{cases}
$$

## Proprietà degli intervalli di ricerca

Per ogni $k$, le ipotesi del teorema del valor medio sono verificate in $[a_k, b_k]$, quindi esiste almeno una radice di $f$ in $[a_k,b_k]$. 

L’ampiezza del $k$-esimo intervallo di ricerca è data da:

$$
b_k-a_k = \frac{b-a}{2^{k-1}}
$$

### 📜Dimostrazione

$b_{k+1} - a_{k+1} = \frac{b_k - a_k}{2} \; \forall k \gt 0$

posso scrivere la stessa cosa per $b_k$  e $a_k$ → $b_{k} - a_{k} = \frac{b_{k-1} - a_{k-1}}{2} \; \forall k \gt 0$

Se la sostituisco alla prima ottengo:

$$
b_{k+1} - a_{k+1} = \frac{b_{k-1} - a_{k-1}}{2^2} \; \forall k \gt 0
$$

continuando fino ad $a_1$ e $b_1$ ottengo:

$$
b_{k+1}-a_{k+1} = \frac{b_1-a_1}{2^k}
$$

Quindi al passo $k$ avrò:

$$
b_k-a_k = \frac{b - a}{2^{k-1}}
$$

## Teorema di convergenza del metodo di bisezione

a successione dei punti medi $\{c_k\}_{k \in \mathbb N}$ generata dal metodo di bisezione converge ad una radice di $f$ nell’intervallo $[a,b]$ e soddisfa la disuguaglianza:

$$
|c_k -x_*| \le \frac{b-a}{2^k}
$$

---

La disuguaglianza è valida perché, dato:

$$
b_k - a_k = \frac{b_1 - a_1}{2^{k-1}}
$$

prendo il punto medio $c_k$ e so che $|c_k - x_*|$ (distanza tra $c_k$ e $x_*$) è di sicuro più piccola della distanza tra il punto medio $c_k$ e un estremo ($a$ o $b$).

più iterazioni si fanno, più il $k$ diventa grande, più il denominatore aumenta, quindi la distanza tra il punto medio $c_k$ e $x_*$ diminuisce.

$|x_k - x_*| = \mathcal O (\frac{1}{2^k})$

Fissata inoltre una tolleranza $\tau$ posso sapere a priori il numero di iterazioni sufficienti per rispettare una radice di $f$ entro la tolleranza $\tau$

$$
|c_k - x_*| \leq \frac{b -a}{2^k} \leq \tau \rightarrow \frac{b -a}{\tau} \leq \bcancel \tau \frac{2^k}{\bcancel \tau}
$$

da cui vogliamo “*tirare fuori*” $k$.

Siccome $\log_2 ()$ è una funzione crescente, posso applicarla a sinistra e a destra, quindi ottengo:

$$
\log_2 \bigg(\frac{b-a}{\tau} \bigg) \lt k
$$

## Formula stabile per il calcolo del punto medio

Tipicamente il punto medio si calcola facendo

$$
c = \frac{a -b}{2}
$$

tuttavia essa può portare a grandi errori di approssimazione. Quindi siccome noi lavoriamo in aritmetica finita risulta più comodo utilizzare la formula:

$$
c = a+ \frac{b-a}{2}
$$

## Ordine di convergenza del metodo di bisezione

Assumendo che valga l’approssimazione $|c_k - x_*| \simeq \frac{b-a}{2^k}$, si può mostrare che il metodo di bisezione ha [convergenza lineare](Equazioni%20non%20lineari%20aed016b2420e4a388c17d51ca625d236.md) (sostituendo $c_k$ ad $x_k$):

$$
\lim_{x \rightarrow \infty} \frac{|x_{k+1} - x_*|}{|x_k - x_*|} \simeq \lim_{k \rightarrow \infty } \frac{\frac{b-a}{2^{k+1}}}{\frac{b-a}{2^k}} = \frac 1 2
$$

## Vantaggi & Svantaggi

| PRO | CONTRO |
| --- | --- |
| solamente continuità della funzione | converge lentamente ad un una soluzione |
| bassa complessità computazionale
 | non si può estendere al caso di equazioni nonlineari  |

## Pseudocodice

Si assume di avere a disposizione un metodo per calcolare il valore della funzione $f$

<aside>
💻 **PSEUDOCODICE
INPUT: $a, b, f, \tau$
$\quad N \leftarrow$ parte intera( $log_2((b-a)/\tau) + 1$**  *questo perchè vogliamo eseguire più iterazioni di quelle necessarie
$\quad fa \leftarrow f(a)$
$\quad fb \leftarrow f(b)$
$\quad$* **for $k=1,2,\ldots,N$
$\qquad \vert \space c \leftarrow a+(b-a)/2$** *punto medio calcolato con la seconda opzione*
**$\qquad \vert \space fc \leftarrow f(c)$
$\qquad \vert \space$ if $fc=0$
$\qquad \vert \space \quad$ return
$\qquad \vert \space$if $fc \cdot fb < 0$**  *valutiamo il prodotto della funzione calcolata in c e b*
**$\qquad \vert \space \quad$$a \leftarrow c$
$\qquad \vert \space \quad fa \leftarrow fc$
$\qquad \vert \space$ else** *f(c) non è 0, quindi l’unica alternativa è che f(c)*f(b)>0*
**$\qquad \vert \space \quad b \leftarrow c \\

\qquad \vert \space \quad fb \leftarrow fc$$\\ \qquad \lfloor \space$ endif**

</aside>

## Costo computazionale

Si misura in numero di valutazioni di funzione per iterazione, ossia quante volte, nella singola iterazione di un metodo, viene calcolata una funzione nonlineare.

La complessità del metodo di bisezione corrisponderà a una valutazione di funzione per iterazione. 

# Metodo di regula falsi

E’ una variante del metodo di bisezione, quindi valgono le ipotesi del teorema del valor medio, però l’unica differenza è che si sceglie $c_k$ come punto di intersezione tra l’asse delle ascisse e la retta che passa per i punti $f(a)$ ed $f(b)$ da cui si può ottenere la formula:

$$
c_k = b_k - \frac{f(b_k)}{\frac{f(b_k) - f(a_k)}{b_k - a_k}}
$$

![Untitled](Untitled%208.png)

Siccome il punto $c_k$ viene trovato in questo modo, non è detto che ad ogni passo si escluda una metà della funzione.

### 📜Dimostrazione

Come si ottiene la formula:

Si hanno i punti $(a, f(a))$ e $(b, f(b))$. 
In generale una retta ha equazione $y = mx + q$ 

Quindi per trovare la retta si fa il seguente sistema:

$$
\begin{cases}
f(a) = ma + q\\
f(b) = mb + q
\end{cases}
\Leftrightarrow
f(a) - ma = f(b) -mb \\
f(a) - f(b) = ma -mb = m(a-b)
$$

Da cui (per il punto $a$):

$$
m = \frac{f(a) - f(b)}{a - b} \quad 
q = f(a)-\frac{f(a)- f(b)}{a -b}a
$$

Quindi:

$$
y = \frac{f(a) - f(b)}{ a - b} x + f(a)-\frac{f(a)- f(b)}{a -b}a = \\ = \frac{f(a)-f(b)}{a - b}(x-a)+f(a)
$$

Poniamo $y = 0$

$$
\frac{f(a) - f(b)}{a - b} (x - a) = -f(a)
$$

A questo punto moltiplichiamo da entrambe le parti per $\frac 1 {\frac{f(a) - f(b)}{a - b}}$ ottenendo quindi:

$$
x = a - \frac{f(a)}{\frac{f(a) - f(b)}{a - b}}
$$