#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Quadrado : public FormaBidimensional
{
public:
  Quadrado(double lad) : FormaBidimensional(4) {
    this->lado=lad;
  }

  virtual void desenhar() {
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
  }
  virtual void calcularArea(){
    double c=lado*lado;
    cout<<"Area do Quadrado: "<<c<<endl;
  }
  virtual void calcularPerimetro(){
    double x=4*lado;
    cout<<"Perimetro do Quadrado: "<<x<<endl;
  }
private:
double lado;
};

#endif