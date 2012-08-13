// Aluno: Gustavo Garcia Valdez e Cristiano Dalbem
// Conta no UVa: cmdalbem
// Problema: 11069 - A Graph Problem
// Código da Submissão Aceita: 7985513
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a, matriz[77] = {1, 1, 2, 2, 3};
    for (int i = 5; i < 77; i++)
        matriz[i] = matriz[i-2] + matriz[i-3];

    while(cin >> a)
              cout << matriz[a] << endl;  
}
