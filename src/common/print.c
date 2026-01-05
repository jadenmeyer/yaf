#include "print.h"
#include "logos.h"
#include <linux/sysinfo.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

// 1024^2 kb -> GB
#define GB_VALUE (1024 << 10)

static char *parse_uptime(struct sysinfo *sys) {
  int total_minutes = sys->uptime / 60;
  int mins = total_minutes % 60;

  int total_hours = total_minutes / 60;
  int hours = total_hours % 24;

  int days = total_hours / 24;

  int len = snprintf(NULL, 0, "Days: %d Hours: %d Mins: %d", days, hours, mins);
  char *uptime = malloc(len + 1);
  snprintf(uptime, len + 1, "Days: %d Hours: %d Mins: %d", days, hours, mins);
  uptime[len] = '\0';

  return uptime;
}

void printer(printinfo *print) {
  // move this to main later edit print struct

  raminfo raminfo = readRamInfo();

  printf("%s\n", pika[0]);
  printf("%s   %s\n", pika[1], print->machine->sysname);
  printf("%s   %s\n", pika[2], print->machine->release);
  printf("%s   %s + %d\n", pika[3], print->cpu->cpuname, print->cpu->cpucores);
  printf("%s   RAM: %.2lfGB/%.2lfGB\n", pika[4],
         (raminfo.totalram - raminfo.unused) / GB_VALUE,
         raminfo.totalram / GB_VALUE);
  char *uptime_string = parse_uptime(print->system);
  printf("%s   %s\n", pika[5],
         uptime_string); // print->system->uptime);
  free(uptime_string);
}

void simple_print(printinfo *print) {
  printf("%s\n", pika[0]);
  printf("%s   %s @ %s\n", pika[1], print->machine->sysname,
         print->machine->nodename);
  printf("%s   %s\n", pika[2], print->machine->machine);
  printf("%s   %s\n", pika[3], print->machine->release);
}
