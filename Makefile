CC := gcc
CFLAGS := -Wall -Wextra -std=c99

# Football executable rule
football.exe: football.o football_main.o
	$(CC) $(CFLAGS) -o football.exe football.o football_main.o

# Temperature executable rule
temperature.exe: temperature.o temperature_main.o
	$(CC) $(CFLAGS) -o temperature.exe temperature.o temperature_main.o

# Object file compilation rules
football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c

football_main.o: football_main.c football.h
	$(CC) $(CFLAGS) -c football_main.c

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c

temperature_main.o: temperature_main.c temperature.h
	$(CC) $(CFLAGS) -c temperature_main.c

# Clean rule to remove all generated files
clean:
	rm -f *.o football.exe temperature.exe

# Default rule to build all executables
all: football.exe temperature.exe

.PHONY: clean all