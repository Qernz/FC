#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Matrix A(3,6,0);
    //Matrix B(3,3,3);

    Matrix I(3,3,0);
    double d;

    int n = 0;
    ifstream dados;
    dados.open("input.txt");
    dados >> n;
    Matrix A(n,2*n,0);
    Matrix C(n,1,0);
    //cout << T << endl;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = ((rand() / (float) RAND_MAX) * 2 * n) - n;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< 2 * n; j++)
        {
            if (j == i+n )
            {
                A[i][j] = 1;
            }
        }
    }
    //cout << A << endl;
    I[0][0] = I[1][1] = I[2][2] = 1;
    //C = A-B;
    //cout << C << endl;
    //cout << A[1][2]<< endl;
    A[1][2] = 0;
    //C = A + B;
    //cout << C[1][2]<< endl;

    // vamos gauss-jordar isto
    //n = A.getsize();
    //cout << n << endl;
    /*A[0][0] = 1; A[0][1] = 3; A[0][2] = 1;
    A[1][0] = 2; A[1][1] = 0; A[1][2] = 2;
    A[2][0] = 2; A[2][1] = 1; A[2][2] = 0;
    A[0][3] = A[1][4] = A[2][5] = 1;
    cout << A << endl;*/
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
    /*    for(int i = n-1; i > 0; i--)
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
            {
        }


        //cout << A << endl;

        for (int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j++)
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
        //cout << A << endl;

        for (int i = 0; i < n; i++)
        {
            d = A[i][i];
            for(int j = 0; j < 2*n; j++)
            {
                A[i][j] = A[i][j]/d;
            }
        }*/
        //cout << A << endl;
        Matrix M(n,n,0);
        for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            M[i][j] = A[i][j+n];
        }
        //cout << M << endl;
        Matrix B(n,1,0);
        for(int i = 0; i < n; i++)
        {
            B[i][0] = 2;
        }
        C = M * B;
        //cout << M << endl << B << endl << C<< endl;
        for (int i = 0; i< n; i++)
            for (int j = 0; j<n ; j++)
            {
                dados >> M[i][j];
            }
        //cout << M << endl;
        Matrix V(n,1,0);
        Matrix V2(n,1,0);
        Matrix V3(n,1,0);
        Matrix auxV(n,1,0);
        Matrix auxV2(n,1,0);
        V[2][0] = 1;
        Matrix W(1,n,0);
        V = V/mod(V);
        auxV = V;
        //cout << V << endl;
        double lambda;
        double lambda2;
        double a;
        int g;
        for (int i = 0; i < 100; i++)
        {
            V = M*V;
            V = V/mod(V);
            cout << V << endl;
            V2 = V - auxV;
            V2 = V2/mod(V2);
            cout << V2 << endl;
            auxV2 = V2;
            //cout << V << endl;
            //cout << mod(V) << endl;
            V3 = V2 - auxV2;
            cout << V3 << endl;
            //cout << V << endl;
            W = transpose(V);
            //cout << V << endl << W << endl;
            //cin >> g;
            //cout << V << endl << W << endl << W * M * V << endl;
            lambda = doublefy(W * M * V);
            //cout << lambda << endl;


        }
        cout << lambda << endl << V << endl;
    //   cout << lambda << endl;
        Matrix N(n,n,0);
        N = inverse(M);
        //cout << V << endl;
        //auxV = auxV/mod(auxV);
        //Matrix V2(n,1,0);
        //Matrix V3(n,1,0);
        V2 = auxV - (auxV*V)/mod(V);
        cout << V2 << endl;
        
        /*for (int i = 0; i < 100; i++)
        {
            V2 = M*V2;
            //cout << V << endl;
            //cout << mod(V) << endl;

            V2 = V2/mod(V2);
            //cout << V << endl;
            W = transpose(V2);
            //cout << V << endl << W << endl;
            //cin >> g;
            //cout << V << endl << W << endl << W * M * V << endl;
            lambda2 = doublefy(W * M * V2);
            //cout << lambda << endl;
        }
        cout << lambda2 << endl << V2 << endl;*/

    dados.close();
    return 0;
}
