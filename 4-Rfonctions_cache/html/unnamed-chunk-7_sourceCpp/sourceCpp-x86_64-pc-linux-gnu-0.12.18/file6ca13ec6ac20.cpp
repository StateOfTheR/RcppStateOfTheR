#include "RcppArmadillo.h"
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;
using namespace Rcpp;
  
double norme2(vec x) {
  return as_scalar(sqrt(sum(pow(x,2))));
}

// [[Rcpp::export]]
double frCpp(vec theta) {
  vec X = (randn(1000)+1)/2;
  const double pi = 3.141592653589793238462643383280; 
  int n = X.n_elem;
  double m = theta[0];
  double sigma2 = theta[1];
  return -( -(n/2)*log(sigma2*2*pi) - pow(norme2(X-m),2)/(2*sigma2) ); 
}
