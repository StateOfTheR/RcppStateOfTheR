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


#include <Rcpp.h>
// prodByValue
mat prodByValue(mat X, mat Y);
RcppExport SEXP sourceCpp_1_prodByValue(SEXP XSEXP, SEXP YSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< mat >::type Y(YSEXP);
    rcpp_result_gen = Rcpp::wrap(prodByValue(X, Y));
    return rcpp_result_gen;
END_RCPP
}
// prodByRef
mat prodByRef(mat& X, mat& Y);
RcppExport SEXP sourceCpp_1_prodByRef(SEXP XSEXP, SEXP YSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< mat& >::type Y(YSEXP);
    rcpp_result_gen = Rcpp::wrap(prodByRef(X, Y));
    return rcpp_result_gen;
END_RCPP
}
