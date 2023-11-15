#include <iostream>

#include "Quadrado.h"
#include "Circulo.h"
#include "Triangulo.h"

int main() {
  //FormaBidimensional fd(2); // ERRO!!!!

  FormaBidimensional *formas[] = {new Quadrado(5), new Circulo(2), new Triangulo(3,3)};

  for (int i = 0 ; i < 3 ; i++)
  {
    formas[i]->desenhar();
    formas[i]->calcularPerimetro();
    formas[i]->calcularArea();
  }

  return 0;
}