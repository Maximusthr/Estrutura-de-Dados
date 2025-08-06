#ifndef FILA_SEQUENCIAL_H
#define FILA_SEQUENCIAL_H

#include <iostream>

class FilaSeq {
    public:
        FilaSeq(int tamanhoMax);
        ~FilaSeq();
        
        bool empty();
        bool full();

        bool push(int valor); 
        int  front(); 
        bool pop(); 

    private:
        int inicio;
        int fim;
        int contador;

        int tamMax;
        int *dados;
};

#endif
