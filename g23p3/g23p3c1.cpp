#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void calcula(double** tt0, double** tt1, double hx, double hy, double ht, int n_print, int n, int nx, int ny, double ka);
double** create_matrix (int nx, int ny, double t_inicial);
void free_matrix(double** v, int nx, int ny);

int main()
{
    double k; // condutividade termica
    double L; // lado do quadrado
    double t_fronteira; // condicoes de fronteira
    double t_inicial; // temperatura inicial
    double ht; // passo no tempo
    double hx, hy; // passos em x e y
    int n_max; // numero maximo de passos no tempo
    int n_print; // numero de passos no tempo entre escritas
    // ler dados de um ficheiro
    ifstream input("dados1.txt");
    input >> k >> L >> t_fronteira >> t_inicial
        >> ht >> hx >> hy >> n_max;
    input.close();

    // criar matrix e preencher com valores iniciais
    int nx = L / hx, ny = L / hy;
    //cout << nx << " " << ny;

    double** tt0 = create_matrix(nx, ny, t_inicial);
    double** tt1 = create_matrix(nx, ny, t_inicial);

    // preencher as fronteiras de tt0
    for(int i = 0; i < nx; i++) {
        tt0[0][i] = t_fronteira;
        tt0[i][0] = t_fronteira;
        tt0[nx - 1][i] = t_fronteira;
        tt0[i][ny - 1] = t_fronteira;

        tt1[0][i] = t_fronteira;
        tt1[i][0] = t_fronteira;
        tt1[nx - 1][i] = t_fronteira;
        tt1[i][ny - 1] = t_fronteira;
    }
    n_print = 30/ht;
    calcula(tt0, tt1, hx, hy, ht, n_print, n_max, nx, ny, k );
    return 0;
}

// percorre todas as casas de tt0 e tt1 e aplicar a equacao de interesse
void calcula(double** tt0, double** tt1, double hx, double hy, double ht, int n_print, int n, int nx, int ny, double ka )
{
    ofstream dados;

    dados.open("resultados1.txt");
    

    for( int i = 0; i < n; i++)
    {
        for (int j = 1; j < nx - 1; j++)
        {
            for (int k = 1; k < ny - 1; k++)
            {
                tt1[j][k] = tt0[j][k] + ((ka*ht)/(hx*hx)) * (tt0[j][k+1] - 2 *tt0[j][k] + tt0[j][k-1]) + ((ka*ht)/(hy*hy)) * (tt0[j+1][k] - 2*tt0[j][k] + tt0[j-1][k]);

            }


        }

        if (i%3000 == 0)
        {
            dados << i << endl;
            for (int l = 0; l< nx ;l++)
            {
                for (int m = 0; m < ny; m++)
                {
                    dados << endl << l << " " << m << " " <<  tt0[l][m] << endl;
                }
            }
        }
        for(int l = 0; l < nx; l++)
        {
            for(int m = 0; m < ny; m++)
            {
                tt0[l][m] = tt1[l][m];
            }
        }
    }
    dados.close();
}


double** create_matrix(int nx, int ny, double inicial)
{
    double **v = new double*[nx];
    for (int i = 0; i < nx; i++) {
        v[i] = new double[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = inicial;
        }
    }
    return v;
}

void free_matrix(double** v, int nx, int ny)
{
    for (int i = 0; i < nx; i++) delete[] v[i];
    delete[] v;
}
