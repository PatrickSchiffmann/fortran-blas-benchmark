#include <benchmark/benchmark.h>

extern "C" {
    void dscal_noblas(long n, double a, double* x);
    void dscal_blas(long n, double a, double* x);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

static void dscal_noblas(benchmark::State& state) {
    const int n = state.range(0);
    double a = 42;
    double* x = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dscal_noblas(n, a, x);

    free(x);
}
BENCHMARK(dscal_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void dscal_blas(benchmark::State& state) {
    const int n = state.range(0);
    double a = 42;
    double* x = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        dscal_blas(n, a, x);

    free(x);
}
BENCHMARK(dscal_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
