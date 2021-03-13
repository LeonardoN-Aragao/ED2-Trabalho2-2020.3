#include <iostream>
#include <fstream>
#include <sstream>
#include "ArvoreAvl.h"
#include "QuadTree.h"
#include "ArvoreB.h"
#include "TabelaHash.h"

using namespace std;

/*
    ----- Esturturas -----

    QuadTree    Inserção e busca
    TabelaHash  Dimensione a tabela adequadamente e função de hash que permita
                uma boa distribuição de chaves na tabela.
                Escolha também uma técnica para tratamento de colisões.
                Utilize como chave o par (código da cidade, data).
    Árvore AVL  Inserção e busca
    Árvore B    Inserção e busca


    É importante frisar que o código da cidade no arquivo com a contagem de casos
    possui um dígito a menos à direita. No entanto, isso não é um problema, pois
    os outros 6 dígitos são suficientes para identificar unicamente a cidade. 
    Assim, para todos os efeitos, considere cada código de cidade neste trabalho 
    como sendo composto pelos 6 primeiros dígitos (da esquerda para a direita) 
    presentes no arquivo de cidades.
    
    Solução: (numero de 7 digitos -(numero de 6 digitos * 10) < 10 && >= 0)


    ----- Trabalho Solicitado -----

    Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree

    Etapa 2 - 

*/

// Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree
void etapa1(QuadTree * aux){

    fstream file;
    file.open("brazil_cities_coordinates.csv", fstream::in);

    if(file.is_open()){
        
        string str;
        getline(file, str); // para nao pegar a primeira linha
        int count = 0;

        while(!file.eof()){

            str = ' ';
            Cidade aux;

            getline(file, str,',');
            aux.codigo_estado = stoi(str);

            getline(file, str,',');
            aux.codigo_cidade = stoi(str);

            getline(file, str,',');
            aux.nome_cidade = str;

            getline(file, str,',');
            aux.latitude = stod(str);

            getline(file, str,',');
            aux.longitude = stod(str);

            getline(file, str);
            if(str == "FALSE")
                aux.isEstado = 0;
            else
                aux.isEstado = 1;
            
            count++;

            /* Teste
            cout<<aux.codigo_estado<<" "
                <<aux.codigo_cidade<<" "
                <<aux.nome_cidade<<" "
                <<aux.latitude<<" "
                <<aux.longitude<<" "
                <<aux.isEstado<<endl;     

            return;
            */
        }       
        cout<<count<<" cidades lidas.";
    }
    else{
        cout<<"Erro: arquivo brazil_cities_coordinates.csv não encontrado!"<<endl;
        exit(1);
    }
}

void etapa2(){
    
}

void menuSelecionado(char a)
{
    switch (a){

    case '1':
    {   
        break;
    }
    case '2':
    {
        break;
    }
    case '3':
    {        
        //N = 1000, 5000, 10000, 50000, 100000 e 500000
        int n [4] = {1000, 5000, 10000, 50000}; 
        
        cout << "\nAguarde... \n";

        for(int i = 0; i<4; i++){
            for(int j = 0; j < 5;j ++){
                for(int k = 0; k <3 ; k ++){
                
                }
            }
        }

        cout << "\nFinalizado! \n";
        break;
    }
    //---------- Usar para Testes ----------
    case '4':
    {
        cout << "\nSem testes por aqui no momento. :(" << endl;
        break;
    }
    default:
        break;
    }
}

/* Menu de funcionalidades*/
void menu()
{
    //System("tput reset");
    char menu;
    while (true)
    {
        cout << endl;
        cout << "\n# Menu principal #" << endl;
        cout << "[1] - Parte 1" << endl;
        cout << "[2] - Parte 2" << endl;
        cout << "[3] - Parte 3" << endl;
        cout << "[4] - Parte 4" << endl;
        cout << endl;
        do
        {
            cout << "Digite uma opcao do menu: ";
            cin >> menu;
        } while (((menu < '0' || menu > '5') && (menu < 'a' || menu > 'z')) && menu != 'q');

        if (menu == 'q')
        {
            cout << "Saindo..." << endl;
            cout << "Bye" << endl;
            return;
        }
        menuSelecionado(menu);
    }
}

int main(){

    srand(0);

    cout<<"Etapa 1"<<endl;
    cout<<"Lendo arquivo brazil_cities_coordinates.csv ..."<<endl;
    QuadTree * a = new QuadTree();
    etapa1(a);

    menu();
    
    return 0;
}