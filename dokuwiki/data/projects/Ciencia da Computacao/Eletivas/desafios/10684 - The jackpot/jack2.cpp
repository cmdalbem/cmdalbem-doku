/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                10684 - The jackpot
                                UVa username: cmdalbem
                                Accepted @ submission #7970241

*/

#include<iostream>
using namespace std;

int main()
{
	int nbets, sum, max;
	int m[10000];
	
	while( cin>>nbets && nbets!=0 )
	{
				
		for( int bet=0; bet<nbets; bet++ )
			cin >> m[bet];
			
		sum = 0;
		max = 0;

		for(int i = 0; i < nbets; i++)
		{
			sum += m[i];
			if(sum < 0)
				sum = 0;
			if(max < sum)
				max = sum;
		}
	
		if(max == 0)
			cout << "Losing streak." << endl;
		else
			cout << "The maximum winning streak is " << max << "." << endl;
	}
	
	
	return 0;
}
