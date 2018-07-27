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
