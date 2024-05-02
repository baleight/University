Esercizi d'esame

###### Quali istruzione assebly corrisponde alla stringa esadecimale:

0x0073C433

- Cosa la compone?
  
  - Traduciamola in formato binario
    `0000 0000 0111 0011 1100 0100 0011 0011`
  
  - Otteniamo il nostro Opcode da gli ultimi 7 bit: 011 0011
    Appartiene alla famiglia R -> le istruzioni che hanno come operandi sempre dei registri
  
  - Grazie alla famiglia sappiamo come dividere il binario
    ![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-01-19-21-56-image.png)
  
  - Guardiamo prima `OPCODE > f3 > f7`
  
  - Con f3 100 sappiamo che e' un **xor** 
  
  - Dobbiamo inserire gli operandi rd l registro di destinazione e' 01000
    rs1 e il primo operando e rs2 e il secondo operando
  
  - I registri sono 32 tramite la codifica di 01000 sappiamo che il registro corrisponde a x8, Ricorda se abbiamo una sola cifra sicuro che sara una potenza di $2^3$
  
  - Per Rs1  e Rs2 stessa cosa: 00111, 00111 che corrispondono x7 x7
  
  L'istruzione e' xor $x_8 , x_7 , x_7$ ->raddopio x7 e lo aggiungo in x8

###### Assembly > codifica in Hex

```assembly
bne x5, x6, 0xFE9
```

0xFE9 e' un immediato con 3 cifre esadeciamali

**bne**appartiene alla famiglia sb che ah questo formato:<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-05-01-20-34-28-image.png" title="" alt="" width="512">

da lui la configurazione dei bit

- Converti 0xFE9 in binario -> 1111 1110 1001
  Questi 12 bit sono sparsi negli altri campi, 

- Formiamo i bit del immediato-> 1111110

- 5 bit de opcode i bit che vanno da 4 a 1-> 10011

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-01-20-53-04-WhatsApp%20Image%202024-05-01%20at%2020.52.23_b6bbafb5.jpg)

- per $x_5$ traduciamo il numero 5 -> 00101 che rappresenta rs1
  <img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-05-01-20-23-56-image.png" title="" alt="" width="175"> in rs2 mettiamo quindi 00101

- per rs1 00110

- bne ha come istruzione opcode(ce la do il prof) 1100111 e funct3 001

- Convertiamo il numero ottenuto in esadecimale

- ![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-01-20-30-49-image.png)

```c
1111110 00110 00101 001 10011 1100111 -> 0xfc6299e7
```


