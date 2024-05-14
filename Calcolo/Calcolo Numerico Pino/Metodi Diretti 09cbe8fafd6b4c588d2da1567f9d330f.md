# Metodi Diretti

## Algoritmi

I metodi diretti per la soluzione dei sistemi lineari sono algoritmi in due fasi:  

1. **Fattorizzazione della matrice dei coefficient**i: gli elementi della fattorizzazione sono matrici semplici (triangolari, diagonali, ortogonali).
2. **Soluzione del sistema lineare**: tramite un cambiamento di variabili la soluzione si ottiene risolvendo sistemi semplici associati alle matrici della fattorizzazione.

---

[Metodo di Gauss](Metodo%20di%20Gauss%2010c2fab9840546e7abe45f26b2930251.md)

L’obiettivo è riscrivere la matrice di partenza come prodotto di due matrice triangolari per poi risolvere i sistemi con le sostituzioni in avanti/indietro. 

Tre versioni: 

- [Generica](Metodo%20di%20Gauss%2010c2fab9840546e7abe45f26b2930251.md)
- [Con scambio di righe](Metodo%20di%20Gauss%2010c2fab9840546e7abe45f26b2930251.md) (con pivoting)
- [Matrici simmetriche](Metodo%20di%20Gauss%2010c2fab9840546e7abe45f26b2930251.md) ($LDL^T$)

---

[Metodo di Cholesky](Metodo%20di%20Cholesky%207d3e3e659f1148f39245af673edf47b7.md)

Vengono soddisfatte le ipotesi del metodo di Guass per matrici simmetriche ma, tuttavia, si può ottenere un teorema di fattorizzazione ad hoc. 

---

[Fattorizzazione QR](Fattorizzazione%20QR%201ceebb1b7cc3498e96280c7480fcb6a7.md)

Si riscrive la matrice $A$ come il prodotto di due matrici $QR$ dove $Q$ è ortogonale $R$ triangolare superiore non singolare.

---

## Confronto tra algoritmi di fattorizzazione

| Algoritmo | Ipotesi | Complessità | Stabilità |
| --- | --- | --- | --- |
| Gauss con pivoting parziale | $A$ non singolare | $\mathcal O(\frac{ n^3}{3})$ | debole |
| $LDL^T$ | $A$ simmetrica, minori principali $\neq 0$ | $\mathcal O(\frac{n^3}{6})$ | debole |
| Cholesky | $A$ simmetrica, definita positiva | $\mathcal O(\frac{n^3}{6})$ | forte |
| $QR$ | colonne di $A$ linearmente indipendenti | $\mathcal O(\frac{2 n^3}{3})$ | debole |
- L’algoritmo di soluzione di un sistema triangolare può diventare instabile quando gli elementi della matrice triangolare diventano ‘troppo’ grandi
- La stabilità delle fattorizzazioni si definisce individuando dei limiti superiori
per gli elementi dei fattori
- Si parla di stabilità forte se questi limiti non dipendono dalla dimensione della
matrice, se invece dipendono dalla dimensione della matrice, si ha stabilità
debole.