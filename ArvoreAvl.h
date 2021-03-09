#include "NoAvl.h"

class ArvoreAvl{
    public:
        ArvoreAvl(bool b);
        virtual ~ArvoreAvl(){};   
        
        NoAvl * raiz;
        bool balanceada;
        int comparacao;

        int getAltura();
        int auxGetAltura(NoAvl * p);
        int  getComparacao(){ return comparacao;}
        bool eBalanciada(){return balanceada;}
        void insere(int value);
        void remove(int value);
        NoAvl * busca(int value);
        void atualizaFator(NoAvl* p);
        void verificaBalanceamento(NoAvl * p);

        void rotDir(NoAvl * p);
        void rotEsq(NoAvl * p);
        void duplaRotDir(NoAvl * p);
        void duplaRotEsq(NoAvl * p);
};