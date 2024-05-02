# Premessa

### Linguaggi Statici vs Dinamici

1. Linguaggi Statici (es. Java, C++, C#):
   
   - Tipizzazione Statica: I tipi di variabili devono essere dichiarati esplicitamente e sono verificati al momento della compilazione (compile-time).
   - Forti e Strettamente Tipizzati: I cast devono essere espliciti, riducendo errori di tipo.
   - Errori Rilevati Precoce: Gli errori di tipo sono individuati prima dell'esecuzione del programma, aumentando la robustezza.
   - Linguaggi Compilati: Il codice è tradotto in linguaggio macchina o intermedio prima dell'esecuzione.

2. Linguaggi Dinamici (es. Python, JavaScript, Ruby):
   
   - Tipizzazione Dinamica: I tipi sono risolti a runtime, e possono cambiare durante l'esecuzione.
   - Linguaggi Interpretati: Il codice è eseguito direttamente da un interprete, linea per linea.
   - Casting Implicito: Possibilità di casting automatico tra tipi, che può portare a comportamenti imprevisti.
   - Controllo dei Tipi a Runtime: Ciò può causare errori di tipo durante l'esecuzione.
   - Flessibilità: Non è necessario dichiarare i tipi; il codice è più flessibile ma potenzialmente meno efficiente e più difficile da mantenere.

### Linguaggi Compilati vs Interpretati

1. Compilato (es. C, C++, Rust):
   
   - Compilazione in Anticipo: Il codice sorgente è trasformato in un formato eseguibile prima dell'esecuzione.
   - Efficienza: Il codice oggetto è immediatamente eseguibile, rendendo l'esecuzione più efficiente.

2. Interpretato (es. Python, JavaScript, PHP):
   
   - Esecuzione Diretta: Il codice sorgente è eseguito dall'interprete senza una fase di compilazione pre-esecuzione.
   - Flessibilità: Maggiore flessibilità ma potenzialmente meno efficienza.

3. Java (Ibrido):
   
   - Bytecode: Viene compilato in bytecode, che è poi interpretato dalla Java Virtual Machine (JVM).

### Linguaggi di Alto/Basso Livello

1. Alto Livello (es. Python, Java, C#):
   
   - Astrazione Elevata: Più vicini al linguaggio naturale, più leggibili e portabili.
   - Facilità d'Uso: Più facili da imparare e usare, consentono una programmazione più efficiente.

2. Basso Livello (es. Assembly, Linguaggio Macchina):
   
   - Vicinanza all'Hardware: Richiedono una comprensione approfondita dell'architettura hardware.
   - Efficienza: Più efficienti in termini di prestazioni, ma meno portabili e più complessi.

### Tipizzazione

- Debole vs Forte: La tipizzazione debole permette conversioni implicite, mentre quella forte richiede conversioni esplicite.
- Safe vs Unsafe: Nel contesto della tipizzazione, "safe" implica restrizioni sulle conversioni implicite per prevenire errori, mentre "unsafe" permette conversioni che possono causare crash.

In sintesi, i linguaggi statici e compilati tendono ad essere più robusti e efficienti, ma meno flessibili. I linguaggi dinamici e interpretati offrono maggiore flessibilità e facilità di uso, ma possono essere meno efficienti e più difficili da mantenere su larga scala. La scelta tra questi dipende dalle esigenze specifiche del progetto e dalle preferenze del programmatore.

Python è object oriented e con tipizzazione dinamica delle variabili (queste sono però strettamente tipizzate). Non è necessario dichiarare le variabili prima di usarle né dichiarare il loro tipo. Ogni variabile in Python è un'istanza di una classe che si può assegnare a un identificatore.

Python e' un linguaggio di programmazione Alto Livello, interpretato, general purpose(non hanno uno scopo specifico), multiparadigma(Supporta diversi paradigmi di programmazione, supporta paradigma imperativo:procedurale che quello agli oggetti e paradigma funzionale) e opensource e dinamicamente tipizzato

Python e' un linguaggio:

- ad Alto livello: piu vicini al linguaggio umano rispetto al linguaggio macchina

- Dinamico: Gestisce internamente la memoria, facile da usare perche semplice

- Interpretato: per eseguirlo si converte in linguaggio macchina in tempo reale riga per riga

**1. Variabili e Tipi di Dati:**

- `x = 5`: Assegna il valore 5 alla variabile x.

- `int`, `float`, `str`, `list`, `tuple`, `dict`, `set`: Rappresentano i diversi tipi di dati supportati in Python.

## **2. Operazioni Matematiche:**

- `+`, `-`, `*`, `/`: Eseguono operazioni matematiche di addizione, sottrazione, moltiplicazione e divisione.
- `%`: Restituisce il resto della divisione.
- `**`: potenza 3**2=9
- `//` Floor division 3 // 2=1
- `<< >>`
- `&`
- 

## **3. Input/Output:**

- `print("Testo")`: Stampa il testo sulla console.
- `input("Prompt")`: Riceve l'input dall'utente tramite la console.

## **4. Costrutti di Base:**

- `if`, `elif`, `else`: Permettono di eseguire istruzioni condizionali.

```python
if condiziONE:

elif codiziTWO:

else:
    condiziTHREE
```

- `for elemento in sequenza:`: Itera attraverso gli elementi di una sequenza.
- keyword continue/break
  - break, interrompe il ciclo
  - continue, salta solo l'interazione corrente senza uscire dal for

Lo statement for parte chiamando una funzione '_iter_() '

```python
for i in range(10): 
    print(i)
#range(inizio, fine, intervallo)
range(0,10,2) -> 0,2,4,6,8
range(0,5) -> 0,1,2,3,4
range(5) -> 0,1,2,3,4
a = 'cio'    #Stringhe
for i in a: print(i) -> c i o 
a = set(['a','b'])    #SET
for i in a: print(i) -> a\n b\n 
a = {'key1': 1, 'key2': 2}    #Dizionari
for i in a: print(i) -> key1\n key2\n 
a = 'abc'    #Enumara la sequenza su cui si itera
for i,o in enumerate(a): print(i)#stampa (a,'a')(1,'b')(2,'c')
-> 0\n 1\n 2\n 
```

- `while condizione:`: Esegue un blocco di istruzioni finché la condizione è vera.

```python
while b<10: #funche la condizione e' vera
    b=b+1
else: #quando esce esegue 100
    b=100
```

- `break`, `continue`: Modificano il flusso di esecuzione di cicli (for/while).

`break -> interrompe un ciclo for/while
continue -> salta all'iterazione for/while successiva`

## **5. Funzioni:**

- `def nome_funzione(parametri):`: Definisce una funzione con i relativi parametri.
- `return valore`: Restituisce un valore dalla funzione.
- `args`, `kwargs`: Parametri arbitrari in una funzione (argomenti posizionali, argomenti keyword).

Funzioni vs Metodi? Funzioni sono blocchi di codice che possono essere definiti una volta e richiamati in qualsiasi punto del programma. I metodi sono simili alle funzioni ma sono associati a oggetti specifici, istanze di classi

```python
#metodo
testo.upper()
#funzione
def somma(a,b): return a + b
risultato= somma(3,2)
#PASSAGGIO DI ARGOMENTI
a = funzione(1,2)
a = funzioni(arg2=3, arg1=1) def funzione(arg1,arg2=23) print(arg2) #posso specificare l'argomento
il risultato della funzione sopra e' 3, arg2=23 e' solo un parametro di default se ce null
funzione(1,2,3,4) e uguale a a=[1,2,3,4] funz(a*)
Posso fare la stessa cosa i dizionari
a = {a:1, b:2, c:3}
funzione(**a) OR funzione(a=1,b=2,c=3)
f
```

Funzioni Generatrici? Una funzioneche generano una sequenza di valori al momento del bisogno.

```py
def contatore_massimo(max):
    n = 0
    while n < max:
        yield n #uguale al return
        n +=1
#creazione del generatore
gen = contatore_massimo(3)
for i in gen: #for richiede a gen ogni volta la i, yield gli passa il valore e si spospende e continua cosi ogni valore che gli serve
    print(i) #0,1,2
```

## **6. Liste, Tuple, Dizionari e Set:**

- `lista = [1, 2, 3]`: Definisce una lista.
- `tupla = (1, 2, 3)`: Definisce una tupla.
- `dizionario = {'chiave': 'valore'}`: Definisce un dizionario.
- `insieme = {1, 2, 3}`: Definisce un insieme.

```python
#Liste
lista.append(ogg): #appende l'oggetto in fondo alla lista
lista.insert(indice, ogg) #inserisce in posizione indice ogg
lista.pop(indi) #rimuove e estrae l'ogg del indice
my_lista.sort() #modifica la lista originale non ne crea una nuova
my_lista=sorted(lista) #crea una nuova lista 

a=[1,2,3];  b=a;  copia il riferimento quindi b[0]=5 anche a[0] sara 5
#PER COPIARE SENZA RIFERIMENTO USA LO SLICING (to slice=affettare accedere alle strutture dati affettandole)
s[::2] #Tutti gli elementi con index pari 0 2 4 ..
b = a[:]; se modifico b non modifico la lista a 
```

```python
#TUPLE sono come le stringhe immutabili, non puo essere modificato,
#ogni volta che modifico un carattere es: 'ciao' io sto ricreando una nuova stringa
tup=('one','two','21')
```

```python
#SET, insieme non ordinato di oggetti quindi non posso accederci tramite indice 
# e non replicato lo stesso oggetto non puo comprarire piu volte
Creazione del set:
a = set() OR b = set([lista]) OR c = {1,2}
#utilizzati per eliminare le occorenze in una lista
AGGIUNTO ELEMENTI
my_set.add(4) OR my_set.update([5,6])
CANCELLARE
my_set.remove(3) OR my_set.discard(2)
UTILIZZO
set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}
# Unione di set
union_set = set1.union(set2)
print(union_set)  # Output: {1, 2, 3, 4, 5, 6}
# Intersezione di set
intersection_set = set1.intersection(set2)
print(intersection_set)  # Output: {3, 4} #elementi che compaiono in tutti i due set
# Differenza di set
difference_set = set1.difference(set2)
print(difference_set)  # Output: {1, 2} #elem che non compaiano in set2
# Differenza simmetrica di set
symmetric_difference_set = set1.symmetric_difference(set2)
print(symmetric_difference_set)  # Output: {1, 2, 5, 6}
```

```python
#DICTIONARY, collezione di coppie chiave-valore
my_dict = {'nome': 'Alice', 'età': 25, 'sesso': 'F'}
print(my_dict['nome'])  # Output: Alice
print(my_dict['età'])   # Output: 2
# Modifica di un valore
my_dict['età'] = 2
# Aggiunta di una nuova coppia chiave-valore
my_dict['email'] = 'alice@example.com
# Rimozione di una coppia chiave-valore utilizzando del
del my_dict['sesso']
removed_value = my_dict.pop('età') #rimuovo la chiave e ritorno il valore 26 nella variabile
#ITERAZIONE
for key in my_dict.keys(): OR my_dict.values(): OR my_dict.items():
    print(key)
```

## **7. Gestione delle Eccezioni:**

- `try:`, `except:`, `finally:`: Gestiscono le eccezioni e i potenziali errori durante l'esecuzione del codice.

## **8. File I/O:**

- `open('file.txt', 'r')`: Apre un file in modalità lettura.
- `open('file.txt', 'w')`: Apre un file in modalità scrittura.
- `read()`, `write()`, `close()`: Metodi per leggere, scrivere e chiudere file.
- Cos'è il context manager? 
  ![](C:\Users\baleo\AppData\Roaming\marktext\images\2024-03-22-15-21-29-image.png)

## **9. Moduli e Importazioni:**

Moduli sono librerie di codice che si possono importare nel proprio script o in un istanza interrattiva dell'interprete. Si utilizza a keyword import 

- `import nome_modulo`: Importa i moduli esterni(librerie) per utilizzarne nel codice

```python
import pandas
a = pandas.DataFrame()
```

- `from modulo import oggetto`: Importa specifici oggett(funzioni)i da un modulo.

```python
from pandas import DataFrame
a = DataFrame()
from pandas import * #importa tutte le funzioni del modulo
```

## **10. Gestione di Stringhe:**

- `len(stringa)`: Restituisce la lunghezza di una stringa.
- `stringa.lower()`, `stringa.upper()`: Modificano il case della stringa.
- `stringa.split(delimitatore)`: Suddivide una stringa in una lista di sottostringhe.

```python
s.find('a')#ritorna l'indice della prima occorenza di 'a' in s
ciao.replace('a','o') #cioo, rimpiazza tutte le a con o
';'.join([1,2,3])="1;2;3"
'1+2+3'.split('+')=['1' ,'2','3']
s.lower() e s.upper #minuscolo e maiuscolo
```

Questi sono solo alcuni dei comandi base in Python. Esistono molte altre funzioni e librerie che possono essere utilizzate per svolgere una vasta gamma di attività di programmazione. La pratica e l'esplorazione costante aiuteranno a comprendere meglio e a utilizzare appieno il linguaggio Python.

## 11. Programmazione di Ordine Superiore

Si riferisce a concetti in cui le funzioni sono trattate come "cittadini di prima classe". Questo significa che le funzioni possono essere passato essere come argomenti ad altre funzioni, possono essere assegnate a variabili o memorizzate in strutture dati.

```python
#FUNZIONI COME OGGETTI DI PRIMA CLASSE:
In python, le funzioni sono oggetti di prima classe.
Cio' significa che possono essere passate e utilizzate come qualsiasi altro oggetto,
come stringhe o numeri.

#FUNZIONI COME ARGOMENTI
def quadrato(n):
    return n * n
numeri = [1,2,3,4]
risultati = map(quadrato, numeri) #Applico 'quadrato' a ogni elemento
#FUNZIONI CHE RESTITUISCONO FUNZIONI
def potenza(exponente):
    def elevatore(base):
        return base ** exponente
    return elevatore
quadrato = potenza(2)
cubo = potenza(3) # 9
```

### LAMBDA

Funzioni Lambda

```python#lambda
#lambda arguments:expression
#ES1
somma = lambda x,y: x+y
print(somma(5,3))
#ES2
numeri = [1,2,3,4]
quadrati = map(lambda x : x*x, numeri)
print(list(quadrati)) #[1,4,9,16,25]
#ES3
numeri = [1,2,3,4,5,6]
pari = filter (lambda x: x% 2 == 0, numeri)
print(list(pari)) #solo i pari
#ES4
punti = [(1,2),(3,3),(5,1)]
print(sorted(punti, key=lambda x: x[1])) #ordino da chiave
#lambda imediatamente invocata
ris=(lambda x,y : x + y)(5,3)
```

### Closure

La closure si presentano quando unafunzione annidata fa riferimento a una variaibile del suo suo ambiente.

```python
def moltplicatore(n) #funzione esterna
    def inner(x): #funzione interna (closure)
        return x * n
    return inner

doppio = moltiplicazione(2) #prende la funzione inner(x)
print(doppio(5)) #outuput 10
```

### Scope

In Python, lo "scope" di una variabile determina la parte di codice in cui la variabile è accessibile. Ci sono quattro tipi principali di scope:

1. **Built-in Scope**: Questo è lo scope più esterno. Contiene entità predefinite in Python, come print(), len(), ecc. Sono disponibili in qualsiasi parte del codice.

2. **Global Scope: **Questo scope include variabili definite al livello più alto del codice, fuori da qualsiasi funzione o blocco. Queste variabili sono accessibili da qualsiasi parte del codice dopo la loro definizione.

3. **Enclosing** (Non-Local) Scope: Rilevante in contesti di funzioni annidate. Una variabile definita in una funzione esterna (non globale) è in uno scope "enclosing" per le funzioni interne.

4. **Local Scope:** Questo è lo scope all'interno di una funzione. Le variabili definite qui sono accessibili solo all'interno della funzione stessa.

### Esempi di Scope

```python
a = 1  #variabile globale
def local():
    # Local Scope
    c = 3 + b

def another():
    d = 0
    # Qui 'd' è in uno scope locale per 'another'
#ESEMPIO 1
def fun(x) #viene passato il riferimento
    print(x)
    x = 'ciao' #viene modificata la x e quindi ne si crea un nuovo riferimento
    print(x)
x = 5
fun(x)
print(x) #non viene alterato
#output 5 ciao 5
#ESEMPIO 2
def fun(x)
    print(x) #[1,2]
    x.append(3)
x = [1,2]
fun(x) #viene passato il riferimento
print(x) [1,2,3]
```

***Attenzione*** in realta' quando si sta prendendo il riferimento all'oggetto, si prende lo stesso puntato dalla x, MA quando si cambia si ri-assegna/modifica la x , la x puntera ad nuovo oggetto creatosi

### Risoluzione dello Scope

Quando Python deve accedere a una variabile, segue questo ordine per risolvere lo scope:

1. Local: Prima cerca nello scope locale.
2. Enclosing: Se non trovata, cerca negli scope enclosing (funzioni annidate).
3. Global: Se ancora non trovata, cerca nello scope globale.
4. Built-in: Infine, cerca nello scope built-in.

### Shadowing di Variabili

Le variabili con lo stesso nome in scope diversi possono "nascondere" quelle in scope esterni:

x = 1  # Globale

def funzione():
    x = 2  # Locale, "nasconde" la x globale

### Uso della Parola Chiave global

Si può forzare l'uso di una variabile globale dentro una funzione usando la parola chiave global:

x = 1

def funzione():
    global x
    x = 3  # Modifica la x globale

### Comportamento degli Argomenti delle Funzioni

Gli argomenti passati alle funzioni entrano nel loro scope locale. Se una funzione modifica un oggetto mutabile (come una lista) passato come argomento, la modifica è visibile fuori dalla funzione, poiché l'oggetto è passato per riferimento.

```py
def funzione(x):
    x.append(3)

y = [1, 2]
funzione(y)  # Modifica y anche all'esterno della funzione
```

**In sintesi, lo "scope" in Python è un concetto fondamentale che determina la visibilità delle variabili all'interno di diversi blocchi di codice. Comprendere come funziona lo scope è essenziale per scrivere codice chiaro e per evitare errori legati alla visibilità delle variabili.**

Aggiungendo la parte sulla gestione delle eccezioni e i decoratori al testo precedente, avremo una panoramica completa su alcuni concetti chiave della programmazione in Python: scope, gestione delle eccezioni e decoratori.

### Gestione delle Eccezioni

In Python, le eccezioni sono utilizzate per gestire errori e altri eventi eccezionali durante l'esecuzione del codice. La sintassi per catturare un'eccezione è la seguente:

```py
try:
    # Codice che potrebbe sollevare un'eccezione
except Classe_eccezione as identificativo:
    # Gestisce una specifica eccezione
except Altraclasse_eccezione as identificativo:
    # Gestisce un'altra eccezione
except:
    # Gestisce qualsiasi eccezione non catturata dalle clausole precedenti
else:
    # Codice eseguito se non si verificano eccezioni
finally:
    # Codice che viene eseguito in ogni caso, con o senza eccezioni
#Si può utilizzare raise per sollevare intenzionalmente un'eccezione. Ad esempio:
raise NameException(arg1, arg2)
```

### Decoratori

I decoratori sono una potente caratteristica di Python che permette di modificare o **estendere** il comportamento di funzioni o metodi. Vengono utilizzati per "avvolgere" una funzione, aggiungendo funzionalità prima e/o dopo l'esecuzione della funzione originale.

Il decoratore e' una funzione che prendi in ingresso un altra funzione e ne ritorna un altra.

Un descrittore puo anche essere un attributo  esempio property

```python
@dec
def fun(): #a fun sara associata la funzione ritornata da dec
 pass
```

#### Esempio Base di Decoratore

```python
def time_function(function):
    def new_function(*args, **kwargs):
        start = time.time()
        value = function(*args, **kwargs)
        end = time.time()
        print("Ci ha messo", end - start, "secondi")
        return value
    return new_function

@time_function
def func(x, y, z):
    time.sleep(random.random()*x + (y - z))
#L'utilizzo del decoratore @time_function modifica il comportamento di 'func'
```

In questo esempio, time_function è un decoratore che misura il tempo di esecuzione di qualsiasi funzione. Quando @time_function viene applicato a func, func diventa una "funzione arricchita" che ora include la logica di misurazione del tempo.

Un altro esempio:

```python
# Definizione di un decoratore
def decoratore(funzione):
    def wrapper():
        print("Prima di eseguire la funzione")
        funzione()
        print("Dopo l'esecuzione della funzione")
    return wrapper

# Applicazione del decoratore usando il simbolo @
@decoratore
def saluta():
    print("Ciao!")

# Chiamata della funzione decorata
saluta()
#output
Prima di eseguire la funzione
Ciao!
Dopo l'esecuzione della funzione
```

### Uso di super() in Classi Derivate

In Python, super() è utilizzato per fare riferimento a metodi della classe genitore (o classe base) in una classe derivata.

```python
class Fuoristrada(Automobile):
    def ridotte(self):
        self.rapporto = 0.01

def muoviti(self, l):
    l = l * self.rapporto
    super().muoviti(l)  # Chiama il metodo 'muoviti' della classe genitore
```

In questo esempio, super().muoviti(l) chiama il metodo muoviti della classe genitore Automobile all'interno della classe Fuoristrada.

### Ereditarietà Multipla

Python supporta l'ereditarietà multipla, permettendo a una classe di ereditare da più classi base.

```python
class Automobile:
    def __init__(self):
        self.posizione = 0

def muoviti(self, l):
    self.posizione += l

class Barca:
    def affonda(self):
        self.affondato = True

class Anfibio(Barca, Automobile):
    pass
In questo esempio, Anfibio eredita sia da Barca che da Automobile.
```

### Ciclo di inizializzazione

__new__ #crea l'oggetto e lo resituisce

__init__ #inizializza senza restituitlo

### Metodi Privati

iniziano con __ e terminano massimo con uno _

- __priv_\ OR __priv\
  
  Anche se non sono veramente private perche possibile accederle utilizzando _NomeClasse__NomeEntita_\

### Metodi Classe VS statici

In Python, ci sono differenze tra i "metodi statici" e i "metodi di classe".

I metodi di classe in Python sono associati alla classe stessa e non alle sue istanze. Questi metodi sono definiti all'interno di una classe utilizzando il decoratore `@classmethod`. Il primo argomento di un metodo di classe è sempre `cls` (convenzionalmente chiamato così, ma potrebbe essere qualsiasi altro nome), che si riferisce alla classe stessa anziché a un'istanza specifica della classe (come farebbe `self` per i metodi di istanza).

Esempio di metodo di classe:

```python
class MiaClasse:
    variabile_di_classe = "Valore della variabile di classe"

    @classmethod
    def metodo_di_classe(cls): 
        ciccio = cls(arg) #viene istanziata la classe
        return cls.variabile_di_classe

# Chiamata del metodo di classe senza creare un'istanza della classe
print(MiaClasse.metodo_di_classe())  # Output: Valore della variabile di classe
```

I metodi di classe possono accedere agli attributi della classe stessa attraverso `cls` e possono essere chiamati direttamente dalla classe senza dover creare un'istanza.

### Metodi Statici:

I metodi statici in Python sono definiti all'interno di una classe utilizzando il decoratore `@staticmethod`. Questi metodi non ricevono implicitamente alcun riferimento alla classe o all'istanza (né `self`, né `cls`) come primo argomento. Sono metodi che operano indipendentemente dalle istanze e dalla classe stessa.

Esempio di metodo statico:

```python
class MiaClasse:
    @staticmethod
    def metodo_statico():
        return "Questo è un metodo statico"

# Chiamata del metodo statico senza creare un'istanza della classe
print(MiaClasse.metodo_statico())  # Output: Questo è un metodo statico
```

I metodi statici possono essere chiamati direttamente dalla classe senza dover creare un'istanza e non hanno accesso implicito a variabili di classe o istanze. Sono utili per organizzare funzionalità all'interno di una classe ma che non dipendono da specifiche istanze o variabili di classe.

In breve, la differenza principale tra metodi di classe e metodi statici è che i primi accedono alla classe stessa attraverso `cls` e sono utili per operare su variabili di classe, mentre i metodi statici non hanno accesso implicito a variabili di classe o istanze e possono essere chiamati direttamente dalla classe.

### Metodi Speciali

| Metodo speciale                                                                  | Descrizione                                             | Esempio di utilizzo                                                             |
| -------------------------------------------------------------------------------- | ------------------------------------------------------- | ------------------------------------------------------------------------------- |
| `__init__`                                                                       | Costruttore, chiamato quando un oggetto è creato        | `def __init__(self, arg1, arg2):`                                               |
| `__del__`                                                                        | Distruttore, chiamato quando un oggetto viene distrutto | `def __del__(self):`                                                            |
| `__repr__`                                                                       | Rappresentazione della stringa dell'oggetto             | `def __repr__(self):`                                                           |
| `__str__`                                                                        | Rappresentazione stringa leggibile dell'oggetto         | `def __str__(self):`                                                            |
| `__len__`                                                                        | Ritorna la lunghezza dell'oggetto                       | `def __len__(self):`                                                            |
| `__getitem__`                                                                    | Accesso agli elementi attraverso l'operatore `[]`       | `def __getitem__(self, key):`                                                   |
| `__setitem__`                                                                    | Impostazione degli elementi attraverso l'operatore `[]` | `def __setitem__(self, key, value):`                                            |
| `__iter__`                                                                       | Iterazione attraverso l'oggetto                         | `def __iter__(self):`                                                           |
| `__next__`                                                                       | Ritorna il prossimo elemento durante l'iterazione       | `def __next__(self):`                                                           |
| `__contains__`                                                                   | Verifica la presenza di un elemento nell'oggetto        | `def __contains__(self, item):`                                                 |
| `__call__`                                                                       | Permette di chiamare un oggetto come una funzione       | `def __call__(self, *args, **kwargs):`                                          |
| `__add__`, `__sub__`,<br>`__mul__`, `__div__`,<br>`__truediv__`, `__mod__`, etc. | Operazioni matematiche o di operatore                   | `def __add__(self, other):`                                                     |
| `__getattr__`                                                                    | Gestisce gli accessi agli attributi non esistenti       | `def __getattr__(self, name):`                                                  |
| `__setattr__`                                                                    | Gestisce la modifica degli attributi                    | `def __setattr__(self, name, value):`                                           |
| `__delattr__`                                                                    | Gestisce la rimozione degli attributi                   | `def __delattr__(self, name):`                                                  |
| `__enter__`, `__exit__`                                                          | Utilizzati in contesto con la dichiarazione `with`      | `def __enter__(self):`<br>`def __exit__(self, exc_type, exc_value, traceback):` |
| `__hash__`                                                                       | Ritorna il codice hash dell'oggetto                     | `def __hash__(self):`                                                           |
| `__eq__`, `__ne__`,<br>`__lt__`, `__le__`,<br>`__gt__`, `__ge__`                 | Confronto tra oggetti                                   | `def __eq__(self, other):`                                                      |

Certamente! I metodi `__getattr__` e `__setattr__` sono due metodi speciali in Python che gestiscono rispettivamente la lettura e la scrittura degli attributi di un oggetto in modo personalizzato. Ecco degli esempi che illustrano il loro utilizzo:

Il metodo `__getattr__` viene chiamato quando viene tentato di accedere a un attributo che non esiste nell'oggetto.

```python
class MiaClasse:
    def __init__(self):
        self.attributo_esistente = "Questo attributo esiste"

    def __getattr__(self, nome_attributo):
        return f"L'attributo '{nome_attributo}' non esiste"

# Utilizzo della classe
oggetto = MiaClasse()

# Accesso a un attributo esistente
print(oggetto.attributo_esistente)  # Output: Questo attributo esiste

# Accesso a un attributo inesistente
print(oggetto.attributo_inesistente)  # Output: L'attributo 'attributo_inesistente' non esiste
```

In questo esempio, quando si tenta di accedere a un attributo non esistente come `attributo_inesistente`, il metodo `__getattr__` viene chiamato e restituisce un messaggio personalizzato.

### Metodo `__setattr__`:

Il metodo `__setattr__` viene chiamato ogni volta che viene effettuata una modifica ad un attributo dell'oggetto.

```python
class MiaClasse:
    def __setattr__(self, nome_attributo, valore):
        print(f"Impostazione dell'attributo '{nome_attributo}' a '{valore}'")
        # Questo metodo deve essere chiamato in modo esplicito per evitare ricorsione infinita
        self.__dict__[nome_attributo] = valore

# Utilizzo della classe
oggetto = MiaClasse()

# Impostazione di un attributo
oggetto.attributo = 10  # Output: Impostazione dell'attributo 'attributo' a '10'
```

Da notare che nel metodo `__setattr__`, è necessario usare `self.__dict__[nome_attributo] = valore` per impostare effettivamente l'attributo. Se si tenta di utilizzare `self.nome_attributo = valore` all'interno di `__setattr__`, si finirà in un loop infinito poiché la chiamata a `self.nome_attributo = valore` richiamerebbe nuovamente `__setattr__`.

Il decoratore `property` in Python è un modo per implementare gli attributi di tipo property, consentendo di definire metodi getter, setter e deleter per gestire l'accesso, la modifica e la cancellazione di attributi di classe in modo controllato.

### Uso del decoratore `property` con metodi getter, setter e deleter:

```python
class Persona:
    def __init__(self, nome, eta):
        self._nome = nome
        self._eta = eta

    @property
    def nome(self):
        return self._nome

    @property
    def eta(self):
        return self._eta

    @eta.setter
    def eta(self, nuova_eta):
        if nuova_eta > 0:
            self._eta = nuova_eta
        else:
            raise ValueError("L'età deve essere maggiore di zero")

    @eta.deleter
    def eta(self):
        del self._eta

# Utilizzo della classe
persona = Persona("Alice", 30)

# Accesso tramite il metodo getter
print(persona.nome)  # Output: Alice
print(persona.eta)   # Output: 30

# Modifica tramite il metodo setter
persona.eta = 32
print(persona.eta)   # Output: 32

# Tentativo di impostare un'età negativa
try:
    persona.eta = -5
except ValueError as e:
    print(e)  # Output: L'età deve essere maggiore di zero

# Cancellazione dell'attributo età
del persona.eta
print(persona.eta)   # Output: AttributeError: 'Persona' object has no attribute '_eta'
```

In questo esempio, la classe `Persona` ha un attributo `_nome` e `_eta` (con il prefisso underscore per indicare che sono "privati"). Utilizzando il decoratore `property`, definiamo i metodi `nome()` e `eta()` come metodi getter per ottenere i valori degli attributi. Inoltre, definiamo un metodo `eta.setter` per controllare la modifica dell'attributo `_eta`, in modo che sia consentito solo un valore maggiore di zero. Infine, il metodo `eta.deleter` consente di eliminare l'attributo `_eta`.

Il decoratore `property` ci consente di accedere agli attributi come se fossero attributi di classe, ma di fatto essi vengono gestiti attraverso i metodi getter, setter e deleter definiti, consentendo di controllare l'accesso e la modifica degli attributi in modo più controllato e sicuro.

### Accesso agli attributi 2

Tra gli attributi di istanza e quelli di classe viene data la prioprieta a queli distanza

```python
class Animale:
x=0
y=0
def __init__(self)
    self.x = 1 #viene usato questo non quello globale
    self.b = 1
```

Ogni oggetto in Python ha un dizionario `__dict__` che memorizza i suoi attributi. Quando si accede a un attributo di un oggetto, Python cerca prima l'attributo all'interno del `__dict__` dell'oggetto stesso. Se non lo trova, cerca nell'`__dict__` delle classi base e della gerarchia delle classi. In realta si passa per il metodo `__getattribute__` che controlla nel dict e negli attributi di classe

<img src="file:///C:/Users/baleo/AppData/Roaming/marktext/images/2024-01-09-23-43-51-image.png" title="" alt="" width="279">

## Metaclasse

e' una classe le cui istanze sono a loro volta classi

In python tutto e' un oggetto anche le classe anche le istanze delle classi.

La metaclasse madre e' TYPE , tutto l'istanze delle classe sono istanze di type

`__call__` metodo speciale che consente all oggetto istanziato di essere chiamato come una funzione. Cioe posso invocare l'oggetto stesso  come se fosse una funzione

```python
class MyClass:
    def __init__(self, value):
        self.value = value

def __call__(self, x):
    return self.value * x

# Creiamo un'istanza della classe MyClass

obj = MyClass(5)

# Ora possiamo chiamare l'istanza come se fosse una funzione

result = obj(4)  # Chiamata usando l'operatore ()
print(result)    # Stampa: 20, perché obj(4) chiama __call__(4) che restituisce 5 * 4 = 20
```

Questo implica che anche una classe puo essere un decoratore

### Classi astratte

In Python, le classi astratte forniscono uno strumento per definire classi che non possono essere istanziate direttamente ma che vengono utilizzate come modelli per altre classi derivate. Questo concetto fa parte del modulo `abc` (Abstract Base Classes) che consente di definire interfacce e classi base astratte.

Per definire una classe astratta in Python, è necessario utilizzare il modulo `abc` e la classe `ABC` come base per la classe astratta. Inoltre, si possono utilizzare i decoratori `@abstractmethod` per segnalare i metodi che devono essere implementati dalle sottoclassi.

Ecco un esempio:

```python
from abc import ABC, abstractmethod

class FormaGeometrica(ABC):
    @abstractmethod
    def calcola_area(self):
        pass

    @abstractmethod
    def calcola_perimetro(self):
        pass

class Rettangolo(FormaGeometrica):
    def __init__(self, lunghezza, larghezza):
        self.lunghezza = lunghezza
        self.larghezza = larghezza

    def calcola_area(self):
        return self.lunghezza * self.larghezza

    def calcola_perimetro(self):
        return 2 * (self.lunghezza + self.larghezza)

# Esempio di utilizzo delle classi
# Non è possibile istanziare direttamente la classe astratta FormaGeometrica
# È necessario implementare tutti i metodi astratti in una sottoclasse prima di poterla istanziare
# Quindi possiamo istanziare la classe Rettangolo che implementa tutti i metodi astratti
rettangolo = Rettangolo(5, 3)
print("Area del rettangolo:", rettangolo.calcola_area())  # Stampa: 15
print("Perimetro del rettangolo:", rettangolo.calcola_perimetro())  # Stampa: 16
```

I paradigmi di programmazione imperativo e orientato agli oggetti rappresentano due approcci differenti per risolvere i problemi di programmazione, ognuno con le proprie caratteristiche e concetti chiave.

1. **Programmazione Imperativa:**
   
   - **Stile di Programmazione:** Nel paradigma imperativo, il codice si concentra su "come" eseguire una determinata azione, scrive le funzioni per risolvere il problema. Si basa sul concetto di cambiamento di stato delle variabili e sull'esecuzione di istruzioni per modificarle.
   - **Focus sulle istruzioni:** Le istruzioni imperativo definiscono passo dopo passo come eseguire un istruzione
   - **Esempio:** Linguaggi come C, Pascal, e assembly sono orientati principalmente a questo paradigma.

2. **Programmazione Orientata agli Oggetti (OOP):**
   
   - **Stile di Programmazione:** L'OOP si concentra su "cosa" deve essere fatto, astrae il mondo in termini di oggetti che possono contenere sia dati (attributi) che operazioni (metodi) su quei dati.
   - **Oggetti e Classi:** Gli oggetti sono istanze di classi, che fungono da modelli per creare gli oggetti stessi. Le classi definiscono la struttura e il comportamento degli oggetti.
   - **Incapsulamento e Astrazione:** L'OOP si basa sull'incapsulamento, che nasconde i dettagli implementativi all'esterno e consente l'accesso controllato ai dati attraverso metodi pubblici. Inoltre, offre l'astrazione, che permette di concentrarsi sui dettagli rilevanti, ignorando quelli irrilevanti.
   - **Ereditarietà e Polimorfismo:** L'ereditarietà permette di creare nuove classi basate su classi esistenti, mentre il polimorfismo consente a oggetti di classi diverse di essere trattati allo stesso modo se condividono un'interfaccia comune.
   - **Esempio:** Linguaggi come Python, Java, C++, e molti altri sono orientati agli oggetti.

3. Funzionale: Programmazione in stile matematico, si dichiara che funzione utilizzare per ottenere un risultato
- **Basato sul Concetto di Funzione:**
  
  - Nel paradigma funzionale, le funzioni sono trattate come "cittadini di prima classe". Possono essere assegnate a variabili, passate come argomenti ad altre funzioni e restituite come risultati di altre funzioni.

- **Immutabilità e Purezza:**
  
  - Le funzioni in stile funzionale sono generalmente "pure", il che significa che dato uno stesso input, restituiscono sempre lo stesso output senza effetti collaterali.
  - L'approccio funzionale favorisce l'immutabilità dei dati, in cui gli oggetti sono immutabili e le funzioni non modificano lo stato dei dati ma producono nuovi dati.

- **Ricorsione e Composizione Funzionale:**
  
  - La ricorsione è un elemento fondamentale nella programmazione funzionale, consentendo di scrivere algoritmi senza utilizzare cicli.
  - La composizione funzionale permette di combinare più funzioni per creare nuove funzioni.
  
  LAMBDA IN PYTHON E' FUNZIONALE
1. Logico

2. **Basato sulla Logica e sulle Regole:**
   
   - Il paradigma logico si basa sull'uso di regole di inferenza logica e sulla rappresentazione delle conoscenze mediante fatti e regole.
   - Utilizza principalmente la programmazione dichiarativa, in cui vengono fornite delle regole e si richiede al sistema di trovare una soluzione.

3. **Linguaggi basati su Regole e Relazioni:**
   
   - I linguaggi logici come Prolog sono utilizzati per creare sistemi che risolvono problemi deduttivamente attraverso il ragionamento logico.

4. **Ricerca della Soluzione:**
   
   - In un programma logico, si definiscono le relazioni tra i dati e si specifica quali regole devono essere soddisfatte per trovare una soluzione al problema.

5. **Esempi:**
   
   - Linguaggi come Prolog e Datalog sono esempi di linguaggi logici che seguono il paradigma logico.

# Programmazione funzionale

La programmazione funzionale in Python è uno stile di programmazione che tratta il calcolo principalmente tramite l'uso di funzioni e promuove l'immuabilità e l'espressione di operazioni senza effetti collaterali. In Python, questo stile è supportato, sebbene il linguaggio non sia puramente funzionale. Ecco una panoramica di alcuni strumenti e concetti chiave della programmazione funzionale in Python:

1. Funzioni di Ordine Superiore: Sono funzioni che prendono altre funzioni come argomenti o restituiscono funzioni come risultato. Questo è un concetto centrale nella programmazione funzionale.

2. map(): Questa funzione applica una funzione specificata a ciascun elemento di un iterabile (come una lista) e restituisce un iteratore con i risultati. È utile per applicare una trasformazione a tutti gli elementi di una sequenza.

3. reduce() (dal modulo functools): Importata da functools, reduce() applica ripetutamente una funzione a coppie di elementi in un iterabile, riducendoli a un singolo valore. È utile per operazioni cumulative come somme o prodotti.

4. eval(): Questa funzione esegue una stringa di codice Python e restituisce il risultato. È utile per eseguire codice generato dinamicamente, ma può essere pericoloso se usato impropriamente, poiché può eseguire codice arbitrario.

5. exec(): Simile a eval(), ma è usato per eseguire codice Python che non restituisce un valore, come istruzioni o definizioni di funzioni.

6. compile(): Questa funzione compila un codice sorgente Python in un oggetto codice che può essere eseguito da exec() o valutato da eval().

7. Modulo functools: Fornisce funzioni di alto livello che agiscono su o restituiscono altre funzioni. Include reduce(), ma anche partial() (per il partial application), lru_cache() (per la memorizzazione nella cache dei risultati delle funzioni), tra gli altri.

La programmazione funzionale in Python incoraggia l'uso di funzioni pure (funzioni che non hanno effetti collaterali e restituiscono un valore basato solo sui loro input) e l'immutabilità (evitare di modificare gli stati). Questi concetti contribuiscono a rendere il codice più prevedibile e facile da testare.

### Reduce

La funzione `reduce` del modulo `functools` in Python è utilizzata per applicare una funzione specifica in sequenza a tutti gli elementi di un'iterabile, riducendo la sequenza ad un unico valore. La funzione `reduce` prende due argomenti: la funzione da applicare e l'iterabile su cui applicarla.

```python
from functools import reduce

result = reduce(lambda x, y: x + y, [1, 2, 3, 4])
print(result)
```

- `lambda x, y: x + y` è una funzione lambda che prende due argomenti `x` e `y` e restituisce la loro somma.
- `[1, 2, 3, 4]` è la lista su cui verrà eseguita l'operazione.

Quindi, `reduce(lambda x, y: x + y, [1, 2, 3, 4])` somma tutti gli elementi nella lista in sequenza, utilizzando la funzione lambda fornita. Il risultato sarà `10`, poiché `1 + 2 = 3`, `3 + 3 = 6` e `6 + 4 = 10`. Questo esempio riduce la lista `[1, 2, 3, 4]` ad un singolo valore, sommando tutti i suoi elementi.

Altro esempio

```python
from functools import reduce

result = reduce(lambda x, y: x.union(set([y])), set())
```

Questa espressione è intesa per creare un set accumulando gli elementi usando `union` all'interno della funzione lambda, ma presenta un problema perché non è fornita alcuna sequenza di elementi su cui applicare questa operazione. La funzione `reduce` necessita di un'iterabile come secondo argomento per funzionare correttamente.
