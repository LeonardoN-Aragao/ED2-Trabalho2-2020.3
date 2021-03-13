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

    ----- Anotações -----

    É importante frisar que o código da cidade no arquivo com a contagem de casos
    possui um dígito a menos à direita. No entanto, isso não é um problema, pois
    os outros 6 dígitos são suficientes para identificar unicamente a cidade. 
    Assim, para todos os efeitos, considere cada código de cidade neste trabalho 
    como sendo composto pelos 6 primeiros dígitos (da esquerda para a direita) 
    presentes no arquivo de cidades.
    
    Solução: (numero de 7 digitos -(numero de 6 digitos * 10) < 10 && >= 0)

    Lembrar de avisar que são 5570 cidades e 1.431.490 (sem contar cabeçalho);

    Você deverá armazenar estes registros em uma tabela hash. Dimensione a tabela 
    adequadamente e utilize uma função de hash que permita uma boa distribuição de 
    chaves na tabela. Escolha também uma técnica para tratamento de colisões. 
    Utilize como chave o par (código da cidade, data).

    S1) Obter o total de casos de uma cidade;
    S2) Obter o total de casos nas cidades contidas
    no intervalo [(x0, y0), (x1, y1)], onde x0 e x1 
    são latitudes e y0 e y1 são longitudes.

    ----- Trabalho Solicitado -----

    Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree

    Etapa 2 - Ler brazil_covid19_cities_processado.csv e armazenar na Tabela Hash

    Etapa 3 - Implementação de estruturas de dados balanceada Arvore B e AVL
    
    Etapa 4 - Modulo de Testes

    Etapa 5 - Analise das estruturas de dados balanceada

*/

void menuSelecionado(char a){

    switch (a){

        case '1':
        {   
            // Inserção de N cidades na quad tree

            break;
        }
        case '2':
        {
            // Inserção de N registros na tabela hash

            break;
        }
        case '3':
        {        
            // Inserção de N chaves na árvore AVL

            break;
        }
        case '4':
        {
            // Inserção de N chaves na árvore B

            break;
        }
        default:
            break;
    }
}

void menu(){

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
            return;
        }
        menuSelecionado(menu);
    }
}

void leituraCoordenadas(QuadTree* aux, int N){

    if(N > 5571 || N < 0){
        cout<<"Erro: Valor de N inválido!"<<endl;
        return;
    }

    fstream file;
    string name = "brazil_cities_coordinates.csv";
    file.open(name, fstream::in);

    if(file.is_open()){
        
        string str;
        getline(file, str); // para nao pegar a primeira linha
        int contador = 0;

        while(contador < N){

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
            
            contador++;

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
        cout<<contador<<" cidades lidas."<<endl;
        file.close();
    }
    else{
        cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

void leituraProcessados(TabelaHash * aux, int N){
    
    if(N > 1431490 || N < 0){
        cout<<"Erro: Valor de N inválido!"<<endl;
        return;
    }

    fstream file;
    string name = "brazil_covid19_cities_processado.csv";
    file.open(name, fstream::in);

    if(file.is_open()){
        
        string str;
        getline(file, str); // para nao pegar a primeira linha
        int count = 0;

        while(count < N){

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
        cout<<count<<" registros lidos."<<endl;
        file.close();
    }
    else{
        cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

void armazearId(ArvoreB * b, ArvoreAvl * avl,int N){
    
    if(N > 1431490 || N < 0){
        cout<<"Erro: Valor de N inválido!"<<endl;
        return;
    }

    TabelaHash aux(1); //TODO: retirar apos mover função getDia() de lugar

    fstream file;
    string name = "brazil_covid19_cities_processado.csv";
    file.open(name, fstream::in);

    if(file.is_open()){
        
        string str;
        getline(file, str); // para nao pegar a primeira linha
        int count = 0;

        while(count < N){

            str = ' ';
            string data;
            int codigo;

            getline(file, str,',');
            data = str;

            getline(file, str,','); //siglaEstado
            getline(file, str,','); //NomeCidade


            getline(file, str,',');
            codigo = stoi(str);

            getline(file, str,','); //Casos
            getline(file, str); //Mortes    

            long id = aux.getDia(data)*codigo;

            if(b!= NULL)
                b->InserirNoB(id); 
                
            if(avl!= NULL)
            avl->insere(id);

            count ++;
        }       
        cout<<count<<" registros lidos."<<endl;
        cout<<"Deletando Arvore."<<endl;

        delete b;
        delete avl;
        file.close();
    }
    else{
        cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

// Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree
void etapa1(QuadTree * aux){
    leituraCoordenadas(aux,5570);
}

// Etapa 2 - Ler brazil_covid19_cities_processado.csv e armazenar na Tabela Hash
void etapa2(TabelaHash * aux){
    leituraProcessados(aux,1431490);
}

// Etapa 3 - Implementação de estruturas de dados balanceada
void etapa3(){
    //TODO: Se der tempo "A ordenação da árvore será determinada pelo par (código da cidade, data)"
    ArvoreB * b = new ArvoreB(200); 
    ArvoreAvl * avl = new ArvoreAvl(true);

    armazearId(b,avl,1431490);

    delete b;
    delete avl;
}

// Etapa 4 - Modulo de Testes
void etapa4(){
    menu();
}

// Etapa 5 - Analise das estruturas de dados balanceada
void etapa5(){
    
}

int main(){

    srand(0);

    cout<<"----- Etapa 1 -----"<<endl;
    cout<<"Lendo arquivo brazil_cities_coordinates.csv ..."<<endl;

    QuadTree * a = new QuadTree();
    etapa1(a);

    //--------------------------------------------------------------------

    cout<<"\n----- Etapa 2 -----"<<endl;
    cout<<"Lendo arquivo brazil_covid19_cities_processado.csv ..."<<endl;
    
    TabelaHash * tabela = new TabelaHash(1431490*11);
    etapa2(tabela);
    cout<<tabela->getColisoes()<<" colisoes."<<endl;

    //--------------------------------------------------------------------

    cout<<"\n----- Etapa 3-----"<<endl;
    cout<<"Testando implementaçãos ArvoreB e ArvoreAvl..."<<endl; 
    
    etapa3();

    //--------------------------------------------------------------------

    cout<<"\n----- Etapa 4 -----"<<endl;
    cout<<"Modulo de Testes"<<endl;

    etapa4();

    //--------------------------------------------------------------------

    cout<<"\n----- Etapa 5 -----"<<endl;
    etapa5();
    
    return 0;
}