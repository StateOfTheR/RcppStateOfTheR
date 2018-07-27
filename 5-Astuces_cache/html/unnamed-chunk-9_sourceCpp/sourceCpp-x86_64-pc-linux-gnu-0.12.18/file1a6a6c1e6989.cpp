#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
vec invProdCpp (mat A, vec b) {
  return A.i() * b;
}

// [[Rcpp::export]]
vec solveCpp (mat A, vec b) {
  return solve(A, b);
}
