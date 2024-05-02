function [L,U] = gauss1(A)
% Function per calcolare la fattorizzazione LU di una matrice A
% Input: A, matrice nxn
% Output: L, matrice nxn triangolare inferiore con diagonale unitaria
%         U, matrice nxn triangolare superiore, L*U = A

% Dimensioni di A
[m,n] = size(A);
if m ~= n
    error('La matrice non è quadrata')
end

% Algoritmo di Gauss
for k = 1 : n-1 % passo del metodo
    if abs(A(k,k)) < eps
        error('Fattorizzazione non calcolabile')
    else
        %qui metto l'alternativa che sta sotto
        for i = k+1 : n % indice di riga
            A(i,k) = A(i,k)/A(k,k); % moltiplicatore
            for j = k+1 : n % indice di colonna
                A(i,j) = A(i,j)-A(k,j)*A(i,k);
            end
        end
    end
end
U = triu(A); % fattore prendeno la parte triangolo superiore di a e la diagonale di a
L = (A-U) + eye(n); %triangolo inferiore tutto i moltiplicatore del metodo, A-U nella parte superioire e' 0
% sommo i zeri della superioire a n
%Un alternativa dei due for gaous e usare : che accede alla sotto colonna 

A(k+1:n,k) = A(k+1:n,k)/A(k,k)%tutti e solo i moltiplicatori al passo k, mi calcola tutti i moltiplicatori di gaus
A(k+1:n,k+1:n) = A(k+1:n,k+1:n) - A(k,k+1:n)*A(k,k+1:n); %la trasformazione di gauss



% Script per verificare la correttezza di gauss1

A = [1e-15 1 -2; 1 4 1; 2 5 6]; %matrice A
x = ones(3,1);
b = A*x; %vettori dei termini noti

[L,U] = gauss1(A);
y = L \ b;
xc = U \ y;

norm(x-xc)/norm(x)
%Output:
%Ce un warning perche? instabilita numerica, prendo un sistea 3x3 presenta
%u elmento piccolo.

la funzione di matlab lu [Les,Ues]=lu(A):
Quando facciamo i confronti tra Les e l
CI ACCORGIAMO che i due fattori non sono uguali, les non e' triangolo inferiore e sono tutti piu piccoli di 1
L e' invece ha gli elementi piu grandi di 1. lu calcola con scambio di righe con pivoting ecco perche.


           