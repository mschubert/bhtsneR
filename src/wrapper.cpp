#include <Rcpp.h>
#include "src/tsne.h"

RcppExport SEXP bh_sne(SEXP X, int no_dims=2, double perplexity=30, double theta=0.5) {
BEGIN_RCPP

    // create matrix from SEXP
    Rcpp::NumericMatrix X_r(X);
    int N = X_r.nrow();
    int D = X_r.ncol();

    // access to double array for input
    double *X_c = as<double*>(X_r);

    // create out matrix
    double Y_c[N*no_dims];

    // run TSNE
    TSNE tsne = TSNE();
    tsne.run(&X_c, N, D, &Y_c, no_dims, perplexity, theta);

    // return an R matrix
    return Rcpp::Matrix::create(Y_c)

END_RCPP
}

