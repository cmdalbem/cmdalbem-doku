#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define MAX 100000

void insertion_sort(float vetor[], int tam)
{
    float key;

    for(int k=1;k<tam;k++)
    {
        key = vetor[k];
        int i=k-1;
        while(i>=0 && vetor[i]>key)
        {
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = key;
    }    
}
void insertion_sort_Binary(float vetor[], int tam, int tipo)
{
    float key;
    char Input[100];


    
    for(int k=1;k<tam;k++)
    {
        int pos=k/2;
        int endpos=k;
        int delta=k;
        key = vetor[k];
		while(delta!=1)
        //iterações para cada inserção
        {
            delta=delta/2;
                
            int desl = (int)ceil ( (float) (endpos-pos)/2 );
            if(desl==0)
                desl=1;

            if(key > vetor[pos])
                pos = pos+desl;
            else
            {
                int postemp=pos;
                pos = pos-desl;
                endpos=postemp;
            }
            
        }
        
        //-----------DESLOCAMENTOS------------//
        if(key > vetor[pos])
          pos++;
        switch(tipo)
        {
            case 1:
                //deslocamento clássico
                for(int i=k; i!=pos; i--)
                    vetor[i]=vetor[i-1];
                break;                
            case 2:
                //deslocamento por memcpy
                memcpy(&vetor[pos+1] , &vetor[pos] , (k-pos)*sizeof(int));
                break;
                
            case 3:
                //deslocamento por memmov
                memmove(&vetor[pos+1] , &vetor[pos] , (k-pos)*sizeof(int));
                break;
        }
        vetor[pos] = key;
    }    
}





int main()
{
    FILE *reg;
    reg = fopen("reg.txt", "a+");
    int tam = 0;
    
    clock_t start, end;
    float tempo;
    
    char Input[50];
    
    float vetor[MAX];
    srand(1);
    for(int i=0;i<MAX;i++)
    {
        vetor[i] = rand() % 100000;
    }

    for(int caso=0;caso<4;caso++)
    {
        switch(caso)
        {
            case 0:
                sprintf(Input,"Insertion Sort Clássico\n\n");    
                break;
            case 1:
                sprintf(Input,"\n\nInsertion Sort com Busca Binária\n\n");
                break;
            case 2:
                sprintf(Input,"\n\nInsertion Sort com MEMCPY\n\n");
                break;
            case 3:
                sprintf(Input,"\n\nInsertion Sort com MEMMOVE\n\n");
                break;
        }            
        fwrite(Input, strlen(Input), 1, reg);
        
        tam = 0;
        for(int tams=0;tams<10;tams++)
        //laço no número de entradas do vetor
        {
            tam = tam + 10000;
            tempo = 0;
            
            for(int cont_media=0;cont_media<10;cont_media++)
            {
                    switch(caso)
                    {
                        case 0:
                            printf("classico: %i elementos - %i0%%",tam,cont_media);
                            break;
                        case 1:
                            printf("busca binaria: %i elementos - %i0%%",tam,cont_media);
                            break;
                        case 2:
                            printf("busca binaria (memcpy): %i elementos - %i0%%",tam,cont_media);
                            break;
                        case 3:
                            printf("busca binaria (memmove): %i elementos - %i0%%",tam,cont_media);
                            break;
                    }
    
                    float vetor_atual[tam];
                    for(int i=0;i<tam;i++)
                    {
                        vetor_atual[i] = vetor[i];
                    }
                    
                    /*IMPRIMIR VETOR INICIAL
                    printf("\n\n");
                    for(int i=0;i<tam;i++)
                        printf("%.0f - ",vetor_atual[i]); */
            
                    start = clock();
                    if(caso==0)
                        insertion_sort(vetor_atual, tam);
                    else
                        insertion_sort_Binary(vetor_atual, tam, caso);
                    end = clock();        
                    tempo = tempo + (float) (end - start) / CLOCKS_PER_SEC;
            
                    /*IMPRIMIR VETOR FINAL
                    printf("\n\n");
                    for(int i=0;i<tam;i++)
                        printf("%.0f - ",vetor_atual[i]);
                    printf("\n\n");
                    system("pause"); */
                    
                    system("cls");
            }
    
            char Input[100];
            sprintf(Input,"%i elementos: %g segundos\n",tam,tempo/10);
            fwrite(Input, strlen(Input), 1, reg);
        }
    }            
            
            
    fclose(reg);
    printf("\n\n");
    system("pause");
}
