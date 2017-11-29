#include <iostream>
#include <fstream>
#include <cmath>
#include "vector.h"
using namespace std;

void calcula(Vector tt0, Vector tt1, double hx, double hy, double ht, int n_print, int n, int nx, int ny, double ka );

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
    Vector tt1(nx);
    Vector tt0(nx);

    // preencher as fronteiras de tt0

    tt0[0] = t_fronteira;

    tt0[nx-1] = t_fronteira;

    for(int i = 1; i < nx-1; i++) {
        tt0[i] = t_inicial;
    }
    tt1 = tt0;
    n_print = 30/ht;
    calcula(tt0, tt1, hx, hy, ht, n_print, n_max, nx, ny, k );
    return 0;
}

// percorre todas as casas de tt0 e tt1 e aplicar a equacao de interesse
void calcula(Vector tt0, Vector tt1, double hx, double hy, double ht, int n_print, int n, int nx, int ny, double ka )
{
    ofstream dados;
    int caramba;
    dados.open("resultados2.txt");
    

    for( int i = 0; i < n; i++)
    {

        tt1 = tt0 + ((ka*ht)/(hx*hx)) * 2 * (med(tt0) - tt0);
        if (i%3000 == 0)
        for (int j = 0; j< nx; j++)
        {
            dados << i/100 << " " << tt0[j] << endl;
        }

        tt0 = tt1;

    }
    dados.close();
}
