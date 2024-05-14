# Metodo di Gauss-Seidel

- $M = D- E$
- $N = F$

Quindi andiamo a sostituire $M$ ed $N$ a $Mx^{(k+1)} = Nx^{(k)} +b$ e otteniamo:

$$
(D - E)x^{(k+1)} = Fx^{(k)} + b
$$

La componente i-esima della nuova iterata $x^{(k+1)}$ si calcola in funzione sia dell’iterata precedente $x^{(k)}$ che delle prime $i-1$ componenti della nuova iterata stessa, già calcolate. 

L’ordine con cui si calcolano le componenti della nuova iterata successiva è sequenziale: *metodo degli spostamenti successivi.* 

**COMPONENTE 1**

Calcolo $p = F x^{(0)} + b$

Risolvo $(D - E) x^{(1)} = p$

**COMPONENTE $i$**

$$
x_i^{(k+1)} = \Bigg (
b_i 
- \sum^{i-1}_{j=1} a_{ij} \, x_{j}^{(k+1)} 
- \sum^{n}_{j=i+1} a_{ij}x_{j}^{(k)} \Bigg ) / a_{ii}, \space i = 1, \dots , n
$$

**FORMALMENTE**

$$
x^{(k+1)} = (D-E)^{-1} F x^{(k)}  + (D-E)^{-1} b \Rightarrow x^{(k+1)} = \mathcal G  x^{(k)} + c 
$$

Con:

- $\mathcal G = (D - E)^{-1} F$
- $c = (D - E)^{-1} b$