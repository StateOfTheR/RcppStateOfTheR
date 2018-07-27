#include "RcppArmadillo.h" 
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
void printMatrix(arma::mat X) {
  X.print();
}
// [[Rcpp::export]]
void showMatrix(arma::mat X) {
  Rcpp::Rcout << "Armadillo matrix is" << std::endl << X << std::endl;
}


#include <Rcpp.h>
// printMatrix
void printMatrix(arma::mat X);
RcppExport SEXP sourceCpp_1_printMatrix(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    printMatrix(X);
    return R_NilValue;
END_RCPP
}
// showMatrix
void showMatrix(arma::mat X);
RcppExport SEXP sourceCpp_1_showMatrix(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    showMatrix(X);
    return R_NilValue;
END_RCPP
}
