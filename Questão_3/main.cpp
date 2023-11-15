#include <iostream>
#include <string>
#include <cstring>
using std::string;
using std::cin, std::cout, std::endl;

using std::left, std::right;

#include <iomanip>
using std::setw;
using std::setfill;


int main() {
  string mat;
  cout<<"Digite a string: ";
  cin>>mat;


  //com largura
  for (int l = 0 ; l < mat.size() ; l++)
  {
      cout.width((mat.size())*2);
      cout << mat[l] << " "; 

  }

  cout << endl << endl;


  return 0;
}