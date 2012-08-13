// Aluno: Gustavo Garcia Valdez e Cristiano Dalbem
// Conta no UVa: cmdalbem
// Problema: 10790 - How Many Points of Intersection?
// Código da Submissão Aceita: 7985516
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned long int a, b;
    int i = 1;
    while(true){
        cin >> a >> b;
        if (a == 0 && b == 0)
           return 0;
        cout<< "Case " << i++ << ": " << ((a-1)*(a)*(b-1)*(b))/4 << endl;
    }
}
