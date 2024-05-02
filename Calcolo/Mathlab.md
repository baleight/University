# Mathlab

Ecco una lista dei comandi essenziali di MATLAB che possono aiutarti a iniziare:

1. **Operazioni di base:**
   
   - `+`, `-`, `*`, `/`: Operazioni aritmetiche di base.
   - `^`: Elevamento a potenza.
   - `=`: Assegnazione di valori a variabili.
   - Espressioni logiche
     <img src="file:///C:/Users/baleo/AppData/Roaming/marktext/images/2024-03-15-14-37-13-image.png" title="" alt="" width="220">
   - Variabili predefinite
     - ans: valore ultima operazione eseguita che non e' stata assegnata
     - eps: precisione di macchina
     - realmax: massimo numero reale positivo rappresentabile
     - realmin: minimo numero
     - inf: un numero maggiore di realmax
     - Nan: Not A Number un numero indeterminato
     - compute: tipo di computer 

2. **Manipolazione di array:**
   
   - `:`: Generazione di sequenze e indicizzazione.
   - `length(A)`: Restituisce la lunghezza massima tra il numero di righe e colonne di A.
   - `size(A)`: Restituisce la dimensione di A.
   - `zeros(n,m)`, `ones(n,m)`, `eye(n)`: Creazione di array di zeri, uni o di una matrice identità.

3. **Manipolazione di matrici:**
   
   - [ 3 4 5 ; 6 7 8 ; 6 , 3 , 5]
   
   - Come specificare il valore A[i,j]? A(righe,col) Es: A(2,3) -> 5 
   
   - x = [1 , 3; 4, 5] , a=[5 ,5; 5,5] Y = [ x a ] vengono affiancati, **x** a sx e **a** a dx
   
   - Le matr. sono impilate dal alto verso il basso e da sinistra verso destra: se io metto A(2) esce il valore 6
   
   - Trasposta(Scambaite le righe colonne) si fa con l'apostrofo: b=[5 3 4] -> b' 
   
   - rand(3) fa una matrice con valori randomici 3x3
   
   - zeros(2,3) matrice 2x3 con tutti zero oppure ones(3,4) stessa cosa con 1
   
   - Definire vettori che sono euistanzi di un certo valore Es: -3 : 3
     
     <img src="file:///C:/Users/baleo/Pictures/Typedown/81667c1a-98e2-4494-aaf7-c2d74ef8a9cb.png" title="" alt="81667c1a-98e2-4494-aaf7-c2d74ef8a9cb" style="zoom:50%;">
     Un altro esempio: -3 : 0.5 : 3 -> 0.5 e l'intervallo
   
   - A (2:3,2:3)
   
   - Somma e sottrazione tra matrici
   
   - Moltiplicazone
   
   - Divisione
   
   - Elevamento a potenza?

4. **Funzioni matematiche:**
   
   - `sum(A)`: Somma degli elementi.
   
   - `mean(A)`: Media degli elementi.
   
   - `median(A)`: Mediana degli elementi.
   
   - `std(A)`: Deviazione standard degli elementi.
   
   - `factorial(10)` : fattoriale
   
   - Attenti:  le funzioni non modificano le variabile di ingresso, non prendo come in c++ il puntatore ma il valore
     
     ```mathlab
     
     ```

5. **Grafici:**
   
   - `plot(x,y)`: Grafico di y in funzione di x.
   - `title('titolo')`: Aggiunge un titolo al grafico.
   - `xlabel('x')`, `ylabel('y')`: Etichette degli assi.
   - `legend('etichetta')`: Aggiunge una legenda.

6. **Controllo di flusso:**
   
   - `if`, `elseif`, `else`: Strutture condizionali.
     
     ```matlab
     n = input(’Inserisci un numero reale’);
     if n < 0
     disp(’Il numero e’’ negativo’)
     elseif n > 0
     disp(’Il numero e’’ negativo’)
     else
     disp(’Il numero e’’ nullo’)
     end
     ```
   
   - `for`: Ciclo for.
   
   - `while`: Ciclo while.
   
   - `break`: Interruzione di un ciclo.
   
   - `continue`: Passa alla successiva iterazione del ciclo.

7. **Funzioni e script:**
   
   - `function`: Definisce una nuova funzione.
     
     ```matlab
     function [output] = nomefuction(input)
         %codice
     end
     %per la chiamata
     [output] = nomefunction(input)
     %esempio
     function M = massa(A,B,C)
     end
     M = (A + B + C)/3;
     ```
   
   - `return`: Restituisce un valore e termina la funzione.

8. **Input/Output:**
   
   - `disp(A)`: Visualizza il contenuto di A.
   - fprintf('Ciao %f',nome)
   
   <img src="file:///C:/Users/baleo/Pictures/Typedown/e3d9b78f-fb18-46f4-a505-d9376bfd30f3.png" title="" alt="e3d9b78f-fb18-46f4-a505-d9376bfd30f3" style="zoom:50%;">
   
   Esempio noi sappiamo che tutti i dati sono double manel formato short e,
   
   - `input('prompt')`: Prende un input dall'utente.
   - `load('file.mat')`: Carica i dati da un file .mat.
   - `save('file.mat', 'A')`: Salva la variabile A in un file .mat.

9. **Debugging:**
   
   - `dbstop`: Imposta un punto di interruzione.
   - `dbcont`: Riprende l'esecuzione.
   - `dbquit`: Esce dalla modalità di debug.
   - clc: pulire la schermata
   - whos: per conoscere la dimensione delle entita
   - 
