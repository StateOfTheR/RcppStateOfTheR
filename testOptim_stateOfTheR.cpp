#include "RcppArmadillo.h"
using namespace arma;
// [[Rcpp::depends(RcppArmadillo)]]

double norme2(vec x) {
  return as_scalar(sqrt(sum(pow(x,2))));
}

// [[Rcpp::export]]
double fr(vec theta, vec X) {
  double pi = 3.141592653589793238462643383280; 
  int n = X.n_elem;
  double m = theta[0];
  double sigma2 = theta[1];
  return -(n/2)*log(sigma2*2*pi) - pow(norme2(X-m),2)/(2*sigma2); 
}
// [[Rcpp::export]]
vec grr(vec theta, vec X) {
  int n = X.n_elem;
  double m = theta[0];
  double sigma2 = theta[1];
  vec gradient(2);
  gradient[0] = sum(X-m)/sigma2;
  gradient[1] = -n/(2*sigma2) + pow(norme2(X-m),2)/(2*pow(sigma2,2));
  return gradient;
}

/*** R
X <- rnorm(100, mean = 1, sd = 2)
theta_Chap <- optim(c(0,1), fr, grr, X=X, control=list(fnscale=-1))$par
print(theta_Chap)
*/
