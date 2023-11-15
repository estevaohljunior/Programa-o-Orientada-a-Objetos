#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Circulo : public FormaBidimensional
{
public:
  Circulo(double rai) : FormaBidimensional(99999) {
    this->raio=rai;
  }

  virtual void desenhar() {
    cout << "  _ " << endl;
    cout << "/   \\" << endl;
    cout << "\\   /" << endl;
    cout << "  ~ " << endl;
  }
  virtual void calcularArea(){
    double a=3.14*(raio*raio);
    cout<<"Area do Circulo: "<<a<<endl;
  }
  virtual void calcularPerimetro(){
    double e=2*3.14*raio;
    cout<<"Perimentro do Circulo: "<<e<<endl;
  }
  private:
  double raio;
};

#endif