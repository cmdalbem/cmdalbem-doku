/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                10541 - Stripe
                                UVa username: cmdalbem
                                Accepted @ submission #

*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>


#define VERBOSE 0


long long int output;
int n, length, ncode, acode;
static bool rect[200];



void processPermutation()
{
	bool okay=true;
	int nfound=0;

	if(VERBOSE)
	{
		for( int it=0; it<length; it++ )
			cout<<rect[it];
		cout<<" -> ";			
	}
	
	for( int it=0; it<length && okay && nfound<ncode; it++ )
		if( rect[it] )
			if(  (it==0 || rect[it-1]==false)  &&  (it==length-1 || rect[it+1]==false)  )
			{
				okay = true;
				nfound++;
			}
			else
				okay = false;
				
			
	if(okay)
		output++;				
	
	
	if(VERBOSE) cout<<okay<<endl;	
}


int main()
{
	cin>>n;
	
	for( int ni=0; ni<n; ni++ )
	{
		output=0;
			
		cin>>length;
		cin>>ncode;
		if( ncode==0 )
			output=1;
		else
		{
			//entrada
			for( int codei=0; codei<ncode; codei++ )
			{
				cin>>acode;
				if( acode > 1)
					length -= acode-1;
			}
			
			for( int i=0; i<length; i++ )
				rect[i] = false;			
			for( int i=0; i<ncode; i++ )
				rect[length-i-1] = true;
			
			
			//permutações
			do{
				processPermutation();
			}while( next_permutation(rect,rect+length) );
		}
		
		
		cout<<output<<endl;
	}
	
	
	
	return 0;	
}
