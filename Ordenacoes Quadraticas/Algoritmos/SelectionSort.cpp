#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

void selectionSort(vector<int> &arr){
    int tam = (int)arr.size();

    for (int i = 0; i < tam; i++){
        int idx = i;
        for (int j = i+1; j < tam; j++){
            if (arr[j] < arr[idx]){
                idx = j;
            }
        }
        if (idx != i) {
            swap(arr[i], arr[idx]);
        }
    }
}

int main(){
    
    // freopen("./instancias-num/num.1000.1.in", "r", stdin);
    
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    double segundos = diff.count();
    cout << fixed << setprecision(7) << "Tempo (s): " << segundos << "\n";

    // freopen("resultado.out", "w", stdout);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
    
}