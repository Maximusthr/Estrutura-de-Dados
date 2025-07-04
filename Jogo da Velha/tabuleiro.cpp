#include <bits/stdc++.h>

using namespace std;

int preencher(vector<vector<int>> &mat){

}

int main(){
    vector<vector<char>> mat(3, vector<char> (3));    

    int n = 3;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == ' '){
                int verif = 0;
                
                int sum = 0;
                // verifica a linha
                for (int k = 0; k < n; k++){
                    if (mat[i][k] == ' ' || mat[i][k] == '0') sum++;
                    else if (mat[i][k] == 'X'){
                        sum = 0;
                        break;
                    }
                }
                if (sum == 2) {
                    verif++;
                    sum = 0;
                }

                // verifica a coluna
                for (int k = 0; k < n; k++){
                    if (mat[k][j] == ' ' || mat[k][j] == '0') sum++;
                    else if (mat[k][j] == 'X'){
                        sum = 0;
                        break;
                    }
                }

                if (sum == 2){
                    verif++;
                    sum = 0;
                }

                // diagonais
                if (i != 1 && j != 1){
                    if (i == 0 && j == 0 || i == 2 && j == 2){
                        for (int k = 0; k < n; k++){
                            if (mat[k][k] == ' ' || mat[k][k] == '0') sum++;
                            else {
                                sum = 0;
                                break;
                            }
                        }
                        if (sum == 2){
                            verif++;
                            sum = 0;
                        }
                    }
                    else {
                        for (int k = 0; k < n; k++){
                            if (mat[k][2-k]  == ' ' || mat[k][2-k] == '0') sum++;
                            else {
                                sum = 0;
                                break;
                            }
                        }
                        if (sum == 2){
                            verif++;
                            sum = 0;
                        }
                    }
                }

                if (verif >= 2){
                    // return (i, j)
                }
            }
        }
    }
}

//     vector<vector<char>> mat(3, vector<char> (3));
    
//     mat = {{'x', 'x', 'x'}, {'x', 'o', 'o'}, {'o', 'o', 'o'}};


//     // bool ok = false;
//     // o = 1
//     // x = 5

//     // r1

//     // linhas
//     for (int i = 0; i < 3; i++){
//         int sum = 0;
//         int i_empty = -1;
//         int j_empty = -1;
//         for (int j = 0; j < 3; j++){
//             if (mat[i][j] == 'o') sum++;
//             if (mat[i][j] == ' ') {
//                 i_empty = i;
//                 j_empty = j;
//             }
//         }
//         if (sum == 2){
//             //return preencher(mat[i_empty][j_empty]);
//         }
//     }

//     // colunas
//     for (int i = 0; i < 3; i++){
//         int sum = 0;
//         int i_empty = -1;
//         int j_empty = -1;
//         for (int j = 0; j < 3; j++){
//             if (mat[j][i] == 'o') sum++;
//             if (mat[j][i] == ' '){
//                 j_empty = j;
//                 i_empty = i;
//             }
//         }
//         if (sum == 2) // return preencher(mat[j_empty][i_empty]);
//     }

//     // main diag
//     int temp = 0;
//     int i_empty = -1;
//     for (int i = 0; i < 3; i++){
//         temp += (mat[i][i] == 'o');
//         if (mat[i][i] == ' '){
//             i_empty = i;
//         }
//     }
//     if (temp == 2) // return preencher(mat[i_empty][i_empty]);

//     // sec diag
//     temp = 0;
//     i_empty = -1;
//     for (int i = 0; i < 3; i++){
//         temp += (mat[i][2-i]);
//         if (mat[i][2-i] == ' '){
//             i_empty = i;
//         }
//     }
//     if (temp == 2) // return preencher(mat[i_empty][2 - i_empty]);


//     // r2



//     // r3
//     if (mat[1][1] == ' '){
//         // return preencher(mat[1][1]);
//     }

//     // r4
//     if (mat[0][0] == 'x' && mat[2][2] == ' '){
//         //return preencher(mat[2][2]);
//     }
//     if (mat[2][0] == 'x' && mat[0][2] == ' '){
//         //return preencher(mat[0][2]);
//     }
//     if (mat[2][2] == 'x' && mat[0][0] == ' '){
//         //return preencher(mat[0][0]);
//     }
//     if (mat[0][2] == 'x' && mat[2][0] == ' '){
//         //return preencher(mat[2][0]);
//     }

//     // r5
//     if (mat[0][0] == ' '){
//         //return preencher(mat[0][0]);
//     }
//     if (mat[2][2] == ' '){
//         //return preencher(mat[2][2]);
//     }
//     if (mat[2][0] == ' '){
//         //return preencher(mat[2][0]);
//     }
//     if (mat[0][2] == ' '){
//         //return preencher(mat[0][2]);
//     }

//     // r6
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             if (mat[i][j] == ' '){
//                 // return preencher(mat[i][j]);
//             }
//         }
//     }

//     // campeao
    
//     // x == 15
//     // o == 3

//     // linhas

//     function  <bool(int)> vencedor = [] (int x) {
//         if (x == 3) return true;
//         else if (x == 15) return true;
//         else return false;
//     };

//     for (int i = 0; i < 3; i++){
//         int sum = 0;
//         for (int j = 0; j < 3; j++){
//             if (mat[i][j] == 'o') sum++;
//             else if (mat[i][j] == 'x') sum += 5;
//         }

//         if (vencedor(sum)){
//             if (sum == 3) // return ganhador('o');
//             else if (sum == 15) // return ganhador('x');
//         }
//     }

//     // colunas
//     for (int i = 0; i < 3; i++){
//         int sum = 0;
//         for (int j = 0; j < 3; j++){
//             if (mat[j][i] == 'o') sum++;
//             else if (mat[j][i] == 'x') sum += 5;
//         }
//         if (vencedor(sum)){
//             if (sum == 3) // return ganhador('o');
//             else if (sum == 15) // return ganhador('x');
//         }
//     }

//     // main diag
//     int temp = 0;
//     for (int i = 0; i < 3; i++){
//         temp += (mat[i][i] == 'o' ? 1 : 5);

//         if (vencedor(sum)){
//             if (sum == 3) // return ganhador('o');
//             else if (sum == 15) // return ganhador('x');
//         }
//     }

//     // sec diag
//     temp = 0;
//     for (int i = 0; i < 3; i++){
//         temp += (mat[i][2-i] == 'o' ? 1 : 5);

//         if (vencedor(sum)){
//             if (sum == 3) // return ganhador('o');
//             else if (sum == 15) // return ganhador('x');
//         }
//     }

//     // return ganhador('ninguem');
// }

