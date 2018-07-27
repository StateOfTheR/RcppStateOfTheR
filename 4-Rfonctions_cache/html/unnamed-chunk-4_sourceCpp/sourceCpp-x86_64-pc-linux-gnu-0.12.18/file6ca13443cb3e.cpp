#include <RcppArmadillo.h>
// [[Rcpp::depends(Matrix,RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
double runifCpp2()
{
  return randu();
}
