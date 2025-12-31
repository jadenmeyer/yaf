#include "print.h"
#include "logos.h"
#include <linux/sysinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// 1024^3
#define GB_VALUE (1024 << 20)

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

static char *parse_ram(struct sysinfo *sys) {
  double used =
      ((double)(sys->totalram - sys->bufferram - sys->freeram) / GB_VALUE);
  double total = ((double)(sys->totalram) / GB_VALUE);
  printf("%.2lf\n", used);
  printf("%.2lf\n", total);
  // snprintf(NULL, 0, "%lfGB/%lfGB");
  return "eh";
}

void printer(printinfo *print) {
  parse_ram(print->system);
  printf("%s\n", pika[0]);
  printf("%s   %s\n", pika[1], print->machine->sysname);
  printf("%s   %s\n", pika[2], print->machine->release);
  printf("%s   %s + %d\n", pika[3], print->cpu->cpuname, print->cpu->cpucores);
  printf("%s   RAM: %.2ld/%ld\n", pika[4], print->system->freeram,
         print->system->totalram);
  char *uptime_string = parse_uptime(print->system);
  printf("%s   %s\n", pika[5],
         uptime_string); // print->system->uptime);
  free(uptime_string);
}

void simple_print() {}
