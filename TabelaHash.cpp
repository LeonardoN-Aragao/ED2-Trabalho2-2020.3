#include "TabelaHash.h"

TabelaHash::TabelaHash(int tam, int sond){
    tamanho = tam;
    tabela = new int[tamanho];
    colisoes = 0;

    for(int i = 0; i<tamanho; i++){
        tabela[i] = -1;
    }

    sondagem = sond;
}

void TabelaHash::add(int chave){
                
    for(int i = 0; i < tamanho; i++){
        
        int pos;

        if(sondagem == 1)
            pos = linear(chave,i);
        else
            pos = dupla(chave,i);

        if(tabela[pos] == -1){
            tabela[pos] = chave;
            return;
        }
        else
            colisoes++;
    }
}

int TabelaHash::search(int chave, int iteracoes){
    int resposta = -1;
    
    for(int i = 0; i < iteracoes; i++){
        int resposta;
        
        if(sondagem == 1)
            resposta = linear(chave,i);
        else
            resposta = dupla(chave,i);

        if (resposta == chave || resposta == -1)
            break;
    }

    return resposta;
}