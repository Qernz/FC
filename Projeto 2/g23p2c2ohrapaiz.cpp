#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

namespace forRK{
    float v, x;
};
namespace forF{
    float lambda, m, k, F0, wf;
}
// dif eq : v' = -lambda*v
float Fovm (float t , float v, float x) {return -forF::k*x -forF::lambda*v + forF::F0*sin(forF::wf*t); }
float RuKuNew1(float h, float (*f)(float, float, float), float v0, float x0, float t0);

int main()
{
    float h = 0;
    int n = 0;
    forRK::v = 0;
    forRK::x = 0;
    float t = 0;
    float** matrix = new float*[3];

    ofstream output;
    ifstream input;

    input.open("dados1b.txt");

    output.open("1b.txt");

    input >> h >> n >> forRK::v >> forRK::x >> forF::k >> forF::lambda >> forF::F0 >> forF::wf;
    for (int j = 0; j <3 ; j++)
    {
        matrix[j] = new float[n];

    }
    for (int i = 0; i < n; i++)
    {
        output << i << " " << t << " " << forRK::x << " " << forRK::v << endl;
        matrix[0][i] = t;
        matrix[1][i] = forRK::x;
        matrix[2][i] = forRK::v;
        t = RuKuNew1(h, &Fovm,forRK::v, forRK::x, t );

    }
    output << n << " " << t << " " << forRK::x << " " << forRK::v << endl;
    matrix[0][n-1] = t;
    matrix[1][n-1] = forRK::x;
    matrix[2][n-1] = forRK::v;
    input.close();
    output.close();
    for(int i = 0; i< 3 ; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}


float RuKuNew1(float h, float (*f)(float, float, float), float v0, float x0, float t0)
{
    float t = t0;
    float x = x0;
    float v = v0;
    float kv1, kv2, kv3, kv4, kx1, kx2, kx3, kx4;

        kv1 = f(t,v,x);
        kx1 = v;
        kv2 = f(t + (h/2), v + (h/2)*kv1, x + (h/2)*kx1 );
        kx2 = v + h*(kv1/2);
        kv3 = f(t + (h/2), v + (h/2)*kv2, x + (h/2)*kx2);
        kx3 = v + h*(kv2/2);
        kv4 = f(t + h, v + h*kv3, x+ h*kx3);
        kx4 = v + h*kv3;

        forRK::v = v + (h/6) * (kv1 + 2 *kv2+ 2*kv3 + kv4);
        forRK::x = x + (h/6) * (kx1 + 2* kx2 + 2*kx3 + kx4);
        t += h;

    return t;
}
