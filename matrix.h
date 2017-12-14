#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <assert.h>
#include <cmath>

#include "vector.h"

class Matrix {
private:
    Vector* lines;

public:
    int nx, ny;
    Matrix(int _nx, int _ny, double init) {
        nx = _nx; ny = _ny;
        lines = new Vector[nx];

        for(int i = 0; i < nx; i++) {
            lines[i].init(ny);
            if(init != 0) { // o vector ja inicializa os elementos a 0
                // preencher todo o vector e portanto toda a matriz
               for(int j = 0; j < ny; j++) lines[i][j] = init; 
            }
        }
    }
    Matrix(const Matrix& other) { // construtor por copia
        nx = other.nx; ny = other.ny;
        lines = new Vector[nx];
        for(int i = 0; i < nx; i++) {
            lines[i].init(ny);
            lines[i] = other[i];
        }
    }
    ~Matrix() {
        delete[] lines;
    }

    Vector& operator[](int index) {
        assert(index < nx);
        return lines[index];
    }
    Vector operator[](int index) const {
        assert(index < nx);
        return lines[index];
    }

    Matrix& operator=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny); // so podemos copiar matrizes do mesmos tamanho
        for(int i = 0; i < nx; i++) {
            lines[i] = r[i];
        }
    }

    Matrix& operator+=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny); // so podemos adicionar matrizes do mesmo tamanho
        for(int i = 0; i < nx; i++) {
            lines[i] += r[i];
        }
    }

    Matrix& operator-=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny); // so podemos subtrair matrizes do mesmo tamanho
        for(int i = 0; i < nx; i++) {
            lines[i] -= r[i];
        }
    }
};

Matrix transpose(const Matrix& l) {
    Matrix n(l.ny, l.nx,0);
    for(int i = 0; i < l.nx; i++) {
        for (int j = 0; j< l.ny; j++) {
            n[j][i] = l[i][j];
        }
    }
    return n;
}

std::ostream& operator<<(std::ostream& out, const Matrix& v) {
    for(int i = 0; i < v.nx; i++) {
        out << v[i] << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Matrix& v) {
    for(int i = 0; i < v.nx; i++) in >> v[i];
    return in;
}

Matrix operator*(double a, const Matrix& r) {
    Matrix result(r.nx, r.ny, 0);
    for(int i = 0; i < r.nx; i++) {
        result[i] = a * r[i];
    }
    return result;
}

Matrix operator/(const Matrix& r, double a)
{
    return (1 / a) * r ;
}

Vector operator*(const Vector& l, const Matrix& r) {
    assert(l.dim() == r.nx);
    Vector result(l.dim());
    Matrix transposed = transpose(r);
    for(int i = 0; i < l.dim(); i++) result[i] = l * transposed[i];
    return result;
}
Vector operator*(const Matrix& l, const Vector& r) {
    assert(l.ny == r.dim());
    Vector result(r.dim());
    for(int i = 0; i < r.dim(); i++) result[i] = l[i] * r;
    return result;
}

Matrix operator*(const Matrix& l, const Matrix& r) {
    assert(l.ny == r.nx);
    Matrix result(l.nx, r.ny, 0);
    for(int i = 0; i < result.nx; i++) {
        for(int j = 0; j < result.ny; j++) {
            for(int k = 0; k < r.nx; k++) {
                result[i][j] = l[i][k] * r[k][j];
            }
        }
    }
    return result;
}

Matrix operator+(const Matrix& l, const Matrix& r) {
    assert(l.nx == r.nx && l.ny == r.ny); // so podemos somar matrizes do mesmo tamanho
    Matrix result(r.nx, r.ny, 0);
    for(int i = 0; i < r.nx; i++) {
        result[i] = l[i] + r[i];
    }
    return result;
}

Matrix operator-(const Matrix& l) {
    Matrix result(l.nx, l.ny, 0);
    for(int i = 0; i < l.nx; i++) result[i] = -l[i];
    return result;
}
Matrix operator-(const Matrix& l, const Matrix& r) {
    assert(l.nx == r.nx && l.ny == r.ny); // so podemos subtrair matrizes do mesmo tamanho
    Matrix result(r.nx, r.ny, 0);
    for(int i = 0; i < r.nx; i++) {
        result[i] = l[i] - r[i];
    }
    return result;
}

Matrix med(const Matrix& m)
{
    Matrix n(m.nx, m.ny, 0);
    n = m;
    for(int i = 1; i < m.nx; i++) {
        for(int j = 1; j < m.ny; j++) {
            n[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
        }
    }
    return n;
}

double mod(const Matrix& l)
{
    double sum = 0;
    for(int i = 0; i < l.nx; i++)
    {
        sum += l[i][0] * l[i][0];
    }
    return sqrt(sum);
}

double doublefy(const Matrix& l) {
    assert(l.nx == 1 && l.ny == 1);
    return l[0][0];
}

Matrix inverse(const Matrix& l) {
    int n = l.nx;
    double d = 0;
    Matrix A(l.nx,2*l.ny,0);
    Matrix res(l.nx, l.ny,0);
    for(int i = 0; i < l.nx; i++)
    {
        for (int j = 0; j < l.ny; j++)
        {
            A[i][j] = l[i][j];
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
            {
        }


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

        for (int i = 0; i < n; i++)
        {
            d = A[i][i];
            for(int j = 0; j < 2*n; j++)
            {
                A[i][j] = A[i][j]/d;
            }
        }
        for (int i = 0; i < l.nx; i++)
        {   for (int j = 0; j < l.ny; j++)
            {
                res[i][j] = A[i][j+n];
            }
        }
        int g;

        return res;
}

#endif
