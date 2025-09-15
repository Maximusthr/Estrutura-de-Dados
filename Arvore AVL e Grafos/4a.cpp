/*
4. Considere o grafo não direcionado representado pela lista de adjacência:
A: B, C
B: A, D, E
C: A, F
D: B
E: B, F
F: C, E
Construa a matriz de adjacência e a ordem de percurso dos vértices (em ordem alfabética) usando: (a) Busca em
Largura (BFS) iniciando em A e (b) Busca em Profundidade (DFS) iniciando em A.
*/

// USANDO BFS

#include <bits/stdc++.h>

using namespace std;

int main(){
    int matriz[6][6]; // A-F

    memset(matriz, 0, sizeof(matriz));

    vector<vector<int>> lista(6);
    vector<bool> vis(6);

    // Caminhos: {A - B}, {A - C}, {B - D}, {B - E}, {C - F}, {E - F}
    vector<pair<char, char>> caminho = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}};
    for (int i = 0; i < 6; i++){
        matriz[caminho[i].first - 'A'][caminho[i].second - 'A'] = 1;
        matriz[caminho[i].second - 'A'][caminho[i].first - 'A'] = 1;

        lista[caminho[i].first - 'A'].push_back(caminho[i].second - 'A');
        lista[caminho[i].second - 'A'].push_back(caminho[i].first - 'A');
    }


    vector<char> ordem;

    ordem.push_back(0 + 'A');

    queue<int> fila;
    fila.push(0);
    vis[0] = true;

    while(!fila.empty()){
        int v = fila.front();

        fila.pop();

        for (auto vizinhos : lista[v]){
            if (!vis[vizinhos]){
                fila.push(vizinhos);
                ordem.push_back(vizinhos + 'A');
                vis[vizinhos] = true;
            }
        }
    }

    cout << "Ordem de impressao: ";
    for (auto &i : ordem) cout << i << " ";
    cout << "\n\n";

    cout << "Matriz de Adjacencia:" << "\n";
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cout << matriz[i][j] << " \n"[j == 5];
        }
    }
}