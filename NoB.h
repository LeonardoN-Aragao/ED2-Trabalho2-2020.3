#include <iostream>
#include <vector>

using namespace std;

class NoB{

    public:
        NoB();
        NoB(int m);
        ~NoB();

        int * getValores() {return valores;}
        NoB** getFilhos() {return filhos;}
        int getNumChaves() {return numChaves;}
        void setValores(int * id) {valores = id;}
        bool buscaNo(int id); 
        void split(int id, NoB* p);
        void insereValor(int valor);
        void incrementaQuantChaves() { numChaves++;}
        bool isFolha();
        
    private:
        int d;
        int numChaves;
        int * valores;
        NoB** filhos;
};