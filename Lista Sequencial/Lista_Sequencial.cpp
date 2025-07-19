#include <bits/stdc++.h>

using namespace std;

// Criação da lista vazia
// Lista vazia?
// Lista cheia?
// Tamanho da lista
// Atualizar ou obter um elemento em uma pos da lista
// Indice do elemento na lista
// Inserir elemento
// Remover elemento

struct ListaSeq{
    int tamAtual;
    int tamMax;
    int *dados;

    ListaSeq(int tamanhoMax){
        tamAtual = 0;
        tamMax = tamanhoMax;
        dados = new int[tamMax];
    }

    ~ListaSeq(){
        delete[] dados;
    }

    bool vazia(){
        return (tamAtual == 0);
    }
    bool cheia(){
        return (tamAtual == tamMax);
    }
    int tamanho(){
        return tamAtual;
    }

    int indice(int dado){
        for (int i = 0; i < tamAtual; i++){
            if (dados[i] == dado){
                return (i+1);
            }
        }
        return -1;
    }

    int elemento(int pos){
        if ((pos > tamAtual) || (pos <= 0)){
            return -1;
        }

        return dados[pos-1];
    }


    bool atualizar(int valor, int pos){
        if (pos > tamAtual || pos <= 0){
            return false;
        }

        dados[pos-1] = valor;
        return true; 
    }

    bool inserir(int valor, int pos){
        if ((pos > tamAtual+1) || (pos <= 0) || (cheia())){
            return false;
        }
        
        for (int i = tamAtual; i >= pos; i--){
            dados[i] = dados[i-1];
        }

        dados[pos-1] = valor;
        tamAtual++;
        return true;
    }

    int remover(int pos){
        if (vazia() || (pos > tamAtual) || (pos <= 0)){
            return -1;
        }

        int valor = dados[pos-1];

        for (int i = pos; i < tamAtual; i++){
            dados[i-1] = dados[i];
        }

        tamAtual--;
        return (valor);
    }

    void exibe(){
        if (vazia()){
            cout << "Lista Vazia" << "\n";
        }

        for (int i = 0; i < tamAtual; i++){
            cout << dados[i] << " ";
        }
        cout << "\n";
    }
};

int main(){
    cout << "Qual sera o tamanho da lista?\n";
    int capacidade; cin >> capacidade;

    ListaSeq lista(capacidade);

    // Definindo a quantidade de operacoes na lista
    cout << "Quantas operacoes tera a lista?\n";
    int oper; cin >> oper;

    cout << "MENU" << "\n";
    cout << "-\n";
    cout << "1 - Lista Vazia" << "\n";
    cout << "-\n";
    cout << "2 - Lista Cheia" << "\n";
    cout << "-\n";
    cout << "3 - Tamanho da Lista" << "\n";
    cout << "-\n";
    cout << "4 - Indice de um elemento na lista (Insira o elemento)" << "\n";
    cout << "-\n";
    cout << "5 - Elemento da lista (Insira o indice)" << "\n";
    cout << "-\n";
    cout << "6 - Atualizando elemento da lista (Insira elemento, indice)" << "\n";
    cout << "-\n";
    cout << "7 - Inserindo elemento na lista dado a posicao (Insira elemento, indice)" << "\n";
    cout << "-\n";
    cout << "8 - Removendo elemento da lista (insira o indice)" << "\n";
    cout << "\n";
    cout << "9 - Exibe todos os elementos da lista" << "\n";
    cout << "\n";
    
    while(oper--){

        int x; cin >> x;

        int elemento, indice;

        switch(x){
            // lista vazia?
            case 1:
                cout << (lista.vazia() ? "SIM" : "NAO") << "\n\n";
                break;
            
            // lista cheia?
            case 2:
                cout << (lista.cheia() ? "SIM" : "NAO") << "\n\n";
                break;
            
            // tamanho da lista
            case 3:
                cout << lista.tamanho() << "\n\n";
                break;

            // Indice de um elemento na lista
            case 4:
                cin >> elemento;
                indice = lista.indice(elemento);

                if (indice == -1) cout << "Nao foi possivel achar o elemento na lista" << "\n\n";
                else cout << "Indice do elemento: " << indice << "\n\n";
                break;

            // Elemento dado um indice
            case 5:
                cin >> indice;

                if (lista.elemento(indice) == -1) cout << "Elemento nao encontrado" << "\n\n";
                else cout << "Elemento: " << lista.elemento(indice) << "\n\n";
                break;
            
            // atualizando elemento da lista
            case 6:
                cin >> elemento >> indice;

                cout << (lista.atualizar(elemento, indice) ? "Atualizado" : "Erro") << "\n\n";
                break;
            
            // Inserir elemento na lista dado a posicao
            case 7:
                cin >> elemento >> indice;

                cout << (lista.inserir(elemento, indice) ? "Elemento inserido" : "Nao foi possivel inserir") << "\n\n"; 
                break;
            
            // Remover elemento dado a posicao
            case 8:
                cin >> indice;

                cout << (lista.remover(indice) == -1 ? "Nao foi possivel remover" : "Elemento  Removido.") << "\n\n";
                break;

            case 9:
                lista.exibe();
                break;
            
            default:
                cout << "Comando invalido" << "\n";
        }
    }

    cout << "\n";
}
