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
    float integral = 0;
    float size = (b - a) / n;
    float last_fx = f(a); // first left corner is a
    for(float x = a + size; x < b; x += size) {
        float fx = f(x);
        float area = ((last_fx + f(x)) * size) / 2;
        integral += area;
        last_fx = fx;
    }

    return integral;
}
