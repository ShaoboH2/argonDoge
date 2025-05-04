# argonDoge

## New Difficulty Adjustment Algorithms

Implemented by: **Hao Lin** (haolin5)

* **Implemented 2 advanced difficulty adjustment algorithms**  
    - Dogecoin’s original DigiShield v3 suffers from slow responsiveness to hashrate fluctuations. To address this, I used an **adaptive difficulty algorithm**. On top of that, I further improve responsiveness and smoothness by using **LWMA (Linearly Weighted Moving Average)** as a better solution.

* **Conducted controlled experiment for the new algorithms**  
    - The experiment is conducted in the `regtest` environment with a `Target_Pow_Timespan = 10 seconds`. The experiment emulates sudden increases and decreases in hashrate by varying the delay between block generations.

* **Experiment Procedure**  
    - For each block, record the block height, on-chain timestamp, and difficulty.  
    - Repeat for a total of 40 blocks under the above mining delay pattern.  
    - Difficulty changes are measured and plotted to observe how each algorithm reacts to hashrate dynamics.

* **Deliveries and Output**  
    - Main algorithm implementation at [src/dogecoin.cpp](./src/dogecoin.cpp).
    - Experiment scripts and output at [difficulty-bench](./difficulty-bench/).  

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

