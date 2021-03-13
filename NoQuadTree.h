#include <iostream>
#include <vector>

// 52,5200050,Abadia de Goiás,-16.7573,-49.4412,FALSE
struct Cidade
{
    int codigo_estado;
    int codigo_cidade;
    std::string nome_cidade;
    float longitude;
    float latitude;
    bool isEstado;
};

//latitude -34, 5
//longitude  -32, -73
struct Quadrante
{
    float x_centro;
    float y_centro;
    float tam;
};

class NoQuadTree{

    public:

        NoQuadTree();
        NoQuadTree(Quadrante r);
        ~NoQuadTree();

        NoQuadTree * getPai(){ return pai;}
        NoQuadTree * getA(){ return a;}
        NoQuadTree * getB(){ return b;}
        NoQuadTree * getC(){ return c;}
        NoQuadTree * getD(){ return d;}
        Quadrante getQuadrante(){ return regiao;}
        
        void setPai(NoQuadTree * p){ pai = p;}
        void setA(NoQuadTree * p){ a = p;}
        void setB(NoQuadTree * p){ b = p;}
        void setC(NoQuadTree * p){ c = p;}
        void setD(NoQuadTree * p){ d = p;}
        void setQuadrante(float x, float y, float d);
        
        bool inserir(Cidade c);
        bool busca(Cidade c);
        void subdivide();

    private:
        /*
            Diposição dos quadrantes
                A B
                C D
        */
        Quadrante regiao;
        std::vector<Cidade> localizacao;
        NoQuadTree * pai;
        NoQuadTree * a;
        NoQuadTree * b;
        NoQuadTree * c;
        NoQuadTree * d;
};