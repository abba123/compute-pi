#include <stdio.h>

double compute_pi_baseline(size_t N);
double compute_pi_openmp(size_t N);
double compute_pi_avx(size_t N);
double compute_pi_avx_unroll(size_t N);
double compute_pi_Wallis_Product(size_t N);
double compute_pi_Leibniz_2(size_t N);
double compute_pi_Leibniz_2_openmp(size_t N);
double compute_pi_Wallis_Product_openmp(size_t N);
