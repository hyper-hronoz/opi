#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>


using namespace std;

int main(int argc, char *argv[]){
    long clocksPerSecond = sysconf(_SC_CLK_TCK);
    long clocks;
    struct tms start, end;

    auto chronoTimeStart = chrono::high_resolution_clock::now();
    time_t timeTimeStart;
    ctime(&timeTimeStart);  

    clock_t clockTimeStart = clock();

    double cpu_Hz = 3200000000ULL;
    union ticks{
        unsigned long long t64;
        struct s32 { long th, ts; } t32;
    } startTicks, endTicks;

    asm("rdtsc\n":"=a"(startTicks.t32.th),"=d"(startTicks.t32.ts));

    if(argc != 3){
        cout << "N parameter is required!" << endl;
        cout << argc;
        return 0;
    }

    int n{};
    float x{};
    sscanf(argv[1], "%g", &x);
    sscanf(argv[2], "%i", &n);
    cout << "X: " << x << " N: " << n << endl;
    float result{}; 

    for(int i = 1; i <= n; i++){
        result += pow(-1, i + 1) * pow(x, i) / i;
    }  
    cout << result << endl;

    asm("rdtsc\n":"=a"(endTicks.t32.ts));

    auto chronoTimeEnd = chrono::high_resolution_clock::now();
    time_t timeTimeEnd;
    ctime(&timeTimeEnd);
    clock_t clockTimeEnd = clock();
    clocks = end.tms_utime - start.tms_utime;
    double procTime = (double)clocks / CLOCKS_PER_SEC; 
    chrono::duration<double> chronoDiff = chronoTimeEnd - chronoTimeStart;

    cout << "chrono: " << 
    chronoDiff.count()
     << endl;

    cout << "procTicks: " << (endTicks.t64-startTicks.t64)/cpu_Hz << endl;
    cout << "time: " << difftime(timeTimeStart, timeTimeEnd) << endl;
    cout << "clock: " << clockTimeEnd - clockTimeStart << endl;
    cout << "sysTime: " << procTime << endl;

    return 0;
}
