/*
8. Implemente a estrutura de dados para manipular árvore AVL com métodos:
(a) inserir(valor)
(b) altura(no)
(c) fator_balanceamento(no)
(d) rotações: rotacao_direita(no), rotacao_esquerda(no)
(e) balanceamento automático após inserção
(f) Verificação de Balanceamento
Adicione um método esta_balanceada() que percorra toda a árvore e verifique se o fator de balanceamento de todos os
nós está entre -1 e 1.
*/

#include <bits/stdc++.h>

using namespace std;

struct No{
    int valor;
    int altura;
    No* esquerda;
    No* direita;
};

class ArvoreAVL {
    private:
        No* raiz;

        // b) Altura
        int altura(No* no){
            if (no == nullptr){
                return 0;
            }
            return no->altura;
        }

        // c) Balanceamento
        int fator_balanceamento(No* no){
            if (no == nullptr){
                return 0;
            }
            // subárvore direita - subárvore esquerda
            return altura(no->direita) - altura(no->esquerda);
        }

        No* criarNo(int valor){
            No* novoNo = new No();
            novoNo->valor = valor;
            novoNo->esquerda = nullptr;
            novoNo->direita = nullptr;
            novoNo->altura = 1;
            return novoNo;
        }

        // d) Rotação à direita
        No* rotacao_direita(No* x){
            cout << "Rotacao a direita em " << x->valor << "\n";
            
            No* y = x->esquerda;
            No* aux = y->direita;

            // rotação
            y->direita = x;
            x->esquerda = aux;

            // atualiza a altura dos nós afetados
            x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
            y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

            return y; // nova raiz
        }

        // d) Rotação à esquerda
        No* rotacao_esquerda(No* x){
            cout << "Rotacao a Esquerda em " << x->valor << "\n";
            
            No* y = x->direita;
            No* aux = y->esquerda;

            // rotação
            y->esquerda = x;
            x->direita = aux;

            // atualiza a altura dos nós afetados
            x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
            y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

            return y; // nova raiz
        }

        // a) & e) Inserção com balanceamento automático
        No* inserir(No* no, int valor) {
            if (no == nullptr) {
                return criarNo(valor);
            }

            // Supondo que nao exista duplicatas:
            if (valor < no->valor) {
                no->esquerda = inserir(no->esquerda, valor);
            } else if (valor > no->valor) {
                no->direita = inserir(no->direita, valor);
            }

            // Atualiza a altura
            no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

            // Fator de Balanceamento
            int fb = fator_balanceamento(no);

            // 4. Se o nó estiver desbalanceado, aplica uma das 4 rotações

            // Esquerda-Esquerda (Rotação Simples à Direita)
            if (fb < -1 && valor < no->esquerda->valor) {
                return rotacao_direita(no);
            }

            // Direita-Direita (Rotação Simples à Esquerda)
            if (fb > 1 && valor > no->direita->valor) {
                return rotacao_esquerda(no);
            }

            // Esquerda-Direita (Rotação Dupla)
            if (fb < -1 && valor > no->esquerda->valor) {
                no->esquerda = rotacao_esquerda(no->esquerda);
                return rotacao_direita(no);
            }

            // Direita-Esquerda (Rotação Dupla)
            if (fb > 1 && valor < no->direita->valor) {
                no->direita = rotacao_direita(no->direita);
                return rotacao_esquerda(no);
            }

            // Retorna o nó (potencialmente nova raiz da subárvore)
            return no;
        }

        // f) Árvore balanceada?
        bool esta_balanceada(No* no) {
            if (no == nullptr) {
                return true;
            }

            // Verifica o FB do nó atual
            int fb = fator_balanceamento(no);
            if (abs(fb) > 1) {
                cout << "Verificacao falhou! No " << no->valor 
                        << " tem FB = " << fb << std::endl;
                return false;
            }

            // Verifica as subárvores esquerda e direita
            return esta_balanceada(no->esquerda) && esta_balanceada(no->direita);
        }

        // Função auxiliar para imprimir a árvore em ordem (para verificação)
        void imprimirEmOrdem_recursivo(No* no) {
            if (no != nullptr) {
                imprimirEmOrdem_recursivo(no->esquerda);
                std::cout << no->valor << " ";
                imprimirEmOrdem_recursivo(no->direita);
            }
        }
    public:
        ArvoreAVL() {
            raiz = nullptr;
        }

        // a) Inserir um valor
        void inserir_valor(int valor) {
            cout << "Inserindo " << valor << "..." << "\n";
            raiz = inserir(raiz, valor);
        }

        // f) Verificar balanceamento
        bool esta_balanceada() {
            return esta_balanceada(raiz);
        }

        // Imprimir a árvore
        void imprimirEmOrdem() {
            cout << "Arvore em ordem: ";
            imprimirEmOrdem_recursivo(raiz);
            cout << "\n";
        }
};

int main(){
    ArvoreAVL arvore;

    cout << "--- Construindo a arvore AVL ---" << "\n";
    arvore.inserir_valor(10);
    arvore.inserir_valor(20);
    arvore.inserir_valor(30); // Deve causar uma rotação à esquerda em 10
    arvore.imprimirEmOrdem();
    cout << "--------------------------" << "\n";
    
    arvore.inserir_valor(40);
    arvore.inserir_valor(50); // Deve causar uma rotação à esquerda em 30
    arvore.imprimirEmOrdem();
    cout << "--------------------------" << "\n";

    arvore.inserir_valor(25); // Deve causar uma rotação dupla (direita-esquerda)
    arvore.imprimirEmOrdem();
    cout << "--------------------------" << "\n";

    cout << "\n--- Verificacao Final ---" << "\n";
    if (arvore.esta_balanceada()) {
        cout << "A arvore esta perfeitamente balanceada." << "\n";
    } else {
        cout << "A arvore NAO esta balanceada." << "\n";
    }

}