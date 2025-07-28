#include <iostream>
#include "No.h"

using namespace std;

No::~No(){}

int No::getValor(){
    return valor;
}

No* No::getProximo(){
    return proximo;
}

void No::setValor(int valor){
    this->valor = valor;
}

void No::setProximo(No* proximo){
    this->proximo = proximo;
}
