CC			:= gcc
PROGNAME	:= WebAdvisorExtractor
CFLAGS		:= -std=c99 -Wall
TESTNAME	:= csv_test
OBJS		:= course_csv_writer.o

all: prog test

debug: DFLAGS += -g
debug: all

prog: $(OBJS)
	$(CC) main.c $(DFLAGS) $(OBJS) $(CFLAGS) -o $(PROGNAME)

test: DFLAGS += -g
test: $(OBJS)
	$(CC) test.c $(DFLAGS) $(OBJS) $(CFLAGS) -o $(TESTNAME) 

%.o: %.c
	$(CC) $< $(DFLAGS) $(CFLSGS) -c -o $@

clean:
	$(RM) $(PROGNAME) $(TESTNAME) $(OBJS) *.exe
