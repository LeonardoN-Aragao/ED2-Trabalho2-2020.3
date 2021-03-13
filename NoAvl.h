#include <iostream>

class NoAvl{

    public:
        int id;
        int fator;
        NoAvl * pai;
        NoAvl * esq;
        NoAvl * dir;

        NoAvl(int v){
            fator = 0; 
            id = v;
            pai = NULL;
            esq = NULL;
            dir = NULL;
        }
        ~NoAvl(){};

        int getId(){ return id;}
        int getFator(){ return fator;}
        NoAvl * getEsq(){ return esq;}
        NoAvl * getDir(){ return dir;}
        NoAvl * getPai(){ return pai;}

        void setId(int v){ id = v;}
        void setFator(int f){ fator = f;}
        void setEsq(NoAvl * p){ esq = p;}
        void setDir(NoAvl * p){ dir = p;}
        void setPai(NoAvl * p){ pai = p;}
};