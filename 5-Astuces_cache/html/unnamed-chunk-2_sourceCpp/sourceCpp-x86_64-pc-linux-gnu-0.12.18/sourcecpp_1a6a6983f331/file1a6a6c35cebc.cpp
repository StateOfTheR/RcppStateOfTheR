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


#include <Rcpp.h>
// byValue
void byValue(vec x, double newValue);
RcppExport SEXP sourceCpp_1_byValue(SEXP xSEXP, SEXP newValueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< vec >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type newValue(newValueSEXP);
    byValue(x, newValue);
    return R_NilValue;
END_RCPP
}
// byRef
void byRef(vec& x, double newValue);
RcppExport SEXP sourceCpp_1_byRef(SEXP xSEXP, SEXP newValueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type newValue(newValueSEXP);
    byRef(x, newValue);
    return R_NilValue;
END_RCPP
}
