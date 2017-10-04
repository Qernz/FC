#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double generator(double);

int main()
{
    int n_max; // numero de iteradas
    double x; // valor inicial

    // perguntar valores ao utilizador
    cout << "Insira o numero de iteradas: ";
    cin >> n_max;
    cout << "Insira o valor da iterada inicial: ";
    cin >> x;

    // criar uma matrix para a tabela dos resultados
    double **table = new double *[2];
    for(int i =0; i<2; i++) table[i] = new double[n_max];


    int ni = 0, ne = 0;
    ofstream piconv;
    piconv.open("piconv.txt");
    for(int d = 1; d < n_max; d++)
    {
        for(int n = 0; n < d; n++)
        {
            table[0][n] = x / pow(2., 32);
            x = generator(x);
            table[1][n] = x / pow(2., 32);

            if (sqrt(pow(table[0][n], 2) + pow(table[1][n], 2)) < 1) ni ++;
            else ne ++;
        }
        piconv << d << " " << 4 * (((float)ni) / ((float)ni + (float)ne)) << endl;
    }
    piconv.close();

    for(int i = 0; i < 2; i++) delete[] table[i];
    delete[] table;

    return 0;
}

double generator( double x)
{
    return fmod((1664525. * x + 1013904223.), pow(2., 32));
}
