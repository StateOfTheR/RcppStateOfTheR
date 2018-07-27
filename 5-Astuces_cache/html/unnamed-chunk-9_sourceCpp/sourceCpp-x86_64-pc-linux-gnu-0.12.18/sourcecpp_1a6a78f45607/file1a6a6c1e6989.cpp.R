`.sourceCpp_1_DLLInfo` <- dyn.load('/home/E69275/Documents/PhD/StateOfTheR/Rcpp/5-Astuces_cache/html/unnamed-chunk-9_sourceCpp/sourceCpp-x86_64-pc-linux-gnu-0.12.18/sourcecpp_1a6a78f45607/sourceCpp_2.so')

invProdCpp <- Rcpp:::sourceCppFunction(function(A, b) {}, FALSE, `.sourceCpp_1_DLLInfo`, 'sourceCpp_1_invProdCpp')
solveCpp <- Rcpp:::sourceCppFunction(function(A, b) {}, FALSE, `.sourceCpp_1_DLLInfo`, 'sourceCpp_1_solveCpp')

rm(`.sourceCpp_1_DLLInfo`)
