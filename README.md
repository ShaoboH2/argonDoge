# argonDoge

## New Difficulty Adjustment Algorithms

Implemented by: **Hao Lin** (haolin5)

* Added **Adaptive Difficulty** and **LWMA** algorithms, introducing a sigmoid-like adjustment function and a linearly weighted moving average, respectively, for improved responsiveness and stability.

* Updated consensus parameters and flags to support integration of these algorithms into RegTest network rules.

* Modified RegTest settings to activate Adaptive Difficulty at block height 600, and LWMA at block height 800, for testing purposes.
