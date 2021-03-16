#include "NoB.h"

class ArvoreB
{
    public:
        ArvoreB();
        ArvoreB(int m);
        ~ArvoreB();

        void noOverflow(NoB* no);
        void noUnderflow(NoB* noE,NoB* noD, NoB* pai,int indice);
        bool buscarValue(int value);
        void InserirNoB(int value);

        // Variáveis de análise
        int comparacao;
        int getComparacoes() {return this->comparacao;}
        
    private:
        int d;
        NoB* raiz;
};