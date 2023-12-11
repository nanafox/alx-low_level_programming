#!/bin/bash

# This script creates dynamic library with all C source files in the directory
# it is executed in

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -shared \
	-Wl,-soname,liball.so -o liball.so *.c
