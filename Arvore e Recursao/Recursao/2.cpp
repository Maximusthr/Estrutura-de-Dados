/*
2) Máximo em Lista
Crie uma função recursiva que receba uma lista de números e retorne o maior elemento.
Exemplo: maximo([3, 7, 2, 9, 1]) → 9.
*/

#include <bits/stdc++.h>

using namespace std;

// Global (outra lógica)
// int maximo(const vector<int> &arr, int tam){
//     if (tam == arr.size()){
//         return arr[tam];
//     }

//     int maior = maximo(arr, tam+1);
//     return max(maior, arr[tam]);
// }

int main(){
    cout << "Digite a quantidade de numeros: " << "\n";
    int n; cin >> n;

    cout << "Digite os valores: " << "\n";
    vector<int> num(n);
    for (auto &i : num) cin >> i;

    // Lambda
    auto maximo = [&](auto self, const vector<int> &arr, int tam) -> int {
        if (tam == arr.size()){
            return -LONG_MAX;
        }

        return max(arr[tam], self(self, arr, tam+1));
    };

    cout << "Maior elemento: " << maximo(maximo, num, 0) << "\n";
}