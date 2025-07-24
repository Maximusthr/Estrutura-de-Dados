#include <iostream>
#include "Lista_Sequencial.h"

using namespace std;

void imprimeMenu() {
    cout << "\nMENU DE OPERACOES:\n";
    cout << "1 - Verificar se a lista esta vazia\n";
    cout << "2 - Verificar se a lista esta cheia\n";
    cout << "3 - Obter tamanho da lista\n";
    cout << "4 - Buscar indice de um elemento\n";
    cout << "5 - Obter elemento por indice\n";
    cout << "6 - Atualizar elemento na posicao\n";
    cout << "7 - Inserir elemento na posicao\n";
    cout << "8 - Remover elemento da posicao\n";
    cout << "Escolha a opcao: ";
}

int main() {
    cout << "Qual sera o tamanho maximo da lista?\n";
    int capacidade; cin >> capacidade;

    ListaSeq lista(capacidade);

    cout << "Quantas operacoes voce deseja executar?\n";
    int oper; cin >> oper;

    while (oper--) {
        imprimeMenu();

        int opcao; cin >> opcao;

        int elemento, idx;
        bool sucesso;

        switch (opcao) {

            case 1:
                cout << (lista.vazia() ? "SIM" : "NAO") << "\n";
                break;

            case 2:
                cout << (lista.cheia() ? "SIM" : "NAO") << "\n";
                break;

            case 3:
                cout << "Tamanho atual: " << lista.tamanho() << "\n";
                break;

            case 4:
                cout << "Informe o elemento a buscar: ";
                cin >> elemento;
                idx = lista.indice(elemento);
                if (idx == -1) cout << "Elemento nao encontrado.\n";
                else cout << "Posicao do elemento: " << idx << "\n";
                break;

            case 5:
                cout << "Informe a posicao: ";
                cin >> idx;
                elemento = lista.elemento(idx);
                if (elemento == -1)
                    cout << "Posicao invalida.\n";
                else
                    cout << "Elemento na posicao " << idx << ": " << elemento << "\n";
                break;

            case 6:
                cout << "Informe novo valor e posicao: ";
                cin >> elemento >> idx;
                sucesso = lista.atualizar(elemento, idx);
                cout << (sucesso ? "Atualizado.\n" : "Erro ao atualizar.\n");
                break;

            case 7:
                cout << "Informe elemento e posicao para insercao: ";
                cin >> elemento >> idx;
                sucesso = lista.inserir(elemento, idx);
                cout << (sucesso ? "Inserido com sucesso.\n" : "Falha ao inserir.\n");
                break;

            case 8:
                cout << "Informe o indice para remocao: ";
                cin >> idx;
                elemento = lista.remover(idx);
                if (elemento == -1) cout << "Falha ao remover.\n";
                else cout << "Elemento removido: " << elemento << "\n";
                break;

            default:
                cout << "Comando invalido.\n";
        }
    }

    return 0;
}
