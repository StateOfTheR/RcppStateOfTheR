#include "RcppArmadillo.h"
using namespace arma;  // Evite d'écrire arma::fonctionArmadillo
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]] // Importe la fonction qui suit dans l'environnement global de R
mat addition(int a, mat M) {
  return a + M;
}


#include <Rcpp.h>
// addition
mat addition(int a, mat M);
RcppExport SEXP sourceCpp_1_addition(SEXP aSEXP, SEXP MSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type a(aSEXP);
    Rcpp::traits::input_parameter< mat >::type M(MSEXP);
    rcpp_result_gen = Rcpp::wrap(addition(a, M));
    return rcpp_result_gen;
END_RCPP
}
