#/bin/bash

# compile with flags
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o run

# run
./run

# delete the executable file
rm run



