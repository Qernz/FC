#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
namespace forRK{
     extern float v, x;
};
namespace forF{
     extern float lambda, m, k, F0, wf;
};


float Fovm (float t , float v, float x);
float RuKuNew1(float h, float (*f)(float, float, float), float v0, float x0, float t0);
