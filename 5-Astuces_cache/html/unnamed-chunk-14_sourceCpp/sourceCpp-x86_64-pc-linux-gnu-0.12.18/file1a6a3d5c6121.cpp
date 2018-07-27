#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
mat covOutOfScope (mat X) 
{
  mat y = zeros(X.n_cols, X.n_cols);
  rowvec z = rowvec(X.n_cols);
  
  for (uword i = 0; i < X.n_rows; i++) {
    z = X.row(i);
    y += z.t() * z;
  }
  
  return y / X.n_rows;
}

// [[Rcpp::export]]
mat covInScope (mat X) 
{
  mat y = zeros(X.n_cols, X.n_cols);

  for (uword i = 0; i < X.n_rows; i++) {
    rowvec z = X.row(i);
    y += z.t() * z;
  }
  
  return y / X.n_rows;
}
