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

    // escrever a tabela num ficheiro
    ofstream dados;
    dados.open("data5.txt");
    for(int n = 0; n < n_max; n++)
    {
        dados << table[0][n] << " " << table[1][n] << endl;
    }
    dados.close();

    // limpar espaco da tabela
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
