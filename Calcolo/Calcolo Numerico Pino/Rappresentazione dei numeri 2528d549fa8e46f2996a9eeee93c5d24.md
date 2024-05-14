# Rappresentazione dei numeri

# Rappresentazione matematica

## La notazione posizionale

Un numero può essere rappresentato in molteplici modi a seconda dei criteri di rappresentazione adottati, al contrario la quantità che rappresenta è univocamente determinata. 

La convenzione da noi usata per esprimere un numero è detta **notazione posizionale**, in cui ogni cifra assume un valore diverso a seconda della sua posizione all’interno della stringa usata per rappresentarlo. 

Data una certa base $\beta$  e il corrispondente insieme di simboli $S$ ogni numero naturale $N$ si può rappresentare in modo univoco con una stringa di cifre. 

Se identifichiamo con $c_i$ il valore della cifra allora il valore del numero è 

$$
N = (c_pc_{p-1}\dots c_1 c_0)_{\beta}= c_{p}\beta^{p}+c_{p-1}\beta^{p-1}+\dots+c_{1}\beta^{}+c_0 
$$

**Osservazione**: all’aumentare della base, aumenta il numero di simboli. Al contrario, con una base più grande sono in genere necessarie meno cifre per rappresentare uno stesso valore.

## Rappresentazione di un numero reale

Un numero reale $\alpha$  si può ottenere come somma della sua parte intera più la sua parte frazionaria. La rappresentazione finale sarà composta da:

- segno → vale +1 o -1 a seconda del segno di $\alpha$
- mantissa → $m=\sum_{i=1}^{\infty}(a_iB^{-i})=(0.a_1a_2\dots)_\beta$ è un numero reale $< 1$ chiamato mantissa
- esponente → $\beta^p$ è un intero chiamto parte esponente di  $\alpha$

$$
\alpha = segno(\alpha)(a_1B^{-1}+a_2B^{-2}+a_3B^{-3}+\dots)\beta^p
$$

Le rappresentazioni del tipo segno-mantissa-esponente si dicono in forma scientifica; se $a_i\neq 0$ si parla di forma scientifica normalizzata.

## Algoritmi usati per la rappresentazioni di numeri

### Divisioni successive

Serve per rappresentare un intero positivo 𝛼 ∈ 𝑁 da base 10 ad una diversa base 𝛽. Esegue la divisione intera (quoziente e resto) del numero 𝛼 per 𝛽 finché non si raggiunge quoziente nullo, con il resto che diventa la cifra del numero convertito (le cifre vanno lette dal basso verso l’alto).

### Moltiplicazioni successive

Serve per rappresentare un reale decimale in una base maggiore di uno. Si tratta di determinare le cifre della rappresentazione 𝛼 = (. 𝑎1 … )𝛽 moltiplicando il numero 𝛼 per la base, sottraendo ad ogni passo la parte intera.
Ad esempio il numero $(0.1)_{10}$  diventa 

$$
0.1 ∗ 2 = 0.2, 0.2 ∗ 2 = 0.4, 0.4 ∗ 2 = 0.8, 0.2 ∗ 2 = 1.6, 0.6 ∗ 2 = 1.2, 0.2 ∗
2 = 0.4 … (0.1)_{10} = (0.000\overline{1100})_
2
$$

L’algoritmo deve avere, tra i suoi dati, un numero massimo di cifre da calcolare
(un numero che in base 10 non è periodico, in altre basi potrebbe esserlo!).

### Algoritmo complessivo

Questo algoritmo unisce la divisione successiva alla moltiplicazione, applicandoli contemporaneamente. Si determina per primo il valore assoluto, ricordando il segno, per poi determinarne la parte intera con le DS e quella frazionaria (assoluto-parte intera) e eseguire la conversione con le MS e infine scrivere segno, conversione parte intera, punto
radice e conversione frazionaria.

 Ad esempio per convertire il seguente numero in base 2

$$
\alpha = −(25.375)_{10}
$$

$$
25.375\space-, [|\alpha|] = (25)_{10}=(11001)_2,|\alpha|-[|\alpha|]=(.375)_{10}=(0.11)_2,\alpha=(-11011.011)_2
$$