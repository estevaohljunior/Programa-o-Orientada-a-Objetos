#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Agenda.h"

using namespace std;
  
int main()
{
  Agenda A;
  A.cadastrarContato("Mateus",35,1.80);
  A.cadastrarContato("Lucas",20,1.75);
  A.cadastrarContato("Lívia",21,1.50);

  A.buscaContato("Mateus");
  cout << endl;

  A.imprimirContatos();

  A.removerContato("Lucas");
  cout << endl;

  A.imprimirContatos();
  
  return 0;
}