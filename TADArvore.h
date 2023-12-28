#ifndef TADARVORE_H_INCLUDED
#define TADARVORE_H_INCLUDED

#include <iostream>
#include <vector>
#include <locale.h>

#include "FuncoesJogoVelha.h"
using namespace std;

struct Node{
    vector<char> tabuleiro;
    vector<Node*> filhos;
    int pontuacao;
};

typedef struct Node* NodePtr;
typedef struct Node* Arvore;

void Cria(Arvore &R) {
    R = NULL;

}

bool Vazia(Arvore &R) {
    return R == NULL;
}

NodePtr Insere(Arvore &R, const vector<char> &tabuleiro) {
    NodePtr No = new Node;
    No->tabuleiro = tabuleiro;
    No->pontuacao = 0;
    R = No;
    return R;
}

void Remove(Arvore &R){
    if(Vazia(R))
        return;

    for(NodePtr filho : R->filhos){
        Remove(filho);
    }
    delete R;
}





#endif // TADARVORE_H_INCLUDED
