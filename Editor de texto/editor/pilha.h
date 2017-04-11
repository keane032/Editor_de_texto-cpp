#ifndef PILHA_H
#define PILHA_H
#include"snode.h"

using namespace std;

struct pilha{

    snode *haed;

    pilha(){
       haed = new snode;
    }

    void push_front(char letra){
        snode *node = new snode(letra);
        node->next = haed->next;
        this->haed->next = node;
    }

   snode *front(){
        return this->haed->next;
   }

   snode pop_front(){
       snode *node = this->haed->next;
       this->haed->next = node->next;
       delete node;
   }

};

#endif // PILHA_H
