/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Abril de 2010

                                10050  	Hartals
                                UVa username: cmdalbem
                                Subsmission #: 7875071

*/



#include <iostream>
using namespace std;
#include <set>

#define VERBOSE 0


int simulate(int ndays,int nparties,int hparams[])
{
    set<int> hartals;
    
    
    
    for( int party=0; party<nparties; party++ )
    {
         int today=hparams[party];
         
         while( today <= ndays )
         {
                if( today%7!=6 && today%7!=0 )
                    hartals.insert(today);
                
                today += hparams[party];
         }
         
    }
    
    
    return hartals.size();
}




int main()
{
    int ncases;
    
    cin >> ncases;
    
    for( int caso=0; caso<ncases; caso++ )
    {
        //if(caso!=0)
            //cout<<endl;
                
         int ndays;
         cin >> ndays;
         
         int nparties;
         cin >> nparties;
         
         int hparams[nparties];
         for( int party=0; party<nparties; party++)
              cin >> hparams[party];
         
         
         cout << simulate(ndays,nparties,hparams) << endl;
    }
    
}
