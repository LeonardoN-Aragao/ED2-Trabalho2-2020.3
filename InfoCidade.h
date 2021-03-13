#ifndef INFOCIDADE_H
#define INFOCIDADE_H
#include <iostream>

// 2020-03-27,AC,Acrelândia,120001.0,0,0
class InfoCidade{

    public:
        InfoCidade(){
            data = " ";
            sigla_estado = " ";
            nome_cidade = " ";
            codigo_cidade = 0;
            casos = 0;
            mortes = 0;
        }
        ~InfoCidade(){};

        std::string getData() { return data;}
        std::string getSiglaEstado() { return sigla_estado;}
        std::string getNomeCidade() { return nome_cidade;}
        int getCodigoCidade() { return codigo_cidade;}
        int getCasos() { return casos;}
        int getMortes() { return mortes;}

        void setData(std::string d) { data = d;}
        void setSiglaEstado(std::string s) { sigla_estado = s;}
        void setNomeCidade(std::string nome) { nome_cidade = nome;}
        void setCodigoCidade(int c) { codigo_cidade = c;}
        void setCasos(int c) { casos = c;}
        void setMortes(int m) { mortes = m;}

    private:
        std::string data;
        std::string sigla_estado;
        std::string nome_cidade;
        int codigo_cidade;
        int casos;
        int mortes;
};

#endif