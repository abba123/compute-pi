#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "computepi.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 2) return -1;

    int N = atoi(argv[1]);
    int i, loop = 25;

    // Baseline
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_baseline(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // OpenMP
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_openmp(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // AVX SIMD
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_avx(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // AVX SIMD + Loop unrolling
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_avx_unroll(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // LEIBNIZ_2
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_Leibniz_2(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // LEIBNIZ_2 with OpenMP
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_Leibniz_2_openmp(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // WALLIS
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_Wallis_Product(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // WALLIS with OpenMP
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        compute_pi_Wallis_Product_openmp(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    return 0;
}
