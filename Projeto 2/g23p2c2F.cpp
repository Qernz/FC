#include "g23p2c2.h"
using namespace std;

float Fovm (float t , float v, float x) {return -forF::k*x -forF::lambda*v + forF::F0*sin(forF::wf*t); }
