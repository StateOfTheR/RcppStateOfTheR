#include "RcppArmadillo.h"
using namespace arma;
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
mat addition(int a, mat M) {
  return M + a;
}
