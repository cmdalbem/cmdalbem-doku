/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                11121 - Base -2
                                UVa username: cmdalbem
                                Accepted @ submission #7991420
*/
#include <iostream>
using namespace std;
#include <vector>


int main()
{
	long long int n, num;
	cin >> n;
	
	for( int caso=0; caso<n; caso++ )
	{
		vector<bool> final;
		cin>>num;
		
		
		if(num==0)
			final.push_back(0);
		else
			while( true )
			{
				if(!num)
					break;
				
				int resto = num%(-2);
				
				if( resto == -1 )
				{
					final.push_back(1);
					num = num/(-2) + 1;
				}
				else
				{				
					final.push_back(resto);
					num = num/(-2);
				}
			}
        
        cout<<"Case #"<<caso+1<<": ";
        vector<bool>::reverse_iterator rit;
        for(rit=final.rbegin(); rit<final.rend(); rit++)
			cout<<*rit;
		cout<<endl;
	}
}
