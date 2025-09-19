#include <bits/stdc++.h>

using namespace std;

// Questao 1
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

// Questao 2
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

// Questao 3
int altura(No* node){
    if (node == nullptr){
        return 0;
    }

    int altura_esq = altura(node->esquerda);
    int altura_dir = altura(node->direita);
    return max(altura_esq, altura_dir) + 1;
}

// Questao 4
// a)
int totalNos(No* node){
    if (node == nullptr) return 0;

    return 1 + totalNos(node->esquerda) + totalNos(node->direita);
}

// b)
int filhosNos(No* node){
    if (node == nullptr) return 0;

    if (node->direita == nullptr && node->esquerda == nullptr){
        return 1;
    }

    return filhosNos(node->direita) + filhosNos(node->esquerda);
}

// Questao 5
No* busca(No* raiz, int valor){
    if (raiz == NULL || raiz->valor == valor){
        return raiz;
    }
    
    if (raiz->valor > valor){
        // valor vai estar para a esquerda
        return busca(raiz->esquerda, valor);
    }

    // valor vai estar para a direita
    return busca(raiz->direita, valor);
}

// Questao 6
No* menor_elemento(No* node){
    if (node == nullptr){
        return node;
    }
    if (node->esquerda == nullptr){
        return node;
    }
    return menor_elemento(node->esquerda);
}

No* maior_elemento(No* node){
    if (node == nullptr){
        return node;
    }
    if (node->direita == nullptr){
        return node;
    }
    return maior_elemento(node->direita);
}

// Questao 7
// Função auxiliar recursiva que verifica a propriedade da BST com limites
bool verificarBSTAux(No* node, int min, int max) {
    // Caso base: uma árvore vazia é uma BST.
    if (node == NULL) {
        return true;
    }

    // O valor do nó deve estar dentro dos limites [min, max].
    if (node->valor <= min || node->valor >= max) {
        return false;
    }

    // Verifica recursivamente as subárvores, atualizando os limites:
    // Para a subárvore esquerda, o valor máximo agora é o valor do nó atual.
    // Para a subárvore direita, o valor mínimo agora é o valor do nó atual.
    return verificarBSTAux(node->esquerda, min, node->valor) &&
           verificarBSTAux(node->direita, node->valor, max);
}

// Função principal que inicia a verificação
bool ehBST(No* raiz) {
    // A primeira chamada usa os limites mais amplos possíveis para um inteiro.
    return verificarBSTAux(raiz, INT_MIN, INT_MAX);
}

int main(){
    
    
}   