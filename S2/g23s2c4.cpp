#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "markov.h"

using namespace std;
const double pi = 3.141592653589793238463;
// probability function
float p(float x) {return (1/pow(pi,(1/2))*exp(-(x*x)));}
// function to integrate
float f(float x) {return pow(x,4);}

int main ()
{

    int n, m;
    float a, b, r;
    srand (time(NULL));
    // read arguments from user
    cout << "r value: "; cin >> r;
    cout << "Markov chain size: "; cin >> n;
    cout << "m: "; cin >> m;
    cout << "lower integration limit: "; cin >> a;
    cout << "upper integration limit: "; cin >> b;
    float* markov_chain = markov(r, m, &p, n, a, b);
    // calculate integral
    float integral = 0;
    for(int i = 0; i < n; i++)
    {
         integral += f(markov_chain[i]);
         cout << markov_chain[i] << " " << f(markov_chain[i]) << endl;
    }
    integral /= n;

    // print to cout and file the result
    cout << "Integral value: " << integral << endl;
}
