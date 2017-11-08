#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

float f (float t , float v, float x) {return -x -0.5*v + 0.5*sin(sqrt(15/16)*t); }

int main()
{
    float h = 0;
    int n = 0;
    float v = 0;
    float x = 0;
    float t = 0;

    ifstream input;

    input.open("dados1a.txt");

    input >> h >> n >> v >> x ;
    ofstream output;
    output.open("1a)wf.txt");

    float kv1, kv2, kv3, kv4, kx1, kx2, kx3, kx4;
    for (int i = 0; i < n; i++)
    {
        kv1 = f(t,v,x);
        kx1 = v;
        kv2 = f(t + (h/2), v + (h/2)*kv1, x + (h/2)*kx1 );
        kx2 = v + h*(kv1/2);
        kv3 = f(t + (h/2), v + (h/2)*kv2, x + (h/2)*kx2);
        kx3 = v + h*(kv2/2);
        kv4 = f(t + h, v + h*kv3, x+ h*kx3);
        kx4 = v + h*kv3;





        output << n << " " << t << " " << x << " " << v << endl;
        v = v + (h/6) * (kv1 + 2 *kv2+ 2*kv3 + kv4);
        x = x + (h/6) * (kx1 + 2* kx2 + 2*kx3 + kx4);
        t += h;
    }
    output << n << " " << t << " " << x << " " << v << endl;
    input.close();
    output.close();
    return 0;
}