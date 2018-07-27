#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
mat prodByRowOrdering (mat A, mat B) 
{
  mat C = mat(size(A));
  
  for (uword i = 0; i < A.n_rows; i++)
    for (uword j = 0; j < A.n_cols; j++)
      C(i,j) = A(i,j) * B(i,j);
  
  return C;
}
  
// [[Rcpp::export]]
mat prodByColOrdering (mat A, mat B)
{
  mat C = mat(size(A));
  
  for (uword j = 0; j < A.n_cols; j++)
    for (uword i = 0; i < A.n_rows; i++)
      C(i,j) = A(i,j) * B(i,j);
  
  return C;
}
