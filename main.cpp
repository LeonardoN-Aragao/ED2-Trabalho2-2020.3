#include <iostream>
#include <fstream>
#include "ArvoreAvl.h"
#include "QuadTree.h"
#include "ArvoreB.h"
#include "TabelaHash.h"

using namespace std;

string PATH;

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

    Lembrar de avisar que são 5570 cidades e 1.431.490 (sem contar cabeçalho);

    É importante frisar que o código da cidade no arquivo com a contagem de casos
    possui um dígito a menos à direita. No entanto, isso não é um problema, pois
    os outros 6 dígitos são suficientes para identificar unicamente a cidade. 
    Assim, para todos os efeitos, considere cada código de cidade neste trabalho 
    como sendo composto pelos 6 primeiros dígitos (da esquerda para a direita) 
    presentes no arquivo de cidades.
    
    Solução: (numero de 7 digitos -(numero de 6 digitos * 10) < 10 && >= 0)

    Você deverá armazenar estes registros em uma tabela hash. Dimensione a tabela 
    adequadamente e utilize uma função de hash que permita uma boa distribuição de 
    chaves na tabela. Escolha também uma técnica para tratamento de colisões. 
    Utilize como chave o par (código da cidade, data).

    Para estes testes, dependendo do valor de N, você deverá exibir a saída no 
    console ou salvá-la em um arquivo. Se N <= 20, utilize a saída em console. 
    Caso contrário, utilize a saída em arquivo.

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

void leituraCoordenadas(QuadTree* aux, int N){

    if(N > 5571 || N < 0){
        std::cout<<"Erro: Valor de N inválido!"<<endl;
        return;
    }

    fstream saida;
    if(N > 20 && N != 5570)
        saida.open("Log-Etapa4.txt");

    fstream file;
    string name = "brazil_cities_coordinates.csv";
    file.open(PATH + name, fstream::in);

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

            string mensagem = "Cidade: "+ c.nome_cidade + ", lat: " + to_string(c.latitude)+ ", long: "+ to_string(c.longitude) +" inserida na Tabela Hash.\n";
            if(N > 20)
                saida<<mensagem;
            else
                std::cout<<mensagem<<endl;
            
            contador++;

            //Teste
            /*
            std::cout<<c.codigo_estado<<" "
                <<c.codigo_cidade<<" "
                <<c.nome_cidade<<" "
                <<c.latitude<<" "
                <<c.longitude<<" "
                <<c.isEstado<<endl;     

            return;
            */
        }       
        file.close();

        if(N > 20)
            saida.close();
    }
    else{
        std::cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

void leituraProcessados(TabelaHash * aux, int N){
    
    if(N > 1431490 || N < 0){
        std::cout<<"Erro: Valor de N inválido!"<<endl;
        return;
    }

    fstream saida;
    if(N > 20 && N != 1431490)
        saida.open("Log-Etapa4.txt");

    fstream file;
    string name = "brazil_covid19_cities_processado.csv";
    file.open(PATH + name, fstream::in);

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

            string mensagem = "Cidade: "+ c.getNomeCidade() + ", data: " +c.getData() + ", codigo: "+ to_string(c.getCodigoCidade()) +" inserida na Tabela Hash.\n";
            if(N > 20)
                saida<<mensagem;
            else
                std::cout<<mensagem<<endl;

            

            // Teste
            /*
            std::cout<<c.getData()<<" "
                <<c.getSiglaEstado()<<" "
                <<c.getNomeCidade()<<" "
                <<c.getCodigoCidade()<<" "
                <<c.getCasos()<<" "
                <<c.getMortes()<<endl;     

            return;
            */
        }       
        std::cout<<count<<" registros lidos."<<endl;
        file.close();

        if(N > 20)
            saida.close();
    }
    else{
        std::cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

void inserirId(ArvoreB * b, ArvoreAvl * avl,int N){
    
    if(N > 1431490 || N < 0){
        std::cout<<"Erro: Valor de N inválido!"<<endl;
        return;
    }

    fstream saida;
    if(N > 20 && N != 1431490)
        saida.open("Log-Etapa4.txt");

    TabelaHash aux(1); //TODO: retirar apos mover função getDia() de lugar

    fstream file;
    string name = "brazil_covid19_cities_processado.csv";
    file.open(PATH + name, fstream::in);

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

            string mensagem = "Chave " + to_string(id) + " inserida na arvore.\n";
            if(N > 20)
                saida<<mensagem;
            else
                std::cout<<mensagem<<endl;

            count ++;
        }       
        std::cout<<count<<" registros lidos."<<endl;
        std::cout<<"Deletando Arvore."<<endl;

        delete b;
        delete avl;
        file.close();
        if(N > 20)
            saida.close();
    }
    else{
        std::cout<<"Erro: arquivo "<<name<<" não encontrado!"<<endl;
        exit(1);
    }
}

void armazenarId(TabelaHash * aux, ArvoreB * b, ArvoreAvl * avl,int N){

    vector<InfoCidade> vet = aux->getRegistros(N);

    for(int i = 0; i < N; i++){
        long id = aux->getDia(vet[i].getData())*vet[i].getCodigoCidade();

        if(b != NULL)
            b->InserirNoB(id); 

        if(avl != NULL)
            avl->insere(id);
    }
}

void menuSelecionado(char a){

    switch (a){

        case '1':
        {   
            // Inserção de N cidades na quad tree

            int n;
            std::cout<<"Digite o valor de N: ";
            cin>>n;

            QuadTree * a = new QuadTree();
            leituraCoordenadas(a,n);
            delete a;

            break;
        }
        case '2':
        {
            // Inserção de N registros na tabela hash

            int n;
            std::cout<<"Digite o valor de N: ";
            cin>>n;

            TabelaHash * t = new TabelaHash(n*11);
            leituraProcessados(t,n);
            delete t;

            break;
        }
        case '3':
        {        
            // Inserção de N chaves na árvore AVL

            int n;
            std::cout<<"Digite o valor de N: ";
            cin>>n;

            ArvoreAvl * avl = new ArvoreAvl(true);
            inserirId(NULL,avl,n);
            //delete avl;

            break;
        }
        case '4':
        {
            // Inserção de N chaves na árvore B

            int n,d;
            std::cout<<"Digite o valor de N: ";
            cin>>n;
            std::cout<<"Digite o valor de d: ";
            cin>>d;
            
            ArvoreB * b = new ArvoreB(d); 
            inserirId(b,NULL,n);

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
        std::cout << endl;
        std::cout << "[1] - Inserção de N cidades na quad tree" << endl;
        std::cout << "[2] - Inserção de N registros na tabela hash" << endl;
        std::cout << "[3] - Inserção de N chaves na árvore AVL" << endl;
        std::cout << "[4] - Inserção de N chaves na árvore B" << endl;
        std::cout << endl;
        do
        {
            std::cout << "Digite uma opcao do menu ou 'q' para continuar: ";
            cin >> menu;
        } while (((menu < '0' || menu > '5') && (menu < 'a' || menu > 'z')) && menu != 'q');

        if (menu == 'q')
        {
            return;
        }
        menuSelecionado(menu);
    }
}

// Etapa 1 - Ler brazil_cities_coordinates.csv e armazenar na QuadTree
void etapa1(QuadTree * aux){
    leituraCoordenadas(aux,5570);
    std::cout<<"5570 cidades lidas."<<endl;
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

    inserirId(b,avl,1431490);
}

// Etapa 4 - Modulo de Testes
void etapa4(){
    menu();
}

// Etapa 5 - Analise das estruturas de dados balanceada
void etapa5(TabelaHash * aux){

    fstream saida;
    saida.open("saida.txt");

    if(saida.is_open()){

        int valores [5] = {10000, 50000, 100000, 500000, 1000000};

        for(int m = 0; m < 5; m++){

            std::cout<<"\nM: "<<m<<endl;

            double tempo_insercao_b20,tempo_insercao_b200,tempo_insercao_avl,tempo_insercao_quad;
            double tempo_busca_b20,tempo_busca_b200,tempo_busca_avl,tempo_busca_quad;
            clock_t inicio,fim;

            //Tabela hash Para Auxiliar

            for(int i = 0; i < 5; i ++){

                ArvoreAvl * avl = new ArvoreAvl(true);
                ArvoreB * b20 = new ArvoreB(20);
                ArvoreB * b200 = new ArvoreB(200);
                QuadTree * quad = new QuadTree();
                
                //---------- S1 ----------
                int codigo;
                std::cout<<"\nN: "<<valores[i]<<endl;
                std::cout<<"S1) obter o total de casos de uma cidade"<<endl;
                std::cout<<"Digite o codigo da cidade: ";
                cin>>codigo;

                string data = "2020-06-19"; //data escolhida aleatoriamente apenas pq precisa dela
                bool encontrado = false;

                //Insere Avl
                inicio = clock();
                armazenarId(aux,NULL,avl,valores[i]);
                tempo_insercao_avl = (double) (clock() - inicio)/CLOCKS_PER_SEC; 

                //Busca Avl
                inicio = clock();

                if(avl->busca(aux->getDia(data)*codigo) != NULL)
                    encontrado = true;

                cout<<"Resultado avl: "<<encontrado<<endl;
                tempo_busca_avl = (double)(clock() - inicio)/CLOCKS_PER_SEC;

                //Insere B20
                inicio = clock();
                armazenarId(aux,b20,NULL,valores[i]);
                tempo_insercao_b20 = (double) (clock() - inicio)/CLOCKS_PER_SEC; 

                //Busca B20
                inicio = clock();
                encontrado = b20->buscarValue(aux->getDia(data)*codigo);
                cout<<"Resultado B20: "<<encontrado<<endl;
                tempo_busca_b20 = (double) (clock() - inicio)/CLOCKS_PER_SEC;

                //Insere B200
                inicio = clock();
                armazenarId(aux,b200,NULL,valores[i]);
                tempo_insercao_b200 = (double) (clock() - inicio)/CLOCKS_PER_SEC;

                //Busca B200
                inicio = clock();
                encontrado = b200->buscarValue(aux->getDia(data)*codigo);
                cout<<"Resultado B200: "<<encontrado<<endl;
                tempo_busca_b200 = (double) (clock() - inicio)/CLOCKS_PER_SEC;

                //Resultado da busca
                if(encontrado == true){
                    InfoCidade ic = aux->getCidade(aux->search(data,codigo));
                    cout<<"Total de casos de "<<ic.getNomeCidade()<<": "<<ic.getCasos()<<endl;
                }
                printf("\n");

                //---------- S2 ----------
                int x,y,tam;
                std::cout<<"S2) Obter o total de casos nas cidades contidas no intervalo"<<endl;
                std::cout<<"Digite o quadrante na forma (x,y,tam): ";
                cin>>x>>y>>tam;

                //Insere Quad
                inicio = clock();
                leituraCoordenadas(quad,5570);
                tempo_insercao_quad = (double) (clock() - inicio)/CLOCKS_PER_SEC;

                //Busca Quad
                inicio = clock();
                vector<Cidade> vetCidade = quad->buscaQuadrante(x,y,tam);
                tempo_busca_quad = (double) (clock() - inicio)/CLOCKS_PER_SEC;    

                //Mostra resultado na tela
                cout<<vetCidade.size()<<" cidades encontradas."<<endl;
                int casos = 0;
                for(int c = 0; c < vetCidade.size(); c++){
                    casos += vetCidade[c].codigo_cidade;
                }

                //Salvando no saida.txt
                saida<<"Valor de N: "<< valores[i]<<endl;
                saida<<"Avl tempo_busca: "<<tempo_busca_avl<<" tempo_insercao: "<<tempo_insercao_avl<<" comparacoes: "<<avl->getComparacao()<<endl;
                saida<<"B20 tempo_busca: "<<tempo_busca_b20<<" tempo_insercao: "<<tempo_insercao_b20<<" comparacoes: "<<endl;
                saida<<"B200 tempo_busca: "<<tempo_busca_b200<<" tempo_insercao: "<<tempo_insercao_b200<<" comparacoes: "<<endl;
                saida<<"Quad tempo_busca: "<<tempo_busca_quad<<" tempo_insercao: "<<tempo_insercao_quad<<" comparacoes: "<<endl;
                saida<<endl;
            }
        }
    }
    else{
        cout<<"Erro não foi possivel encontrar o arquivo \"saida.txt\"."<<endl;
        exit(1);
    }
}

int main(int tam_args, char ** args){

    if(tam_args == 1){
        cout<<"Erro: Esqueceu de passar o caminho para pasta!"<<endl;
        exit(1);
    }

    
    PATH = args[1];

    std::cout<<"----- Etapa 1 -----"<<endl;
    std::cout<<"Lendo arquivo brazil_cities_coordinates.csv ..."<<endl;

    QuadTree * a = new QuadTree();
    etapa1(a);

    //--------------------------------------------------------------------

    std::cout<<"\n----- Etapa 2 -----"<<endl;
    std::cout<<"Lendo arquivo brazil_covid19_cities_processado.csv ..."<<endl;
    
    TabelaHash * tabela = new TabelaHash(1431490*11);
    etapa2(tabela);
    std::cout<<tabela->getColisoes()<<" colisoes."<<endl;

    //--------------------------------------------------------------------

    std::cout<<"\n----- Etapa 3-----"<<endl;
    std::cout<<"Testando implementaçãos ArvoreB e ArvoreAvl..."<<endl; 
    
    etapa3();

    //--------------------------------------------------------------------

    std::cout<<"\n----- Etapa 4 -----"<<endl;
    std::cout<<"Modulo de Testes"<<endl;

    etapa4();

    //--------------------------------------------------------------------

    std::cout<<"\n----- Etapa 5 -----"<<endl;
    etapa5(tabela);
    
    return 0;
}