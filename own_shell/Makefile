all:main
main:main.o read_lines.o parse_strings.o launch.o execute.o builtin.o
	gcc -o main.o read_lines.o parse_strings.o launch.o execute.o builtin.o

main.o:main.c
	gcc -c -o main.o main.c
 
read_lines.o:read_lines.c
	gcc -c -o read_lines.o read_lines.c
 
parse_strings.o:parse_strings.c
	gcc -c -o parse_strings.o parse_strings.c
 
launch.o:launch.c
	gcc -c -o launch.o launch.c
 
execute.o:execute.c
	gcc -c -o execute.o execute.c
 
builtin.o:builtin.c
	gcc -c -o builtin.o builtin.c

clear:

	rm -rf*.o
	rm -rf main
