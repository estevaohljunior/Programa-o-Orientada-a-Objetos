#include <iostream>
using std::cin, std::cout, std::endl;

using std::showpoint, std::noshowpoint;
using std::left, std::right;
using std::fixed, std::scientific, std::defaultfloat;

#include <iomanip>
using std::setprecision;

#include <iomanip>
using std::setw;
using std::setfill;

int main() {
  int fahrenheit;
  double celsius;
  cout<<"Digite a temperatura em fahrenheit:";
  cin>>fahrenheit;
  celsius = 5.0 / 9.0 * (fahrenheit - 32);
  cout << fixed;
  cout.precision(3);
  cout<<right;
  cout << setw(3) <<"fahrenheit:"<<setw(3)<<" "<<"celsius:"<<endl;
  cout << setw(3) <<fahrenheit <<setw(10)<<" "<<celsius; 
  cout << endl;
  return 0;
}