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
    dados.open("data2.txt");
    float t = 0;
    float x = x0;
    float y = y0;
    float ky1, ky2, ky3, ky4, kx1, kx2, kx3, kx4;
    for (int i = 0; i < n; i++)
    {
        ky1 = f(t,y,x);
        kx1 = y;
        ky2 = f(t + (h/2), y + (h/2)*ky1, x + (h/2)*kx1 );
        kx2 = y + h*(ky1/2);
        ky3 = f(t + (h/2), y + (h/2)*ky2, x + (h/2)*kx2);
        kx3 = y + h*(ky2/2);
        ky4 = f(t + h, y + h*ky3, x+ h*kx3);
        kx4 = y + h*ky3;





        dados << t << " " << x << /*" " << f(t,y) <<*/ endl;
        y = y + (h/6) * (ky1 + 2 *ky2+ 2*ky3 + ky4);
        x = x + (h/6) * (kx1 + 2* kx2 + 2*kx3 + kx4);
        t += h;
    }
    dados.close();
}
