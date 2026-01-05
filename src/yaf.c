#include <stdlib.h>
#define _GNU_SOURCE
#include "common/print.h"
// #include "ram/ram.h"
// TODO:
// refine the parser for the CPU information
// refine the printer methods

int main(int argc, char *argv[]) {
  // TODO:
  // Still want to create a custom malloc
  //

  printinfo *info = malloc(sizeof(printinfo));
  info->machine = malloc(sizeof(struct utsname));
  info->system = malloc(sizeof(struct sysinfo));
  info->cpu = malloc(sizeof(cpuinfo));
  uname(info->machine);
  sysinfo(info->system);
  getCPUInfo(info->cpu);
  if (argc > 1) {
    simple_print(info);
  } else {
    printer(info);
  }
  // readRamInfo();
  //  should obfuscate this somewhere
  free(info->cpu->cpuname);
  free(info->cpu);
  free(info->machine);
  free(info->system);
  free(info);
  return 0;
}
