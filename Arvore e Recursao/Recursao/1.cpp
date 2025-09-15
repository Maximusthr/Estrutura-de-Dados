/*
1) Inverter String
Escreva uma função recursiva que receba uma string e retorne a string invertida.
Exemplo: inverter("recursao") → "oasrucer"
*/

#include <bits/stdc++.h>

using namespace std;

void inverter(string &s, int tam, string &inv){
    if (tam < 0){
        return;
    }

    inv += s[tam];
    inverter(s, tam - 1, inv);
}

int main(){
    string s; cin >> s;
    string invertida = "";

    inverter(s, (int)s.size(), invertida);

    cout << invertida << "\n";
}