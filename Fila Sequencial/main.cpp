// Fila sequencial com incremento circular

#include <iostream>
#include "Fila_Sequencial.h"

using namespace std;

void imprimeMenu() {
    cout << "\nMENU DE OPERACOES:\n";
    cout << "1 - Verificar se a fila esta vazia\n";
    cout << "2 - Verificar se a fila esta cheia\n";
    cout << "3 - Obter o primeiro elemento da fila\n";
    cout << "4 - Inserir elemento na fila\n";
    cout << "5 - Remover elemento da fila\n";
    cout << "Escolha a opcao: ";
}

int main() {
    cout << "Qual sera o tamanho maximo da fila?\n";
    int capacidade; cin >> capacidade;

    FilaSeq fila(capacidade);

    cout << "Quantas operacoes voce deseja executar?\n";
    int oper; cin >> oper;

    while (oper--) {
        imprimeMenu();

        int opcao; cin >> opcao;

        int elemento;
        bool sucesso;

        switch (opcao) {

            case 1:
                cout << "Fila vazia: ";
                cout << (fila.empty() ? "SIM" : "NAO") << "\n";
                break;

            case 2:
                cout << "Fila cheia: ";
                cout << (fila.full() ? "SIM" : "NAO") << "\n";
                break;

            case 3:
                cout << "Elemento da Fila: " << fila.front() << "\n";
                break;

            case 4:
                cout << "Informe o elemento a ser inserido na Fila: ";
                cin >> elemento;
                sucesso = fila.push(elemento);
                cout << (sucesso ? "Inserido com sucesso na Fila.\n" : "Falha ao inserir na Fila.\n");
                break;

            case 5:
                cout << "Removendo da Fila: ";
                if (fila.pop()) cout << "Elemento removido.\n";
                else cout << "Fila vazia.\n";
                break;

            default:
                cout << "Comando invalido.\n";
                break;
        }
    }

    return 0;
}
