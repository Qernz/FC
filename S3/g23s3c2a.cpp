// basico trivial, filthy 2nd year students

#include <iostream>
using namespace std;

class melhor_pratica_de_sempre
{
public:
    int x, y;
    melhor_pratica_de_sempre(int _x, int _y) {
        x = _x;
        y = _y;
    }
    melhor_pratica_de_sempre() {
        x = 0; y = 0;
    }
private:
};

class tou_com_sono
{
public:
    int bixo, mato, grosso;
    tou_com_sono()
};
int main()
{
    melhor_pratica_de_sempre RS;
    cout << RS.x << " " << RS.y << endl;
    melhor_pratica_de_sempre b(3,4);
    cout << b.x << " " << b.y << endl;

}
