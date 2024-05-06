## Latex

1. **Document Class**: Il comando `\documentclass` è il primo comando di un documento LaTeX e specifica il tipo di documento che si intende creare, come `article`, `report`, `book`, o `letter`.
   
   ```latex
   \documentclass{article}
   ```

2. **Preambolo**: Il preambolo è la parte del documento compresa tra `\documentclass` e `\begin{document}`. È qui che vengono inserite le impostazioni globali del documento, come i pacchetti da utilizzare, le impostazioni di formattazione e i comandi personalizzati.
   
   ```latex
   \usepackage{graphicx} % Per l'inserimento di immagini
   \usepackage{amsmath}  % Per la matematica avanzata
   ```

3. **Inizio e Fine del Documento**: Il testo del documento LaTeX viene inserito tra i comandi `\begin{document}` e `\end{document}`.
   
   ```latex
   \begin{document}
   Contenuto del documento...
   \end{document}
   ```

4. **Titolo e Autore**: Per inserire il titolo, l'autore e la data del documento, si utilizzano i comandi `\title`, `\author` e `\date`.
   
   ```latex
   \title{Il mio primo documento LaTeX}
   \author{Il Mio Nome}
   \date{\today}
   ```

5. **Creare il Titolo**: Per creare il titolo nel documento, è necessario utilizzare il comando `\maketitle`.
   
   ```latex
   \maketitle
   ```

6. **Sezioni e Sottosezioni**: Per suddividere il documento in sezioni e sottosezioni, si utilizzano i comandi `\section`, `\subsection` e `\subsubsection`.
   
   ```latex
   \section{Introduzione}
   Questa è la sezione introduttiva.
   
   \subsection{Sottosezione}
   Questa è una sottosezione.
   ```

7. **Formattazione del Testo**: LaTeX offre vari comandi per formattare il testo, come `\textbf` per il grassetto, `\textit` per l'italico e `\underline` per il sottolineato.
   
   ```latex
   \textbf{Testo in grassetto}
   \textit{Testo in corsivo}
   \underline{Testo sottolineato}
   ```

8. **Elenco Puntato**: Per creare un elenco puntato, si utilizza l'ambiente `itemize`.
   
   ```latex
   \begin{itemize}
   \item Primo elemento
   \item Secondo elemento
   \end{itemize}
   ```

9. **Elenco Numerato**: Per creare un elenco numerato, si utilizza l'ambiente `enumerate`.
   
   ```latex
   \begin{enumerate}
   \item Primo elemento
   \item Secondo elemento
   \end{enumerate}
   ```

10. **Inserire Immagini**: Per inserire un'immagine nel documento, si utilizza il pacchetto `graphicx` e il comando `\includegraphics`.
    
    ```latex
    \usepackage{graphicx}
    ...
    \begin{figure}
    \centering
    \includegraphics{immagine.png}
    \caption{Didascalia dell'immagine}
    \label{fig:immagine}
    \end{figure}
    ```

Questi sono solo alcuni dei comandi di base in LaTeX. Con questi, sei pronto per iniziare a creare documenti semplici. Con l'esperienza, potrai imparare altri comandi e tecniche per creare documenti più complessi e personalizzati.
