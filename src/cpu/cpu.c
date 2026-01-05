#include "cpu.h"
#include <fcntl.h> //get open function
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for read
#define CPUINFO_PATH "/proc/cpuinfo"

// return a file descriptor
static int readFile(cpuinfo *cpu) {
  int fd = open(CPUINFO_PATH, O_RDONLY); // readonly look
  char buffer[PROC_BUFFER];
  size_t bytes_read = read(fd, buffer, PROC_BUFFER);
  buffer[bytes_read] = '0';
  char *first_half =
      strstr(buffer, "model name"); // only for some CPU architectures for now
  first_half = strstr(first_half, ": ");
  first_half += 2; // inline with full cpu name now

  int length = 0;
  // TODO: Make this better
  // loop just for counting
  for (; first_half[length] != '\n'; length++) {
  }

  cpu->cpuname = malloc(length + 1);
  memcpy(cpu->cpuname, first_half, length);
  cpu->cpuname[length] = '\0';

  first_half = strstr(buffer, "cores");
  first_half = strstr(first_half, ": ");
  first_half += 2; // move ptr 2 spots
  char *end;
  cpu->cpucores = (int)strtol(first_half, &end, 10);
  close(fd); // currently unsafe no check for fd being readable

  return 0;
}

char *getCPUName(cpuinfo *cpu) { return cpu->cpuname; }

int getCPUCores(cpuinfo *cpu) { return cpu->cpucores; }

int getCPUInfo(cpuinfo *cpu) { return readFile(cpu); }
