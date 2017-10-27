#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void Numerov_method(float h, int n, float (*f)(float, float,float, float, float, float), float*, float*, float*, float*, float*, float*);

float force (float t, float r1, float r2, float r3, float dist12, float dist13)
{



    float r12 = r2 - r1;
    float r13 = r3 - r1;
    float f = r12/pow(dist12,3) + r13/pow(dist13,3);
    //cout << "r12: " << r12 << " " << "r13: " << r13 << endl;

    /*for (int i = 0; i < 2; i++)
    {
        r12[i] = r2[i] - r1[i];
    }
    for (int i = 0; i < 2; i++)
    {
        r13[i] = r3[i] - r1[i];
    }
    for (int i = 0; i < 2; i++)
    {
        f[i] = r12[i]/pow(dist12,3) + r13[i]/pow(dist13,3);
    }*/
    return f;
}

int main()
{
    float r1[2];
    float r2[2];
    float r3[2];
    float h = 0;
    int n = 0;
    float r01[2];
    float r03[2];
    float r02[2];
    ifstream dados;
    dados.open("dados.txt");
    dados >> h;
    dados >> n;
    dados >> r01[0] >> r01[1];
    dados >> r1[0] >> r1[1];
    dados >> r02[0] >> r02[1];
    dados >> r2[0] >> r2[1];
    dados >> r03[0] >> r03[1];
    dados >> r3[0] >> r3[1];
    Numerov_method(h, n, &force, r1, r2, r3, r01, r02, r03);
    /*r1 = Numerov_method(h, n , &force, r1, r2, r3, r01, r02, r03);
    r2 = Numerov_method(h, n , &force, r2, r1, r3, r02, r01, r03);
    r3 = Numerov_method(h, n , &force, r3, r2, r1, r03, r02, r01);*/

    dados.close();

    return 0;
}


void Numerov_method(float h, int n, float (*f)(float, float, float, float, float, float), float* r1, float* r2, float* r3, float* r01, float* r02, float* r03 )
{
    ofstream dados1;
    ofstream dados2;
    ofstream dados3;
    dados1.open("newdata1.txt");
    dados2.open("newdata2.txt");
    dados3.open("newdata3.txt");
    float t = 0;
    float temp1[2];
    float temp2[2];
    float temp3[2];
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
    {
        dados1 << t << " " << r1[0] << " " << r1[1] << endl;
        dados2 << t << " " << r2[0] << " " << r2[1] << endl;
        dados3 << t << " " << r3[0] << " " << r3[1] << endl;
        float dist12 = sqrt(pow(r1[0] - r2[0]+ 0.0001,2) + pow(r1[1] - r2[1]+ 0.0001,2));
        float dist13 = sqrt(pow(r1[0] - r3[0]+ 0.0001,2) + pow(r1[1] - r3[1]+ 0.0001,2));
        float dist23 = sqrt(pow(r2[0] - r3[0]+ 0.0001,2) + pow(r2[1] - r3[1]+ 0.0001,2));
        //cout << "dist12:" << dist12 << " " << "dist13:" << dist13 << " " << "dist23:" << dist23 << " " << endl;
        if ( dist12 ==0 || dist13 == 0 || dist23 == 0)
        {
            cout << "FODEU!!" << endl;
        }
        for (j = 0; j<2; j++)
        {
            temp1[j] = r1[j];
            temp2[j] = r2[j];
            temp3[j] = r3[j];
        }

        for (j = 0; j<2; j++)
        {
            r1[j] = 2*temp1[j] - r01[j] + h*h*f(t, temp1[j], temp2[j], temp3[j], dist12, dist13);
            r2[j] = 2*temp2[j] - r02[j] + h*h*f(t, temp2[j], temp1[j], temp3[j], dist12, dist23);
            r3[j] = 2*temp3[j] - r03[j] + h*h*f(t, temp3[j], temp1[j], temp2[j], dist23, dist13);
        }
        //cout << "valor r1:" << "(" << r1[0] << "," << r1[1] << ")" << endl;
        //cout << "valor r2:" << "(" << r2[0] << "," << r2[1] << ")" << endl;
        //cout << "valor r3:" << "(" << r3[0] << "," << r3[1] << ")" << endl;
        for (j = 0; j<2; j++)
        {
            r01[j] = temp1[j];
            r02[j] = temp2[j];
            r03[j] = temp3[j];
        }


        t += h;


    }

    dados1.close();
    dados2.close();
    dados3.close();
}
