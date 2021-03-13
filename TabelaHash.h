#include <iostream>
#include "InfoCidade.h"

using namespace std;

class TabelaHash{

    public:
        TabelaHash(){};
        TabelaHash(long tam);
        ~TabelaHash(){ delete [] this->tabela;}
        
        //pior colisão encontrada 26.527.153
        //melhor colisão encontrada 4.905.383, total de 3.4 colisoes por registro
        //Caso precise 250169 é primo
        int funcHash(int chave){ return (chave) % tamanho;}
        int funcHash2(int chave){ return 1 + ((chave) % (tamanho-1));}
        int linear(int chave, int iteracoes){ return ((funcHash(chave) + iteracoes)) % tamanho;}
        int dupla(int chave, int iteracoes){ return (funcHash(chave) + (iteracoes * funcHash2(chave))) % tamanho;}        
        int getDia(string b){ return (b[b.size()-2] -48) * 10 + (b[b.size()-1] -48);} //TODO: mudar essa funcao para o infoCidade.h
        int getColisoes() { return colisoes;}
        int search(string data,int codigo){ return auxSearch((getDia(data)*codigo),20);}
        int auxSearch(int chave, int iteracoes);
        void add(InfoCidade cidade);

    private:
        long tamanho;
        InfoCidade * tabela;
        int colisoes;
};