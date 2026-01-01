#ifndef RAM
#define RAM

#define RAM_BUFFER 1024 * 32

#define RAM_PATH "/proc/meminfo"

typedef struct raminfo {
  double unused;
  double totalram;
} raminfo;

raminfo readRamInfo();

#endif // !RAM
