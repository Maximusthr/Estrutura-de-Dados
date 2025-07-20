// Lista_Sequencial.cpp
#include "Lista_Sequencial.h"

ListaSeq::ListaSeq(int tamanhoMax) : tamAtual(0), tamMax(tamanhoMax), dados(new int[tamanhoMax]) {}

ListaSeq::~ListaSeq() {
    delete[] dados;
}

bool ListaSeq::vazia(){
    return tamAtual == 0;
}

bool ListaSeq::cheia(){
    return tamAtual == tamMax;
}

int ListaSeq::tamanho(){
    return tamAtual;
}

int ListaSeq::indice(int dado){
    for (int i = 0; i < tamAtual; i++) {
        if (dados[i] == dado) {
            return i + 1;
        }
    }
    return -1;
}

int ListaSeq::elemento(int pos){
    if (pos <= 0 || pos > tamAtual) {
        return -1;
    }
    return dados[pos - 1];
}

bool ListaSeq::atualizar(int valor, int pos) {
    if (pos <= 0 || pos > tamAtual) {
        return false;
    }
    dados[pos - 1] = valor;
    return true;
}

bool ListaSeq::inserir(int valor, int pos) {
    if (pos <= 0 || pos > tamAtual + 1 || cheia()) {
        return false;
    }
    for (int i = tamAtual; i >= pos; --i) {
        dados[i] = dados[i - 1];
    }
    dados[pos - 1] = valor;
    tamAtual++;
    return true;
}

int ListaSeq::remover(int pos) {
    if (vazia() || pos <= 0 || pos > tamAtual) {
        return -1;
    }
    int valor = dados[pos - 1];
    for (int i = pos; i < tamAtual; ++i) {
        dados[i - 1] = dados[i];
    }
    tamAtual--;
    return valor;
}

void ListaSeq::exibe(){
    if (vazia()) {
        std::cout << "Lista Vazia\n";
        return;
    }
    for (int i = 0; i < tamAtual; i++) {
        std::cout << dados[i] << " ";
    }
    std::cout << "\n";
}
