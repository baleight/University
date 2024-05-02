





% funzione per la risoluzione di un sistema triangolare superiore U*x=b
function [x, det_U] = solupper(U, b)
    % input: U, matrice nxn
    %        b, vettore nx1
    %DATI: u e b hanno le dimensioni corrette senza fare dei controlli
    %necessari, sono triangolari superiori
    n = lenght(b); % numeri delle righe, compnenti di b
    x = b; %inizializziamo x
    % Calcolo del determinante di U senza usare il comando det ma usando
    % la moltiplicazione degli elementi sulla diagonale
    d = 1;
    for i = 1 : n
        if abs(U(i,i)) < eps % In verita, quando molto vicino a zero, ordine alla -16 ma non e' uguale a zero, quindi molto piu picoclo della precisione di macchina, la divisione in un numero positivo diverso da zero molto picoclo puo dare un INF.
            error('Il determinante di U è zero, quindi U è singolare.');
        else     % se il controllo passa allora e' invertibile
            d = d*U(i,i);
        end
    end
    
    % Risoluzione del sistema tramite sostituzione all'indietro

    for i = n: -1:1
        elem_destra_diag= U(i,i+1:n); %elementi della riga iessima, che stanno a destra del elementi diagonale
        x(i) = b(i) - elem_destra_diag*x(i+1:n); %accedo al iessima, da i+1 a n dopo faccio il prodotto riga per colonna
        x(i) = x(i)/U(i,i);
    end
    % Si puo fare anche cosi
    x = zeros(n, 1);
    for i = n:-1:1
        sum = 0;
        for j = i+1:n
            sum = sum + U(i, j) * x(j);
        end
        x(i) = (b(i) - sum) / U(i, i);
    end
 
    % Output:x, vettore nx1, soluzione di U*x=b
    %        d, scalare 1x1, d=det(U) d conterra il determinante della matrice U

   
   
end
