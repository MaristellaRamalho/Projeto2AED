#ifndef FUNCOESJOGOVELHA_H_INCLUDED
#define FUNCOESJOGOVELHA_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

void ImprimirTabuleiro(const vector<char>& tabuleiro) {
    for (int i = 0; i < 9; i += 3) {
        cout << " " << tabuleiro[i] << " | " << tabuleiro[i + 1] << " | " << tabuleiro[i + 2] << endl;
        cout << "------------" << endl;
    }
}

bool Vitoria(const vector<char>& tabuleiro, char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i] == jogador && tabuleiro[i + 3] == jogador && tabuleiro[i + 6] == jogador)
            return true;
    }

    for (int i = 0; i < 9; i += 3) {
        if (tabuleiro[i] == jogador && tabuleiro[i + 1] == jogador && tabuleiro[i + 2] == jogador)
            return true;
    }

    if (tabuleiro[0] == jogador && tabuleiro[0] == tabuleiro[4] && tabuleiro[0] == tabuleiro[8])
        return true;

    if (tabuleiro[2] == jogador && tabuleiro[2] == tabuleiro[4] && tabuleiro[2] == tabuleiro[6])
        return true;

    return false;
}

bool DeuVelha(const vector<char>& tabuleiro) {
    for (char caractere : tabuleiro) {
        if (caractere == ' ')
            return false;
    }
    return true;
}

int CalculaPontuacao(const vector<char>& tabuleiro, char jogador) {
    if (Vitoria(tabuleiro, 'X'))
        return -1; // vitória usuário
    else if (Vitoria(tabuleiro, 'O'))
        return 1; // vitória máquina
    else
        return 0; // empate
}

int Minimax(vector<char>& tabuleiro, char jogador, int profundidade) {
    if (Vitoria(tabuleiro, 'X'))
        return -1; // vitória usuário
    else if (Vitoria(tabuleiro, 'O'))
        return 1; // vitória máquina
    else if (DeuVelha(tabuleiro) || profundidade == 0)
        return 0; // empate ou limite de profundidade atingido

    int melhorPontuacao = (jogador == 'O') ? -10000 : 10000;

    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] == ' ') {
            tabuleiro[i] = jogador;

            int pontuacao = Minimax(tabuleiro, (jogador == 'X') ? 'O' : 'X', profundidade - 1);

            tabuleiro[i] = ' '; // Desfaz a jogada

            if ((jogador == 'O' && pontuacao > melhorPontuacao) || (jogador == 'X' && pontuacao < melhorPontuacao)) {
                melhorPontuacao = pontuacao;
            }
        }
    }

    return melhorPontuacao;
}



#endif // FUNCOESJOGOVELHA_H_INCLUDED
