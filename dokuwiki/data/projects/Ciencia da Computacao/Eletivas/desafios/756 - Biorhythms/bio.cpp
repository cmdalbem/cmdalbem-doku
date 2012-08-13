/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                756 - Biorhythms
                                UVa username: cmdalbem
                                Accepted @ submission #8047167
*/
#include <iostream>
using namespace std;
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>


bool myfunction(int i, int j)
{
    return (i < j);
}

struct myclass {
    bool operator() (int i, int j) {
        return (i < j);
}}
myobject;


int lesser(int a, int b, int c)
{
    vector < int >myvector;
    myvector.push_back(a);
    myvector.push_back(b);
    myvector.push_back(c);
    vector < int >::iterator it;
    sort(myvector.begin(), myvector.end());
    return myvector[0];
}


int main()
{
    int a, b, c, days;
    int caso = 0;

    while (cin >> a >> b >> c >> days && a != -1 && b != -1 && c != -1 && days != -1) {
        caso++;
        long int x = a, y = b, z = c;
        int count = 0;
        
        while(days>21252)
			days-=21252;

        do {
			do {
                int l = lesser(x, y, z);
                if (l == x)
                    x += 23;
                else if (l == y)
                    y += 28;
                else {
                    z += 33;
                    count++;
                }
            } while (x != y || x != z);
        } while (x == days);

        if (x - days > 21252)
            x -= 21252;

		if (days > x) {
			x+=21252-days;
			days=0;
		}

        cout << "Case " << caso << ": the next triple peak occurs in " << x-days << " days." << endl;
    }

}
