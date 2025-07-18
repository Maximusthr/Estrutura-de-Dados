#include <bits/stdc++.h>

using namespace std;

// criação da lista vazia
// lista vazia?
// lista cheia?
// tamanho da lista
// atualizar ou obter um elemento em uma pos da lista
// indice do elemento na lista
// inserir elemento
// remover elemento

struct ListaSeq{
    // int dados[];
    int tamAtual = 0;
    static const int tamMax = 100;
    int dados[tamMax];

    bool vazia(){
        return (tamAtual == 0);
    }
    bool cheia(){
        return (tamAtual == tamMax);
    }
    int tamanho(){
        return tamAtual;
    }

    int elemento(int pos){
        // 1-indexado
        if ((pos > tamAtual) || (pos <= 0)){
            return -1;
        }

        return dados[pos-1];
    }

    int indice(int dado){
        for (int i = 0; i < tamAtual; i++){
            if (dados[i] == dado){
                return (i+1);
            }
        }
        return -1;
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
};

int main(){
    ListaSeq lista;

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        lista.inserir(x, i+1);
    }

    for (int i = 0; i < n; i++){
        cout << lista.elemento(i+1) << " ";
    }

    cout << "\n";
}
