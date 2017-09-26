#include <iostream>
using namespace std;
int main()
{
  int n_max = 10;
  int n = 0;
  float r = 0, x = 0; // r eh o parametro de controle
  cout << "r = ";
  cin >> r;
  cout << "x = ";
  cin >> x;
  cout << "número de iterações = ";
  cin >> n_max;
   for (n = 1; n <= n_max; n++)
   {
     x = x*r*(1.-x);
    cout << "x(" << n << ")= " << x << endl;
   }
  return 0;
}
