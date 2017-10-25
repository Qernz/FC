// dif eq : y' = -lambda*y
float f (float t , float x) {return -0.2*x; }
void Euler_method(float h, int n, float (*f)(float, float), float y0);
