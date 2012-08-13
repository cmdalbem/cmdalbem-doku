/*
UFRGS -  INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Março de 2010

                                10189 - Minesweeper
                                UVa username: cmdalbem
                                Subsmission #: 7817406                           

*/



#include <iostream> 
using namespace std; 

#define MINA -1
#define VAZIO 0


void printCell(int val)
{
    if( val == MINA) 
        cout << "*";
    else
        cout << val;
}



int main()
{
   int x, y;
   int nfields=1;
   
   while( cin >> x >> y  &&  (x!=0 || y!=0) )
   {     
                  int m[x][y];
        
                  for(int lin=0; lin<x; lin++)
                      for(int col=0; col<y; col++)
                      {
                          char entry;
                          cin>>entry;
                          
                          if(entry == '*')
                             m[lin][col] = MINA;
                          else
                             m[lin][col] = VAZIO;
                      }
                         
                  if(nfields!=1)
                    cout << endl;
                  cout << "Field #" << nfields << ":" << endl;


                  
                  //iterar na matriz:
                  for(int lin=0; lin<x; lin++)
                  {
                      if(lin!=0)
                       cout<<endl;    
                      for(int col=0; col<y; col++)
                      {
                              if(m[lin][col] != MINA)
                              {
                                  int nmines = 0;
            
                                  //iterar na 8-vizinhança:
                                  for(int linDif =-1; linDif<=1; linDif++)
                                      for(int colDif =-1; colDif<=1; colDif++)
                                            if( lin+linDif>=0 && col+colDif >=0 && lin+linDif<x && col+colDif<y) //check boundaries
                                                if(m[lin+linDif][col+colDif] == MINA)
                                                    nmines++;
                                   
                                  m[lin][col] = nmines;
                              }
        
                              printCell(m[lin][col]);
                      }  
                   }
                   
                   
                   cout << endl;
                                    
                   nfields++;
   }    
   
     
}
