#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <iostream>

class ListaSeq {
    public:
        ListaSeq(int tamanhoMax);
        ~ListaSeq();

        bool vazia();
        bool cheia();
        int  tamanho();
        int  indice(int dado);
        int  elemento(int pos);
        bool atualizar(int valor, int pos);
        bool inserir(int valor, int pos);
        int  remover(int pos);
        void exibe();

    private:
        int tamAtual;
        int tamMax;
        int *dados;
};

#endif
