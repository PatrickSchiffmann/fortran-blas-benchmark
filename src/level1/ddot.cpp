#include <benchmark/benchmark.h>

extern "C" {
    double ddot_noblas(long n, double* x, double* y);
    double ddot_blas(long n, double* x, double* y);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

static void ddot_noblas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        ddot_noblas(n, x, y);

    free(x);
    free(y);
}
BENCHMARK(ddot_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void ddot_blas(benchmark::State& state) {
    const int n = state.range(0);
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        ddot_blas(n, x, y);

    free(x);
    free(y);
}
BENCHMARK(ddot_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
