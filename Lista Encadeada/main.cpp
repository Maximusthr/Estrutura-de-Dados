#include "Lista_Encadeada.h"
#include <iostream>

using namespace std;

int main(){

    Lista *lista = new Lista();
    
    cout << "Lista criada!" << "\n";
    cout << (lista->vazia() ? "Lista vazia!" : "Lista nao vazia!") << "\n";
    
    cout << "O tamanho da lista eh: " << lista->Tamanho() << "\n";

    lista->inserir(1, 5);
    lista->inserir(2, 16);
    lista->inserir(3, 325);
    lista->inserir(4, 21);
    lista->inserir(5, 43);
    cout << "Elementos inseridos: " << "\n";
    lista->imprimir();

    cout << "Elemento na posicao 1: " << lista->elemento(1) << "\n\n";
    cout << "Modificando elemento da posicao 1" << "\n";
    lista->modificar(1, 91);
    cout << "Novo elemento na posicao 1: " << lista->elemento(1) << "\n";
    
    cout << "Removendo elemento da posicao 2" << "\n\n";
    lista->remover(2);
    cout << "Lista apos remocao: ";
    lista->imprimir();
    
    cout << "Tamanho final da lista: " << lista->Tamanho() << "\n";
    cout << "A lista esta vazia? " << (lista->vazia() ? "Sim" : "Nao") << "\n";

    cout << "Lista atual: ";
    lista->imprimir();

    cout << "Removendo todos!" << "\n\n";
    int tam = lista->Tamanho();
    for (int i = 0; i < tam; i++){
        lista->remover(1);
    }

    cout << "A lista esta vazia? " << (lista->vazia() ? "Sim" : "Nao") << "\n";

   
    delete(lista);
}

