#include "Fila_Sequencial.h"

FilaSeq::FilaSeq(int tamanhoMax) : inicio(0), fim(0), contador(0), tamMax(tamanhoMax), dados(new int[tamanhoMax]) {}

FilaSeq::~FilaSeq() {
    delete[] dados;
}

bool FilaSeq::empty(){
    return contador == 0;
}

bool FilaSeq::full(){
    return contador == tamMax;
}

int FilaSeq::front(){
    if (empty()) throw std::runtime_error("Fila vazia: nao eh possivel acessar o elemento da frente.");

    return dados[inicio];
}

bool FilaSeq::push(int valor) {
    if (full()) return false;

    dados[fim] = valor;

    fim = (fim + 1) % tamMax;

    contador++;
    return true;
}

bool FilaSeq::pop() {
    if (empty()) return false;

    inicio = (inicio + 1) % tamMax;

    contador--;

    return true;
}
