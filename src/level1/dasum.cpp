#include <benchmark/benchmark.h>
#include "parameters.h"

extern "C" {
    double dasum_noblas(long N, double* vecA);
    double dasum_blas(long N, double* vecA);
}

static void dasum_noblas(benchmark::State& state) {
    const int N = state.range(0);
    double* vecA = (double*) malloc(sizeof(double)*N);

    for (auto _ : state)
        dasum_noblas(N, vecA);

    free(vecA);
}
BENCHMARK(dasum_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void dasum_blas(benchmark::State& state) {
    const int N = state.range(0);
    double* vecA = (double*) malloc(sizeof(double)*N);

    for (auto _ : state)
        dasum_blas(N, vecA);

    free(vecA);
}
BENCHMARK(dasum_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
