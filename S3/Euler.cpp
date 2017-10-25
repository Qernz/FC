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
    dados.open("data.txt");
    float t = 0;
    int y = y0;
    for (int i = 0; i < n; i++)
    {
        dados << t << " " << y << /*" " << f(t,y) <<*/ endl;
        y = y + h*f(t,y);
        t += h;
    }
    dados.close();
}
