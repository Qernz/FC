#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <assert.h>

class Matrix {
    double **p;

public:
    class CRow {
        friend class Matrix;
    public:
       double& operator[](int col)
       {
           return parent.p[row][col];
       }
   private:
       CRow(Matrix &parent_, int row_) :
           parent(parent_),
           row(row_)
       {}

       Matrix& parent;
       int row;
    };

   CRow operator[](int row)
   {
       return CRow(*this, row);
   }
    int nx, ny;
    Matrix(int n1, int n2, double val)
    {
        nx = n1;
        ny = n2;
        p = new double*[nx];
        for(int i = 0; i < nx; i++)
        {
            p[i] = new double[ny];
            for(int j = 0; j < n2; j++) p[i][j] = val;
        }
    }

    ~Matrix()
    {
        for(int i = 0; i <nx; i++ )
        {
            delete[] p[i];
        }
        delete[] p;
    }
    Matrix& operator=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny);
         // so podemos copiar matrizes do mesmos tamanho
        for(int i = 0; i < nx; i++)
        {
            for(int j = 0; j < ny;j++ )
            {
                p[i][j] = r.get(i,j);
            }
        }
    }
    double& get(int x, int y) const {return p[x][y];}
    int getsize() const {return nx;}

    Matrix& operator+=(const Matrix& r) {
        assert(nx == r.nx && ny == r.ny); // so podemos adicionar matrizes do mesmo tamanho
        for(int i = 0; i < nx; i++)
        {
            for(int j = 0; j < ny;j++ )
            {
                p[i][j] += r.get(i,j);
            }
        }
    }
};

std::ostream& operator<<(std::ostream& out, const Matrix& v) {
    for(int i = 0; i < v.nx; i++) {
        out << " ";
        for(int j = 0; j < v.ny; j++) {
            out << v.get(i, j);
            if(j != v.ny - 1) out << " ";
        }
        out << "\n";
    }
    return out;
}

Matrix operator*(double a, const Matrix& r)
{
    Matrix result(r.nx,r.ny, 0);
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
    Matrix result(r.nx,r.ny, 0);
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
    Matrix result(r.nx,r.ny, 0);
    for(int i = 0; i < r.nx; i++)
    {
        for(int j = 0; j < r.ny; j++)
        {
            result.get(i,j) = l.get(i,j) - r.get(i,j);
        }
    }


    return result;
}

Matrix med(const Matrix& m)
{
    Matrix n(m.nx, m.ny, 0);
    n = m;
    for(int i = 1; i < m.nx; i++) {
        for(int j = 1; j < m.ny; j++) {
            n.get(i, j) = (m.get(i, j + 1) + m.get(i, j - 1) + m.get(i - 1, j) + m.get(i + 1, j)) / 2;
        }
    }
    return n;
}


Matrix operator*(const Matrix& l, const Matrix & r)
{
    Matrix result(r.nx, r.ny, 0);
    for(int k = 0; k < r.nx; k++)
    {
        for(int i = 0; i < r.nx ; i++)
        {
            for(int j = 0; j< r.nx; j++)
            {
                result.get(i,j) = l.get(k,j) * r.get(i,k);
            }
        }
    }
    return result;
}


#endif
