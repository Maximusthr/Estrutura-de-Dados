#include "Lista_Encadeada.h"
using namespace std;

Lista::~Lista() {
    No* atual = head;
    while (atual) {
        No* tmp = atual->getProximo();
        delete atual;
        atual = tmp;
    }
}

bool Lista::vazia(){
    return tamanho == 0;
}

int Lista::Tamanho(){
    return tamanho;
}

int Lista::elemento(int pos){
    if (vazia() || pos < 1 || pos > tamanho) return -1;
    No* aux = head;
    int cont = 1;
    while (cont < pos) {
        aux = aux->getProximo();
        cont++;
    }
    return aux->getValor();
}

bool Lista::modificar(int pos, int valor) {
    if (vazia() || pos < 1 || pos > tamanho) return false;
    No* aux = head;
    int cont = 1;
    while (cont < pos) {
        aux = aux->getProximo();
        cont++;
    }
    aux->setValor(valor);
    return true;
}

bool Lista::inserir(int pos, int valor) {
    if (pos < 1 || pos > tamanho + 1) return false;

    if (pos == 1) {
        No* novo = new No();
        novo->setValor(valor);
        novo->setProximo(head);
        head = novo;
    } 
    else {
        No* aux = head;
        int cont = 1;
        while (cont < pos - 1) {
            aux = aux->getProximo();
            cont++;
        }
        No* novo = new No();
        novo->setValor(valor);
        novo->setProximo(aux->getProximo());
        aux->setProximo(novo);
    }

    tamanho++;
    return true;
}


bool Lista::remover(int pos) {
    if (vazia() || pos < 1 || pos > tamanho) return false;

    No* alvo = nullptr;
    if (pos == 1) {
        alvo = head;
        head = head->getProximo();
    } else {
        No* aux = head;
        int cont = 1;
        while (cont < pos - 1) {
            aux = aux->getProximo();
            cont++;
        }
        alvo = aux->getProximo();
        aux->setProximo(alvo->getProximo());
    }
    
    tamanho--;
    delete alvo;
    return true;
}

void Lista::imprimir(){
    No* aux = head;
    while (aux != nullptr) {
        cout << aux->getValor() << (aux->getProximo() ? " " : "\n");
        aux = aux->getProximo();
    }
}
