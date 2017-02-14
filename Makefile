# Name: Sarah Depew

all: check_mat main

check_mat: matrix.o check_mat.o
	gcc -o check_mat matrix.o check_mat.o -lcheck

main: main.o 
	gcc -o main main.o 
	
matrix.o: matrix.c matrix.h
	gcc -c matrix.c

check_mat.o: check_mat.c matrix.h
	gcc -c check_mat.c
	
main.o: main.c matrix.h
	gcc -c main.c