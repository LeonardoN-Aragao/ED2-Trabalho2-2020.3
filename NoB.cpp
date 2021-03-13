#include "NoB.h"

NoB::NoB(int m){

    d=m;
    valores = new int[2*d-1];
    filhos = new NoB* [2*d];
    for (int i=0;i<2*d;i++) valores[i]= 0;
    numChaves = 0;
}

NoB::~NoB(){

    delete [] filhos;
    delete [] valores;
}

// Verifica se é nó folha
bool NoB::isFolha(){

    if(this->filhos[0]->numChaves == 0)
        return false;
    return true;
}

NoB* NoB::buscaNo(int value){

    //Procura posição
    int aux= 0;
    while(aux < numChaves && value > valores[aux])
        aux++;

    //Verifica se achou o valor na posição
    if(valores[aux] == value)
        return this;
    
    //Se o nó atual não é folha continua buscando
    if(this->isFolha())
        return NULL;
    return filhos[aux]->buscaNo(value);
}

void NoB::split(int value, NoB* no){

    NoB* aux = new NoB(no->d);
    aux->numChaves = d-1;

    //Copia os valores
    for(int i = 0; i < d-1; i++)
        aux->valores[i]= no->valores[d+i];

    //Copia os filhos
    if(no->isFolha()){

        for(int i =0; i< d; i++)
            aux->filhos[i]= no->filhos[d+i];
    }
    //Atualiza o numero de chaves
    no->numChaves = d-1;
    
    //Move os filhos para uma posição a frente
    for (int i = numChaves; i >= value +1; i--)
        filhos[i+1] = filhos[i];
    
    //Adiciona aux no seu lugar
    filhos[value+1] = aux;

    //Move os valores uma posicao para frente
    for(int i = numChaves-1; i >= value; i--)
        valores[i+1] = valores[i];
    valores[value] = no->valores[d-1];

    //Atualiza novo numero de chaves
    numChaves++;

    return;
}

void NoB::insereValor(int valor){

    int aux = numChaves - 1;
    
    if(this->isFolha()){

        while (aux >= 0 && valores[aux] > valor){

            valores[aux+1] = valores[aux];
            aux--;
        }
        valores[aux+1] = valor;
        numChaves= numChaves+1;
    }
    else{

        while (aux >= 0 && valores[aux] > valor)
            aux--;
        
        if (filhos[aux+1]->numChaves == 2*d-1){

            split(aux+1, filhos[aux+1]);
            if (valores[aux+1] < valor)
                aux++;
        }
        filhos[aux+1]->insereValor(valor);
    }
    return;
}