#include <iostream>
#include <fstream>
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

    Lembrar de avisar que são 5570 cidades;

    Você deverá armazenar estes registros em uma tabela hash. Dimensione a tabela 
    adequadamente e utilize uma função de hash que permita uma boa distribuição de 
    chaves na tabela. Escolha também uma técnica para tratamento de colisões. 
    Utilize como chave o par (código da cidade, data).

    ----- Trabalho Solicitado -----

    Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree

    Etapa 2 - Ler brazil_covid19_cities_processado.csv e armazenar na Tabela Hash

    Etapa 3 - Implementação de estruturas de dados balanceada Arvore B e AVL
    
    Etapa 4 - Modulo de Testes

    Etapa 5 - Analise das estruturas de dados balanceada

*/

// Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree
void etapa1(QuadTree * aux){

    fstream file;
    string name = "brazil_cities_coordinates.csv";
    file.open(name, fstream::in);

    if(file.is_open()){
        
        string str;
        getline(file, str); // para nao pegar a primeira linha
        int count = 0;

        while(!file.eof()){

            str = ' ';
            Cidade c;

            getline(file, str,',');
            c.codigo_estado = stoi(str);

            getline(file, str,',');
            c.codigo_cidade = stoi(str);

            getline(file, str,',');
            c.nome_cidade = str;

            getline(file, str,',');
            c.latitude = stod(str);

            getline(file, str,',');
            c.longitude = stod(str);

            getline(file, str);
            if(str == "FALSE")
                c.isEstado = 0;
            else
                c.isEstado = 1;

            aux->inserir(c);
            
            count++;

            //Teste
            /*
            cout<<c.codigo_estado<<" "
                <<c.codigo_cidade<<" "
                <<c.nome_cidade<<" "
                <<c.latitude<<" "
                <<c.longitude<<" "
                <<c.isEstado<<endl;     

            return;
            */
        }       
        cout<<count<<" cidades lidas."<<endl;
    }
    else{
        cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

// Etapa 2 - Ler brazil_covid19_cities_processado.csv e armazenar na Tabela Hash
void etapa2(TabelaHash * aux){

    fstream file;
    string name = "brazil_covid19_cities_processado.csv";
    file.open(name, fstream::in);

    if(file.is_open()){
        
        string str;
        getline(file, str); // para nao pegar a primeira linha
        int count = 0;

        while(!file.eof()){

            str = ' ';
            InfoCidade c;

            getline(file, str,',');
            c.setData(str);

            getline(file, str,',');
            c.setSiglaEstado(str);

            getline(file, str,',');
            c.setNomeCidade(str);

            getline(file, str,',');
            c.setCodigoCidade(stoi(str));

            getline(file, str,',');
            c.setCasos(stoi(str));

            getline(file, str);
            c.setMortes(stoi(str));

            aux->add(c);

            count++;
            cout<<count<<" registros lidos."<<endl;
            // Teste
            /*
            cout<<c.getData()<<" "
                <<c.getSiglaEstado()<<" "
                <<c.getNomeCidade()<<" "
                <<c.getCodigoCidade()<<" "
                <<c.getCasos()<<" "
                <<c.getMortes()<<endl;     

            return;
            */
        }       
        cout<<count<<" registros lidos.";
    }
    else{
        cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

// Etapa 3 - Implementação de estruturas de dados balanceada
void etapa3(){

}

// Etapa 4 - Modulo de Testes
void etapa4(){

}

// Etapa 5 - Analise das estruturas de dados balanceada
void etapa5(){

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
        break;
    }
    case '4':
    {
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
        cout << "[1] - Inserção de N cidades na quad tree" << endl;
        cout << "[2] - Inserção de N registros na tabela hash" << endl;
        cout << "[3] - Inserção de N chaves na árvore AVL" << endl;
        cout << "[4] - Inserção de N chaves na árvore B" << endl;
        cout << endl;
        do
        {
            cout << "Digite uma opcao do menu ou 'q' para continuar: ";
            cin >> menu;
        } while (((menu < '0' || menu > '5') && (menu < 'a' || menu > 'z')) && menu != 'q');

        if (menu == 'q')
        {
            cout << "Saindo..." << endl;
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

    cout<<"\nEtapa 2"<<endl;
    cout<<"Lendo arquivo brazil_covid19_cities_processado.csv ..."<<endl;
    
    TabelaHash * tabela = new TabelaHash(1431490*5); //Ver qual sondagem usar
    etapa2(tabela);

    cout<<"\nEtapa 3"<<endl;
    etapa3();

    cout<<"\nEtapa 4"<<endl;
    cout<<"Modulo de Testes"<<endl;
    menu();

    cout<<"\nEtapa 5"<<endl;
    etapa5();
    
    return 0;
}