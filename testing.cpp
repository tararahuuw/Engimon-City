#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main()
{
  // A test of setw()

  cout << "*" << -17 << "*" << endl;
  cout << "*" << setw(6) << -17 << "*" << endl << endl;

  cout << "*" << "Hi there!" << "*" << endl;
  cout << "*" << setw(20) << "Hi there!" << "*" << endl;
  cout << "*" << setw(20) << "Hi!" << "*" << endl;
  cout << "*" << setw(20) << "Hi there!" << "*" << endl;
  cout << "*" << setw(3) << "Hi there!" << "*" << endl;
// g++ -o testing testing.cpp
  return 0;
}