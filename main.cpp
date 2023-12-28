#include <iostream>
#include "TADArvore.h"
#include "FuncoesJogoVelha.h"
#include "OperacoesNaoPrimitivas.h"

#include <iostream>
#include "TADArvore.h"

using namespace std;

int main()
{
    vector<char> tabuleiro(9, ' ');
    vector<char> tabuleiroInstr(9);

    for(int i = 0; i < 9; i++){
        char posicao = '0' + i;
        tabuleiroInstr[i] = posicao;

    }

    cout << "---------- JOGO DA VELHA ----------" << endl << endl;

    cout << "INSTRUCOES: As posicoes de 0 a 8 indicam as casas do tabuleiro, sendo 0 a primeira casa na primeira linha: " << endl;
    cout << "USUARIO : X | COMPUTADOR: O" << endl;
    ImprimirTabuleiro(tabuleiroInstr);
    cout << endl << endl;

    while(true){
        ImprimirTabuleiro(tabuleiro);
        if(Vitoria(tabuleiro, 'X')){
            cout << "Voce venceu! " << endl;
            break;
        }else if(Vitoria(tabuleiro, 'O')){
            cout << "Eu venci! " << endl;
            break;
        }else if(DeuVelha(tabuleiro)){
            cout << "oops, deu velha!" << endl;
            break;
        }

        int pos;
        cout << "Digite a posicao (0 a 8)" << endl; // primeira linha  0 1 2
        cin >> pos;

        if(pos < 0 || pos > 8 || tabuleiro[pos] != ' '){
            cout << "Posição inválida! " << endl << endl;
            continue;
        }

        tabuleiro[pos] = 'X';
        JogarMaquina(tabuleiro);

    }


    return 0;
}
