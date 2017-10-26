#include <iostream>
#include <cmath>
#include "Euler2.h"
#include <fstream>
using namespace std;


int main()
{
    float h = 0;
    int n = 0;
    float y0 = 0;
    float x0 = 0;
    cout << "Type the step size (h): "; cin >> h;
    cout << "Type the number of iterations (n): "; cin >> n;
    cout << "Type the initial y condition: "; cin >> y0;
    cout << "Type the initial x condition: "; cin >> x0;
    Euler_method(h, n, &f, y0, x0 );
    return 0;
}


void Euler_method(float h, int n, float (*f)(float, float, float), float y0, float x0)
{
    ofstream dados;
    dados.open("data.txt");
    float t = 0;
    float y = y0;
    float x = x0;
    for (int i = 0; i < n; i++)
    {
        dados << t << " " << x << /*" " << f(t,y) <<*/ endl;
        x = x + h*y;
        y = y + h*f(t,y,x);
        t += h;
    }

    dados.close();
}
