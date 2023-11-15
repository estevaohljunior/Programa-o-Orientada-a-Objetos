#include <iostream>
#include "Conta_P.h"
#include "Conta_l.h"
#include "Conta_c.h"
int main() {
  Conta *contas[]={new Poupanca(13,"Ellisson Barbosa",22000,13),new Corrente(14,"Ellisson Barbosa",2000),new Limite(15,"Ellisson Barbosa",22000,10000)};
  
  for (int c=0;c<3;c++){
  contas[c]->deposito(150);
  contas[c]->retirada(100);
  contas[c]->extrato();}
}