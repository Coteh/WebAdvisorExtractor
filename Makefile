CC				:= gcc
PROGNAME		:= WebAdvisorExtractor
CFLAGS			:= -std=c99 -Wall
TESTNAME		:= run_tests
PRINTTESTNAME 	:= csv_print_test
OBJS			:= course_csv_writer.o

all: prog test

debug: DFLAGS = -g
debug: all

prog: $(OBJS)
	$(CC) main.c $(DFLAGS) $(OBJS) $(CFLAGS) -o $(PROGNAME)

test: DFLAGS = -g
test: $(OBJS)
	$(CC) test.c $(DFLAGS) $(OBJS) $(CFLAGS) -o $(TESTNAME)

print-test: DFLAGS = -g
print-test: $(OBJS)
	$(CC) print_test.c $(DFLAGS) $(OBJS) $(CFLAGS) -o $(PRINTTESTNAME)

%.o: %.c
	$(CC) $< $(DFLAGS) $(CFLSGS) -c -o $@

clean:
	$(RM) $(PROGNAME) $(TESTNAME) $(OBJS) *.exe
