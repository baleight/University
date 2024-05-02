.globl start
.text
start:
li t0, 10 
li t1, 12
li t2, 14

primoif: #primo if
ble t0, t1, condizione1 #vero se no si fa sulla prossima riga se false
addi t3,t0,0
j secondoif #jUMP

secondoif: #Secondo if
ble t3,t2,condizione2 #if(w<z)
add t3,t3,0 #w=w
j end

condizione1:
addi t3,t1,0 #w=y
j secondoIF

condizione2:
addi t3,t2,0 #w=z
j end
#stampo il valore piu alto sulla console
end:
li a7, 1
add a0,t3,zero
ecall
#esco dal programma
addi x17, x0, 10
ecall
