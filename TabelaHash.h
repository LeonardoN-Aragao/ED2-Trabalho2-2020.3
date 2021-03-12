#include <iostream>

using namespace std;

class TabelaHash{

    public:

        TabelaHash(int tam, int sond);
        ~TabelaHash(){ delete tabela;}

        int funcHash(int chave){ return chave % tamanho;}
        int funcHash2(int chave){ return 1 + (chave % (tamanho-1));}
        int linear(int chave, int iteracoes){ return (funcHash(chave) + iteracoes) % tamanho;}
        int dupla(int chave, int iteracoes){ return funcHash(chave) + (iteracoes * funcHash2(chave)) % tamanho;}        

        int getColisoes() { return colisoes;}
        int search(int chave, int iteracoes);
        void add(int chave);

    private:

        int tamanho;
        int * tabela;
        int sondagem;
        int colisoes;
};