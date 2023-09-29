#!/bin/bash
# generate object files
gcc -Wall -pedantic -Wextra -Werror -std=gnu89 -c *.c
# creates the static libary
ar rc liball.a *.o
# index library
ranlib liball.a
