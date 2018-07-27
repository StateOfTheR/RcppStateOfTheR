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
