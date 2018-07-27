#include <RcppArmadillo.h>
// [[Rcpp::depends(Matrix,RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
double runifCpp2()
{
  return randu();
}


#include <Rcpp.h>
// runifCpp2
double runifCpp2();
RcppExport SEXP sourceCpp_1_runifCpp2() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(runifCpp2());
    return rcpp_result_gen;
END_RCPP
}
