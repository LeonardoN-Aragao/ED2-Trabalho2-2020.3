#include <iostream>
#include "ArvoreAvl.h"
#include "QuadTree.h"

using namespace std;

/*
    QuadTree
    TabelaHash  Dimensione a tabela adequadamente e função de hash que permita
                uma boa distribuição de chaves na tabela.
                Escolha também uma técnica para tratamento de colisões.
                Utilize como chave o par (código da cidade, data).
    Árvore AVL  Inserção e busca
    Árvore B    Inserção e busca
*/

int main(){

    QuadTree a;

    srand(0);
    for(int i = 0; i < 10;i++){
        cout<<a.inserir(rand()%100,rand()%100)<<endl;
    }
    
    return 0;
}