bhtsneR
=======

A minimal, CRAN-compliant wrapper for the Barnes-Hut implementation of [T-      distributed Stochastic Neighbor Embedding (t-SNE)](http://homepage.tudelft.nl/  19j49/t-SNE.html).

### Installation

You will need the following software:

 * [cblas](http://www.netlib.org/blas/) or [openblas](https://github.com/xianyi/OpenBLAS)
 * R packages: Rcpp, devtools

Run this in R to install the current GitHub version:

```splus
devtools::install_github("bhtsneR", username="mschubert")
```

### Running

Here is an example on how to run it on the iris data set:

```splus
library(bhtsneR)

result = bhtsne(iris[1:4])
plot(result, col=iris[[5]])
```

### More information

Barnes-Hut-SNE. (2013). L.J.P. van der Maaten. [arXiv:1301.3342](http://arxiv.  org/abs/1301.3342).

