/*
- the being only in a headers does affect compile
times but as these are small projects this effect
should be small enough.
- the operator overload follow the most common convention in the C++
community. */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>
#include <cmath>

class Vector {
private:
    double* c; // componentes
    int _dim;

public:
    Vector() {} // construtor por defeito
    void init(int n) {
        _dim = n; c = new double[n];
        for(int i = 0; i < _dim; i++) c[i] = 0;
    }
    Vector(int n) {
        _dim = n; c = new double[n];
        for(int i = 0; i < _dim; i++) c[i] = 0;
    }
    Vector(double x, double y) {
        _dim = 2; c = new double[2];
        c[0] = x; c[1] = y;
    }
    Vector(double x, double y, double z) {
        _dim = 3; c = new double[3];
        c[0] = x; c[1] = y; c[2] = z;
    }
    Vector(const Vector& other) {
        _dim = other._dim; c = new double[_dim];
        for(int i = 0; i < _dim; i++) c[i] = other[i];
    }
    ~Vector() { delete[] c; }

    int dim() const { return _dim; }

    double& operator[](int index) {
        assert(index < _dim); // programa crasha se indice >= _dimensao do vetor
        return c[index];
    }
    double operator[](int index) const {
        assert(index < _dim);
        return c[index];
    }

    Vector& operator=(const Vector& r) {
        assert(_dim == r._dim); // so podemos copiar vetores do mesmos tamanho
        for(int i = 0; i < _dim; i++) {
            this->c[i] = r[i];
        }
    }

    Vector& operator+=(const Vector& r) {
        assert(_dim == r._dim);
        for(int i = 0; i < _dim; i++) (*this)[i] += r[i];
    }

    Vector& operator-=(const Vector& r) {
        assert(_dim == r._dim);
        for(int i = 0; i < _dim; i++) (*this)[i] -= r[i];
    }

    double dot(const Vector& r) {
        double sum = 0;
        for(int i = 0; i < _dim; i++) sum += (*this)[i] * r[i];
        return sum;
    }

    friend Vector med(const Vector& r);
};

Vector med(const Vector& r) {
    Vector result(r.dim());
    for(int i = 1; i < r.dim() - 1; i++) {
        result[i] = (r[i - 1] + r[i + 1]) / 2;
    }
    result[0] = r[0]; result[r.dim() - 1] = r[r.dim() - 1];
    return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    //out << "(";
    for(int i = 0; i < v.dim(); i++) {
        out << v[i];
        if(i != v.dim() - 1) { // ultimo valor nao leva uma virgula a seguir
            out << " ";
        }
    }
    //out << ")";

    return out;
}
std::istream& operator>>(std::istream& in, Vector& v) {
    for(int i = 0; i < v.dim(); i++) in >> v[i];
    return in;
}

inline bool operator==(const Vector& l, const Vector& r) {
    assert(l.dim() == r.dim()); // sem isto alguns vetores 2 e 3 podiam ser comparados como iguais
    for(int i = 0; i < l.dim(); i++)
        if(l[i] != r[i]) return false;
    return true;
}

Vector operator+(const Vector& l, const Vector& r) {
    assert(l.dim() == r.dim());
    Vector sum(l.dim());
    for(int i = 0; i < l.dim(); i++) sum[i] = l[i] + r[i];
    return sum;
}

Vector operator-(const Vector& r) {
    Vector minus(r.dim());
    for(int i = 0; i < r.dim(); i++) minus[i] = -r[i];
    return minus;
}
Vector operator-(const Vector& l, const Vector& r) {
    assert(l.dim() == r.dim());
    Vector dif(l.dim());
    for(int i = 0; i < l.dim(); i++) dif[i] = l[i] - r[i];
    return dif;
}

Vector operator*(int a, const Vector& r) {
    Vector result(r.dim());
    for(int i = 0; i < r.dim(); i++) result[i] = r[i] * a;
    return result;
}
Vector operator*(double a, const Vector& r) {
    Vector result(r.dim());
    for(int i = 0; i < r.dim(); i++) result[i] = r[i] * a;
    return result;
}
double operator*(const Vector& l, const Vector& r) {
    assert(l.dim() == r.dim());
    double result = 0;
    for(int i = 0; i < r.dim(); i++) result += l[i] * r[i];
    return result;
}
double mod(const Vector& l)
{
    double res = 0;
    for (int i = 0; i< l.dim() ; i++)
    {
        res += l[i]*l[i];
    }
    return sqrt(res);
}


Vector operator/(const Vector& l, double a)
{
    return  (1/a)* l;
}
#endif // close the include guard
