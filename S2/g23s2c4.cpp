#include <iostream>
#include <cmath>

#include "markov.h"

using namespace std;
const double pi = 3.141592653589793238463;
// probability function
float p(float x) {return (1/pow(pi,(1/4))*exp(-(x*x)/(2)));}
// function to integrate
float f(float x) {return pow(x,4);}

int main ()
{
    int n, m;
    // read arguments from user
    cout << "Markov chain size: "; cin >> n;
    cout << "m: "; cin >> m;
    float* markov_chain = markov(n, m, &p);

    // calculate integral
    float integral = 0;
    for(int i = 0; i < n; i++) integral += f(markov_chain[i]);
    integral /= n;

    // print to cout and file the result
    cout << "Integral value: " << integral << endl;
}
