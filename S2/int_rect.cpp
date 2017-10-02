#include <iostream>
#include <cmath>

using namespace std;

float f(float);
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

float f(float x) { return sin(x); }

float integral(float a, float b, int n, float (* f)(float))
{
    float integral = 0;
    float size = (b - a) / n;
    for(float x = a; x < b; x += size) {
        integral += f(x) * size;
    }

    return integral;
}
