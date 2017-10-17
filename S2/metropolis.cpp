#include <iostream>

using namespace std;

float metropolis(float x0, float r, int m, float (*p)(float))
{
    float rn = 0; // random number
    float cx = 0; // current x
    float c2 = x0;
    int accepted = 0;
    for(int i = 0; i < m; i++)
    {
        rn = ((rand() / (float) RAND_MAX) * 2 * r) - r;
        //rn = ((float)rand()) * ((2*r) /((float)RAND_MAX)) - r;
        cx = rn + c2;
        if((p(cx)/p(c2)) > (float) rand()/((float) RAND_MAX))
        {
            c2 = cx;
            accepted++;
            //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
    cout << "acceptence rate: " << accepted / (float) m << endl;

    return c2;
}
