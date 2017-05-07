CC	:= gcc
PROGNAME	:= WebAdvisorExtractor

all:
	$(CC) main.c -std=c99 -Wall -o $(PROGNAME)

clean:
	$(RM) $(PROGNAME)
