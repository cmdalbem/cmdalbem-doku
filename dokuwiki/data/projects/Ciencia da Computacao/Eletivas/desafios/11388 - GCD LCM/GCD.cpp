/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                11388 - GCD LCM
                                UVa username: cmdalbem
                                Accepted @ submission #8046999
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	for(int caso=0; caso<n; caso++)
	{
        int g,l;
        cin >> g >> l;
        if(l % g == 0)
            cout<<g<<" "<<l<<endl;
        else
            cout<<"-1"<<endl;
	}
		
}
