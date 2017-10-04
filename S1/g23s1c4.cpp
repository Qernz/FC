#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
  int n_max = 0;
  int n = 0;
  float r = 0, x = 0; // r eh o parametro de controle

  /*cout << "r = ";
  cin >> r;
  cout << "x = ";
  cin >> x;*/
  ifstream dados;
  dados.open("dados.txt");
  dados >> r >> x >> n_max;
  cout << r << endl << x << endl << n_max << endl;
  dados.close();
  ofstream dados2;
  dados2.open("dados5.txt");
  for (r = 2.4; r < 4; r+= 0.005)
  {
    for (n = 1; n <= n_max; n++)
    {
      dados2 << r << " ";
      x = x*r*(1.-x);
      //cout << "x(" << n << ")= " << x << endl;
      dados2 << x << endl;
    }
    //x = 0.56;
  }
  dados2.close();
  return 0;
}
