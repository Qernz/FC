#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
  int n_max = 10;
  int n = 0;
  float r = 0, x = 0; // r eh o parametro de controle

  /*cout << "r = ";
  cin >> r;
  cout << "x = ";
  cin >> x;*/
  ifstream dados;
  dados.open("dados.txt");
  dados >> r >> x >> n_max;
  cout << r << endl;
  cout << x << endl;
  cout << n_max << endl;
  dados.close();
  ofstream dados2;
  dados2.open("dados2.txt");
   for (n = 1; n <= n_max; n++)
   {
     dados2 << x << " ";
     x = x*r*(1.-x);
    //cout << "x(" << n << ")= " << x << endl;
    dados2 << x << endl;
   }
   dados2.close();
  return 0;
}
