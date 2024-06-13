#include "header.hpp"

// [[Rcpp::export]]
int cpp_function(Rcpp::List data) {
    return parse_data(data);
}
