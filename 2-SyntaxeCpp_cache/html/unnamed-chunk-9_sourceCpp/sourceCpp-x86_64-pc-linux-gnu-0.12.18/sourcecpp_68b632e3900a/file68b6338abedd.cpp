#include <iostream>
using namespace std;

int test(int a)
{
    if (a > 10)
        cout << "a est plus grand que 10" << endl;
    else
        cout << "a est inférieur ou égal à 10" << endl;
    return 0;
}


#include <Rcpp.h>
