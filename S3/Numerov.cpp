#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
// dif eq : y' = -lambda*y
float f (float t , float x) {return -x; }
void Euler_method(float h, int n, float (*f)(float, float), float x0_, float x0);


int main()
{
    float h = 0;
    int n = 0;
    float x0_ = 0;
    float x0 = 0;
    cout << "Type the step size (h): "; cin >> h;
    cout << "Type the number of iterations (n): "; cin >> n;
    cout << "Type the initial x_ condition: "; cin >> x0_;
    cout << "Type the initial x condition: "; cin >> x0;
    Euler_method(h, n, &f, x0_, x0 );
    return 0;
}


void Euler_method(float h, int n, float (*f)(float, float), float x0_, float x0)
{
    ofstream dados;
    dados.open("data3.txt");
    float t = 0;
    float tmp = 0;
    float x_ = x0_;
    float x = x0;

    for (int i = 0; i < n; i++)
    {
        dados << t << " " << x << /*" " << f(t,y) <<*/ endl;

        tmp = x;
        x = 2*x - x_ + h*h*f(t,x);
        x_ = tmp;
        t += h;


    }

    dados.close();
}
