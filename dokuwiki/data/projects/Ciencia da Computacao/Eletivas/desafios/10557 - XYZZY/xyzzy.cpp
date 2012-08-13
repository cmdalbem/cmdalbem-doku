/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                10557 - XYZZY
                                UVa username: cmdalbem
                                Subsmission #: 7957557



OBS: código foi feito praticamente por inteiro junto do grupo durante a aula. isso quer dizer que ele deve estar idêntico para com os dos colegas.
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define NEGINFINITY -9999



struct Edge {
    int source;
    int dest;
    int weight;
};


//bool doorways[100][100];
vector<Edge> doorways;
int rooms[100];

char * output[2] = {"hopeless", "winnable"};
enum { LOSE, WIN };


bool hascycle = false;
set<int> ciclo;
set<int> acessiveis;

bool BellmanFord(vector<Edge> edges, int edgecount, int nodecount, int source, int exit) {

    int energia[100];
    
    int i,j,trocou;
    for (i = 0; i < nodecount; i++) {
       energia[i] = NEGINFINITY;
    }
    energia[source]=100;
    ciclo.clear();
    acessiveis.clear();
	acessiveis.insert(source);
    
    for (i = 0; i < nodecount ; i++) {
       trocou = 0;
       for (j = 0; j < edgecount; j++) {
          if ( energia[edges[j].dest] < energia[edges[j].source] + edges[j].weight  &&
               (energia[edges[j].source] + edges[j].weight) > 0 && acessiveis.find( edges[j].source ) != acessiveis.end() )
          {
             if( i== nodecount -1 ){
			//	cout << edges[j].dest << " ";
				ciclo.insert( edges[j].dest );
			}
             acessiveis.insert( edges[j].dest );
		     //cout << edges[j].dest << " ";
             energia[edges[j].dest] = energia[edges[j].source] + edges[j].weight;
             trocou=1;
          }
       }
       // se nenhuma iteração teve efeito, futuras iterações estão dispensadas
       if (trocou==0) break;

    }
    
           if ( trocou==1 )
           {
			//ciclo.insert(source);
//                cout<<"ciclo"<<endl;
               for ( int k = 0; k < nodecount; k++) {
                   for (j = 0; j < edgecount; j++) {
                        if( ciclo.find( edges[j].source ) != ciclo.end() )
                            ciclo.insert( edges[j].dest );
                    }
                }
                if( ciclo.find( exit ) != ciclo.end() )
                    return true;
				else
					return false;
                }
               
                
    // usado somente para detectar ciclos negativos (dispensável)
    //for (i = 0; i < edgecount; i++) {
     //  if (energia[edges[i].dest] > energia[edges[i].source] + edges[i].weight) {
     //     cout << "Ciclo negativo de pesos de arestas detectado" << endl;
     //     break;
    //   }
    //}
    //for (i = 0; i < nodecount; i++) {
    //   //cout << "A energia mais curta entre os nodos " << source << " e " << i <<" eh " << energia[i] << endl;

        if (energia[exit] > 0)
            return true;
        else
            return false;
   // }
 }
 



int main()
{
    int total_rooms = 0;

    while(cin >> total_rooms && total_rooms != -1)
    {
       // static int ncase=0;
        //if(ncase!=0)
        //    cout<<endl;
        //++ncase;
        
        
        /*for(int i = 0; i < total_rooms; i++)
            for(int j = 0; j < total_rooms; j++)
                doorways[i][j] = false;*/
        doorways.resize(0);
        hascycle=false;

        int room_energies[100];

        for(int i = 0; i < total_rooms; i++)
        {
            int room_energy, room_doorways;

            cin >> room_energy >> room_doorways;
            
            room_energies[i] = room_energy;
            
            for(int j = 0; j < room_doorways; j++)
            {
                int room_id;
                cin >> room_id;

                //doorways[i][room_id] = doorways[room_id][i] = true;
                
                Edge doorway;
                    doorway.source = i;
                    doorway.dest = room_id -1;
                    //doorway.weight = room_energy;
                doorways.push_back( doorway );
            }
        }

        for(int i=0; i<doorways.size(); i++)
            doorways[i].weight = room_energies[ doorways[i].dest ];
        
        //for(int i=0; i<doorways.size(); i++)  cout<<doorways[i].source << " -> " << doorways[i].dest << " = " << doorways[i].weight << endl;
    
        
        
        bool answer = BellmanFord(doorways, doorways.size(), total_rooms, 0, total_rooms-1);
        


        cout << output[answer] << endl;
    }

    return 0;
}
