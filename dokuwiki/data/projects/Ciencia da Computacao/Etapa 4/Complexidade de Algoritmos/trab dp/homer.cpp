#include <cstdio>
#include <cstdlib>

using namespace std;



typedef struct{
    int beerCount;
    int hambCount;
} structure;




void clearStructure(structure * state, int size){
    for(int i = 0; i < size; i++){
        state[i].beerCount = 0;
        state[i].hambCount = 0;
    }
}


int min(int a, int b){
    if (a > b) return b;
    else       return a;
}

int max(int a, int b){
    if (a > b) return a;
    else       return b;
}

structure min(structure a, structure b){
    if (a.beerCount < b.beerCount)
        return a;
    if (a.beerCount > b.beerCount)
        return b;
    else
        if (a.hambCount > b.hambCount)
            return a;
        else
            return b;
}



int main(){
    int m, n, t, smaller, bigger;


    while( scanf("%d %d %d", &m, &n, &t) != EOF){
        
				structure state [ t + 1 ];
				clearStructure(state, t + 1);
        

				smaller = min(m, n);
    		bigger  = max(m, n);

        for(int i = 0; i < t + 1; i++){
					
					
            if (i < smaller){
							
                state[i].beerCount = i;
                state[i].hambCount = 0;
            }
            else if (i < bigger){
										
	                    state[i].beerCount = state[i - smaller].beerCount;
	                    state[i].hambCount = 1 + state[i - smaller].hambCount;
	                }
	                else{               
										
	                    structure minState = min (state[i - n], state[i - m]);
	                    
	                    state[i].beerCount = minState.beerCount;
	                    state[i].hambCount += minState.hambCount + 1;
	                }
	                
            //printf("beer_vector[%d] = %d\n", i, state[i].beerCount);
            //printf("hamb_vector[%d] = %d\n", i, state[i].hambCount);            
        }
        
        
        //PRINT
        if( state[t].beerCount )
        		printf("%i %i\n",state[t].hambCount,state[t].beerCount);
        else
					  printf("%i\n",state[t].hambCount);

    }



}
