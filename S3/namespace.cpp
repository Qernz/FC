#include <iostream>


// Nota: os :: chamam-se operador de scope, usa-se no namespace e nas classes

// aqui definimos uma funcao

void coisa() {
     // assim a funcao passa a pertencer ao namespace global que inclui aquilo
     // que esta definido por defeito, e ainda aquilo que definimos fora dos namespaces
	std::cout << "::coisa()" << std::endl;
	}

namespace meuespaco {

	void coisa() {
		std::cout << "meuespaco::coisa()" << std::endl; // o cout e o endl estao no namespace std,
        // nota: foi o iostream que acrescentou cout, cin e endl ao namespace std
		// que e o namespace da biblioteca standard do c++, diferente do que se usa no c
		}

	 void test() {
          coisa(); // aqui nao da bronca pois dentro desta definicao o defeito e o namespace
          ::coisa();
          }

	}

int main() {

    coisa(); // ou ::coisa()
    meuespaco::coisa();

    {// aqui iniciamos um bloco, no qual se vai usar o namespace meuespaco
    using namespace meuespaco;
//    coisa(); // da bronca! este e ambiguo, vai dar erro de compilacao pois nao sabe que funcao e
    ::coisa(); // este esta no namespace global que nao tem nome, basta o scope,
    meuespaco::coisa(); // este esta no namespace meuespeaco
    }

    meuespaco::test();

    return 0;
}