
factorielleR_Rec <- function(n) {
  if(n==1){
    return(1)
  } else {
    return(n*factorielleR_Rec(n-1))
  }
}

factorielleR_Loop <- function(n) {
  prod <- 1
  for (i in 1:n) {
    prod <- prod*i
  }
  prod
}
