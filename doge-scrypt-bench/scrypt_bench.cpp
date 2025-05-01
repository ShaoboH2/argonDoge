#include <iostream>
#include <chrono>
#include "scrypt.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: scrypt_bench <N> <r>\n";
        return 1;
    }

    unsigned int N = std::stoi(argv[1]);
    unsigned int r = std::stoi(argv[2]);
    const int count = 100;

    char input[80] = {0};
    char output[32];

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; ++i) {
        scrypt_N_R_1_256(input, output, N, r);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_elapsed = end - start;

    double avg_time = total_elapsed.count() / count;
    std::cout << avg_time << std::endl;

    return 0;
}
