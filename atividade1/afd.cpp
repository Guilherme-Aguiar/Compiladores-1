#include <bits/stdc++.h>

using namespace std;

char* alocarVetorChar(int Linhas){ 
 
    int i;
 
    char *m = (char*)malloc(Linhas * sizeof(char*)); 
 
    for (i = 0; i < Linhas; i++){ 
        m[i]= 0; 
    }
    return m; 
}

int* alocarVetorInt(int Linhas){ 
 
    int i;
 
    int *m = (int*)malloc(Linhas * sizeof(int*)); 
 
    for (i = 0; i < Linhas; i++){ 
        m[i]= 0; 
    }
    return m; 
}

int main() {

    int estados,
        simbolos;
    char *alfabeto;
    
    cin >> estados >> simbolos;

    alfabeto = alocarVetorChar(simbolos);

    for(int i = 0; i < simbolos; i++) {
        cin >> alfabeto[i];
    }
    map<int,map<char, int>> tabtrans;

    for(int i = 0; i < estados; i++){
        int posicao,
            destino; 
        char letra;
        for(int j = 0; j < simbolos; j++){
            cin >> posicao >> letra >> destino;
            tabtrans[posicao][letra] = destino;
        }
    }
    int inicial,
        nEstadosFinais,
        *finais;
    cin >> inicial >> nEstadosFinais;
    finais = alocarVetorInt(nEstadosFinais);

    for(int i = 0; i < nEstadosFinais; i ++){
        cin >> finais[i];
    }

    string entrada;
    cin >> entrada;

    int estadoAtual = inicial;

    for(char& caracter : entrada){
        estadoAtual = tabtrans[estadoAtual][caracter];
    }
        
    
    for(int i = 0; i < nEstadosFinais; i++)
        if(estadoAtual == finais[i]){
            cout << "Aceito" << '\n';
            return 0;
        }
    cout << "Rejeito" << '\n';        
    return 0;
}