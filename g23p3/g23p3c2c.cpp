#include <iostream>
#include <fstream>
#include <cmath>

#include "matrix.h"

using namespace std;

void calcula(Matrix tt0, Matrix tt1, double hx, double hy, double ht, int n_print, int n, int nx, int ny, double ka);

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

    Matrix tt0(nx, ny, t_inicial);
    Matrix tt1(nx, ny, t_inicial);

    // preencher as fronteiras de tt0
    for(int i = 0; i < nx; i++) {
        tt0.get(0, i) = t_fronteira;
        tt0.get(i, 0) = t_fronteira;
        tt0.get(nx - 1, i) = t_fronteira;
        tt0.get(i, ny - 1) = t_fronteira;
    }
    tt1 = tt0;

    n_print = 30/ht;
    calcula(tt0, tt1, hx, hy, ht, n_print, n_max, nx, ny, k);

    return 0;
}

void calcula(Matrix tt0, Matrix tt1, double hx, double hy, double ht, int n_print, int n, int nx, int ny, double ka)
{
    ofstream dados("resultados1.txt");

    for( int i = 0; i < n; i++)
    {
        tt1 = tt0 + 2 * (ka / (ht * hx)) * (med(tt0) - 2 * tt0);
        if (i % 3000 == 0)
        {
            dados << i << endl;
            dados << tt0 << endl;
        }
        tt0 = tt1;
    }
    dados.close();
}
