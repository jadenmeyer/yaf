#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
// #include <string.h>
#include "cpu/cpu.h"
#include <sys/sysinfo.h>
#include <sys/utsname.h>

// TODO:
// create a new file that parses the CPU information
// create a new file to print out a picture
// create a new file to get GPU information

struct photo {
  char *cols[8];
};
/*
*
*
*

▕▔╲┊┊┊┊┊┊┊┊┊╱▔▏
┊╲┈╲╱▔▔▔▔▔╲╱┈╱
┊┊╲┈╭╮┈┈┈╭╮┈╱┊
┊┊╱┈╰╯┈▂┈╰╯┈╲┊
┊┊▏╭╮▕━┻━▏╭╮▕┊
┊┊╲╰╯┈╲▂╱┈╰╯╱┊
*
*
*/
static struct photo p = {
    .cols[1] = "▔╲         ╱▔",
    .cols[2] = "╲┈╲╱▔▔▔▔▔╲╱┈╱",
    .cols[3] = " ╲┈╭╮┈┈┈╭╮┈╱",
    .cols[4] = " ╱┈╰╯┈▂┈╰╯┈╲",
    .cols[5] = " ▏╭╮▕━┻━▏╭╮▕",
    .cols[6] = " ╲╰╯┈╲▂╱┈╰╯╱",
    .cols[7] = " ",
    .cols[0] = " ",
};
/*
 *
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

// print out the time very ugly should change soon
void parse_uptime(long value) {

  int days = value / 86400; // days
  int hours = value / 3600; // hours
  if (days > 0) {
    hours -= days * 24;
  }
  printf("%d d %d h\n", days, hours);
}

int main(int argc, char *argv[]) {

  // add documentations soon here
  // eventually some custom stuff
  if (argc > 0 && argc < 2) {
    printf("var = %d\n", 3);
  }

  // static in case i decide to expand out
  static struct utsname info;
  static struct sysinfo system;

  uname(&info); // fill info struct
  sysinfo(&system);

  cpuinfo *cpu = malloc(sizeof(cpuinfo));
  getCPUInfo(cpu);

  // want this to be a double value
  printf("%ld/%ld %s\n", system.freeram / 1000000000,
         system.totalram / 1000000000, "RAM");
  // get the uptime
  // printf("%ld\n", system.uptime);
  parse_uptime(system.uptime);
  // get this to work maybe through /proc
  printf("%s\n", info.sysname);
  printf("%s CPU:", cpu->cpuname);
  printf("CPU Cores: %d\n", cpu->cpucores);
  // get the kernel version
  printf("%s\n", info.release);

  // print the fun picture
  for (int i = 0; i < 8; i++) {
    printf("%s\n", p.cols[i]);
  }
  free(cpu->cpuname);
  free(cpu);
  return 0;
}
