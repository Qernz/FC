#include <iostream>

#include "vector.h"

int main() {
    Vector a(0, 1, 2), b(2, 1, 0);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "-a: " << -a << std::endl;
    std::cout << "a.dot(b): " << a.dot(b) << std::endl;

    Vector tmp = a;
    std::cout << "Vector tmp = a; tmp: " << tmp << std::endl;
    tmp = b;
    std::cout << "tmp = b; tmp: " << tmp << std::endl;

    std::cout << "let's try entering a vector. choose a dimension: ";
    int d; std::cin >> d;
    std::cout << d << " float separated by spaces: ";
    Vector v(d);
    std::cin >> v;
    std::cout << "inputed vector: " << v << std::endl;
}
