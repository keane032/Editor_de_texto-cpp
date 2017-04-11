#include <iostream>
#include"snode.h"
#include"editor.h"
#include<stack>
using namespace std;
int main(){
    editor edit;
    char letra;
    stack<STRUCT> pilha;
    while (true) {
        cout << "digite $ para sair \n";
        cin >> letra;
        if(letra == 'B'){
            snode *node = edit.apag();
            if(node != nullptr){
                pilha.push(STRUCT('B',node->letra));
                delete node;
            }

        }
        else if(letra =='>'){
            edit.moverD();
            pilha.push('>');
        }
        else if(letra == '<'){
            edit.moverE();
            pilha.push('<');
        }
        else if(letra == '$'){
            return 0;
        }
        else if(letra == 'D'){
            snode *node = edit.dell(pilha);
            if(node != nullptr){
                pilha.push(STRUCT('D',node->letra));
                delete node;
            }
        }
        else if(letra == 'Z'){
            if(pilha.size() != 0){
             edit.ctz(pilha);
            }
        }
        else{
            edit.inser(letra);
            pilha.push('I');
        }
        edit.show();
        cout << "\n";
    }
}
