#include <bits/stdc++.h>

using namespace std;

// Questao 5
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

No* criarNo(int valor){
    No* novoNo = new No();

    novoNo -> valor = valor;
    novoNo -> esquerda = nullptr;
    novoNo -> direita = nullptr;

    return novoNo;
};

No* inserirNo(No* raiz, int valor){
    if (raiz == NULL) {
        return criarNo(valor); // raiz vazia
    }

    if (raiz->valor > valor){
        // adicionar para o lado esquerdo
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    }
    else {
        // adicioanr para o lado direito
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz; // retornamos a raiz intocável
}

// Questao 6
bool busca(No* raiz, int valor){
    if (raiz == nullptr) return false;
    if (raiz->valor == valor) return true;

    if (valor < raiz->valor){
        // valor vai estar para a esquerda
        return busca(raiz->esquerda, valor);
    }

    // valor vai estar para a direita
    return busca(raiz->direita, valor);
}

// Questao 7
void preOrdem(No* node){
    if (node != nullptr){
        cout << node->valor << " ";
        preOrdem(node->esquerda);
        preOrdem(node->direita);
    }
}

void inOrdem(No* node){
    if (node != nullptr){
        inOrdem(node->esquerda);
        cout << node->valor << " ";
        inOrdem(node->direita);
    }
}

void posOrdem(No* node){
    if (node != nullptr){
        posOrdem(node->esquerda);
        posOrdem(node->direita);
        cout << node->valor << " ";
    }
}

int main(){
    cout << "===== INICIANDO CASOS DE TESTE =====" << endl;

    // --- Teste 1: Criando uma árvore e testando inserção (Questao 1) e travessias (Questao 2) ---
    cout << "\n--- Teste 1: Insercao e Travessias ---" << endl;
    No* raiz = nullptr;
    raiz = inserirNo(raiz, 50);
    inserirNo(raiz, 30);
    inserirNo(raiz, 70);
    inserirNo(raiz, 20);
    inserirNo(raiz, 40);
    inserirNo(raiz, 60);
    inserirNo(raiz, 80);

    /* A arvore resultante deve ser:
             50
           /    \
          30     70
         / \    / \
        20  40 60  80
    */

    cout << "Pre-Ordem: ";
    preOrdem(raiz); // Esperado: 50 30 20 40 70 60 80
    cout << endl;

    cout << "In-Ordem (deve estar ordenado): ";
    inOrdem(raiz); // Esperado: 20 30 40 50 60 70 80
    cout << endl;

    cout << "Pos-Ordem: ";
    posOrdem(raiz); // Esperado: 20 40 30 60 80 70 50
    cout << endl;

    // --- Teste 4: Busca de elementos (Questao 5) ---
    cout << "\n--- Teste 4: Busca de Elementos ---" << endl;
    int valorBusca1 = 40;
    bool encontrado1 = busca(raiz, valorBusca1);
    if (encontrado1){
        cout << "Valor " << valorBusca1 << " encontrado na arvore." << endl; // Esperado: Encontrado
    } else {
        cout << "Valor " << valorBusca1 << " NAO encontrado na arvore." << endl;
    }

    int valorBusca2 = 99;
    bool encontrado2 = busca(raiz, valorBusca2);
    if (encontrado2){
        cout << "Valor " << valorBusca2 << " encontrado na arvore." << endl;
    } else {
        cout << "Valor " << valorBusca2 << " NAO encontrado na arvore." << endl; // Esperado: NAO Encontrado
    }

    // Criando uma arvore que NAO e uma BST manualmente para testar o caso 'false'
    No* raizNaoBST = criarNo(50);
    raizNaoBST->esquerda = criarNo(30);
    raizNaoBST->direita = criarNo(70);
    raizNaoBST->esquerda->direita = criarNo(65); // Erro! 65 > 50, nao pode estar na sub-arvore esquerda

    cout << "\n===== FIM DOS TESTES =====" << endl;
}