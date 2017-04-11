#ifndef EDITOR_H
#define EDITOR_H
#include"snode.h"
#include<iostream>
#include<stack>

using namespace std;
struct STRUCT{
    char letra;
    char value;
    STRUCT(char letra, char value = ' '){
        this->letra = letra;
        this->value = value;
    }
};

struct editor{

    snode *head;
    snode *tail;
    snode *curs;

    editor(){
        head = new snode;
        tail = new snode;
        head->next = tail;
        curs->previus = head;
        curs->next = tail;
        tail->previus = curs;

    }

    void inser(char letra){
       if(letra < 'A' || letra > 'Z'){
        snode *nod = new snode(letra,curs,curs->previus);
        curs->previus->next = nod;
        curs->previus = nod;
       }
    }

    void inserD(char letra){
        snode *nod = new snode(letra,curs->next,curs);
        curs->next->previus = nod;
        curs->next = nod;
    }

    void show(){
        _rshow(this->head->next);
    }

    void _rshow(snode *node){
        if(node == curs){
            cout << "|";
        }
        if(node == tail){
            return;
        }
        cout << node->letra << " ";
        _rshow(node->next);
    }

    snode *apag(){
        if(curs->previus != head){
        snode *node = this->curs->previus;
        curs->previus = node->previus;
        node->previus->next = curs;
        return node;
        }
        return nullptr;
    }

    void moverE(){
        if(curs->previus == head){
            return;
        }
        snode *node = this->curs->previus;
        node->next = this->curs->next;
        this->curs->next->previus = node;
        node->previus->next = this->curs;
        this->curs->next = node;
        this->curs->previus = node->previus;
    }

    void moverD(){
        if(curs->next == tail){
            return;
        }
        snode *node = this->curs->next;
        this->curs->next = node->next;
        node->next->previus = this->curs;
        node->next = this->curs;
        node->previus = this->curs->previus;
        this->curs->previus->next = node;
        this->curs->previus = node;
    }

    snode *dell(stack<STRUCT> pilha){
        if(curs->next != tail){
        snode *node = this->curs->next;
        this->curs->next = node->next;
        node->next->previus = this->curs;
        pilha.push(STRUCT('Z',node->letra));
        return node;
        }else{
            return nullptr;
        }

    }

    void ctz(stack<STRUCT> &pilha){
        STRUCT struc = pilha.top();
        if (struc.letra == 'B') {
            this->inser(struc.value);
            pilha.pop();
            return;
        }
        if(struc.letra == '<'){
            this->moverD();
            return;
        }
        if(struc.letra == '>'){
            this->moverE();
            return;
        }
        if(struc.letra == 'D'){
            this->inserD(struc.value);
            pilha.pop();
            return;
        }
        if(struc.letra == 'I'){
            this->apag();
            pilha.pop();
            return;
        }
    }
};

#endif // EDITOR_H
