#!/bin/bash

gcc -c sta_array.h sta_array.c && gcc -o sta_test.elf sta_array.c && ./sta_test.elf
gcc -c dyn_array.c dyn_array.h && gcc -o dyn_test.elf dyn_array.c && ./dyn_test.elf

echo "test finished"

