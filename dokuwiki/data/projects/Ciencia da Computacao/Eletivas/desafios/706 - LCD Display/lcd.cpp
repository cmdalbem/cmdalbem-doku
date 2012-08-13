/*
UFRGS -  INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Março de 2010

                                706 - LCD Display
                                UVa username: cmdalbem
                                Subsmission #: 7817395                                   

*/


#include <string>

#include <iostream> 
using namespace std; 


#define SIZE_X(x) x+2
#define SIZE_Y(x) x*2 +3

#define VAZIO ' '

#define MAX_Y 23


void cleanBufferMatrix(int matrixSizeX, char matrix[][MAX_Y])
{
    for(int x=0; x<matrixSizeX; x++)
        for(int y=0; y<MAX_Y; y++)
            matrix[x][y] = VAZIO;  
}
                
void printBufferMatrix(int size_x, int size_y, char matrix[][MAX_Y])
{
    for(int y=0; y<size_y; y++)
    {
        for(int x=0; x<size_x; x++)
            printf("%c",matrix[x][y]);
        cout << endl;
    }
}


void recordNumber(int number, int size, int position, char matrix[][MAX_Y])
{
    switch(number)
    {
        case 0:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                
            
                matrix[position][k+1] = '|';
                matrix[position+size+1][k+1] = '|';

                matrix[position][k+size+2] = '|';
                matrix[position+size+1][k+size+2] = '|';
            }
            break;

        case 1:

            for(int k=0; k<size; k++)
            {
                matrix[size+position+1][k+1] = '|';

                matrix[size+position+1][k+size+2] = '|';
            }
                        
            break;
        case 2:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][size+1] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                

                matrix[position+size+1][k+1] = '|';

                matrix[position][k+size+2] = '|';
            }            
            
            break;
        case 3:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][size+1] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                

                matrix[size+position+1][k+1] = '|';

                matrix[size+position+1][k+size+2] = '|';
            }               
            
            break;
        case 4:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][size+1] = '-';             
            
                matrix[position][k+1] = '|';
                matrix[position+size+1][k+1] = '|';

                matrix[position+size+1][k+size+2] = '|';
            }            
            
            break;
        case 5:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][size+1] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                
            
                matrix[position][k+1] = '|';

                matrix[position+size+1][k+size+2] = '|';
            }            
            
            break;
        case 6:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][size+1] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                
            
                matrix[position][k+1] = '|';

                matrix[position][k+size+2] = '|';
                matrix[position+size+1][k+size+2] = '|';
            }            
            
            break;
        case 7:

            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
            
                matrix[position+size+1][k+1] = '|';

                matrix[position+size+1][k+size+2] = '|';
            }            
            
            break;
        case 8:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][size+1] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                
            
                matrix[position][k+1] = '|';
                matrix[position+size+1][k+1] = '|';

                matrix[position][k+size+2] = '|';
                matrix[position+size+1][k+size+2] = '|';
            }            
            
            break;
        case 9:
            
            for(int k=0; k<size; k++)
            {
                matrix[position+k+1][0] = '-';
                matrix[position+k+1][size+1] = '-';
                matrix[position+k+1][SIZE_Y(size)-1] = '-';                
            
                matrix[position][k+1] = '|';
                matrix[position+size+1][k+1] = '|';

                matrix[position+size+1][k+size+2] = '|';
            }            
            
            break;                                                                                                
        
        
    }
    
}


int main()
{
    string entry;
    int size;

    while( cin>>size>>entry  &&  entry.size()!=0 && size !=0 )
    {
           
        int matrixSizeX = ( (SIZE_X(size)+1)*entry.size() )  -  1;

        char bufferMatrix[matrixSizeX][MAX_Y];
        cleanBufferMatrix(matrixSizeX, bufferMatrix);

        //itera sobre cada dígito de entrada
        for( int k=0; k<entry.size(); k++ )
            recordNumber(entry[k] - '0', size, (size+3)*k, bufferMatrix);        
        
        printBufferMatrix(matrixSizeX, SIZE_Y(size), bufferMatrix);
        
        cout << endl;        
    }   

      
}
