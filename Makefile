CFLAGS = -Wall -pedantic
OBJS = main.o list.o date.o user.o file.o utils.o
TESTOBJS = datetest.o listtest.o filetest.o

# ----------------------
# OS dependent makros
# ----------------------
ifeq ($(OS), Windows_NT)
RM = del
BINS = main.exe
TESTBINS = datetest.exe listtest.exe
else
RM = rm -rf
BINS = main
TESTBINS = datetest listtest
endif


all: main datetest listtest

clean:
	$(RM) $(OBJS) $(TESTOBJS) $(BINS) $(TESTBINS)

# ----------------------
# Rules for the app
# ----------------------
main.o: main.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c main.c 

list.o: list.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c list.c

date.o: date.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c date.c 

user.o: user.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c user.c 

file.o: file.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c file.c 

utils.o: utils.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c utils.c 

main: main.o list.o date.o user.o file.o utils.o
	gcc $(CFLAGS) main.o list.o date.o user.o file.o utils.o -o main

# ----------------------
# Rules for unit testing
# ----------------------
datetest.o: tests/datetest.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c tests/datetest.c

listtest.o: tests/listtest.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c tests/listtest.c date.c list.c file.c utils.c user.c

filetest.o: tests/filetest.c headers/list.h headers/date.h headers/file.h headers/utils.h headers/user.h
	gcc $(CFLAGS) -c tests/filetest.c 

filetest: filetest.o date.o
	gcc $(CFLAGS) file.o filetest.o -o filetest

datetest: datetest.o date.o
	gcc $(CFLAGS) date.o datetest.o -o datetest

listtest: listtest.o list.o date.o
	gcc $(CFLAGS) listtest.o -o listtest

runtest: $(TESTBINS)
	./datetest
	./filetest
	./listtest

# ----------------------------
# Implicit rule for future use
# ----------------------------
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@