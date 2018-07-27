#include <RcppArmadillo.h>
// [[Rcpp::depends(Matrix,RcppArmadillo)]]
using namespace Rcpp;

// [[Rcpp::export]]
double runifCpp()
{
  Function runif("runif");
  return as<double>(runif(1));
}



#include <Rcpp.h>
// runifCpp
double runifCpp();
RcppExport SEXP sourceCpp_1_runifCpp() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(runifCpp());
    return rcpp_result_gen;
END_RCPP
}
