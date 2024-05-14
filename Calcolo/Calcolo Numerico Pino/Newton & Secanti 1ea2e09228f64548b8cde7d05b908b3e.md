# Newton & Secanti

# Metodo di Newton

Fissato un intervallo di riferimento $[a, b]$, il metodo di Newton si applica a funzioni differenziabili, $f \in C^1 ([a, b])$. Ossia la funzione oltre che essere continua deve avere la derivata continua. 

A partire da un punto iniziale $x_0 \in [a, b]$, l’iterato successivo $x_{k+1}$ viene calcolato come l’intersezione tra l’asse delle ascisse e la retta tangente al grafico di $f$ nel punto $(x_k, f(x_k))$, per ogni $k = 0,1 \dots$

$$
\begin{cases}
y = 0 \\
y = f(x_k)+f'(x_k)(x-x_k)
\end{cases}
\Longrightarrow
x =x_k - \frac{f(x_k)}{f'(x_k)}
$$

- 🔍 Zoom sulla seconda equazione
    
    La seconda equazione rappresenta una reta tangente al punto $(x_k, f(x_k))$. Sapendo che la derivata di una funzione in un punto è il coefficiente angolare della retta tangente alla curva nel punto allora si ha che:
    
    $$
    y= mx+q  \rightarrow y= f'(x_k)x+q 
    $$
    
    Imponendo il passaggio in $(x_k, f(x_k))$ si ha
    
    $$
    f(x_k)= f'(x_k)x_k+q \rightarrow q = f(x_k)- f'(x_k)x_k
    $$
    
    Di conseguenza
    
    $$
    y = mx+q \rightarrow y = f'(x_k)x +f(x_k)- f'(x_k)x_k 
    $$
    
    Eseguendo un raccoglimento
    
    $$
    y = f'(x_k)(x-x_k) +f(x_k)
    $$
    

La formula usata per trovare il punto successivo dal precedente è:

$$
x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}
$$

## 📜Dimostrazione

Calcoliamo $x_0$, prendiamo la tangente in quel punto.

Il punto $x_1$ sarà l’intersezione tra la retta tangente ad $x_0$ e l’asse delle ascisse.

L’equazione della retta sarà quindi:

$$
y = f(x_k)+ f'(x_k)(x - x_k)
$$

siccome $y = 0$ e la nostra incognita è $x = x_{k+1}$

$$
0 = f(x_k) + f'(x_k)(x_{k+1} -x_k)
$$

risolviamo il prodotto e portiamo di là $f(x_k)$

$$
f(x_k) = - f'(x_k) x_{k+1} + f'(x_k)x_k 
$$

isolo il membro con $x_{k+1}$ 

$$
-\frac{\bcancel{f'(x_k)} x_{k+1}}{\bcancel{f'(x_k)}} = - \frac{\bcancel{f'(x_k)}x_k}{\bcancel{f'(x_k)}} + \frac{f(x_k)}{f'(x_k)} \Rightarrow x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}
$$

## Vantaggi & Svantaggi

| PRO | CONTRO |
| --- | --- |
| Converge più velocemente | Costo computazionale è il doppio rispetto a Regula Falsi (si valutano sia la funzione che la sua derivata, non viene valutata quindi una sola funzione ma 2).  |
|  | C’è da fare lo studio di funzione per verificare che la funzione sia derivabile |

## Teorema di convergenza del metodo di Newton

Sia $f \in C^2([a, b])$ ossia derivabile 2 volte con continuità. 

**Se** $f'(x) \ne 0, \, \forall x \in [a,b]$ e vale una delle seguenti condizioni:

1. $f(a) \lt 0, \,f(b) \gt 0, \, f''(x) \le 0, \, \forall x \in [a,b]$  e $f(b) + f'(b)(a-b) \le 0$
2. $f(a) \gt 0, \,f(b) \lt 0, \, f''(x) \le 0, \, \forall x \in [a,b]$  e $f(a) + f'(a)(b-a) \le 0$
3. $f(a) \lt 0, \,f(b) \gt 0, \, f''(x) \ge 0, \, \forall x \in [a,b]$  e $f(a) + f'(a)(b-a) \ge 0$
4. $f(a) \gt 0, \,f(b) \lt 0, \, f''(x) \ge 0, \, \forall x \in [a,b]$  e $f(b) + f'(b)(a-b) \ge 0$

**Allora** si ha che, per ogni scelta del punto iniziale $x_0 \in [a,b]$, le iterate del metodo di Newton appartengono tutte all’intervallo $[a,b]$ e **convergono** all’unica radice $x_*$ di $f$ in $[a,b]$ con velocità quadratica.

La derivata seconda dà informazioni sulla curvatura.

I punti in cui la derivata seconda si annulla si chiamano punti di flesso.

- curve delle condizioni
    
    ![Untitled](Untitled%209.png)
    

## Criteri di arresto

Ad eccezione del metodo di bisezione nei metodi iterativi non posso sapere a priori quanti passi devo fare per arrivare alla soluzione, quindi ci si basa su dei criteri di arresto.

I criteri di arresto sono i medesimi dei metodi iterativi: iterate successive e il residuo.

> **NB**
> 
> 
> Il residuo non è affidabile quando il grafico di $f$ è molto schiacciato sull’asse $x$, infatti di solito è accompagnato dal metodo della distanza tra due iterate successive.
> 

Fissata una tolleranza $\tau$ i metodi per la ricerca degli zeri di funzione si arrestano alla prima iterazione $k$ in cui sono soddisfatte le disuguaglianze.

$$
\frac{|x_{k+1}-x_{k}|}{x_{k+1}} \leq \tau \qquad \underbrace{|f(x_k)|}_{\text{residuo}} \leq \tau 
$$

# Metodo delle secanti

È una variante del metodo di Newton, ed è quello che usa MATLAB.

Nel metodo delle secanti la derivata viene approssimata con un rapporto incrementale:

$$
x_{k+1} = x_k - \frac{f(x_k)}{\frac{f(x_k)-f(x_{k-1})}{x_k - x_{k-1}}}
$$

Il nuovo punto è l’intersezione tra l’asse delle ascisse e la retta per i punti di coordinate $(x_{k-1}, f(x_{k-1}))$  e $(x_k,f(x_k))$.

Problema: 

- $x_k = x_{k+1}$
- Devi scegliere due punti di partenza

---

Commento

La derivata in un punto $\overline x$ è definita come:

$$
f'(\overline x) = \lim_{x \rightarrow \overline x} \frac{f(x) - f(\overline x)}{x- \overline x}
$$

che se scritta con la definizione di limite diventa:

$$
\forall \epsilon \gt 0 \; \exist \, \delta \gt 0 : \text{ se } |x - \overline x| \lt \delta \Rightarrow \frac{|f(x) - f(\overline x)|}{|x - \overline x|} - f'(\overline x) \lt \epsilon
$$

Quindi siccome in Newton si ha che:

$$
x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}
$$

 possiamo riscrivere $f'(x_k)$ con il rapporto incrementale, ed otteniamo:

$$
x_{k+1}=x_k - \frac{f(x_k)}{\frac{f(x_k)-f(x_{k-1})}{x_k - x_{k-1}}}
$$

A differenza del metodo di Newton servono 2 punti iniziali (non uno).

Il metodo delle secanti è **[superlineare](Equazioni%20non%20lineari%20aed016b2420e4a388c17d51ca625d236.md)**