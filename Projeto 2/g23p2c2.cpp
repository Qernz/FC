#include "g23p2c2.h"
using namespace std;
namespace forRK{
     float v, x;
};
namespace forF{
     float lambda, m, k, F0, wf;
};

int main()
{
    float h = 0;
    int n = 0;
    forRK::v = 0;
    forRK::x = 0;
    float t = 0;
    float** matrix = new float*[3];

    ofstream output;
    ifstream input;

    input.open("dados1b.txt");

    output.open("1b.txt");

    input >> h >> n >> forRK::v >> forRK::x >> forF::k >> forF::lambda >> forF::F0 >> forF::wf;
    for (int j = 0; j <3 ; j++)
    {
        matrix[j] = new float[n];

    }
    for (int i = 0; i < n; i++)
    {
        output << n << " " << t << " " << forRK::x << " " << forRK::v << endl;
        matrix[0][i] = t;
        matrix[1][i] = forRK::x;
        matrix[2][i] = forRK::v;
        t = RuKuNew1(h, &Fovm,forRK::v, forRK::x, t );

    }
    output << n << " " << t << " " << forRK::x << " " << forRK::v << endl;
    matrix[0][n-1] = t;
    matrix[1][n-1] = forRK::x;
    matrix[2][n-1] = forRK::v;
    input.close();
    output.close();
    for(int i = 0; i< 3 ; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
