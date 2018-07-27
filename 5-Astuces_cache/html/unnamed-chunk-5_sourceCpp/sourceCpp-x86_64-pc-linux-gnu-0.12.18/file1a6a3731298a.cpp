#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
mat prodByValue (mat X, mat Y) {
  return X*Y;
}

// [[Rcpp::export]]
mat prodByRef (mat& X, mat& Y) {
  return X*Y;
}
