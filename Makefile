CC=gcc
CFLAGS=-Wall -Wextra

all: student_system

student_system: main.c
	$(CC) $(CFLAGS) -o student_system main.c

clean:
	rm -f student_system students.dat