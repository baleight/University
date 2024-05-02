

Es1

```python
a = """ afwefgewgewgwegwfewf
fqwfqewfqfgqwefqfg
qfgqg
qefqfgqg """
# La funzione map() applica la funzione lambda a ciascun elemento della stringa 'a'
# La funzione lambda prende ogni carattere x e lo trasforma in maiuscolo se non è una vocale
# La funzione filter() filtra solo i caratteri che non sono vocali ('a', 'e', 'i', 'o', 'u') sia minuscole che maiuscole

s = list(map(lambda x: x.upper(), filter(lambda x: x not in['a','e','i','o','u','A','E','I','O','U'], a)))
print(s)
```



Es2

```python
from functools import reduce

# Definizione della stringa
a = "aaabbbbccgewgweg"

# Utilizzo della funzione reduce() per contare le occorrenze di ciascun carattere nella stringa 'a'
# La funzione lambda accetta due argomenti: x e y.
# x è il dizionario parziale in cui stiamo accumulando i conteggi dei caratteri.
# y rappresenta il carattere corrente della stringa 'a'.
# Viene utilizzato il bitwise OR (|) tra x e un nuovo dizionario {y: x.get(y, 0)+1} che conta il numero di volte che il carattere appare.
# x.get(y, 0) restituisce il valore associato alla chiave 'y' nel dizionario 'x', se presente, altrimenti restituisce 0.
# Si incrementa il valore associato alla chiave 'y' di 1 per ogni occorrenza del carattere nella stringa 'a'.
# Il dizionario risultante conterrà i conteggi di ciascun carattere.
result = reduce(lambda x, y: x | {y: x.get(y, 0) + 1}, a, {})

# Stampa del risultato
print(result)

```

Es3

```python
from functools import reduce

# Definizione della stringa
s = "aaaabbcdeeeffgggiiiii"

# Creazione di una lista di 's' ripetuta 10 volte
lista_s = [s for i in range(10)]

# Definizione di una funzione lambda per contare le occorrenze dei caratteri in una stringa
map_f = lambda a: reduce(lambda x, y: x | {y: x.get(y, 0) + 1}, a, {})

# Applicazione della funzione map() su lista_s utilizzando la funzione map_f
result_map = list(map(map_f, lista_s))
print(result_map)

# Definizione di una funzione lambda per ridurre i risultati di map_f in un'unica mappa dei conteggi
reduce_f = lambda x, y: {k: x.get(k, 0) + y.get(k, 0) for k in set(x) | set(y)}

# Utilizzo della funzione reduce() per unire i risultati dei conteggi delle stringhe in result_map
result_reduce = reduce(reduce_f, result_map)
print(result_reduce)

```





Es 4

```python
# Richiede all'utente di inserire un calcolo come input tramite la funzione input()
a = input('Inserire calcolo: ')

# La funzione eval() valuta l'espressione matematica contenuta nella variabile 'a'
b = eval(a)

# Stampa il risultato del calcolo valutato
print(b)

```

Lambda funzioni anonime senza nome

```python
add = lambda x,y : x + y
print(add(2,3)) #out: 5

lista_di_tuple =[(1,2),(3,4),(23,44)]
lista_di_tuple.sort(key=lambda x:x[1])
print(lista)



```



Map cosa fa?

applico una funzione a tutti gli elementi di un iterabile

```python
nums = [1,2,3,4,5,6]
squared = list(map(lambda x:x**2, nums))
print(squared) # 1 , 2 ,4 , 16, 32

#OPPURE

squaredDue = list (map(lambda x: x**2,filter(lambda x:x %2==0, nums)))
print(squaredDue) # 4, 16, 36


```

Filter?

usa le funzioni lambda per fltrare elementi di un iterabile.

```python
nums = [1,2,3,4]
fun = list(filter(lambda x:x%2 == 0, nums))
print(fun) #out 2 e 4
```

Reduce

Applica ripetutamente una funzione ai primi due elementi di una sequenza , riducendo la sequenza ad un singolo valore.

```python
nums = [1,2,3,4]
sum = reduce(lambda x,y : x + y, nums)
print(sum) #risultato 10
```

Sorted

Oridinamente dal piu piccolo al piu grande

```python
data = [{"name":"Mario", "age":30},
        {"name":"Luigi", "age":25},
        {"name":"Ciccio", "age":35}]
sorted_data = sorted(data,key=lambda x:x['age'])
print(sorted_data) #risultato 25,30,35
```

Any (almeno un elemento) o  All(tutti gli elementi)


