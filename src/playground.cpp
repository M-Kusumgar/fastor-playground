#include "header.hpp"

// [[Rcpp::export]]
int cpp_function(const Rcpp::List data) {
    static constexpr int dim1 = 3;
    static constexpr int dim2 = 2;
    parse_data<double, dim1, dim2>(data, "x");
    return 0;
}
