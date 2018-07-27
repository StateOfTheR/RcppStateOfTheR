#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
void byValue (vec x, double newValue) {
  x.fill(newValue);
}

// [[Rcpp::export]]
void byRef (vec& x, double newValue) {
  x.fill(newValue);
}
