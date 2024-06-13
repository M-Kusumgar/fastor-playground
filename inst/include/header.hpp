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

int parse_data(Rcpp::List data) {
    SEXP array_data = data["x"];
    auto fastor = Fastor::tocolumnmajor(Fastor::TensorMap<double, 3, 2>(r_data<double>(array_data)));
    std::cout << "Fastor" << std::endl;
    Fastor::print("fastor", fastor);


    Eigen::TensorMap<Eigen::Tensor<double, 2>> eigen = Eigen::TensorMap<Eigen::Tensor<double, 2>>(r_data<double>(array_data), 3, 2);
    std::cout << "Eigen" << std::endl;
    std::cout << eigen(0, 0) << " ";
    std::cout << eigen(0, 1) << std::endl;
    std::cout << eigen(1, 0) << " ";
    std::cout << eigen(1, 1) << std::endl;
    std::cout << eigen(2, 0) << " ";
    std::cout << eigen(2, 1) << std::endl;
    return 0;
}