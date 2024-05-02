![2bfd2c28-1a47-4535-b1dd-a6e1f8718f5f](file:///C:/Users/baleo/Pictures/Typedown/2bfd2c28-1a47-4535-b1dd-a6e1f8718f5f.png)

### Esercizio 1:

Scrivere una classe Cane che definisca i seguenti attributi:

* zampe (default 4)

* coda (default True)

* età (default=0)

* sessoE i seguenti metodi

* abbaia

* cammina

* corri

```python
class Cane():

      def __init__(self, eta=0, sesso='', zampe = 4, coda = True): #attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
          self.__priv_ = 1
          self.eta = eta
          self.sesso = sesso
          self.zampe = zampe
          self.coda = coda
      def abbaia(self):
          print("bau")

      def cammina(self):
          print("cammina")

      def corri(self):
          print("corre")

a = Cane(40,'M',5,False) print(a.sesso) #Stampa M a.abbaia() #bau a.eta=20 print(a.eta) #stampa 20

       print("corre")
```

##### Esercizio 2:

Aggiungere un attributo di classe che conti il numero di volte che è stata istanziatala classe stessa.Aggiungere un metodo chiamabile direttamente sulla classe che riporti tale numero

```python
class Cane():
    nIstanza = 0
    def __new__(cls, *arg, **kwargs): # istanza l'oggetto senza crearlo'
        cls.nIstanza = cls.nIstanza + 1
        print(f"_Nuovo Ogetto: {cls.nIstanza}")
        return object.__new__(cls)
    def __init__(self, eta=0, sesso='', zampe = 4, coda = True):#attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        Cane.nIstanza = Cane.nIstanza + 1
        print(f"Inizializzazione {self.nIstanza}")
        self.incremento()
        print(f"incremento con funzione {self.nIstanza}")
        self.__class__.nIstanza = self.__class__.nIstanza + 1
        print(f"incremento in privato {self.nIstanza}")
    @classmethod
    def incremento(cls):
        cls.nIstanza = cls.nIstanza + 1
a = Cane()
b = Cane()
c = Cane()
print(a.nIstanza)
```

##### Esercizio 3

Aggiungere due attributi privati a Cane:

* malato (default False)

* spavaldo (default False)Aggiungere dei getters e setters per accederli e modificarli (nel modo classico)

```python
class Cane():
    def __init__(self, spavaldo=False,malato=False):  # attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        self.__spavaldo = spavaldo
        self.__malato = malato

    def getMalato(self):
        return self.__malato

    def getSpavaldo(self):
        return self.__spavaldo

    def setMalato(self, mod):
        self.__malato = mod

    def setSpavaldo(self, mod):
        res = self.__spavaldo + mod
        return res


a = Cane()
print(a.malato) #non vede la variabile perche privata
a.setMalato(True)
print(a.getMalato())  # stampa True

```

##### Esercizio 4

Modificare i getters e setters usando @propertyBis: Definire un comportamento speciale per l’attributo malato:ritorno il valore di malato MA se spavaldo è True ritorna sempre False

```python
class Cane():
    def __init__(self,spavaldo=False, malato=False): #attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        self.__spavaldo = spavaldo
        self.__malato = malato
    @property
    def malato(self):
        if (self.__spavaldo != True):
            return self.__malato
        return False
    @property
    def spavaldo(self):
        return self.__spavaldo
    @malato.setter
    def malato(self, mod):
        self.__malato = mod
    @spavaldo.setter
    def spavaldo(self, mod):
        self.__spavaldo = mod
a=Cane()
print(a.malato)
a.malato=True
print(a.malato)
```

##### Esercizio 5

definire un comportamento per l’operatore + tra due Cane. Per esempio nasce un cucciolo.Prevedere comportamenti diversi in base agli attributi età e sesso dei Cane coinvolti. doc: https://docs.python.org/3/reference/datamodel.html#object.__add__

```python
class Cane():
    def __init__(self,
                 sesso='C'):  # attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        self.sesso = sesso

    def __add__(self, other):  # (self + other)
        if (self.sesso != other.sesso and type(self) == type(other)):
            return type(self)('F')
        return

mastino = Cane('M')
volpino = Cane('F')
cucciolo = mastino + volpino  # uguale a mastino.__add__(volpino)
print(cucciolo.sesso)#None
```

##### Esercizio 6

Fare in modo che la classe Cane erediti da una classe Animale. Creare anche una classe Gatto che eredita da Animale.

Capire quali metodi mettere nelle classe Animale e quali in Cane/Gatto

```python
class Animale:
    def __init__(self,eta=0, sesso='M', zampe = 4, coda = True,spavaldo=False, malato=False): #attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        self.eta = eta
        self.sesso = sesso
        self.zampe = zampe
        self.coda = coda
        self.__spavaldo = spavaldo
        self.__malato = malato

    def cammino(self):
        print('cammino')

    def getMalato(self):
        return self.__malato

    def getSpavaldo(self):
        return self.__spavaldo

    def setMalato(self, mod):
        res = self.__malato + mod
        return res

    def setSpavaldo(self, mod):
        res = self.__spavaldo + mod
        return res

class Gatto(Animale):
    def __init__(self, razza='egiziano'):
        self.razza = razza
    def miagola(self):
        print('miaao')

class Cane(Animale):
    def __init__(self, eta=0, sesso='', zampe = 4, coda = True): #attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        self.eta = eta
        self.sesso = sesso
        self.zampe = zampe
        self.coda = coda
    def abbaia(self):
        print('bau')
```

##### Esercizio 7

Rendere Animale una classe astratta.
Definire un metodo astratto “fai_verso” (al posto di miagola/abbaia) e implementarlonelle classi figlie.

```python
from abc import ABC, abstractmethod

class Animale(ABC):
    def __init__(self, eta=0, sesso='M', zampe=4, coda=True, spavaldo=False, malato=False):
        self.eta = eta
        self.sesso = sesso
        self.zampe = zampe
        self.coda = coda
        self.__spavaldo = spavaldo
        self.__malato = malato

    @abstractmethod
    def fai_verso(self):
        pass

class Gatto(Animale):
    def __init__(self, razza='egiziano'):
        super().__init__()  # Call the constructor of the base class
        self.razza = razza

    def fai_verso(self):
        print("Miao!")  # Implementation of the abstract method


class Cane(Animale):
    def __init__(self, razz=+"volpino"): #attributi di istanza non attributi di classe che vengono condivisi in tutte le classi
        super().__init__()  # Call the constructor of the base class
        self.razza = razza

    def fai_verso(self):
        print("Miao!")

# Create an instance of Gatto e cane
gatto = Gatto()
gatto.fai_verso()

cane = Cane()
cane.fai_verso()
```

##### Esercizio 8

Trattare l’attributo “malato” come descrittore (che considera anche l’attributo “spavaldo”).

```python
class Cane():
    def __init__(self, malato="giallo",spavaldo="uno"): #attributi di istanza non attributi di classe che vengono condivisi in tutte le classi

        self.__spavaldo=spavaldo
        self.__malato=malato

    @property
    def malato(self):
        return "sono in property"

    @property
    def spavaldo(self):
        return "sono in property"

    @malato.setter
    def malato(self, mod):
        self.__malato = mod

    @malato.getter
    def malato(self):
        if (self.__spavaldo == "uno"):
            return self.__malato+self.__spavaldo
        return self.__malato

    @spavaldo.getter
    def spavaldo(self):
        return self.__spavaldo

    @spavaldo.setter
    def spavaldo(self, mod):
        self.__spavaldo = mod

cane = Cane()
cane.malato = "rosso"
print("L'oggetto malato: ",cane.malato)
cane.spavaldo = "due"
print(f"L'oggetto spavaldo: {cane.spavaldo}")
print("L'oggetto malato: ",cane.malato)

```

##### Esercizio 9

Provare a scrivere un decoratore che si comporti come @property.
(limitarsi alle funzionalità get per accedere al dato tralasciando le funzionalità set edelete)

```python
class myproperty:
    def __init__(self, fun):
        self.fun = fun
        self.descriptor = None

    def setter(self, setfun):
        self.descriptor = setfun
        return self
#    def __get__(self, instance, owner):
#        return self.fun(instance)
#    def __set__(self, instance, value):
#        if self.descriptor:
#            self.descriptor(instance, value)
#        else:
#            raise AttributeError("Can't set attribute")

@myproperty
def prova(self):
    return "ciao"

@prova.setter
def setprova(self, value):
    print("ok")

class Cane:
    pass

cane = Cane()

cane.prova = 10  # Usa il descrittore per impostare il valore
print(cane.prova)  # Stampa "ciao"



```

# 
