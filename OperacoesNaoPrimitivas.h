#ifndef OPERACOESNAOPRIMITIVAS_H_INCLUDED
#define OPERACOESNAOPRIMITIVAS_H_INCLUDED

#include "TADArvore.h"
#include "FuncoesJogoVelha.h"

NodePtr GeraArvore(const vector<char>& tabuleiro, char jogador) {
    Arvore R;
    Cria(R);
    Insere(R, tabuleiro);

    if (Vitoria(tabuleiro, 'X') || Vitoria(tabuleiro, 'O')) {
        R->pontuacao = CalculaPontuacao(tabuleiro, jogador);
        return R;
    }

    if (DeuVelha(tabuleiro)) {
        R->pontuacao = 0;
        return R;
    }

    char oponente = (jogador == 'X') ? 'O' : 'X';

    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] == ' ') {
            vector<char> novoTabuleiro = tabuleiro;
            novoTabuleiro[i] = jogador;
            R->filhos.push_back(GeraArvore(novoTabuleiro, oponente));
        }
    }
    return R;
}

void JogarMaquina(vector<char>& tabuleiro) {
    int melhorPontuacao = -10000;
    vector<int> melhoresJogadas;

    NodePtr Raiz = GeraArvore(tabuleiro, 'O');

    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] == ' ') {
            tabuleiro[i] = 'O';

            int pontuacao = Minimax(tabuleiro, 'X', 5); // Considerando que no caso de velha, a altura máxima é 9 -> 6 foi escolhido para dar uma boa inteligência ao jogo.

            tabuleiro[i] = ' '; // Desfaz a jogada

            if (pontuacao > melhorPontuacao) {
                melhorPontuacao = pontuacao;
                melhoresJogadas.clear();
                melhoresJogadas.push_back(i);
            } else if (pontuacao == melhorPontuacao) {
                melhoresJogadas.push_back(i);
            }
        }
    }

    if (!melhoresJogadas.empty()) {
        int melhorJogada = melhoresJogadas[rand() % melhoresJogadas.size()];
        tabuleiro[melhorJogada] = 'O';
    }

    Remove(Raiz);
}
#endif // OPERACOESNAOPRIMITIVAS_H_INCLUDED
