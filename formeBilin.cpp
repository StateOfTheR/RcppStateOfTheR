#include "RcppArmadillo.h"
using namespace arma;
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
double formeBilinCpp_Loop(vec alpha, mat pi) {
  int Q = pi.n_cols;
  double sum = 0;
  for (int q=0; q<Q; q++) {
    for(int l=0; l<Q; l++) {
      sum += alpha[q]*alpha[l]*pi(q,l);
    }
  }
  return sum;
}
// [[Rcpp::export]]
double formeBilinCpp_Prod(vec alpha, mat pi) {
  double sum = as_scalar(alpha.t() * pi * alpha);
  return sum;
}