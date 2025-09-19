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


    // --- Teste 2: Altura da árvore (Questao 3) ---
    cout << "\n--- Teste 2: Altura da Arvore ---" << endl;
    cout << "Altura da arvore: " << altura(raiz) << endl; // Esperado: 3
    No* arvoreVazia = nullptr;
    cout << "Altura de uma arvore vazia: " << altura(arvoreVazia) << endl; // Esperado: 0
    No* arvoreSoRaiz = criarNo(10);
    cout << "Altura de uma arvore com um no: " << altura(arvoreSoRaiz) << endl; // Esperado: 1


    // --- Teste 3: Contagem de nós (Questao 4) ---
    cout << "\n--- Teste 3: Contagem de Nos ---" << endl;
    cout << "Total de nos na arvore: " << totalNos(raiz) << endl; // Esperado: 7
    // Nota: A função 'filhosNos' na verdade conta os nós FOLHA (sem filhos).
    cout << "Total de nos folha (funcao filhosNos): " << filhosNos(raiz) << endl; // Esperado: 4 (20, 40, 60, 80)
    cout << "Total de nos em arvore vazia: " << totalNos(arvoreVazia) << endl; // Esperado: 0
    cout << "Total de nos folha em arvore vazia: " << filhosNos(arvoreVazia) << endl; // Esperado: 0


    // --- Teste 4: Busca de elementos (Questao 5) ---
    cout << "\n--- Teste 4: Busca de Elementos ---" << endl;
    int valorBusca1 = 40;
    No* resultado1 = busca(raiz, valorBusca1);
    if (resultado1 != nullptr){
        cout << "Valor " << valorBusca1 << " encontrado na arvore." << endl; // Esperado: Encontrado
    } else {
        cout << "Valor " << valorBusca1 << " NAO encontrado na arvore." << endl;
    }

    int valorBusca2 = 99;
    No* resultado2 = busca(raiz, valorBusca2);
    if (resultado2 != nullptr){
        cout << "Valor " << valorBusca2 << " encontrado na arvore." << endl;
    } else {
        cout << "Valor " << valorBusca2 << " NAO encontrado na arvore." << endl; // Esperado: NAO Encontrado
    }

    // --- Teste 5: Menor e Maior elemento (Questao 6) ---
    cout << "\n--- Teste 5: Menor e Maior Elemento ---" << endl;
    No* menor = menor_elemento(raiz);
    No* maior = maior_elemento(raiz);
    if(menor) cout << "Menor elemento: " << menor->valor << endl; // Esperado: 20
    if(maior) cout << "Maior elemento: " << maior->valor << endl; // Esperado: 80


    // --- Teste 6: Verificação de BST (Questao 7) ---
    cout << "\n--- Teste 6: Verificacao de BST ---" << endl;
    cout << "A arvore principal e uma BST? " << (ehBST(raiz) ? "Sim" : "Nao") << endl; // Esperado: Sim

    // Criando uma arvore que NAO e uma BST manualmente para testar o caso 'false'
    No* raizNaoBST = criarNo(50);
    raizNaoBST->esquerda = criarNo(30);
    raizNaoBST->direita = criarNo(70);
    raizNaoBST->esquerda->direita = criarNo(65); // Erro! 65 > 50, nao pode estar na sub-arvore esquerda

    /* A arvore invalida:
             50
           /    \
          30     70
           \
            65  <- VIOLAÇÃO DA REGRA DA BST
    */
    cout << "A arvore invalida e uma BST? " << (ehBST(raizNaoBST) ? "Sim" : "Nao") << endl; // Esperado: Nao
    cout << "Uma arvore vazia e uma BST? " << (ehBST(arvoreVazia) ? "Sim" : "Nao") << endl; // Esperado: Sim


    cout << "\n===== FIM DOS TESTES =====" << endl;

    // Liberar a memória (opcional, mas boa prática)
    // Para um programa simples como este, o SO libera ao final,
    // mas em programas maiores, é essencial ter uma função de 'deleteTree'.
    // deleteTree(raiz);
    // deleteTree(arvoreSoRaiz);
    // deleteTree(raizNaoBST);
}   