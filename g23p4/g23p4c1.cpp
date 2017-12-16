#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

struct resultado {
    Vector lambda;
    Vector VEP[4];

};
resultado calcVAP(const Matrix& N);
int main()
{
    double a;
    double b;
    double k;
    double h_;
    double m;
    double A_;
    double n;
    double h;
    double* phi;
    bool check = true;

    ifstream input;
    ofstream output;
    input.open("inputschrodinger.txt");
    output.open("outmatrix.txt");


    input >> A_ >> n >> k >> h_ >> m >> a >> b;

    Matrix M(n, n, 0);
    h =-((2*A_)/(n+1));
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                M[i][j] = -2;
            }
        }
    }
    for (int i = 0; i< n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (i == j)
            {
                M[i][j+1] = 1;
                M[i+1][j] = 1;
            }
        }
    }
    M = -(h_/(2*m))* (1/(h*h)) * M;
    //cout << M << endl;
    Matrix V(n,n,0);
    for (int i = 0; i < n; i++)
    {
        V[i][i] = (pow(a,4)/pow(b,2)) - (pow(a,4)/(pow(((n-1)/2 -i),2) + pow(b,2)));
    }
    //cout << V << endl;
    V = (k/2)*V;


    Matrix H(n,n,0);
    H = M + V;
    //cout<< M << endl << H << endl;

    //cout << N << endl;
    output << H;

    for(int i = 0; i<n ; i++)
    {
        for(int j = 0; j<n ; j++)
        {
            if (H[i][j] != H[j][i])
            {
                check = false;
            }
        }
    }
    if (check)
    {
        cout << "A matrix é simétrica" << endl;
    }





    Matrix N(n,n,0);
    N = inverse(H);

    /*Vector VEP(n);
    Vector VEP2(n);
    Vector VEP3(n);
    Vector VEP4(n);
    Vector auxVEP(n);
    Vector auxVEP2(n);
    Vector auxVEP3(n);
    VEP[8] = 1;
    auxVEP = VEP;
    double lambda;
    double lambda2;
    double lambda3;
    double lambda4;
    for (int i = 0; i < 20; i++)
    {
        //cout << VEP * N * VEP << endl;
        VEP = N*VEP;
        VEP = VEP/mod(VEP);
        VEP2 = VEP - auxVEP;
        VEP2 = VEP2/mod(VEP2);
        if (i > 0)
        {
            auxVEP3 = VEP3;
            VEP3 = VEP2 - auxVEP2;
            VEP3 = VEP3/mod(VEP3);
            //cout << VEP3 * N << endl << VEP3 * N * VEP3 << endl;
            lambda3 = VEP3 * N * VEP3;
        }
        if (i > 1)
        {
            VEP4 = VEP3 - auxVEP3;
            VEP4 = VEP4/mod(VEP4);
            lambda4 = VEP4 * N * VEP4;
        }

        lambda = VEP * N * VEP;
        lambda2 = VEP2 * N * VEP2;
        auxVEP = VEP;
        auxVEP2 = VEP2;

    }*/
    resultado res = calcVAP(N);
    cout << res.lambda << endl << res.VEP[0] << endl<< res.VEP[1] << endl<< res.VEP[2] << endl<< res.VEP[3] << endl;

    input.close();
    output.close();
    return 0;
}




resultado calcVAP(const Matrix& N)
{
    assert(N. nx > 4);
    int n = N.nx;
    resultado res;
    for( int i = 0; i< 4 ; i++)
    {
        res.VEP[i].init(n);
    }
    res.lambda.init(4);
    Vector VEP(n);
    Vector VEP2(n);
    Vector VEP3(n);
    Vector VEP4(n);
    Vector auxVEP(n);
    Vector auxVEP2(n);
    Vector auxVEP3(n);
    VEP[8] = 1;
    auxVEP = VEP;
    Vector lambda(4);
    for (int i = 0; i < 20; i++)
    {
        //cout << VEP * N * VEP << endl;
        VEP = N*VEP;
        VEP = VEP/mod(VEP);
        VEP2 = VEP - auxVEP;
        VEP2 = VEP2/mod(VEP2);
        if (i > 0)
        {
            auxVEP3 = VEP3;
            VEP3 = VEP2 - auxVEP2;
            VEP3 = VEP3/mod(VEP3);
            //cout << VEP3 * N << endl << VEP3 * N * VEP3 << endl;
            lambda[2] = VEP3 * N * VEP3;
        }
        if (i > 1)
        {
            VEP4 = VEP3 - auxVEP3;
            VEP4 = VEP4/mod(VEP4);
            lambda[3] = VEP4 * N * VEP4;
        }

        lambda[0] = VEP * N * VEP;
        lambda[1] = VEP2 * N * VEP2;
        auxVEP = VEP;
        auxVEP2 = VEP2;

    }
    res.lambda = lambda;
    res.VEP[0] = VEP;
    res.VEP[1] = VEP2;
    res.VEP[2] = VEP3;
    res.VEP[3] = VEP4;
    return res;
}
