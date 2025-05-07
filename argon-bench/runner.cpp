#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <sys/resource.h>   // for getrusage
#include <sys/wait.h>       // for waitpid
#include <unistd.h>         // for fork, exec
#include <cstring>          // for strerror
#include <cstdlib>          // for system()

int main() {
    std::ofstream csv("results.csv");
    csv << "M,C,TimeSeconds,CPUSeconds,MemoryKB\n";

    std::vector<int> Ms = {6,7,8,9,10};
    std::vector<int> Cs = {1,2,3,4};

    for (int M : Ms) {
        for (int C : Cs) {
            std::string program = "./argon_bench"; // <- your new executable
            std::string M_str = std::to_string(M);
            std::string C_str = std::to_string(C);
    
            auto wallStart = std::chrono::high_resolution_clock::now();
    
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execl(program.c_str(), program.c_str(), M_str.c_str(), C_str.c_str(), (char*)NULL);
                std::cerr << "Failed to exec: " << strerror(errno) << std::endl;
                exit(1); 
            } else if (pid < 0) {
                std::cerr << "Fork failed!" << std::endl;
                continue;
            }
    
            int status;
            struct rusage usage;
    
            wait4(pid, &status, 0, &usage);
    
            auto wallEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> wallElapsed = wallEnd - wallStart;
    
            double cpuSeconds = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1e6 +
                                usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1e6;
            double memKB = usage.ru_maxrss; // ru_maxrss is already in kilobytes on macOS
    
            csv << M << "," << C << "," << wallElapsed.count() << "," << cpuSeconds << "," << memKB << "\n";
            std::cout << "Finished: N=" << M << "," << " C=" << C << "\n";
        }
    }

    csv.close();
    std::cout << "All tests complete.\n";
    return 0;
}
