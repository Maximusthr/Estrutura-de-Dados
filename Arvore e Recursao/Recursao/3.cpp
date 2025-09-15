/*
3) Soma de Lista Recursiva
Escreva uma função recursiva que calcule a soma dos elementos de uma lista.
Exemplo: soma([1, 2, 3, 4]) → 10.
*/

#include <bits/stdc++.h>

using namespace std;

int soma(const vector<int> &num, int tam){
    if (tam == num.size()){
        return 0;
    }

    return num[tam] + soma(num, tam+1);
}

int main(){
    cout << "Digite a quantidade de numeros: " << "\n";
    int n; cin >> n;

    cout << "Digite os valores: " << "\n";
    vector<int> num(n);
    for (auto &i : num) cin >> i;
 
    cout << soma(num, 0) << "\n";
}