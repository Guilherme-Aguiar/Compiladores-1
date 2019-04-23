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

void trans(map<int,map<char, vector<int>>> tabtrans, string entrada,int nEstadosFinais, int estadosFinais[], int estadoAtual);

int main() {

    int estados,
        simbolos;
    char *alfabeto;
    
    cin >> estados >> simbolos;

    alfabeto = alocarVetorChar(simbolos);

    for(int i = 0; i < simbolos; i++) {
        cin >> alfabeto[i];
    }
    map<int,map<char, vector<int>>> tabtrans;

    for(int i = 0; i < estados; i++){
        int posicao,
            nDestinos,
            destino; 
        char letra;
        for(int j = 0; j < simbolos; j++){
            cin >> posicao >> letra >> nDestinos;
            for(int k = 0; k < nDestinos; k++){
                cin >> destino;
                tabtrans[posicao][letra].push_back(destino);
            }
                
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

    trans(tabtrans,entrada,nEstadosFinais,finais,estadoAtual);
    cout << "Rejeito\n";
    

    return 0;
}

void trans(map<int,map<char, vector<int>>> tabtrans, string entrada,int nEstadosFinais, int estadosFinais[], int estadoAtual) {
    for(auto i : tabtrans[estadoAtual][entrada[0]]) {
        if(entrada.length() == 1){
            for(int j = 0; j < nEstadosFinais; j++) {
                if(estadosFinais[j] == i) {
                    cout << "Aceito\n";
                    exit(EXIT_SUCCESS);
                } else {
                    continue;
                }
            }
        }
        trans(tabtrans,entrada.substr(1),nEstadosFinais,estadosFinais,i);   
    }


    
}

