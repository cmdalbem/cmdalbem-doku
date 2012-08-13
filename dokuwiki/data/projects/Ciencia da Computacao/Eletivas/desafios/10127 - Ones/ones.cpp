/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                10127 - Ones
                                UVa username: cmdalbem
                                Accepted @ submission #7988990
*/
#include <iostream>
using namespace std;


int main()
{
    int num;
    int mult;
    
    while( cin >> num )
    {
        int digits=2;
        mult=11;    
        
        while( mult%num != 0 )
        {
            digits++;
            mult = (mult*10) + 1;
            mult = mult%num;
        }
        
        cout<<digits<<endl;
    }	
}

