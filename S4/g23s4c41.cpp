#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


int main ()
{
    int n;
    ifstream data;
    ofstream data2;
    data.open("dados.txt");
    data2.open("resultados.txt");
    float h = 0;
    int n_iter;
    data >> n >> n_iter;
    float *V = new float[n];
    for (int i = 0; i< n_iter; i++)
    {
        data >> V[i];
    }

    for (int j = 0; j < n; j ++)
    {
        for (int i = 1; i < n -1; i++)
        {
            V[i] = (V[i-1] + V[i + 1])/2;
            data2 << V[i] << " "; ;
        }
        data2 << endl;
    }
    data.close();
    data2.close();
    delete[] V;
    return 0;
}
