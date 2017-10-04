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

    ofstream dados;
    dados.open("data3.txt");
    for(int n = 0; n < n_max; n++) // ciclo das iteradas
    {
        dados << x/pow(2., 32) << " ";
        x = generator(x);
        dados << x/pow(2., 32) << endl;
    }
    dados.close();

    return 0;
}

double generator(double x)
{
    return fmod((1664525. * x + 1013904223.), pow(2., 32));
}
