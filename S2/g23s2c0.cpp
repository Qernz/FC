#include<iostream>
using namespace std;

int main()
{
  int i = 0, n = 0, m = 0, k = 0;
  /*cout << "numero de linhas:";
  cin >> n;
  cout << "numero de colunas:";
  cin >> m;*/
  ifstream dados;
  dados.open("data.txt");
  dados >> n >> m;
int **p = (int**)malloc(n*sizeof(int*));
for(i=0;i < n; i++)
{
  p[i] = (int*)malloc(m*sizeof(int));
  for(k=0; k < m; k++)
  {
    //cout << "filing in " << i << " and " << k << endl;
    p[i][k] = 0;
     //cout << p[i][k] << endl;
  }
}
cout.flush();
 //cout<< "AQUIII" << p[0][0] << endl;
for(i= 0; i<n; i++)
{
  for(k = 0; k<m; k++)
  {
    //cout <<"valor de i:" << i << "valor de k:" << k << endl;
    cout << p[i][k] << " ";
  }
  cout << endl;
}
}
