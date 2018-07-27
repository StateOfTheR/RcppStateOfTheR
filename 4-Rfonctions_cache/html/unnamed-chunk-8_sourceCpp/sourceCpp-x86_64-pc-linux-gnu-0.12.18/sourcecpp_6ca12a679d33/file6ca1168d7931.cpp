#include "RcppArmadillo.h"
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;
using namespace Rcpp;

// [[Rcpp::export]]
vec optimisation(vec thetaInit, Function fn){
  Function optim("optim");
  List resOpt = as<List>(optim(thetaInit,fn));
  return resOpt["par"];
}


#include <Rcpp.h>
// optimisation
vec optimisation(vec thetaInit, Function fn);
RcppExport SEXP sourceCpp_1_optimisation(SEXP thetaInitSEXP, SEXP fnSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< vec >::type thetaInit(thetaInitSEXP);
    Rcpp::traits::input_parameter< Function >::type fn(fnSEXP);
    rcpp_result_gen = Rcpp::wrap(optimisation(thetaInit, fn));
    return rcpp_result_gen;
END_RCPP
}
