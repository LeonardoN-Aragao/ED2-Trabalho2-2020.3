#include <iostream>
#include "ArvoreB.h"

using namespace std;

ArvoreB::ArvoreB (int m){
    raiz = NULL;
    comparacao = 0;
    d = m;
}

void auxDeletarArv(NoB* p){

    if(p == NULL)
        return;

    for(int i = 0; i <= p->getNumChaves(); i++){
        auxDeletarArv(p->getFilhos()[i]);
        delete p->getFilhos()[i];
    }    
}

ArvoreB::~ArvoreB(){
    auxDeletarArv(raiz);
}

bool ArvoreB::buscarValue(int value){
    
    if(raiz == NULL)
        return false;
    else
        return raiz->buscaNo(value);
}

void ArvoreB::InserirNoB(int value){

    //Nesse caso, nao há no na arvore
    if(raiz == NULL){

        raiz = new NoB(d);
        raiz->getValores()[0]=value;
        raiz->incrementaQuantChaves();
    }
    else
    {
        if(raiz->getNumChaves() != 2*d-1)
            raiz->insereValor(value);
        else
        {
            NoB * aux = new NoB(d);
            aux->getFilhos()[0]= raiz;
            aux->split(0, raiz);
            int i = 0;
            
            if (aux->getValores()[0] < value)
                i++;
            comparacao++;
            
            aux->getFilhos()[i]->insereValor(value);
            raiz = aux;
        }
    }      
}