#include <iostream>

using namespace std;
int main()
{
    int n_max=10; // numero de iteradas
    float r=.7, x=.5; // r eh o parametro geomehtrico, x eh o valor inicial
    int n = 0; // variavel auxiliar de iteracao
    for( n =0; n < n_max; n++ )/* ciclo das iteradas */
    {
        x *= r;
        cout << "x(" << n << ")= " << x << endl;
    }
    return 0;
}
