```bash
touc prova.k

vim prova.k
        def f(x) x+1
        deF f(x y) x+1:

.kcomp prova.k
```

as -o prova.o prova.s

//compilazione fino in fondo senza il main program

Valuta questa funzione:
morecomplex.k

```bash
extern x():
extern y():
extern printval(z);
def f(x y) x=5 , y=7:

def helper() f(x()), y()):
def main() printval(helper());
//binding nome valore, 
```

Proviamo 

```bash
../kcomp dumb.k
make clean
rm prova.*
cp -r set()
```

Come fare una funzione nel parser:

```bash
  def fibonacci(n)
      n<2 ? 1 :
      { 
      var a = fibonacci(n-2);
      var b = fibonacci(n-2)
      a+b;
      }
  //dalla frase all'assioma
  ... vardefs ... => ... vardefs; binding .. => ... binding ; binding ...
```
