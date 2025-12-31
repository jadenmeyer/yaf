#include <linux/sysinfo.h>
#include <stdlib.h>
#define _GNU_SOURCE
// #include <stdio.h>
//  #include <string.h>
#include "common/print.h"
// #include "cpu/cpu.h"
// #include <sys/sysinfo.h>
// #include <sys/utsname.h>

// TODO:
// refine the parser for the CPU information
// refine the printer methods
// create a new file to get GPU information???

/*
in case i decide to do gentoo logo again
static struct photo p = {.cols[0] = " _-----_",
                         .cols[1] = "(       \\",
                         .cols[2] = "\\    0   \\",
                         .cols[3] = " \\        )",
                         .cols[4] = " /      _/",
                         .cols[5] = "(     _-",
                         .cols[6] = "\\____-",
                         .cols[7] = " "};
*/

int main(int argc, char *argv[]) {
  // TODO:
  // Still want to create a custom malloc
  printinfo *info = malloc(sizeof(printinfo));
  info->machine = malloc(sizeof(struct utsname));
  info->system = malloc(sizeof(struct sysinfo));
  info->cpu = malloc(sizeof(cpuinfo));
  uname(info->machine);
  sysinfo(info->system);
  getCPUInfo(info->cpu);

  printer(info);

  // should obfuscate this somewhere
  free(info->cpu->cpuname);
  free(info->cpu);
  free(info->machine);
  free(info->system);
  free(info);
  return 0;
}
