#include "RcppArmadillo.h"
using namespace arma;
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
double factorielleCpp_Rec(double n) {
  if(n == 1) {
    return 1;
  } else {
    return n*factorielleCpp_Rec(n-1);
  }
}
// [[Rcpp::export]]
double factorielleCpp_Loop(double n) {
  double prod = 1;
  for(double i=1;i<=n;i++){
    prod = prod*i;
  }
  return prod;
}


