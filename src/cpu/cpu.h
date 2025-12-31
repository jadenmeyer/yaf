#define PROC_BUFFER (32 * 1024)
// if adding things later make this buffer in a common util file

typedef struct cpuinfo {
  char *cpuname;
  int cpucores; // wont do threads here yet
} cpuinfo;

char *getCPUName(cpuinfo *cpu);
int getCPUCores(cpuinfo *cpu);
int getCPUInfo(cpuinfo *cpu);
