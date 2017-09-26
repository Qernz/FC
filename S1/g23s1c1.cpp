#include <iostream>
using namespace std;
int main()
{
  int n_max = 10;
  float r=.7, x=.5; // r eh o parametro de controle
  int n = 0;
  for(n = 1; n<= n_max; n++)
  { /* ciclo das iteradas */
    x *= r;
    cout << "x(" << n << ")= " << x << endl;
  }
  return 0;
}
