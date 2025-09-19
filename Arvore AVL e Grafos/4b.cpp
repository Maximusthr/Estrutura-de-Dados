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

// USANDO DFS

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

    stack<int> pilha;
    pilha.push(0);
    vis[0] = true;
    
    vector<char> ordem;
    while(!pilha.empty()){
        int v = pilha.top();
        pilha.pop();

        ordem.push_back(v + 'A');

        // precisamos inverter os nós de v, pois
        // como trabalhamos em LIFO, estaremos
        // empilhando do menor para o maior (não mais após a inversão)
        reverse(lista[v].begin(), lista[v].end());

        for (auto vizinhos : lista[v]){
            if (!vis[vizinhos]){
                pilha.push(vizinhos);
                vis[vizinhos] = true;
            }
        }
    }

    // Versão lambda recursiva:
    // Não precisamos inverter a ordem dos vizinhos
    /*
    auto dfs = [&] (auto self, int u) -> void {
        if (!vis[u]) vis[u] = true;

        ordem.push_back(u + 'A');
        
        for (auto v : lista[u]){
            if (!vis[v]){
                // ordem.push_back(v + 'A');
                self(self, v);
            }
        }
    };
    dfs(dfs, 0);
    */
    
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