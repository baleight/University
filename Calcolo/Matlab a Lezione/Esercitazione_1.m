% Esercizio 2_1
% Cicli for
% facendo come si fa C++
% z = zeros(20,1); %si puo ommettere,Definiamo un vettore di 20 componenti 
for k = 1:20
    z(k) = k;
end
% Con la notazione vettoriale
z = 1:20;

%2_2Terzo esercizio
%vettore v con 100 compoente, la prima componete 3 e tuttele altre 10 alla
%-3
%con ciclo for
v(1)=3;
for k = 2:100
    v(k) = 1e-3; 
end 
%oppure
for k = 1 : 100
    if k == 1
        z(k)=3;
    else
        z(k)=10^(-3);
    end
end
%Notazione vettoriale, senza ciclo for
v(1)=3;
v(2:100)=1e-3;
v=1e-3*ones(100,1);
v(1)=3;

%Terzo esercizio
%Prende in ingresso un vettore e ne calcolo la norma euclidea.
x = [2,4];
% norma = radice 20 -> 2alla 2 + 4alla 2


function norma = norma2(x) %return/output si chiama norma
    len = length(x); %calcolo il numero delle compoentni x
 %inizializzazione norma
    norma = 0;
 %caclolo la somma dei quadrati
    for k = 1 : len
     norma = norma + x(k)^2;
    end
    norma = sqrt(norma); %square root
end

% Definizione dei vettori
x = [5; -8; 7];
y = [-3.2; 5e-4; 2.8; 3e2];
%calcolo w
w = ones(30, 1);
for i = 2:30
    w(i) = 3 * i / (i - 1);
end
%oppure
ivett = 2 : 30;
w = 3*ivett./(ivett-1);
%oppure
w = 3*(2:30)./(1:29);

w = [1 w]'; %concateno riga

% Calcolo delle norme usando la funzione norma2
norma_x = norma2(x);
normaEsatta_X = norma(x);%calcoliamo l'errore relativo
err = (abs (norma_x - normaEsatta_X)/normaEsatta_X);
disp(err) %se fa 0 si ha un algoritmo stabile perche l'errore relativo e' zero


norma_y = norma2(y);
norma_w = norma2(w);


%Quarto esercizio

function nrm = mynorm(x, p)
    n = length(x);
    norma = 0;

    % Verifica se p è minore di 1
    if p < 1
        error('Il valore di p deve essere maggiore o uguale a 1.'); %interompo la funzione
    
    % Calcola la norma in base al valore di p
    elseif p == inf
        %norma infinito
        norma = abs(x(1)); %valore asoluto di x
        for i=2 : n
            if abs(x(i)) > norma
            end
        end
    else
        %norma p
        for i=1 : n
            norma = norma + abs(x(i))^p;
    end
end
Esempio per testarlo:
x = [1 2 3];
mynorma (x,-1) %errore
mynorma (x,2) %3.7417 

mynorma (x,-1) %errore

