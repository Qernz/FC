#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <assert.h>
#include <cmath>

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
       double operator[](int col) const
       {
           return parent.p[row][col];
       }
   private:
       CRow(Matrix &parent_, int row_) :
           parent(parent_),
           row(row_)
       {}
          /* CRow(const Matrix &parent_, int row_) :
               parent( parent_),
               row(row_)
           {}*/

       Matrix& parent;
       int row;
    };

   CRow operator[](int row)
   {
       return CRow(*this, row);
   }
   /*CRow operator[](int row) const
   {
       return CRow(*this, row);
   }*/
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

Matrix operator/(const Matrix& r, double a )
{
    return (1/a)*r ;
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

double mod(const Matrix& l)
{
    double sum = 0;
    for(int i = 0; i < l.nx; i++)
    {
        sum += l.get(i,0)*l.get(i,0);
    }
    return sqrt(sum);
}



/*Matrix operator*(const Matrix& l, const Matrix & r)
{
    Matrix result(l.nx, r.ny, 0);
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
}*/
Matrix operator*(const Matrix& l, const Matrix & r)
{
    Matrix result(l.nx, r.ny, 0);
    for(int i = 0; i < l.nx; i++)
    {
        for(int j = 0; j < r.ny ; j++)
        {
            for(int k = 0; k< r.nx; k++)
            {
                result.get(i,j) += l.get(i,k) * r.get(k,j);
            }
        }
    }
    return result;
}

double doublefy(const Matrix& l)
{
    if(l.nx == 1 && l.ny ==1)
    {
        return l.get(0,0);
    }
}
Matrix transpose(const Matrix& l)
{

    Matrix n(l.ny, l.nx,0);
    for(int i = 0; i < l.nx; i++)
    {
        for (int j = 0; j< l.ny; j++)
        {
            n.get(j,i) = l.get(i,j);
        }
    }
    return n;
}
Matrix inverse(const Matrix& l)
{
    int n = l.nx;
    double d = 0;
    Matrix A(l.nx,2*l.ny,0);
    Matrix res(l.nx, l.ny,0);
    for(int i = 0; i < l.nx; i++)
    {
        for (int j = 0; j < l.ny; j++)
        {
            A.get(i,j) = l.get(i,j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< 2 * n; j++)
        {
            if (j == i+n )
            {
                A.get(i,j) = 1;
            }
        }
    }
    //cout << A << endl;
    //I[0][0] = I[1][1] = I[2][2] = 1;
    //C = A-B;
    //cout << C << endl;
    //cout << A[1][2]<< endl;
    //A[1][2] = 0;
    //C = A + B;
    //cout << C[1][2]<< endl;

    // vamos gauss-jordar isto
    //n = A.getsize();
    //cout << n << endl;
    /*A[0][0] = 1; A[0][1] = 3; A[0][2] = 1;
    A[1][0] = 2; A[1][1] = 0; A[1][2] = 2;
    A[2][0] = 2; A[2][1] = 1; A[2][2] = 0;
    A[0][3] = A[1][4] = A[2][5] = 1;
    cout << A << endl;*/
    /*for (int k = 0; k< n ; k++){
        max = A[K][k];
        line = 0;
        for(int i = 0; i< n; i++)
        {
            if(A[i][k] > max)
            {
                max = A[i][k];
                line = i;
            }
        }
        if(line > k)
        {

        }*/
        for(int i = n-1; i > 0; i--)
        {
            if(A.get(i-1,0) < A.get(i,0))
            {
                for(int j = 0; j < 2*n ; j++)
                {
                    d = A.get(i,j);
                    A.get(i,j) = A.get(i-1,j);
                    A.get(i-1,j) = d;
                }
            }
        }


        //cout << A << endl;

        for (int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j++)
                if (j!=i)
                {
                    d=A.get(j,i)/A.get(i,i);
                    for(int k = 0; k < 2*n; k++)
                    {
                        A.get(j,k) -= A.get(i,k)*d;
                    }
                }
            }
        //cout << A << endl;

        for (int i = 0; i < n; i++)
        {
            d = A.get(i,i);
            for(int j = 0; j < 2*n; j++)
            {
                A.get(i,j) = A.get(i,j)/d;
            }
        }
        for (int i = 0; i < l.nx; i++)
        {   for (int j = 0; j < l.ny; j++)
            {
                res.get(i,j) = A.get(i,j+n);
            }
        }
        int g;
        //std::cout <<"este é o A:"<< std::endl << A << std::endl << res << std::endl;

        return res;
}


#endif
