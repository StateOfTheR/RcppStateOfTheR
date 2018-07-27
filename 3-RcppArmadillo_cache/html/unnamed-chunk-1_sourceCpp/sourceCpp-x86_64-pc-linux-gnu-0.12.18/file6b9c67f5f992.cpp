#include "RcppArmadillo.h"
using namespace arma;  // Evite d'écrire arma::fonctionArmadillo
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]] // Importe la fonction qui suit dans l'environnement global de R
mat addition(int a, mat M) {
  return a + M;
}
