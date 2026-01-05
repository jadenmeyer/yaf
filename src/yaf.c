#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#include "common/print.h"
// TODO:
// refine the parser for the CPU information

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
  if (argc > 1) {
    if (strcmp(argv[1], "h")) {
      printf(
          "There are two modes: \n simple_print: add any arguments to ./yaf "
          "and you get small pika \n full_print which is full information\n");
    } else {
      simple_print(info);
    }
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
