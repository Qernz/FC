#include "g23p2c2.h"

float RuKuNew1(float h, float (*f)(float, float, float), float v0, float x0, float t0)
{
    float t = t0;
    float x = x0;
    float v = v0;
    float kv1, kv2, kv3, kv4, kx1, kx2, kx3, kx4;

        kv1 = f(t,v,x);
        kx1 = v;
        kv2 = f(t + (h/2), v + (h/2)*kv1, x + (h/2)*kx1 );
        kx2 = v + h*(kv1/2);
        kv3 = f(t + (h/2), v + (h/2)*kv2, x + (h/2)*kx2);
        kx3 = v + h*(kv2/2);
        kv4 = f(t + h, v + h*kv3, x+ h*kx3);
        kx4 = v + h*kv3;

        forRK::v = v + (h/6) * (kv1 + 2 *kv2+ 2*kv3 + kv4);
        forRK::x = x + (h/6) * (kx1 + 2* kx2 + 2*kx3 + kx4);
        t += h;

    return t;
}
