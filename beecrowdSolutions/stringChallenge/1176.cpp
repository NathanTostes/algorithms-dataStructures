#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

/*
Faça um programa que leia um valor e apresente o número de Fibonacci correspondente a este valor lido. Lembre que os 2 primeiros elementos da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele. Todos os valores de Fibonacci calculados neste problema devem caber em um inteiro de 64 bits sem sinal.

Entrada
A primeira linha da entrada contém um inteiro T, indicando o número de casos de teste. Cada caso de teste contém um único inteiro N (0 ≤ N ≤ 60), correspondente ao N-esimo termo da série de Fibonacci.

Saída
Para cada caso de teste da entrada, imprima a mensagem "Fib(N) = X", onde X é o N-ésimo termo da série de Fibonacci.
*/

int main() {
    long long fib1, fib2, aux;
    int cases;

    int currentFib;

    cin >> cases;

    for(int i = 0; i < cases; i++) {
        cin >> currentFib;
        fib1 = 0;
        fib2 = 1;
        for(int j = 0; j < currentFib; j++) {
            aux = fib1;
            fib1 = fib2;
            fib2 = (fib1+aux);
        }
        cout << "Fib(" << currentFib << ") = " << fib1 << endl;

    }

    return 0;
}
