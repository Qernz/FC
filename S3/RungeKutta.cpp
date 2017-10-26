#include <iostream>
#include <cmath>
#include "Euler.h"
#include <fstream>
using namespace std;


int main()
{
    float h = 0;
    int n = 0;
    float y0 = 0;
    cout << "Type the step size (h): "; cin >> h;
    cout << "Type the number of iterations (n): "; cin >> n;
    cout << "Type the initial condition: "; cin >> y0;
    Euler_method(h, n, &f, y0 );
    return 0;
}


void Euler_method(float h, int n, float (*f)(float, float), float y0)
{
    ofstream dados;
    dados.open("data2.txt");
    float t = 0;
    float y = y0;
    float k1, k2, k3, k4;
    for (int i = 0; i < n; i++)
    {
        k1 = f(t,y);
        k2 = f(t + (h/2), y + (h/2)*k1);
        k3 = f(t + (h/2), y + (h/2)*k2);
        k4 = f(t + h, y + h*k3);

        dados << t << " " << y << /*" " << f(t,y) <<*/ endl;
        y = y + (h/6) * (k1 + 2 *k2+ 2*k3 + k4 );
        t += h;
    }
    dados.close();
}
