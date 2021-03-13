#include <iostream>
#include "TabelaHash.h"
#include "InfoCidade.h"

TabelaHash::TabelaHash(long tam){
    tamanho = tam;
    tabela = new InfoCidade[tamanho]();
    colisoes = 0;
}

void TabelaHash::add(InfoCidade cidade){
    
    int chave = stoi(cidade.getData())+cidade.getCodigoCidade();

    for(int i = 0; i < 20; i++){
        
        int pos = linear(chave,i);

        if(tabela[pos].getCodigoCidade() == 0){
            tabela[pos] = cidade;
            return;
        }
        else{ // Re-hashing

            pos = dupla(chave,i);
            if(tabela[pos].getCodigoCidade() == 0){
                tabela[pos] = cidade;
                return;
            }
        }
    }
}

int TabelaHash::auxSearch(int chave, int iteracoes){
    int resposta = -1;
    
    for(int i = 0; i < iteracoes; i++){
        
        int resposta = linear(chave,i);

        if (resposta == chave || resposta == -1)
            break;
        else{

            resposta = dupla(chave,i);
            if (resposta == chave || resposta == -1)
                break;
        }
    }

    return resposta;
}