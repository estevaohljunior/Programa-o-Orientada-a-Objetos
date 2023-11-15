#include <iostream>
using std::cin, std::cout, std::endl;
#include <string>
using std::string;
//using std::ios;
using std::fixed, std::defaultfloat;

using std::left, std::right;

#include <iomanip>
using std::setw;

using std::setprecision;

#include <fstream>
using std::ofstream, std::ifstream;

struct D_SIZE {
  string nome;
  int size;
};
D_SIZE sizes[11] = {
  {"Char",sizeof(char)},
  {"Short",sizeof(short)},
  {"Short_int",sizeof(short int)},
  {"Int",sizeof(int)},
  {"Long",sizeof(long)},
  {"Long_int",sizeof(long int)},
  {"Long_Long",sizeof(long long)},
  {"Long_Long_Int",sizeof(long long int)},
  {"Float",sizeof(float)},
  {"Double",sizeof(double)},
  {"Long_Double",sizeof(long double)},
};
bool salvar_dados(D_SIZE c[], int n)
{
  ofstream fout("dados.dat", std::ios::out);

  if (!fout)
    return false;
  
  for (int i = 0 ; i < n ; i++)
    fout << c[i].nome << ' ' << c[i].size<< endl;

  fout.close(); // opcional

  return true;
}
bool listar_todos()
{
  ifstream fin("dados.dat", std::ios::in);

  if (!fin)
    return false;
  
  D_SIZE c;
  cout << fixed;
  while (fin >> c.nome >> c.size)
  {   
    cout << setw(0) <<c.nome << ' ' << setw(10) << left<< c.size << endl;
  }

  fin.close(); // opcional

  return true;
}
int main() {
  salvar_dados(sizes, 11);
  listar_todos();
}