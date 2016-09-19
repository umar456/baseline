#include <benchmark/benchmark.h>

#include <vector>

using std::vector;

static void BaselineBenchmark(benchmark::State &state) {
  // TODO(you): Initialization code goes here
  vector<int> data(50, 0);

  while (state.KeepRunning()) {
    // TODO(you): Test code goes here
    for (auto values : data) {
      values += 42;
    }
  }

  // TODO(you): Cleanup code goes here
}

BENCHMARK(BaselineBenchmark)->Arg(10)->Arg(20);

BENCHMARK_MAIN();
