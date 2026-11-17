#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

/*
Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .
*/

int main() {
    int strHrs, strMin, endHrs, endMin, durHrs, durMin;
    cin >> strHrs >> strMin >> endHrs >> endMin;

    durHrs = endHrs - strHrs;
    durMin = endMin - strMin;

    if(durHrs == 0 && durMin == 0) {
        durHrs = 24;
    }

    if(endMin < strMin) {
        durHrs -= 1;
        durMin = 60 - (strMin - endMin);
    }

    if(durHrs < 0) {
        durHrs = 24 - (durHrs * -1);
    }

    cout << "O JOGO DUROU " << durHrs << " HORA(S) E " << durMin << " MINUTO(S)" << endl;

    return 0;
}
