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


#include <Rcpp.h>
// invProdCpp
vec invProdCpp(mat A, vec b);
RcppExport SEXP sourceCpp_1_invProdCpp(SEXP ASEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type A(ASEXP);
    Rcpp::traits::input_parameter< vec >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(invProdCpp(A, b));
    return rcpp_result_gen;
END_RCPP
}
// solveCpp
vec solveCpp(mat A, vec b);
RcppExport SEXP sourceCpp_1_solveCpp(SEXP ASEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type A(ASEXP);
    Rcpp::traits::input_parameter< vec >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(solveCpp(A, b));
    return rcpp_result_gen;
END_RCPP
}
