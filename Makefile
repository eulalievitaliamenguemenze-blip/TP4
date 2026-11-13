CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -g
all: test_tp4 motcompte
test_tp4: abr.c hash.c test_tp4.c
$(CC) $(CFLAGS) abr.c hash.c test_tp4.c -o test_tp4
motcompte: hash.c motcompte.c
$(CC) $(CFLAGS) hash.c motcompte.c -o motcompte
