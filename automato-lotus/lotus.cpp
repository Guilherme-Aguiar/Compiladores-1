#include <bits/stdc++.h>

using namespace std;

struct Lotus {
    char entrada;
    string desempilha, empilha;
};

bool megaflag = false;

void transicao(stack<string> pilha, vector<Lotus> lotus, string fita);

int main() {
    vector<Lotus> lotus;
    stack<string> pilha;
    string fita;

    lotus.push_back({'a',"A","AA"});
    lotus.push_back({'a',"?","A"});
    lotus.push_back({'a',"B","E"});
    lotus.push_back({'b',"B","BB"});
    lotus.push_back({'b',"?","B"});
    lotus.push_back({'b',"A","E"});

    while(cin >> fita) {
        megaflag = false;
        transicao(pilha,lotus,fita);
        cout << '\n';
    }
    return 0;
}

void transicao(stack<string> pilha, vector<Lotus> lotus, string fita) {
    stack<string> outraPilha = pilha;
    for(unsigned int i = 0; i < lotus.size(); i++) {
        if(megaflag)
            break;
        if(fita.empty()){
            if(pilha.empty()) {
                cout << "Aceito\n";
                megaflag = true;
            }
            else {
                cout << "Rejeito\n";
                megaflag = true;
            }
        }else {
            if(fita[0] == lotus[i].entrada) {
                if(pilha.empty()){
                    if(lotus[i].desempilha == "?"){
                        pilha.push(lotus[i].empilha);
                    }          
                }
                else if(pilha.top() == lotus[i].desempilha){
                    pilha.pop();
                    if(lotus[i].empilha != "E"){
                        pilha.push(lotus[i+1].empilha);
                        pilha.push(lotus[i+1].empilha);
                    }else {
                    }
                }

                if(pilha.size() != outraPilha.size()) {
                    if(!pilha.empty()){
                        stack <string> segunda = pilha;
                        while(!segunda.empty()){
                            cout << segunda.top();
                            segunda.pop();
                        }
                        cout <<'\n';
                    }else {
                        cout <<"nil\n";
                    }
                    transicao(pilha,lotus,fita.substr(1));
                }         
            }
        }
        
    }
}