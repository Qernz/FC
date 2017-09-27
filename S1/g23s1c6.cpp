#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
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
  dados2.open("dados7.txt");
    for (n = 1; n <= n_max; n++)
    {
      dados2 << x << " ";
      x = fmod((1664525.*x + 1013904223.),  pow(2.,32));
      //cout << "x(" << n << ")= " << x << endl;
      dados2 << x << endl;
    }

  dados2.close();
  return 0;
}
