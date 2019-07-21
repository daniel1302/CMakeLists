#include <benchmark/benchmark.h>
#include "squareRoot.cpp"

static void BM_SquareRoot(benchmark::State& state) {
    double i = 0;
    for (auto _ : state) {
        benchmark::DoNotOptimize(i += 0.01);
        benchmark::DoNotOptimize(squareRoot(i));
    }
}
// Register the function as a benchmark
BENCHMARK(BM_SquareRoot);
// Run the benchmark
BENCHMARK_MAIN();