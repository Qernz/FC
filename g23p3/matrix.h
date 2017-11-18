#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <assert.h>


class Matrix {
    double **p;



public:
    int _nx, _ny;
    Matrix(int n1,int n2 )
    {
        nx = n1;
        ny = n2;
        double **v = new double*[n1];
        for(int i = 0; i < n1; i++)
        {
            p[i] = new double[n2];
        }
    }

    ~Matrix()
    {
        for(int i = 0; i <n1; i++ )
        {
            delete[] p[i];
        }
        delete[] p;
    }
    Matrix& operator=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny);
         // so podemos copiar vetores do mesmos tamanho
        for(int i = 0; i < nx; i++)
        {
            for(int j = 0; j < ny;j++ )
            {
                this->p.get(i,j) = r.get(i,j);
            }
        }
    }
    double& get(int x, int y) {return p[x][y];}

    Matrix& operator+=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny); // so podemos adicionar matrizes do mesmos tamanho
        for(int i = 0; i < nx; i++)
        {
            for(int j = 0; j < ny;j++ )
            {
                this->p.get(i,j) += r.get(i,j);
            }
        }
    }




};

Matrix operator*(double a, const Matrix& r)
{
    Vector result(r.nx,r.ny);
    for(int i = 0; i < r.nx; i++)
    {
        for(int j = 0; j < r.ny; j++)
        {
            result.get(i,j) = r.get(i,j) * a;
        }


    }


    return result;
}

Matrix operator+(const Matrix& l, const Matrix& r)
{
    Vector result(r.nx,r.ny);
    for(int i = 0; i < r.nx; i++)
    {
        for(int j = 0; j < r.ny; j++)
        {
            result.get(i,j) = r.get(i,j) + l.get(i,j);
        }
    }


    return result;
}

Matrix operator-(const Matrix& l, const Matrix& r)
{
    Vector result(r.nx,r.ny);
    for(int i = 0; i < r.nx; i++)
    {
        for(int j = 0; j < r.ny; j++)
        {
            result.get(i,j) = l.get(i,j) - r.get(i,j);
        }
    }


    return result;
}































#endif
