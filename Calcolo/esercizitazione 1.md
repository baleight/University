```matlab
function norma = norma2(x) %return/output si chiama norma
    len = length(x); %calcolo il numero delle compoentni x

 %inizializzazione norma
norma = 0;
 %caclolo la somma dei quadrati
for k = 1 : len
    norma = norma + x(k)^2;
end
norma = sqrt(norma); %square root

% Definizione dei vettori
x = [5; -8; 7];
y = [-3.2; 5e-4; 2.8; 3e2];
w = ones(30, 1);
for i = 2:30
    w(i) = 3 * i / (i - 1);
end

% Calcolo delle norme usando la funzione norma2
norma_x = norma2(x);
norma_y = norma2(y);
norma_w = norma2(w);

% Calcolo delle norme usando la funzione norm di MATLAB
norma_x_matlab = norm(x);
norma_y_matlab = norm(y);
norma_w_matlab = norm(w);
%Calcoliamo l'errore relativo tra le norme




% Visualizzazione dei risultati
disp('Norma di x:');
disp(['Norma2 calcolata: ', num2str(norma_x)]);
disp(['Norma2 di MATLAB: ', num2str(norma_x_matlab)]);
disp(' ');

disp('Norma di y:');
disp(['Norma2 calcolata: ', num2str(norma_y)]);
disp(['Norma2 di MATLAB: ', num2str(norma_y_matlab)]);
disp(' ');

disp('Norma di w:');
disp(['Norma2 calcolata: ', num2str(norma_w)]);
disp(['Norma2 di MATLAB: ', num2str(norma_w_matlab)]);
```

```matlab
%vettore x = (5,-8,7) la trasposta e y = (-3.3,5*10-4,2.8,3*10^2) trasposta

function norma = calcola_norma(x, p)
    % Controlla se p è minore di 1
    if p < 1
        error('Il valore di p deve essere maggiore o uguale a 1.');
    end

    % Calcola la norma corrispondente
    if p == inf
        norma = max(abs(x));
    else
        norma = sum(abs(x).^p)^(1/p);
    end
end
```

 Scrivere una function che, dato in ingresso un vettore x ∈ Rn ed uno scalare p ≥ 1, restituisce
‖x‖p =( n∑i=1|xi|p) 1p , se p 6 = inf
‖x‖∞ = max 1≤i≤n |xi|, se p = inf .
Se il dato in ingresso p `e minore di 1, la function stampa un messaggio di errore
