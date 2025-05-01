#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

double fileTimeToSeconds(const FILETIME& ft) {
    ULARGE_INTEGER time;
    time.LowPart = ft.dwLowDateTime;
    time.HighPart = ft.dwHighDateTime;
    return time.QuadPart / 1e7; // Convert from 100-ns to seconds
}

int main() {
    std::ofstream csv("results.csv");
    csv << "N,r,TimeSeconds,CPUSeconds,MemoryKB\n";

    std::vector<int> Ns = {262144, 524288, 1048576};
    std::vector<int> Rs = {4, 8};           

    for (int N : Ns) {
        for (int r : Rs) {
            STARTUPINFO si = { sizeof(si) };
            PROCESS_INFORMATION pi;

            std::string cmd = "scrypt_bench.exe " + std::to_string(N) + " " + std::to_string(r);
            char cmdLine[256];
            strcpy(cmdLine, cmd.c_str());

            FILETIME createTime, exitTime, kernelTime, userTime;
            PROCESS_MEMORY_COUNTERS memInfo;

            auto wallStart = std::chrono::high_resolution_clock::now();
            CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
            WaitForSingleObject(pi.hProcess, INFINITE);
            auto wallEnd = std::chrono::high_resolution_clock::now();

            GetProcessTimes(pi.hProcess, &createTime, &exitTime, &kernelTime, &userTime);
            GetProcessMemoryInfo(pi.hProcess, &memInfo, sizeof(memInfo));

            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);

            std::chrono::duration<double> wallElapsed = wallEnd - wallStart;
            double cpuSeconds = fileTimeToSeconds(kernelTime) + fileTimeToSeconds(userTime);
            double memKB = memInfo.PeakWorkingSetSize / 1024.0;

            csv << N << "," << r << "," << wallElapsed.count() << "," << cpuSeconds << "," << memKB << "\n";
            std::cout << "Finished: N=" << N << ", r=" << r << "\n";
        }
    }

    csv.close();
    std::cout << "All tests complete.\n";
    return 0;
}
