#include "ram.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

raminfo readRamInfo() {
  raminfo raminfo;

  int fd = open(RAM_PATH, O_RDONLY);

  char buffer[RAM_BUFFER];
  size_t bytes_read = read(fd, buffer, RAM_BUFFER);

  if (bytes_read < 1) {
  }
  buffer[bytes_read] = '\0';

  // parse total ram
  char *total = strstr(buffer, "MemTotal:");
  total += 9;
  sscanf(total, "%lf", &raminfo.totalram);

  // parse memoryavailable
  char *avail = strstr(buffer, "MemAvailable:");
  avail += 13; // move to end of MemAvailable word

  sscanf(avail, "%lf", &raminfo.unused);

  return raminfo;
}
