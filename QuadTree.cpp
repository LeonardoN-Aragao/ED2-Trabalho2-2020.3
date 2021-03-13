#include "QuadTree.h"

QuadTree::QuadTree(){
    raiz = NULL;
}

QuadTree::~QuadTree(){
    delete raiz;
}

bool QuadTree::inserir(Cidade aux){

    //latitude -34, 5
    //longitude  -32, -73
    if(raiz == NULL){
        raiz = new NoQuadTree();
        raiz->setQuadrante(0,0,100.0);
    }
    return raiz->inserir(aux);
}

bool QuadTree::busca(float x, float y){

    if(raiz == NULL)
        return false;
    else{

        Cidade aux;
        aux.longitude = x;
        aux.latitude = y;
        return raiz->busca(aux);
    }
}