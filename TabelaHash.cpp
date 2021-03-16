#include <iostream>
#include "TabelaHash.h"
#include "InfoCidade.h"

TabelaHash::TabelaHash(long tam){
    tamanho = tam;
    tabela = new InfoCidade[tamanho]();
    colisoes = 0;
}

void TabelaHash::add(InfoCidade cidade){
    
    int chave = getDia(cidade.getData())*cidade.getCodigoCidade();

    for(int i = 0; i < 20; i++){
        
        int pos = dupla(chave,i);

        if(tabela[pos].getCodigoCidade() == 0){
            tabela[pos] = cidade;
            return;
        }
        else{ // Re-hashing

            colisoes ++;

            pos = linear(chave,i);
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
        
        int resposta = dupla(chave,i);

        if (resposta == chave || resposta == -1)
            break;
        else{

            resposta = linear(chave,i);
            if (resposta == chave || resposta == -1)
                break;
        }
    }

    return resposta;
}

vector<InfoCidade> TabelaHash::getRegistros(int n){
    vector<InfoCidade> vet;

    for(int i = 0; i< n; i++){
        vet.push_back(tabela[rand()%tamanho]);
    }

    return vet;
}