/* 2 and 3 dimensional vector class
- the being only in a headers does affect compile
times but as these are small projects this effect
should be tiny */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>

class Vector {
private:
    float* c; // componentes
public:
    int dim;

    Vector(int n) {
        dim = n; c = new float[n];
        for(int i = 0; i < dim; i++) c[i] = 0;
    }
    Vector(float x, float y) {
        dim = 2; c = new float[2];
        c[0] = x; c[1] = y;
    }
    Vector(float x, float y, float z) {
        dim = 3; c = new float[3];
        c[0] = x; c[1] = y; c[2] = z;
    }
    Vector(const Vector& other) {
        dim = other.dim; c = new float[dim];
        for(int i = 0; i < dim; i++) c[i] = other[i];
    }
    ~Vector() { delete[] c; }

    float& operator[](int index) const {
        assert(index < dim); // programa crasha se indice >= dimensao do vetor
        return c[index];
    }

    Vector& operator=(const Vector& r) {
        assert(dim == r.dim); // so podemos copiar vetores do mesmos tamanho
        for(int i = 0; i < dim; i++) {
            this->c[i] = r[i];
        }
    }

    Vector& operator+=(const Vector& r) {
        for(int i = 0; i < dim; i++) (*this)[i] += r[i];
    }

    Vector& operator-=(const Vector& r) {
        for(int i = 0; i < dim; i++) (*this)[i] -= r[i];
    }

    float dot(const Vector& r) {
        float sum = 0;
        for(int i = 0; i < dim; i++) sum += (*this)[i] * r[i];
        return sum;
    }
};

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << "(";
    for(int i = 0; i < v.dim; i++) {
        out << v[i];
        if(i != v.dim - 1) { // ultimo valor nao leva uma virgula a seguir
            out << ", ";
        }
    }
    out << ")";

    return out;
}
std::istream& operator>>(std::istream& in, const Vector& v) {
    for(int i = 0; i < v.dim; i++) in >> v[i];
    return in;
}

inline bool operator==(const Vector& l, const Vector& r) {
    assert(l.dim == r.dim); // sem isto alguns vetores 2 e 3 podiam ser comparados como iguais
    for(int i = 0; i < l.dim; i++)
        if(l[i] != r[i]) return false;
    return true;
}

Vector operator+(const Vector& l, const Vector& r) {
    assert(l.dim == r.dim);
    Vector sum(l.dim);
    for(int i = 0; i < l.dim; i++) sum[i] = l[i] + r[i];
    return sum;
}

Vector operator-(const Vector& r) {
    Vector minus(r.dim);
    for(int i = 0; i < r.dim; i++) minus[i] = -r[i];
    return minus;
}
Vector operator-(const Vector& l, const Vector& r) {
    assert(l.dim == r.dim);
    Vector dif(l.dim);
    for(int i = 0; i < l.dim; i++) dif[i] = l[i] - r[i];
    return dif;
}

#endif // close the include guard
