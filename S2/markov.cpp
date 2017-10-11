#include <iostream>
#include "metropolis.h"
using namespace std;
float* markov( float r, int m, float (*p)(float), int n, float a, float b)
{
  float *cm = new float[n];
  float temp = 0;
  float x0 = ((float) rand()) * (2/((float)RAND_MAX)) - 1;
  for (int i = 0; i< n; i++)
  {
    cm[i] = metropolis(x0, r, m, p);
    x0 = cm[i];
  }


  return cm;



}
