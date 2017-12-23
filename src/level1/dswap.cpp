#include <benchmark/benchmark.h>

extern "C" {
    void dswap_noblas(long n, double* x, double* y);
    void dswap_blas(long n, double* x, double* y);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

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
