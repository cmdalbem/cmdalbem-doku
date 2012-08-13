/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                10849 - Move the bishop
                                UVa username: cmdalbem
                                Accepted @ submission #8060263
*/
#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	long int ncases;
	cin>>ncases;
	
	for( int casei=0; casei<ncases; casei++ )
	{
		int nlines;
		cin>>nlines;
		int size;
		cin>>size;
		
		for( int line=0; line<nlines; line++ )
		{
			bool onemove=false;
			
			long int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			
			if( x1==x2 && y1==y2 )
				cout<<"0"<<endl;
			else
			{
				bool impar1 = (int)abs((float)x1-y1)% 2 ;
				bool impar2 = (int)abs((float)x2-y2)% 2;
				
				if( impar1 != impar2  )
					cout<<"no move"<<endl;
				else
				{
					int varx, vary;
					if(x2<x1) varx =-1;
						else  varx = 1;
					
					if(y2<y1) vary = -1;
						else  vary = 1;
						
					while( x1 >= 1 && y1 >= 1 && x1 <= size && y1 <= size)
					{
						x1 += varx;
						y1 += vary;
						if(x1==x2 && y1==y2)
							onemove=true;
					}					

					if(onemove)
						cout<<"1"<<endl;
					else
						cout<<"2"<<endl;
				}
			}
		}
	}

}
