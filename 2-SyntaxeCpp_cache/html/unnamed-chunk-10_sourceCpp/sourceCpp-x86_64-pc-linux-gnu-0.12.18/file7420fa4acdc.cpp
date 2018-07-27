#include <iostream>
using namespace std;

int test(int a)
{
  switch(a)
  {
  case 1 :
    cout << "a vaut 1" << endl;
    break;
  case 2 :
    cout << "a vaut 2" << endl;
    break;
  default :
    cout << "a ne vaut ni 1, ni 2"<< endl;
  break;
  }
  return 0;
}
