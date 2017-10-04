#include <iostream>

using namespace std;

int main()
{
    int n_max = 10; // numero de iteradas
    float r = .7, x = .5; // r e o parametro geometrico, x o valor inicial

    for(int n =0; n < n_max; n++) // ciclo das iteradas
    {
        x *= r;
        cout << "x(" << n << ")= " << x << endl;
    }

    return 0;
}
