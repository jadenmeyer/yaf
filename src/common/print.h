#ifndef PRINT
#define PRINT
#include "../cpu/cpu.h"
#include "../ram/ram.h"
#include <sys/sysinfo.h>
#include <sys/utsname.h>
typedef struct printinfo {
  cpuinfo *cpu; // typedefined
  struct utsname *machine;
  struct sysinfo *system;
} printinfo;

void printer(printinfo *print);
void simple_print(printinfo *print);

#endif // !PRINT
