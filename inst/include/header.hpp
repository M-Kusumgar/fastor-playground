#include <iostream>
#include <Rcpp.h>
#include <Fastor/Fastor.h>
#include <unsupported/Eigen/CXX11/Tensor>

template <typename T>
T* r_data(SEXP x) {
  static_assert(sizeof(T) == 0, "Only specializations of r_data can be used");
}

template <>
double* r_data(SEXP x) {
  return REAL(x);
}

template <>
int * r_data(SEXP x) {
  return INTEGER(x);
}

template<typename T, int ...Dims>
auto parse_data(const Rcpp::List data, const std::string& key) {
    SEXP array_data = data[key];
    auto fastor = Fastor::tocolumnmajor(Fastor::TensorMap<T, Dims...>(r_data<T>(array_data)));
    Fastor::print("Fastor", fastor);
}