#include <Rcpp.h>
#include "tsne.h"
using namespace Rcpp;

RcppExport SEXP bh_sne(SEXP X, SEXP N, SEXP D, SEXP no_dims, SEXP perplexity, SEXP theta) {
BEGIN_RCPP
    SEXP __result; {
        // cast objects
        int N_c = as<int>(N);
        int D_c = as<int>(D);
        int no_dims_c = as<int>(no_dims);
        double perplexity_c = as<double>(perplexity);
//        double theta_c = as<double>(theta); // error???
        std::vector<double> X_c = as< std::vector<double> >(X);

        // create results vector
        std::vector<double> Y_c(5); //N_c*no_dims_c
Y_c[0]=N_c;
        // run TSNE
        TSNE tsne = TSNE();
//        tsne.run(&X_c[0], N_c, D_c, &Y_c[0], no_dims_c, perplexity_c, theta_c);

        // return an R matrix
        NumericVector Y_r = wrap(Y_c);
//        Y_r.attr("dim") = Dimension(N_c, no_dims_c);
        PROTECT(__result = Y_r);
    }
    UNPROTECT(1);
    return(__result);
END_RCPP
}

