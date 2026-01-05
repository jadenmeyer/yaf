CC = gcc
CCFLAGS = -g -Wall -Wextra

Target = yaf
SRC_DIR = src 

# SRC = $(SRC_DIR)/yaf.c $(SRC_DIR)/cpu/cpu.c $(SRC_DIR)/ram/ram.c $(SRC_DIR)/common/print.c $(SRC_DIR)/common/logos.c
SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(SRC:%.c=%.o)

all: $(Target)

$(Target) : $(OBJS)
	$(CC) $(OBJS) -o $(Target)

%.o: %.c 
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY : clean
	
clean:
	@echo cleaning
	rm $(Target) $(OBJS)
