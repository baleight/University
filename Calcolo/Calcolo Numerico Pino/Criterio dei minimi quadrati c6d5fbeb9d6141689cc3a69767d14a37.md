# Criterio dei minimi quadrati

# Perché a volte non conviene interpolare?

In alcune situazioni (spesso in esperimenti fisici) si vuole definire un modello matematico che descriva un fenomeno. Per esempio quando il modello che descrive il fenomeno è di tipo lineare si ha che non conviene fare uso di una funzione (non lineare) che interpoli tutti i punti.

In altre parole si vuole trovare la retta migliore che descriva il fenomeno.

- Esempio
    
    Un esempio si ha quando si cerca di individuare uno o più parametri della formula che lega due quantità, a partire da un numero finito di misurazioni effettuate che contengono una certa quantità di errore. 
    
    La legge di Ohm $V=iR$ che descrive il fenomeno è lineare, ma le misurazioni effettuate contengono una certa di quantità di errore. 
    
    ![Untitled](Untitled%2019.png)
    
    Interpolare i dati con errore non fornisce un modello significativo del fenomeno osservato. 
    

Per capire qual è la retta migliore ci si basa sul **criterio dei minimi quadrati** e la retta risultante prende il nome di **retta di regressione**.

## Criterio dei minimi quadrati: retta di regressione

Dati $(x_i, y_i), \; i =1, \dots, m$ si determinano i parametri del modello scelto $y = a_0+a_1x$ che minimizzano la funzione 

$$
Q(a_0, a_1)=\sum_{i=1}^{m}(a_0+a_1x_i-y_i)^2
$$

![Untitled](Untitled%2020.png)

> Questo criterio ci permette di minimizzare le distanze tra i punti e la retta.
> 
> 
> La nostra retta ha equazione $y = a_0 + a_1 x$
> 
> Abbiamo $2$ punti:
> 
> - punto con coordinate $(x_i, y_i)$
> - punto sulla retta con coordinate $(x_i, a_0+a_1x_i)$
> 
> Definiamo $\ell_i$ come la lunghezza del segmento avente estremi i due punti
> 
> $$
> \ell_i = \vert a_0+a_1x_i-y_i \vert
> $$
> 
> A questo punto definiamo $Q$ come
> 
> $$
> Q = \sum_{i=1}^m \ell^2 = \sum_{i=1}^m (a_0+a_1x_i-y_i)^2 
> $$
> 
> che non è altro che il valore che vogliamo minimizzare.
> 
- Il criterio dei minimi quadrati porta ad inividuare i due parametri di una retta la cui distanza cumulativa è minima.
- Vogliamo riscrivere $Q$ in forma matriciale in modo tale da poter risolvere il sistema e trovare la soluzione del problema.

Lo stesso approccio si può estendere a modelli più generali 

- Dati $(x_i,y_i), i = 1, \ldots, m$
- Ipotesi: si assume che i dati corrispondano ad un modello che dipende da $n$ parametri
    
    $$
    f(a_0, \ldots, a_{n-1}; x)
    
    $$
    
- Obiettivo: si vogliono determinare i parametri del modello che minimizzano la funzione
    
    $$
    Q(a_0, \ldots,a_{n-1})=\sum_{i=1}^m(f(a_0,\ldots,a_{n-1};x_i)-y_i)^2
    $$
    
    Esempio: nel caso di un modello non lineare come può essere una parabola
    
    $$
    Q(a_0, a_1, a_2)= \sum^m_{i=1}(a_0 + a_1x+a_2x^2-y_i)^2
    $$
    

## Q in forma matriciale

È necessario introdurre $2$ vettori $q$ e $y$ definiti nel seguente modo

$$
q(a_0, a_1) = \begin{pmatrix}
a_0+a_1x_1 \\
a_0+a_1x_2 \\
\vdots \\
a_0+a_1x_m \\
\end{pmatrix}
\in \mathbb R^m
$$

Valutazione della retta di regressione nei vari punti

$$
y = \begin{pmatrix}
y_1 \\
y_2 \\
\vdots \\
y_m
\end{pmatrix}
$$

Ordinate degli altri estremi dei segmenti

Abbiamo che $Q$ è definito come

$$
Q = (a_0+ a_1x_1-y_1)^2 + (a_0+ a_1x_2-y_2)^2 + \ldots + (a_0+ a_1x_m-y_m)^2
$$

quindi utilizzando o vettori definiti sopra possiamo riscriverlo come

$$
Q = (q_1-y_1)^2 + (q_2-y_2)^2 + \ldots + (q_m-y_m)^2
$$

Definiamo un ulteriore vettore $u$ nel seguente modo

$$
u := \begin{pmatrix}
q_1-y_1 \\
q_2 - y_2 \\
\vdots \\
q_m -y_m
\end{pmatrix}
= q - y
$$

quindi, dalla definizione di [norma $2$,](Norme%20vettoriali%20e%20matriciali%20c2013a0b8b284b44adb38a6b6d122217.md) riscriviamo $Q$

$$
Q = \Vert u \Vert^2_2 = \Vert q - y\Vert^2_2
$$

- Cat ha scritto:
    
    La norma di un vettore equivale alla radice della somma dei suoi elementi ognuno al quadrato.
    

Infine riscriviamo $q$, in modo da evidenziare i punti della retta di regressione, come

$$
q = \begin{pmatrix}
a_0+a_1x_1 \\
a_0 + a_1 x_2 \\
\vdots \\
a_0 + a_1 x_m
\end{pmatrix}
= \begin{pmatrix}
1 & x_1 \\
1 & x_2 \\
\vdots \\
1 & x_m
\end{pmatrix}
\begin{pmatrix}
a_0 \\
a_1
\end{pmatrix}
= A \cdot \alpha
$$

Perciò abbiamo

$$
q=(a_0, a_1)= A\alpha \Rightarrow Q(a_0,a_1) = \Vert A \alpha - y \Vert ^2
$$

## Risoluzione

Vogliamo capire come determinare $\alpha$.

$A$ è una matrice rettangolare → $A \in \mathbb R^{m \times n}$

Dati $(x_i,y_i), i =1,\ldots,m$ occorre risolver eil problema

$$
\min_{\alpha \in \mathbb R ^n} \lVert A\alpha - y\lVert^2
$$

- caso non degenere → numero dei dati $(m)$ maggiore del grado del polinomio $(n)$, tutte le colonne sono linearmente indipendenti
- caso generale → numero dei dati $(m)$ maggiore del grado del polinomio $(n)$, alcune colonne sono linearmente indipendenti

Si può affrontare meglio fattorizzando la matrice $A$ ricordando che non è quadrata

## Caso non degenere

Se $A \in \mathbb R ^{m \times n}$ con $m \le n$ ha rango $n$, allora la soluzione del problema 

$$
\min_{\alpha \in \mathbb R^n} \Vert A \alpha - y \Vert^2
$$

è unica.

---

### 📜Dimostrazione

> **NB:** $Q$ utilizzata nella dimostrazione non è la funzione obiettivo $Q(a_0, a_1)$
> 

**Proprietà 1**

HP. $Q$ ortogonale

TH. $\Vert Qx \Vert^2 = \Vert x \Vert ^2$

DIM:

chiamiamo $u = Qx$ allora possiamo riscrivere $\Vert Qx \Vert^2 = \Vert u \Vert ^2 = u^T u$

sostituiamo $u$ e otteniamo $u^Tu = (Qx)^T (Qx) = x^T Q^TQx$

per l’ipotesi si ha 

**Proprietà 2**

HP. $z = \begin{pmatrix}z_1 \\ z_2 \end{pmatrix} \in \mathbb R^m \; z_1 \in \mathbb R^n, z_2 \in \mathbb R^{m-n}$

TH. $\Vert z \Vert ^2 = \Vert z_1 \Vert^2 + \Vert z_2 \Vert^2$

DIM:

$z$ è quindi un vettore di vettori $(z_1, z_2)$

$$
z = \begin{pmatrix}
z_1 \\ z_2 \\ \vdots \\ z_n \\z_{n+1} \\ \vdots \\z_{m-1} \\z_m
\end{pmatrix} = 
\begin{pmatrix}
\begin{pmatrix}
z1 \\ \vdots \\ z_n
\end{pmatrix}\\
\begin{pmatrix}
z_{n+1} \\ \vdots \\ z_m
\end{pmatrix}
\end{pmatrix}
$$

Quindi dalla definizione di norma si ottiene in modo molto semplice la tesi

**Proprietà 3**

Si usa la decomposizione $QR$ sulla matrice $A$ che è rettangolare.

$Q$ è ortogonale di dimensione $m \times m$, $R$ è triangolare superiore di dimensione $n \times n$ allora:

$$
A = Q {\begin{pmatrix}
\underset{n\times n}{R} \\ \underset{m-n \times n}{0}
\end{pmatrix}}
$$

---

Prendiamo $\Vert A \alpha - y \Vert ^2$ e applichiamo la prima proprietà con $Q^T$

> **Osservazione**
> 
> 
> Se $Q$ è ortogonale, allora anche $Q^T$ è ortogonale
> 

$$
\Vert A \alpha - y \Vert ^2 = \Vert Q^T (A\alpha - y) \Vert^2 = \Vert Q^T A\alpha - Q^T y \Vert
$$

dove quindi $A \alpha - y  = x$

Chiamo il vettore $Q^Ty = \overline y$

Applichiamo la proprietà 3 al primo membro

$$
\Vert \begin{pmatrix}R \\ 0 \end{pmatrix} \alpha - \overline y \Vert^2
$$

La matrice è di dimensioni $m \times n$ e solo $n$ righe sono diverse da $0$ quindi il loro prodotto con $\alpha$, vettore di dimensione $n \times 1$, sarà diverso da $0$. Quindi dal prodotto otteniamo un vettore colonna di dimensione $m \times 1$ del tipo:

$$
\begin{pmatrix} R \\ 0 \end{pmatrix}\alpha  = \begin{pmatrix}
z_1 \\ \vdots \\ z_n \\ 0 \\ \vdots \\ 0
\end{pmatrix}
$$

$\overline y$ è un vettore $m \times 1$ quindi ho:

$$
\Vert \begin{pmatrix}R \\ 0 \end{pmatrix} \alpha - \begin{pmatrix}\overline y_1 \\ \overline y_2 \end{pmatrix} \Vert^2
$$

Applicco la proprietà 2, perciò ottengo:

$$
\Vert \begin{pmatrix}R \\ 0 \end{pmatrix} \alpha - \begin{pmatrix}\overline y_1 \\ \overline y_2 \end{pmatrix} \Vert^2 = \Vert \begin{pmatrix}R \\ 0 \end{pmatrix} \alpha - \overline y_1 \Vert^2 + \Vert \overline y_2 \Vert ^2
$$

In conclusione abbiamo:

$$
\Vert A \alpha - y \Vert = \Vert \begin{pmatrix}R \\ 0 \end{pmatrix} \alpha - \overline y_1 \Vert^2 + \Vert \overline y_2 \Vert ^2
$$

$$
\min_{\alpha \in \mathbb R^n} \Vert A \alpha - y \Vert = \min_{\alpha \in \mathbb R^n} (\Vert \begin{pmatrix}R \\ 0 \end{pmatrix} \alpha - \overline y_1 \Vert^2 + \Vert \overline y_2 \Vert ^2)
$$

$\Vert R \alpha - \overline y_1 \Vert^2 \ge 0$, quindi il minimo si ha quando $\Vert R \alpha - \overline y_1 \Vert = 0$

Porto $\overline y_1$ a destra e ottengo $R \alpha = \overline y_1$, quindi $\alpha$  risolve il sistema.

In base 2 posso avere al massimo 2 vettori linearmente indipendenti

## Caso degenere

Se le colonne di $A$ non sono linearmente indipendenti ossia se il rango di $A$ è $k$ con $k<n$ allora il problema dei minimi quadrati ha infinite soluzioni, che dipendono da $n-k$ parametri liberi. 

Nel sottospazio delle soluzioni, si individua quella che ha la norma euclidea più piccola, detta *soluzione di norma minima.*