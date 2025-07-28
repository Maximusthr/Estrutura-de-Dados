#ifndef NO_H
#define NO_H

#include <iostream>

class No {
    private:
        int valor;
        No* proximo;

    public:
        No(){
            valor = 0;
            proximo = nullptr;
        }
        ~No();

        int getValor();
        No* getProximo();

        void setValor(int valor);
        void setProximo(No* proximo);
};

#endif