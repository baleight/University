# Equazioni non lineari

## Definizione

Sia $f$ una funzione definita nell’intervallo $[a,b]$ a valori reali. Il punto $x_* \in [a,b]$ si dice **radice** (o **zero**) della funzione $f$ se

$$
f(x_*) = 0
$$

- *esempio*
    
    $$
    \begin{cases}
    y = x^2 +2x -5 \\
    y = 0
    \end{cases}
    $$
    
    Le intersezioni della parabola (1^ equazione) con l’asse delle $x$ (2^ equazione) sono le soluzioni del sistema.
    

## Teorema del valore medio

Sia $f : [a,b] \rightarrow \mathbb R$ una **funzione continua** dove $[a,b]$ è un **intervallo chiuso e limitato**  tale che

$$
f(a) \cdot f(b) \lt 0
$$

Ossia **cambia segno agli estremi dell’intervallo**, allora esiste almeno una radice di $f$ nell’intervallo $[a,b]$, ossia esiste (almeno) un punto $x_* \in [a,b]$  tale che

$$
f(x_*) = 0
$$

NB: le ipotesi (continuità, estremi con segno diverso, intervallo chiuso) non garantiscono l’unicità della soluzione. Una conduzione sufficiente per avere l’unicità è la stretta monotonia della funzione. 

## Condizionamento

Sia $x^*$  una radice di $f$ ossia una soluzione $\rightarrow f(x^*) = 0$.

Il problema perturbato si ottiene fissando $\delta \gt 0$, dopodiché si studia $f(x) = 0 + \delta = \delta$

Chiamiamo $\tilde x$ il valore per cui $f(\tilde x) = \delta$

- Assumiamo per semplicità che la funzione $f$ di cui vogliamo calcolare le radici sia **derivabile**, per definizione si ha
    
    $$
    f'(x^*) = \lim_{x\rightarrow x_*} \frac{ f(x) - f(x_*) }{ x - x_* }
    $$
    
    da cui in un intorno di $x_*$ si ricava l’approssimazione (ricc scrive Se $| x - x_* | \lt \tau$ )
    
    $$
    \frac{ f(x) - f(x_*) }{ x - x_* } \simeq f'(x^*) 
    $$
    
    considerando quindi un intorno è possibile approssimare la derivata prima con il rapporto incrementale.
    
- Sostituendo $x$ con $\tilde x$ otteniamo:

$$
\frac{| f(\tilde x) - f(x_*) |}{| \tilde x - x_*|} \simeq f'(x_*) \Leftrightarrow | f(\tilde x) - f(x_*) | \simeq f'(x_*) \cdot | \tilde x - x_*|
$$

     Quindi portando la derivata a sinistra si ottiene:

$$
\frac{| f(\tilde x) - f(x_*) |}{f'(x_*)} \simeq |\tilde x - x_*|
$$

Dove:

- $f(x_*) = 0$
- $f(\tilde x ) = \delta$

quindi:

$$
|\tilde x - x_*| = \frac{\delta}{f'(x_*)}
$$

la grandezza del denominatore è strettamente correlata al condizionamento del problema. 

- Denominatore grande $\rightarrow$ intervallo piccolo $\rightarrow$ problema bencondizionato
- Denominatore piccolo ($f'(x_*) \simeq 0$) $\rightarrow$ intervallo grande  $\rightarrow$ problema malcondizionato

Si sono aggiunte due ipotesi alle tre del teorema del valore medio: 

- $f$ deve essere differenziabile (derivabile)
- $f'(x_*) \ne 0$ → $x_*$ non è punto di max/min

![Untitled](Untitled%203.png)

Il mal condizionamento si ha quando il grafico di $f$ è molto schiacciato sull’asse orizzontale. 

## Velocità di convergenza

Sia $\{ x_k \} _{k \in \mathbb N} \sub \mathbb R$ una successione che converge ad un punto $x_* \in \mathbb R$. Si dice che la successione  $\{ x_k \} _{k \in \mathbb N}$ ha ordine di convergenza $p$ se

$$
\lim_{k \rightarrow \infty} \frac{|x_{k+1} - x_*|}{|x_k - x_*|^p} = C
$$

per qualche $p \ge 1, C \in \mathbb R$ 

- Se la successione è generata da un metodo iterativo, si dice che il metodo è di ordine $p$.
- Se una successione (o un metodo iterativo) è di ordine $p$, applicando la definizione di limite, per $k$ grande si ha

$$
|x_{k+1} - x_*| \sim C |x_k - x_*| ^p
$$

- Più $p$ è grande, maggiore sarà la riduzione dell’errore ad un’iterazione rispetto alla precedente.

### Commento

Per essere vero il limite deve valere:

$$
\exist \tilde k : \forall k \gt \tilde k \quad |x_{k+1} - x_*| \simeq C |x_k - x_*| ^p
$$

Significa che l’errore commesso al passo $k+1$ è circa uguale a $C |x_k - x_*| ^p$

Quindi l’errore al passo successivo è $p$ volte più piccolo di quello al passo attuale

---

### Casi particolari di convergenza:

- Convergenza quadratica $p = 2$ (Newton)
    
    $$
    \lim_{k \rightarrow \infty} \frac{|x_{k+1} - x_*|}{|x_k - x_*|^2} = C
    $$
    
- Convergenza lineare $p = 1, C \in (0,1)$ (bisezione, regula falsi)
    
    $$
    \lim_{k \rightarrow \infty} \frac{|x_{k+1} - x_*|}{|x_k - x_*|} = C
    $$
    
- Convergenza superlineare $p = 1, C = 0$
    
    $$
    \lim_{k \rightarrow \infty} \frac{|x_{k+1} - x_*|}{|x_k - x_*|} = 0
    $$
    

GUARDARE SLIDE 301

## Sommario

- Condizioni di esistenza delle soluzioni: Teorema del valor medio
- Unicità della soluzione: stretta monotonia (condizione sufficiente)
- Condizionamento del problema: se $f'(x_*) \simeq 0$ il problema è mal condizionato.
- Metodi numerici (iterativi):
    
    [Bisezione & Regula Falsi](Bisezione%20&%20Regula%20Falsi%2034fa0c40a7414dd481241d1551e1cc00.md)
    
    [Newton & Secanti](Newton%20&%20Secanti%201ea2e09228f64548b8cde7d05b908b3e.md)
    
- Analisi di convergenza dei metodi
- Definizione di complessità computazionale
- Definizione di ordine di convergenza