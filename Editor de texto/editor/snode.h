#ifndef SNODE_H
#define SNODE_H

struct snode{

    char letra;

    snode * next;
    snode * previus;

    snode(char letra = ' ', snode *next=nullptr, snode *previus=nullptr){
       this->letra=letra;
        this->next= next;
        this->previus = previus;
    }

};



#endif // SNODE_H
