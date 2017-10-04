#include <iostram>
#include <rand>
using namespace std;

float metropolis(float x0, float r, int m, float (*p)(float))
{
  int rn = 0; // random number
  int cx = 0; // current x
  for(i = 0; i < m; i++)
  {
  rn = ((float)rand())*((2*r)/(float)RAND_MAX) - 1;
  cx = rn + x0;
  if((p(cx)/p(x0)) > (float) rand()/(float) RAND_MAX) x0 = cx
  }
  return x0;
}
