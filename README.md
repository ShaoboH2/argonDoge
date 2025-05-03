# argonDoge

## New Difficulty Adjustment Algorithms

Implemented by: **Hao Lin** (haolin5)

* Added **Adaptive Difficulty** and **LWMA** algorithms, introducing a sigmoid-like adjustment function and a linearly weighted moving average, respectively, for improved responsiveness and stability.

* Updated consensus parameters and flags to support integration of these algorithms into RegTest network rules.

* Modified RegTest settings to activate Adaptive Difficulty at block height 600, and LWMA at block height 800, for testing purposes.

## Scrypt Parameterization and Benchmarking

Implemented by: **Shuban Kagini** (skagini2)

- Refactored Dogecoin’s original Scrypt implementation to support parameterization, allowing configuration of the `N`, `r`, and `p` parameters (work factor, memory cost, and parallelism).
- Replaced hardcoded constants in `scrypt.cpp` with macros, allowing flexibility for benchmarking experiments.
- Developed a standalone C++ benchmarking utility to:
  - Run Scrypt under multiple parameter settings.
  - Measure and save key performance metrics such as:
    - Execution time (wall clock)
    - CPU time
    - Memory usage

