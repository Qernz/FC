#include <cmath>

const double pi = 3.141592653589793238463;

//float f(float x) { return x*x; }
float f(float x) { return (pow(x, 4) * exp(-pow(x, 2))) / sqrt(pi); }
