#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n_max=10; // numero de iteradas
    float r=.7, x=.5; // r eh o parametro geomehtrico, x eh o valor inicial
    int n = 0; // variavel auxiliar de iteracao
    cout << " insira o numero de iteradas: ";
    cin >> n_max;
    cout << "insira o valor de r: ";
    cin >> r;
    cout << "insira o valor da iterada inicial: ";
    cin >> x;
    ofstream dados;
    dados.open("data.txt");
    //dados << n << " " << x << endl; // escrever iterada inicial
    for( n =0; n < n_max; n++ )/* ciclo das iteradas */
    {
        x *= r;
        cout << "x(" << n << ")= " << x << endl;
        dados << n << " " << x << endl; // escrever iteradas seguintes
    }
    dados.close();
    return 0;
}
