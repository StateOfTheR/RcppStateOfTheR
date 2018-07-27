#include <RcppArmadillo.h>
// [[Rcpp::depends(Matrix,RcppArmadillo)]]
using namespace Rcpp;

// [[Rcpp::export]]
double runifCpp()
{
  Function runif("runif");
  return as<double>(runif(1));
}

