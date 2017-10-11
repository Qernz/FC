#include <iostream>
using namespace std;

float metropolis(float x0, float r, int m, float (*p)(float))
{
    float rn = 0; // random number
    float cx = 0; // current x
    float c2 = x0;
    for(int i = 0; i < m; i++)
    {
        rn = ((float)rand()) * ((2*r) /((float)RAND_MAX)) - r;
        cx = rn + c2;
        if((p(cx)/p(c2)) > (float) rand()/((float) RAND_MAX))
        {
            c2 = cx;
            //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
    return c2;
}
