#include <iostream>
using std::cin, std::cout, std::endl;

using std::showpoint, std::noshowpoint;

using std::fixed, std::scientific, std::defaultfloat;

#include <iomanip>
using std::setprecision;

int main() {
  double num = 100.453627;
  cout << fixed;
  cout.precision(1);
  cout << "(1) num = " << num << endl;
  cout.precision(2);
  cout << "(2) num = " << num << endl;
  cout.precision(3);
  cout<<"(3) num = "<<num<<endl;
  cout.precision(4);
  cout<<"(4) num = "<<num<<endl;
  cout << endl;
  return 0;
}