#include <iostream>

class NoAvl{

    public:
        int value;
        int fator;
        NoAvl * pai;
        NoAvl * esq;
        NoAvl * dir;

        NoAvl(int v){
            fator = 0; 
            value = v;
            pai = NULL;
            esq = NULL;
            dir = NULL;
        }
        virtual ~NoAvl(){};

        int getValue(){ return value;}
        int getFator(){ return fator;}
        NoAvl * getEsq(){ return esq;}
        NoAvl * getDir(){ return dir;}
        NoAvl * getPai(){ return pai;}

        void setValue(int v){ value = v;}
        void setFator(int f){ fator = f;}
        void setEsq(NoAvl * p){ esq = p;}
        void setDir(NoAvl * p){ dir = p;}
        void setPai(NoAvl * p){ pai = p;}
};