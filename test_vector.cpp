#include <iostream>
#include <fstream>
#include <limits>
#include <ios>
#include <vector>

#include "vector.h"

int main() {
    std::cout << "------- basic arithmetics ------\n";
    Vector a(0, 1, 2), b(2, 1, 0);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "-a: " << -a << std::endl;
    std::cout << "a.dot(b): " << a.dot(b) << std::endl;
    std::cout << "a[0]: " << a[0] << std::endl;

    std::cout << "------- different ways of indexing ------\n";
    a[0] = 3;
    std::cout << "a[0] = 3; a[0]: " << a[0] << std::endl;
    double t = a[0]; t = -4;
    std::cout << "double t = a[0]; t = -4; a[0]: " << a[0] << std::endl;
    double& h = a[0]; h = -4;
    std::cout << "double& h = a[0]; h = -4; a[0]: " << a[0] << std::endl;
    std::cout << "std::cin >> a[0]; > "; std::cin >> a[0];
    std::cout << "a[0]: " << a[0] << std::endl;

    std::cout << "------- copy/assigment ------\n";
    Vector tmp = a;
    std::cout << "Vector tmp = a; tmp: " << tmp << std::endl;
    tmp = b;
    std::cout << "tmp = b; tmp: " << tmp << std::endl;

    std::cout << "------- reading vector from std::cin ------\n";
    std::cout << "let's try entering a vector. choose a dimension: ";
    int d;
    std::cin >> d;
    Vector v(d);
    std::cout << d << " double(s) separated by spaces: ";
    std::cin >> v;
    std::cout << "inputed vector: " << v << std::endl;

    std::cout << "------- reading vectors from file ------\n";
    std::ifstream data("vectors_file.txt");
    int n, dim; data >> n >> dim;
    std::vector<Vector> vecs;
    for(int i = 0; i < n; i++) {
        Vector v(dim);
        data >> v;
        vecs.push_back(v);
    }
    std::cout << "vectors:\n";
    for(auto v : vecs) std::cout << v << std::endl;

    std::cout << "------- out of bounds checks ------\n";
    std::cout << "accessing out-of-bounds element. this should crash.\n";
    a[10];
}
