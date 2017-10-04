#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double generator(double);

int main()
{
    int n_max = 10; // numero de iteradas
    double x; // valor inicial

    // perguntar valores ao utilizador
    cout << "Insira o numero de iteradas: ";
    cin >> n_max;
    cout << "Insira o valor da iterada inicial: ";
    cin >> x;

    // criar tabela para os valores
    double **tabela = new double *[2];
    for(int i = 0; i < 2; i++) tabela[i] = new double[n_max];

    ofstream dados;
    dados.open("data4.txt");
    for(int n = 0; n < n_max; n++) // ciclo das iteradas
    {
        dados << x/pow(2., 32) << " ";
        tabela[0][n] = x;
        x = generator(x);
        dados << x/pow(2., 32) << endl;
        tabela[1][n] = x;
    }
    dados.close();

    // limpar memoria da tabela
    for(int i = 0; i < 2; i++)
    {
        delete[] tabela[i];
    }
    delete[] tabela;
    return 0;
}

double generator(double x)
{
    return fmod((1664525. * x + 1013904223.), pow(2., 32));
}
