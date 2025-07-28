#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <iostream>
#include "No.h"

class Lista {
    private:
        No* head;
        int tamanho;

    public:
        Lista(){
            head = nullptr;
            tamanho = 0;
        }
        ~Lista();

        bool vazia();
        int Tamanho();

        int elemento(int pos);
        bool modificar(int pos, int valor);

        bool inserir(int pos, int valor);
        bool remover(int pos);

        void imprimir();
};

#endif