#include <iostream>
#include "ArvoreAvl.h"

ArvoreAvl::ArvoreAvl(bool b){
    raiz = NULL;
    balanceada = b;
    comparacao = 0;
}

int ArvoreAvl::auxGetAltura(NoAvl*p){

    if(p == NULL)
        return -1;
    else{
        int he = auxGetAltura(p->getEsq());
        int hd = auxGetAltura(p->getDir());

        if(he < hd)
            return hd + 1;
        else 
            return he + 1;
    }
}

int ArvoreAvl::getAltura(){
    return auxGetAltura(raiz);
}   

NoAvl * ArvoreAvl::busca(int value){
    
    NoAvl * p = raiz;

    while(p!=NULL){
        
        if(p->getValue() == value){
            comparacao++;
            return p;
        }

        if(value > p->getValue())
            p = p->getDir();
        else
            p = p->getEsq();
        
        comparacao++;
    }
    return NULL;
}

void ArvoreAvl::atualizaFator(NoAvl* p){

    int fator;
    if(!p->getDir() && !p->getEsq())
        fator = 0;
    else if(p->getDir() != NULL && p->getEsq() != NULL)
        fator = p->getDir()->getFator() - p->getEsq()->getFator();
    else if(p->getDir() != NULL)
        fator = 1;
    else
        fator = -1;
    p->setFator(fator);
}

void ArvoreAvl::verificaBalanceamento(NoAvl * p){

    while(p != NULL){
        atualizaFator(p);
        if(p->getFator() == 2 && (p->getDir()->getFator() == +1 || p->getDir()->getFator() == 0))
            rotEsq(p);
        if(p->getFator() == -2 && (p->getDir()->getFator() == -1 || p->getDir()->getFator() == 0))
            rotDir(p);
        if(p->getFator() == 2 && p->getDir()->getFator() == -1)
            duplaRotEsq(p);
        if(p->getFator() == -2 && p->getDir()->getFator() == +1)
            duplaRotDir(p);

        p = p->getPai();
    }
}

/*
para inserir:
	- Encontra a posicao aonde inserir
	- Insere o novo n
	- Retorna atualizando os fatores de balanceamento
*/
void ArvoreAvl::insere(int value){
    
    NoAvl * p = new NoAvl(value);

    if(raiz == NULL){
        raiz = p;
    }
    else{
        NoAvl * q = raiz;
        NoAvl * aux;

        while(q!=NULL){
            aux = q;
            //valor já adicionado
            if(q->getValue() == value){
                comparacao++;
                return;
            }

            if(value > p->getValue())
                q = q->getDir();
            else
                q = q->getEsq();
            comparacao++;
        }

        if(value > aux->getValue())
            aux->setDir(p);
        else
            aux->setEsq(p);
        
        p->setPai(aux);
        if(balanceada)
            verificaBalanceamento(p);
    }
}

void ArvoreAvl::remove(int value){
    
    NoAvl * p = busca(value);
    NoAvl * q;
    if( p != NULL){
        q = p->getPai();
        // p é folha
        if(p->getEsq() != NULL && p->getDir() != NULL)
            delete p;
        // p é pai de um filho
        else if(!p->getEsq()){
            NoAvl * aux = p;
            p = p->getDir();
            p->setPai(aux->getPai());
            delete aux;
        }
        else if(!p->getDir()){
            NoAvl * aux = p;
            p = p->getEsq();
            p->setPai(aux->getPai());
            delete aux;
        }
        // p é pai de 2 filhos - troca pelo maior filho da arvore a esquerda
        else {
            NoAvl * aux = p->getEsq();
            while (!aux->getDir()) {
                aux = aux->getDir();
            }
            p->setValue(aux->getValue());
            delete aux;
        }
        
        if(balanceada)
            verificaBalanceamento(q);
    }

}

void ArvoreAvl::rotEsq(NoAvl * p){
	NoAvl * q = p->getDir();
	p->setDir(q->getEsq());
	q->setEsq(p);
}

void ArvoreAvl::rotDir(NoAvl * p){
	NoAvl * q = p->getDir();
	p->setEsq(q->getDir());
	q->setDir(p);
}

void ArvoreAvl::duplaRotEsq(NoAvl * p){
	rotDir(p->getDir());
	rotEsq(p);
}

void ArvoreAvl::duplaRotDir(NoAvl * p){
	rotEsq(p->getEsq());
	rotDir(p);
}