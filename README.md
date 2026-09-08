# CS452-HW1

## Project Description

This project is a generic double-ended queue, named deque, that's implemented as a doubly-linked list in C. The deque supports inserting, removing, and inspecting elements from either end, the head or the tail.


## Building & Running

In order to build and run this project you must have gcc and make installed. To compile this project, you must be one step above the directory containing Main.C, as this is where the head GNUmakefile lies. From this directory you can then run "make" to compile all the files and then call "./deq" to run the Main.C file. This is where my testing suite lies, so it will print the results to all of my tests. To make the valgrind report simply use the command "make valgrind."

## My Experience

This project was definitely a good refresher for me on C, as it's been about a year since I've had to use this language for any large projects. This project heavily relied on pointers which took me a while to map out and test to ensure each node pointed to the correct node within the dequeue. I found that drawing physical replicas was easiest for me to understand this process. I had to complete a similar project in my CS221 class, however it was in Java, so this project was a good refresher for both the data structure and the C language. I created my test suite within the main.c file with non-automated tests. Instead I printed what each test expects for results before printing the actual results. There are no memory leaks or issues currently known within my code.

## Valgrind Report

valgrind --leak-check=full --show-leak-kinds=all ./deq\
==17458== Memcheck, a memory error detector\
==17458== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.\
==17458== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info \
==17458== Command: ./deq \
==17458== \
=====Empty Dequeue===== \
Expected: \
Queue: \
Queue Length: 0 \
\
=====Test Head Put===== \
Expected: c b a \
Queue: c b a \
Queue Length: 3 \
 \
=====Test Tail Put===== \
Expected: a b c \
Queue: a b c \
Queue Length: 3 \
\
=====Test Get on 1 Element Queue===== \
Head get: only \
Queue Length: 0 \
\
=====Test Head & Tail Put===== \
Expected: d b a c \
Queue: d b a c \
Queue Length: 4 \
\
=====Test Head & Tail Ith===== \
Queue: a b c d \
Head_ith(0): a \
Head_ith(4): d \
Tail_ith(0): d \
Tail_ith(4): a \
Queue Length: 4 \
\
=====Test Head & Tail Get===== \
Queue: a b c d \
Get Head: a \
Get Tail: d \
Queue: b c \
Queue Length: 2 \
\
=====Test Head & Tail Rem===== \
Queue: a b c d \
Expected Rem Middle: b \
Actual: b \
\
Expected Rem Head: a \
Actual: a \
\
Expected Rem Tail: d \
Actual: d \
\
Expected Queue: c \
Queue: c \
Queue Length: 1 \
\
=====Rem on One Element Queue===== \
Rem only: only \
Length: 0 \
 \
=====Test Edge Cases===== \
Get on Empty \
Expected: (nil) \
Actual: (nil) \
\
Len on Empty \
Expected: 0 \
Actual: 0 \
\
Negative Ith \
Expected: (nil) \
Actual: (nil) \
\
Out of Range Ith \
Expected: (nil) \
Actual: (nil) \
\
Rem Empty Queue \
Expected: (nil) \
Actual: (nil) \
\
Check Length \
Expected: 1 \
Actual: 1 \
==17458== \
==17458== HEAP SUMMARY: \
==17458==     in use at exit: 0 bytes in 0 blocks \
==17458==   total heap usage: 70 allocs, 70 frees, 1,985 bytes allocated \
==17458== \
==17458== All heap blocks were freed -- no leaks are possible \
==17458==  \
==17458== For lists of detected and suppressed errors, rerun with: -s \
==17458== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) 