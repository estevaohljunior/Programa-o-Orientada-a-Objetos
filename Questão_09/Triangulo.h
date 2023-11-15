#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Triangulo : public FormaBidimensional
{
public:
  Triangulo(double bas, double altur) : FormaBidimensional(3) {
    this->base=bas;
    this->altura=altur;
  }

  virtual void desenhar() {
    cout << "  .   " << endl;
    cout << " / \\ " << endl;
    cout << "/   \\" << endl;
    cout << "~~~~~ " << endl;
  }
  virtual void calcularArea(){
    double d=(this->base*this->altura)/2;
    cout<<"Area do Triangulo: "<<d<<endl;
  }
  virtual void calcularPerimetro(){
    double z=base+altura+altura;
    cout<<"Perimetro do Triangulo: "<<z<<endl;
  }
  private:
  double base, altura;
};

#endif