#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using ll = long long;

void insertionSort(vector<ll> &arr){
    int tam = (int)arr.size();

    for (int i = 1; i < tam; i++){
        ll key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(vector<ll> &arr){
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
    
    freopen("./instancias-num/num.100000.4.in", "r", stdin);
    
    int n; cin >> n;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    
    vector<ll> copy1, copy2;
    copy1 = copy2 = arr;

    auto start1 = chrono::high_resolution_clock::now();
    insertionSort(copy1);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff1 = end1 - start1;
    
    auto start2 = chrono::high_resolution_clock::now();
    selectionSort(copy2);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;


    double segundos1 = diff1.count();
    double segundos2 = diff2.count();

    cout << fixed << setprecision(7);
    
    freopen("./resultados/num.100000.4.out", "w", stdout);

    cout << "InsertionSort - Tempo (s): " << segundos1 << "\n";
    cout << "SelectionSort - Tempo (s): " << segundos2 << "\n";
    for (int i = 0; i < n; i++){
        cout << copy1[i] << "\n";
    }
    
}