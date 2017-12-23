#include <benchmark/benchmark.h>
#include "parameters.h"

extern "C" {
    void dcopy_noblas(long n, double* x, double* y);
    void dcopy_blas(long n, double* x, double* y);
}

static void dcopy_noblas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dcopy_noblas(n, x, y);

    free(x);
    free(y);
}
BENCHMARK(dcopy_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void dcopy_blas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dcopy_blas(n, x, y);

    free(x);
    free(y);
}
BENCHMARK(dcopy_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
