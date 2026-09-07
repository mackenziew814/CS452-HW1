# CS452-HW1

## Building & Running

In order to build and run this project you must have gcc and make installed. To compile this project, you must be one step above the directory containing Main.C, as this is where the head GNUmakefile lies. From this directory you can then run "make" to compile all the files and then call "./deq" to run the Main.C file. This is where my testing suite lies, so it will print the results to all of my tests.   

## My Experience

This project was definitely a good refresher for me on C, as it's been about a year since I've had to use this language for any large projects. This project heavily relied on pointers which took me a while to map out and test to ensure each node pointed to the correct node within the dequeue. I found that drawing physical replicas was easiest for me to understand this process. I had to complete a similar project in my CS221 class, however it was in Java, so this project was a good refresher for both the data structure and the C language.

## Valgrind Report

==12259== Memcheck, a memory error detector \
==12259== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.\
==12259== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info\
==12259== Command: ./try\
==12259== Parent PID: 1055\
==12259== \
==12259== \
==12259== HEAP SUMMARY:\
==12259==     in use at exit: 0 bytes in 0 blocks\
==12259==   total heap usage: 3 allocs, 3 frees, 1,049 bytes allocated\
==12259== \
==12259== All heap blocks were freed -- no leaks are possible\
==12259== \
==12259== For lists of detected and suppressed errors, rerun with: -s\
==12259== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) 