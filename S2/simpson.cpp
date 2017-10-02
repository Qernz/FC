#include <iostream>
#include <cmath>

#include "function.h"

using namespace std;

float integral(float, float, int, float (float));

int main()
{
    float a, b;
    int n;

    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "n: "; cin >> n; 

    cout << "integral from " << a << " to " << b << " is: ";
    cout << integral(a, b, n, &f) << endl;
}

float integral(float a, float b, int n, float (* f)(float))
{
    float integral = f(a) + f(b);
    float size = (b - a) / n;
    for(int j = 1; j < n; j++)
    {
        float x = a + size * j;
        if(j % 2 == 0) integral += 2 * f(x);
        else integral += 4 * f(x);
    }
    integral *= size / 3;

    return integral;
}
