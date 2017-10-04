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
    double **v = new double *[2];
    int ni= 0; int ne = 0;
    cout << " insira o numero de iteradas: ";
    cin >> n_max;
    cout << "insira o valor da iterada inicial: ";
    cin >> x;
    for(int i =0; i<2; i++)
    {
        v[i] = new double[n_max];
    }
    ofstream piconv;


    piconv.open("piconv.txt");
    //dados << n << " " << x << endl; // escrever iterada inicial
    v = creatematrix(n_max, x, &generator, n );
    for( int d = 1; d < n_max; d++)
    {
        for( n = 0; n < d; n++ ) //ciclo das iteradas
        {
            v[0][n] = x/pow(2.,32);
            x = generator(x);
            //cout << "x(" << n << ")= " << x << endl;
            v[1][n] = x/pow(2.,32);
            if (sqrt(pow((v[0][n]), 2)+pow((v[1][n]), 2)) < 1)
            {
                ni ++;
                //dentro << v[0][n] << " " << v[1][n] << endl;

            }
            else
            {
                 ne ++;
                 //fora << v[0][n] << " " << v[1][n] << endl;


            }
        }

        //cout << ni << " " << ne << endl;
        //cout << "o valor do pi eh: " << 4*(((float)ni)/((float)ni+(float)ne)) <<endl;
        piconv << d << " " << 4*(((float)ni)/((float)ni+(float)ne)) << endl;
        if(!(d % 10)) cout << d << endl;
    }

    piconv.close();

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
            //cout << v[1][n]<< " dentro" << endl;;

        }

    return v;
}
