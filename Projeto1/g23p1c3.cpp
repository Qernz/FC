#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    int n_max=10; // numero de iteradas
    double x=.5; // r eh o parametro geomehtrico, x eh o valor inicial
    int n = 0; // variavel auxiliar de iteracao
    cout << " insira o numero de iteradas: ";
    cin >> n_max;
    cout << "insira o valor da iterada inicial: ";
    cin >> x;
    ofstream dados;
    dados.open("data2.txt");
    //dados << n << " " << x << endl; // escrever iterada inicial
    for( n = 0; n < n_max; n++ )/* ciclo das iteradas */
    {
        dados << x/pow(2.,32) << " ";
        x = fmod((1664525.*x + 1013904223.),  pow(2.,32));
        //cout << "x(" << n << ")= " << x << endl;
        dados << x/pow(2.,32) << endl;
    }
    dados.close();
    return 0;
}
