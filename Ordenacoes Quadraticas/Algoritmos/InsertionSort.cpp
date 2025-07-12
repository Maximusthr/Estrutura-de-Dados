#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

void insertionSort(vector<int> &arr){
    int tam = (int)arr.size();

    for (int i = 1; i < tam; i++){
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    
    // freopen("./instancias-num/num.10000.1.in", "r", stdin);
    
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    double segundos = diff.count();
    cout << fixed << setprecision(7) << "Tempo (s): " << segundos << "\n";
    
    // freopen("resultado.out", "w", stdout);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }

}