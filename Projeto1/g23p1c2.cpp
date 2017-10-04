#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n_max = 10; // numero de iteradas
    float r, x; // r e o parametro geometrico, x e o valor inicial

    // receber parametros do utilizador
    cout << "Insira o numero de iteradas: ";
    cin >> n_max;
    cout << "Insira o valor de r: ";
    cin >> r;
    cout << "Insira o valor da iterada inicial: ";
    cin >> x;

    ofstream dados;
    dados.open("data.txt");
    for(int n = 0; n < n_max; n++) // ciclo das iteradas
    {
        x *= r;
        cout << "x(" << n << ")= " << x << endl;
        dados << n << " " << x << endl; // escrever iteradas no ficheiro
    }
    dados.close();

    return 0;
}
