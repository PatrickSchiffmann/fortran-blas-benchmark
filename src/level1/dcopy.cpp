#include <benchmark/benchmark.h>

extern "C" {
    void dcopy_noblas(long N, double* vecA, double* vecB);
    void dcopy_blas(long N, double* vecA, double* vecB);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

static void dcopy_noblas(benchmark::State& state) {
    const int N = state.range(0);
    double* vecA = (double*) malloc(sizeof(double)*N);
    double* vecB = (double*) malloc(sizeof(double)*N);

    for (auto _ : state)
        dcopy_noblas(N, vecA, vecB);

    free(vecA);
    free(vecB);
}
BENCHMARK(dcopy_noblas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);

static void dcopy_blas(benchmark::State& state) {
    const int N = state.range(0);
    double* vecA = (double*) malloc(sizeof(double)*N);
    double* vecB = (double*) malloc(sizeof(double)*N);

    for (auto _ : state)
        dcopy_blas(N, vecA, vecB);

    free(vecA);
    free(vecB);
}
BENCHMARK(dcopy_blas)->RangeMultiplier(RANGE_MULT)->Range(RANGE_MIN, RANGE_MAX);
