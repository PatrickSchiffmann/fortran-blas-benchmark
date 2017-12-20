#include <benchmark/benchmark.h>

extern "C" {
    void daxpy_noblas(long n, double a, double* x, double* y);
    void daxpy_blas(long n, double a, double* x, double* y);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

static void daxpy_noblas(benchmark::State& state) {
    const int n = state.range(0);
    double a = 42;
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);

    for (auto _ : state)
        daxpy_noblas(n, a, x, y);

    free(x);
    free(y);
}
BENCHMARK(daxpy_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void daxpy_blas(benchmark::State& state) {
    const int n = state.range(0);
    double a = 42;
    double* x = (double*) malloc(sizeof(double)*n);
    double* y = (double*) malloc(sizeof(double)*n);


    for (auto _ : state)
        daxpy_blas(n, a, x, y);

    free(x);
    free(y);
}
BENCHMARK(daxpy_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
