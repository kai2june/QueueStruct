# QueueStruct

gcc -c Queue-adt.c Queue.h
gcc -c Queue.c Queue.h
gcc -o output Queue-adt.o Queue.o
./output

gcc -c Queue-adt.c Queue.c Queue.h
gcc -o output Queue-adt.o Queue.o
./output
