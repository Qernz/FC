#include <iostream>
#include <fstream>
#include <limits>
#include <ios>
#include <vector>

#include "vector.h"
#include "matrix.h"

int main() {
    std::cout << "------- basic arithmetics ------\n";
    Matrix a(2, 2, 2), b(2, 2, 0.4);
    std::cout << "a: " << std::endl << a;
    std::cout << "b: " << std::endl << b;
    std::cout << "a + b: " << std::endl << a + b;
    std::cout << "a - b: " << std::endl << a - b;
    std::cout << "-a: " << std::endl << -a;
    std::cout << "3.141592 * a: " << std::endl << 3.141592 * a;
    std::cout << "a / 2: " << std::endl << a / 2;

    std::cout << "------- special operations ------\n";
    Vector c(1, 2);
    std::cout << "vector c: " << c << std::endl;
    std::cout << "a * b: " << std::endl << a * b;
    std::cout << "c * b: " << c * b << std::endl;
    std::cout << "a * c: " << a * c << std::endl;

    std::cout << "------- indexing ------\n";
    std::cout << "two indices: ";
    int x, y; std::cin >> x >> y;
    std::cout << "a[" << x << "][" << y << "]: " << a[x][y] << std::endl;
    std::cout << "changing a[0][0] to 3." << std::endl; a[0][0] = 3;
    std::cout << "a: " << std::endl << a;

    std::cout << "------- copy/assigment ------\n";
    Matrix tmp = a;
    std::cout << "Matrix tmp = a; tmp: " << std::endl << tmp;
    tmp = b;
    std::cout << "tmp = b; tmp: " << std::endl << tmp;

    std::cout << "------- reading vector from std::cin ------\n";
    std::cout << "let's try entering a matrix. choose two dimensions: ";
    int dx, dy; std::cin >> dx >> dy;
    Matrix v(dx, dy, 0);
    std::cout << dx * dy << " doubles: "; std::cin >> v;
    std::cout << "inputed matrix: " << std::endl << v;

    std::cout << "------- reading matrix from file ------\n";
    std::ifstream data("matrix_file.txt");
    int nx, ny; data >> nx >> ny;
    Matrix m(nx, ny, 0);
    data >> m;
    std::cout << "matrix:" << std::endl << m;

    std::cout << "------- out of bounds checks ------\n";
    std::cout << "accessing out-of-bounds element. this should crash.\n";
    a[10][10];
}
