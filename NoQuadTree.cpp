#include "NoQuadTree.h"

NoQuadTree::NoQuadTree(){
    pai = NULL;
    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
}

NoQuadTree::NoQuadTree(Quadrante r){
    regiao = r;
    pai = NULL;
    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
}

NoQuadTree::~NoQuadTree(){
    localizacao.clear();
    delete a;
    delete b;
    delete c;
    delete d;
}

void NoQuadTree::setQuadrante(float x, float y, float t){
    
    regiao.x_centro = x;
    regiao.y_centro = y;
    regiao.tam = t;
}

void NoQuadTree::subdivide(){
    
    Quadrante ra;
    Quadrante rb;
    Quadrante rc;
    Quadrante rd;

    float tamSubRegiao = regiao.tam/2;

    ra.x_centro = regiao.x_centro - tamSubRegiao;
    ra.y_centro = regiao.y_centro + tamSubRegiao;
    ra.tam = tamSubRegiao;

    rb.x_centro = regiao.x_centro + tamSubRegiao;
    rb.y_centro = regiao.y_centro + tamSubRegiao;
    rb.tam = tamSubRegiao;

    rc.x_centro = regiao.x_centro - tamSubRegiao;
    rc.y_centro = regiao.y_centro - tamSubRegiao;
    rc.tam = tamSubRegiao;

    rd.x_centro = regiao.x_centro + tamSubRegiao;
    rd.y_centro = regiao.y_centro - tamSubRegiao;
    rd.tam = tamSubRegiao;

    a = new NoQuadTree(ra);
    a->setPai(this);

    b = new NoQuadTree(rb);
    b->setPai(this);

    c = new NoQuadTree(rc);
    c->setPai(this);

    d = new NoQuadTree(rd);
    d->setPai(this);
}   

 bool NoQuadTree::inserir(Cidade cidade){

    // Se não pertence ao quadrante
    if ((cidade.latitude > (regiao.y_centro+regiao.tam) 
        || cidade.latitude < (regiao.y_centro-regiao.tam))
        && (cidade.longitude > (regiao.x_centro+regiao.tam) 
        || cidade.longitude < (regiao.x_centro-regiao.tam))) 
        return false;

    // Verifica se não está cheio e se não dividiu
    if (localizacao.size() < 4 && a == NULL){
        localizacao.push_back(cidade);
        return true;
    }

    // Divide as regiões se necessário
    if (a == NULL)
        subdivide();

    //Tenta inserir em alguma região
    if (a->inserir(cidade)) return true;
    if (b->inserir(cidade)) return true;
    if (c->inserir(cidade)) return true;
    if (d->inserir(cidade)) return true;

    return false;
}

bool NoQuadTree::busca(Cidade cidade){

    if ((cidade.latitude > (regiao.y_centro+regiao.tam) 
        || cidade.latitude < (regiao.y_centro-regiao.tam))
        && (cidade.longitude > (regiao.x_centro+regiao.tam) 
        || cidade.longitude < (regiao.x_centro-regiao.tam))) 
        return false;

    //Verifica se está na lista do nó atual
    for(int i = 0; i < localizacao.size(); i++){
        if (localizacao[i].latitude == cidade.latitude 
            && localizacao[i].longitude == cidade.longitude)
            return true;
    }

    //Verifica se já dividiu
    if (a == NULL)
        return false;
    else{

        if (a->busca(cidade)) return true;
        if (b->busca(cidade)) return true;
        if (c->busca(cidade)) return true;
        if (d->busca(cidade)) return true;
    }
    
    return false;
}