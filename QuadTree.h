#include "NoQuadTree.h"

/* Quadrante global
    latitude -34, 5
    longitude  -32, -73
*/

class QuadTree
{
    public:
        QuadTree();
        ~QuadTree();

        NoQuadTree * getRaiz(){ return raiz;}
        void setRaiz(NoQuadTree * p) { raiz = p;}

        bool inserir(Cidade aux);
        bool busca(float x, float y);
        std::vector<Cidade> buscaQuadrante(float x, float y, float d);

    private:
        NoQuadTree * raiz;
};