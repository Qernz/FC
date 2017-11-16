#include <iostream>
#include <fstream>

using namespace std;
double** create_matrix (int nx, int ny );
double p(int nx, int ny) {return 5;};

int main()
{
    ifstream data;
    data.open("data.txt");
    ofstream data2;
    data2.open("resultados2.txt");
    int n_iter, nx, ny;
    double h;
    data >> nx >> ny >> h >> n_iter;
    double **v = create_matrix(nx,ny);

    double **lastv = create_matrix(nx,ny);

    for (int i = 0; i < nx; i ++)
    {
        for(int j = 0; j < ny; j++)
        {
            data >> v[i][j];
            lastv[i][j] = v[i][j];
        }
    }
    /*for (int i = 0; i < nx; i ++)
    {
        for(int j = 0; j < ny; j++)
        {
            data >> p[i][j];
        }
    }*/
    for( int i = 0; i < n_iter; i++)
    {
        for (int j = 1; j < nx - 1; j++)
        {
            for (int k = 1; k< ny - 1; k++)
            {
                v[j][k] = ((lastv[j+1][k] + lastv[j-1][k] + lastv[j][k+1] + lastv[j][k-1])/4) + ((h*h*p(j,k))/4);
                //data2 << v[j][k] << " ";
            }
            //data2 << endl;

        }
        //data2 << endl << endl;
        for(int l = 1; l < nx-1; l++)
        {
            for(int m= 1; m < ny-1; m++)
            {
                lastv[l][m] = v[l][m];
            }
        }
    }

    for ( int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            data2 << i  << " " << j << " " << v[i][j] << endl;
        }
    }

    data.close();
    data2.close();
    return 0;
}


double** create_matrix (int nx, int ny )
{
    double **v = new double*[nx];
    for (int i = 0; i< nx; i++)
    {
        v[i] = new double[ny];
        for (int j = 0; j < ny; j++)
        {
            v[i][j] = 0;
        }
    }
    return v;
}
