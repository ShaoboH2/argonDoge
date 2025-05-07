#include <iostream>
#include <chrono>
#include <array>  
#include "argon2.h"
#include <cstring>



std::array<uint8_t, 32> HashArgon2d(const void* input, size_t len, unsigned int c, unsigned int m)
{
    uint8_t hash[32];  // Argon2d output is 32 bytes
    const char* salt = "dogecoin-argon2-salt";  // Could be any fixed or derived value



    int result = argon2d_hash_raw(
        c,             // time cost (3 passes)
        1 << m,     // memory cost in KB
        1,             // parallelism
        input, len,
        salt, strlen(salt),
        hash, sizeof(hash)
    );

    if (result != ARGON2_OK) {
        throw std::runtime_error(argon2_error_message(result));
    }

    std::array<uint8_t, 32> hash_result;
    std::copy(hash, hash + 32, hash_result.begin());
    return hash_result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: argon_bench <M>\n";
        return 1;
    }

    unsigned int m = std::stoi(argv[1]);
    unsigned int c = std::stoi(argv[2]);
    const int count = 100;

    char input[80] = {0};
    char output[32];

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; ++i) {
        auto hash = HashArgon2d(input, sizeof(input), c, m);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_elapsed = end - start;

    double avg_time = total_elapsed.count() / count;
    std::cout << avg_time << std::endl;

    return 0;
}
