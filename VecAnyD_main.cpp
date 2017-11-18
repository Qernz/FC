//---------- VecAnyD_main.cpp ----------
//
//
#include <iostream>
#include "VecAnyD.h"


int main()
{
    using namespace std;


    // aceita input usando os métodos da classe
     cout<<"de a dimensao dos vetores \n";
    unsigned n;
     cin>> n;
     cout<<"de todos os elementos do 1o vetor \n";
    Vector r1(n); 


    for(unsigned i=0;i<n;i++){ 
      double vi; 
       cin>> vi; 
      r1.set(i,vi); // com o método set inicializamos ou alteramos os valores do vetor
    }
     cout << "r1: " << r1 << endl;


      
    return  0;
    
}
