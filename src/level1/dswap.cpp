#include <benchmark/benchmark.h>
#include "parameters.h"

extern "C" {
    void dswap_noblas(long n, double* x, double* y);
    void dswap_blas(long n, double* x, double* y);
}

static void dswap_noblas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dswap_noblas(n, x, y);

    free(x);
    free(y);
}
BENCHMARK(dswap_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void dswap_blas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dswap_blas(n, x, y);

    free(x);
    free(y);
}
BENCHMARK(dswap_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
