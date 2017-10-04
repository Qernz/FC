#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double generator (double);
double** creatematrix(int, double, double(*g)(double), int );
int main()
{
    int n_max=10; // numero de iteradas
    double x=.5; // r eh o parametro geomehtrico, x eh o valor inicial
    int n = 0; // variavel auxiliar de iteracao
    float x_aux = 0;
    //double **v = new double *[2];
    double **v;
    cout << " insira o numero de iteradas: ";
    cin >> n_max;
    cout << "insira o valor da iterada inicial: ";
    cin >> x;
    x_aux = x;
    /*for(int i =0; i<2; i++)
    {
        v[i] = new double[n_max];
    }*/
    ofstream dados;
    dados.open("data2.txt");
    //dados << n << " " << x << endl; // escrever iterada inicial
    for( n = 0; n < n_max; n++ ) //ciclo das iteradas
    {
        dados << x/pow(2.,32) << " ";
        //v[0][n] = x;
        x = generator(x);
        //cout << "x(" << n << ")= " << x << endl;
        dados << x/pow(2.,32) << endl;
        //v[1][n] = x;
    }
    v = creatematrix(n_max, x_aux, &generator, n );
    cout << v[0][256] << " " << v[1][256] << endl;;
    dados.close();
    for(int i = 0; i < 2; i++)
    {
        delete[] v[i];
    }
    delete[] v;
    return 0;
}

double generator( double x)
{
    x = fmod((1664525.*x + 1013904223.),  pow(2.,32));

    return x;

}

double** creatematrix(int n_max,double x, double(*g)(double), int n )
{
    double **v = new double *[2];
    for(int i =0; i<2; i++)
    {
        v[i] = new double[n_max];
    }
    for( int n = 0; n< n_max; n++)
    {

        v[0][n] = x/pow(2.,32);
        cout << v[0][n]<< " ";
        x = g(x);
        v[1][n] = x/pow(2.,32);
        cout << v[1][n]<< " dentro" << endl;;

    }
    return v;
}
