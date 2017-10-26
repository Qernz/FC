// dif eq : y' = -lambda*y
float f (float t , float y, float x) {return -x; }
void Euler_method(float h, int n, float (*f)(float, float, float), float y0, float x0);
