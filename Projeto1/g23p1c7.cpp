#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double generator(double);
double** create_table(int, double, double(*g)(double));

int main()
{
    int n_max; // numero de iteradas
    double x; // valor inicial

    // perguntar valores ao utilizador
    cout << "Insira o numero de iteradas: ";
    cin >> n_max;
    cout << "Insira o valor da iterada inicial: ";
    cin >> x;

    // criar e enchar a uma matrix com uma tabela das iteradas
    double** table = create_table(n_max, x, &generator);

    int ni= 0; int ne = 0;

    // escrever os dados nos respetivos ficheiros
    ofstream dentro, fora;
    dentro.open("dentro.txt");
    fora.open("fora.txt");
    for(int n = 0; n < n_max; n++)
    {
        if (sqrt(pow(table[0][n], 2) + pow(table[1][n], 2)) < 1)
        {
            ni++;
            dentro << table[0][n] << " " << table[1][n] << endl;
        }
        else
        {
             ne++;
             fora << table[0][n] << " " << table[1][n] << endl;
        }
    }
    dentro.close();
    fora.close();

    cout << "O valor do pi e: " << 4 * (((float)ni) / ((float)ni + (float)ne)) << endl;

    for(int i = 0; i < 2; i++) delete[] table[i];
    delete[] table;

    return 0;
}

double generator( double x)
{
    return fmod((1664525. * x + 1013904223.), pow(2., 32));
}

double** create_table(int n_max, double x, double(*g)(double))
{
    // criar espaco para a tabela
    double **table = new double *[2];
    for(int i = 0; i < 2; i++) table[i] = new double[n_max];

    // preencher tabela com iteradas
    for(int n = 0; n < n_max; n++)
    {
        table[0][n] = x / pow(2., 32);
        x = g(x);
        table[1][n] = x / pow(2., 32);
    }

    return table;
}
