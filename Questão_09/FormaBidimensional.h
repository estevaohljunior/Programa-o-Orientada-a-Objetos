#ifndef FORMABI_H
#define FORMABI_H 

//classe abstrata

class FormaBidimensional 
{
public:
  FormaBidimensional(int numLados) : numLados(numLados) { }

  //método virtual puro
  virtual void desenhar(){};
  virtual void calcularArea(){};
  virtual void calcularPerimetro(){};
private:
  int numLados;
};

#endif