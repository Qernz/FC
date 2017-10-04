#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double generator (double);
int main()
{
    int n_max=10; // numero de iteradas
    double x=.5; // r eh o parametro geomehtrico, x eh o valor inicial
    int n = 0; // variavel auxiliar de iteracao
    double **v = new double *[2];
    int ni= 0; int ne = 0;
    for(int i =0; i<2; i++)
    {
        v[i] = new double[n];
    }

    cout << " insira o numero de iteradas: ";
    cin >> n_max;
    cout << "insira o valor da iterada inicial: ";
    cin >> x;
    ofstream dados, dentro, fora;

    dados.open("data3.txt");
    dentro.open("dentro.txt");
    fora.open("fora.txt");
    //dados << n << " " << x << endl; // escrever iterada inicial
    //cout << " AIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII, AJUDAAAAAAAAAAAAAA CARALHOOO"<< endl;
    for( n = 0; n < n_max; n++ ) //ciclo das iteradas
    {
        dados << x/pow(2.,32) << " ";
        v[0][n] = x/pow(2.,32);
        x = generator(x);
        //cout << "x(" << n << ")= " << x << endl;
        dados << x/pow(2.,32) << endl;
        v[1][n] = x/pow(2.,32);
        if (sqrt(pow((v[0][n]), 2)+pow((v[1][n]), 2)) < 1)
        {
            ni ++;
            dentro << v[0][n] << " " << v[1][n];

        }
        else
        {
             ne ++;
             fora << v[0][n] << " " << v[1][n];

             //cout << n <<" " << " AIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII, AJUDAAAAAAAAAAAAAA CARALHOOO"<< endl;
        }
    }
    /*dados.close();
    dentro.close();
    fora.close();*/
    //cout << n <<" " << " AIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII, AJUDAAAAAAAAAAAAAA CARALHOOO"<< endl;
    for(int i = 0; i < 2; i++)
    {
        cout << i <<" " << " AIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII, AJUDAAAAAAAAAAAAAA CARALHOOO"<< endl;
        delete[] v[i];
        cout << i <<" " << " AIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII, AJUDAAAAAAAAAAAAAA CARALHOOO"<< endl;
        //cout << " ai"<< endl;
    }
    delete[] v;
    return 0;
}

double generator( double x)
{
    x = fmod((1664525.*x + 1013904223.),  pow(2.,32));

    return x;

}
