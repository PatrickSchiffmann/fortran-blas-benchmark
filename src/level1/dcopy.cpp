#include <benchmark/benchmark.h>

extern "C" {
    void dcopy_noblas(long N, double* vecA, double* vecB);
    void dcopy_blas(long N, double* vecA, double* vecB);
}

#define RANGE_MIN 4
#define RANGE_MAX 65536
#define RANGE_MULT 4

static void Fortran(benchmark::State& state) {
    const int N = state.range(0);
    double* vecA = (double*) malloc(sizeof(double)*N);
    double* vecB = (double*) malloc(sizeof(double)*N);

    for (auto _ : state)
        bench_1_run(N, vecA, vecB);

    free(vecB);
    free(vecA);
}
BENCHMARK(Fortran)->RangeMultiplier(4)->Range(4, 65536);

static void FortranBLAS(benchmark::State& state) {
    const int N = state.range(0);
    double* vecA = (double*) malloc(sizeof(double)*N);
    double* vecB = (double*) malloc(sizeof(double)*N);

    for (auto _ : state)
        bench_2_run(N, vecA, vecB);

    free(vecB);
    free(vecA);
}
BENCHMARK(FortranBLAS)->RangeMultiplier(4)->Range(4, 65536);

BENCHMARK_MAIN();
