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


#include <Rcpp.h>
// covOutOfScope
mat covOutOfScope(mat X);
RcppExport SEXP sourceCpp_1_covOutOfScope(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type X(XSEXP);
    rcpp_result_gen = Rcpp::wrap(covOutOfScope(X));
    return rcpp_result_gen;
END_RCPP
}
// covInScope
mat covInScope(mat X);
RcppExport SEXP sourceCpp_1_covInScope(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< mat >::type X(XSEXP);
    rcpp_result_gen = Rcpp::wrap(covInScope(X));
    return rcpp_result_gen;
END_RCPP
}
