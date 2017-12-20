#include <benchmark/benchmark.h>

extern "C" {
    double dnrm2_noblas(long n, double* x);
    double dnrm2_blas(long n, double* x);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

static void dnrm2_noblas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dnrm2_noblas(n, x);

    free(x);
}
BENCHMARK(dnrm2_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void dnrm2_blas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dnrm2_blas(n, x);

    free(x);
}
BENCHMARK(dnrm2_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
