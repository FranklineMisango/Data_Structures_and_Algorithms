CC = gcc
CFLAGS = -pedantic-errors -Wall -Werror

SOURCES = algo1.c algo2.c algo3.c
EXECS = $(SOURCES:.c=)

all: $(EXECS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECS)

.PHONY: all clean

