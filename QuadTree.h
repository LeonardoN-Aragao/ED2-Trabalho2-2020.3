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

        bool inserir(float x, float y);

    private:
        NoQuadTree * raiz;
};