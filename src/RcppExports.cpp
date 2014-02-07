#include <Rcpp.h>
#include "tsne.h"
using namespace Rcpp;

RcppExport SEXP bh_sne(SEXP X, int no_dims=2, double perplexity=30, double theta=0.5) {
BEGIN_RCPP
    SEXP __result; {
        // create matrix from SEXP
        NumericMatrix X_r(X);
        int N = X_r.nrow();
        int D = X_r.ncol();

        // create std vectors
        std::vector<double> X_c = as< std::vector<double> >(X_r);
        std::vector<double> Y_c(N*no_dims);

        // run TSNE
        TSNE tsne = TSNE();
        tsne.run(&X_c[0], N, D, &Y_c[0], no_dims, perplexity, theta);

        // return an R matrix
        NumericVector Y_r = wrap(Y_c);
        Y_r.attr("dim") = Dimension(N, no_dims);
        PROTECT(__result = Y_r);
    }
    UNPROTECT(1);
    return(__result);
END_RCPP
}

