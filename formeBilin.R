
formeBilinR_Loop <- function(alpha, pi) {
  Q <- length(alpha)
  sum <- 0
  for(q in 1:Q){
    for (l in 1:Q) {
      sum <- sum + alpha[q]*alpha[l]*pi[q,l]
    }
  }
  sum
}
formeBilinR_Prod <- function(alpha, pi) {
  sum <- t(alpha) %*% pi %*% alpha
  sum
}
