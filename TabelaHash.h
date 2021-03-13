#include <iostream>
#include "InfoCidade.h"

using namespace std;

class TabelaHash{

    public:

        TabelaHash(long tam);
        ~TabelaHash(){ delete [] this->tabela;}

        int funcHash(int chave){ return chave % tamanho;}
        int funcHash2(int chave){ return 1 + (chave % (tamanho-1));}
        int linear(int chave, int iteracoes){ return (funcHash(chave) + iteracoes) % tamanho;}
        int dupla(int chave, int iteracoes){ return funcHash(chave) + (iteracoes * funcHash2(chave)) % tamanho;}        

        int getColisoes() { return colisoes;}
        int search(string data,int codigo){ return auxSearch((stoi(data)*codigo),20);}
        int auxSearch(int chave, int iteracoes);
        void add(InfoCidade cidade);

    private:
        long tamanho;
        InfoCidade * tabela;
        int colisoes;
};