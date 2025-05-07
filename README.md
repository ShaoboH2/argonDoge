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

## Argon2d Proof‑of‑Work Integration & Benchmarking  
Implemented by: **Shaobo Hu** (shaoboh2)

### 1 · Why Argon2d?
* Scrypt is CPU‑bound and ASIC‑friendly once parameters are known.  
* **Argon2d**, designed for password hashing, is deliberately **memory‑hard** and tunable

### 2 · Code‑base changes
| File | Key edits |
|------|-----------|
| `src/hash.cpp` | Added `HashArgon2d()` wrapper (calls `argon2d_hash_raw`). |
| `src/primitives/pureheader.cpp` | Re‑routed `CPureBlockHeader::GetPoWHash()` to **Argon2d** instead of Scrypt. |

### 3 · Standalone Argon2d benchmark harness
Path: `argon-bench/`

* **`argon_bench.cpp`**  
Usage: ./argon_bench <M> <C>
  M – memory‑cost exponent (2^M KiB).
      Example: M = 16 ⇒ 65 536 KiB = 64 MiB.
  C – time‑cost / number of passes.
* **`runner.cpp`**
Usage: ./runner
  ‑ Forks `argon_bench` over a grid of **M ∈ {6,7,8,9,10}** and **C ∈ {1,2,3,4}**,  
  captures wall‑time, user+sys CPU seconds and peak RSS via `wait4()`, writes
  a tidy **`results.csv`**.

