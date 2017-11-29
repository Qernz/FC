#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Matrix A(3,6,0);
    Matrix B(3,3,3);
    Matrix C(3,3,0);
    Matrix I(3,3,0);
    double d;
    int n = 0;
    ifstream dados;
    dados.open("input.txt");
    dados >> n;
    Matrix T(n,2*n,0);
    cout << T << endl;
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

        }
    }
    I[0][0] = I[1][1] = I[2][2] = 1;
    C = A-B;
    cout << C << endl;
    cout << A[1][2]<< endl;
    A[1][2] = 0;
    C = A + B;
    cout << C[1][2]<< endl;

    // vamos gauss-jordar isto
    n = A.getsize();
    cout << n << endl;
    A[0][0] = 1; A[0][1] = 3; A[0][2] = 1;
    A[1][0] = 2; A[1][1] = 0; A[1][2] = 2;
    A[2][0] = 2; A[2][1] = 1; A[2][2] = 0;
    A[0][3] = A[1][4] = A[2][5] = 1;
    cout << A << endl;
    /*for (int k = 0; k< n ; k++){
        max = A[K][k];
        line = 0;
        for(int i = 0; i< n; i++)
        {
            if(A[i][k] > max)
            {
                max = A[i][k];
                line = i;
            }
        }
        if(line > k)
        {

        }*/
        for(int i = n-1; i > 0; i--)
        {
            if(A[i-1][0] < A[i][0])
            {
                for(int j = 0; j < 2*n ; j++)
                {
                    d = A[i][j];
                    A[i][j] = A[i-1][j];
                    A[i-1][j] = d;
                }
            }
        }


        cout << A << endl;

        for (int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j++)
            {
                if (j!=i)
                {
                    d=A[j][i]/A[i][i];
                    for(int k = 0; k < 2*n; k++)
                    {
                        A[j][k] -= A[i][k]*d;
                    }
                }
            }
        }
        cout << A << endl;

        for (int i = 0; i < n; i++)
        {
            d = A[i][i];
            for(int j = 0; j < 2*n; j++)
            {
                A[i][j] = A[i][j]/d;
            }
        }
        cout << A << endl;

    dados.close();
    return 0;
}
