CFLAGS += -Wall -Wextra
LDLIBS = -lcurses
INCLIBS = -Iinc
SH = /bin/sh

SRC_DIR = src
BUILD_DIR = out

PROJECT = cpf_plygnd

include res/help.mk

.PHONY: all clean help run targets
.SUFFIXES:
.DEFAULT: all

CFILES = $(wildcard $(SRC_DIR)/*.c)
OUT = $(PROJECT)
OBJS = $(CFILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(OUT)

$(OUT): $(OBJS)
	gcc -o $(OUT) $(OBJS)

run: all
	@./$(OUT)

help:; @ eval "$$usage"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	gcc $(CFLAGS) $(INCLIBS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

targets:
	@echo all clean help run
