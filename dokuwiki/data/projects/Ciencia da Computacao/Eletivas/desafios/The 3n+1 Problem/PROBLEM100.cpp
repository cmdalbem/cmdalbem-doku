#include <iostream> 
using namespace std; 


int max(int a, int b)
{
    if (a>b)
       return a;
    else
        return b;
}

int cycleLength(int n)
{
   int cycle_length=1;
   while(n!=1)
   {
              cycle_length++;
              
              if( n%2==0 )
                  n = n/2;     
              else
                  n = 3*n + 1;
   }
   return cycle_length;
}


int main()
{
   int e1, e2;
   int n1, n2;
   
   while( cin >> e1 >> e2 )
   {
       if(e1>e2)
       {
          n2=e1;
          n1=e2;
       }
       else
       {
           n1=e1;
           n2=e2;
       }
          
       int maxCycle = 0;
       
       for(int k=n1; k<=n2; k++)
               maxCycle = max(maxCycle, cycleLength(k));   
               
       printf("%i %i %i\n", e1, e2, maxCycle);
   }      
}
