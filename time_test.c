#include <stdio.h>
#include "computepi.h"

int main(int argc, char const *argv[])
{
    __attribute__((unused)) int N = 400000000;
    double pi = 0.0;

#if defined(BASELINE)
    pi = compute_pi_baseline(N);
#endif

#if defined(OPENMP)
    pi = compute_pi_openmp(N);
#endif

#if defined(AVX)
    pi = compute_pi_avx(N);
#endif

#if defined(AVXUNROLL)
    pi = compute_pi_avx_unroll(N);
#endif

#if defined(LEIBNIZ_2)
    pi = compute_pi_Leibniz_2(N);
#endif

#if defined(LEIBNIZ_2_OMP)
    pi = compute_pi_Leibniz_2_openmp(N);
#endif

#if defined(WALLIS)
    pi = compute_pi_Wallis_Product(N);
#endif

#if defined(WALLIS_OMP)
    pi = compute_pi_Wallis_Product_openmp(N);
#endif
    printf("N = %d , pi = %lf\n", N, pi);

    return 0;
}
