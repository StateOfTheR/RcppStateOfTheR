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


#include <Rcpp.h>
// prodByRowOrdering
mat prodByRowOrdering(mat A, mat B);
RcppExport SEXP sourceCpp_1_prodByRowOrdering(SEXP ASEXP, SEXP BSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type A(ASEXP);
    Rcpp::traits::input_parameter< mat >::type B(BSEXP);
    rcpp_result_gen = Rcpp::wrap(prodByRowOrdering(A, B));
    return rcpp_result_gen;
END_RCPP
}
// prodByColOrdering
mat prodByColOrdering(mat A, mat B);
RcppExport SEXP sourceCpp_1_prodByColOrdering(SEXP ASEXP, SEXP BSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type A(ASEXP);
    Rcpp::traits::input_parameter< mat >::type B(BSEXP);
    rcpp_result_gen = Rcpp::wrap(prodByColOrdering(A, B));
    return rcpp_result_gen;
END_RCPP
}
