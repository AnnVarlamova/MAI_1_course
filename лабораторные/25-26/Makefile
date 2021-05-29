prog: main.o stack_int.o
	@gcc -o prog main.o stack_int.o
	@echo "Enter ./prog to launch"

main.o:
	@gcc -c main.c -o main.o

stack_int.o:
	@gcc -c stack_int.c -o stack_int.o

cleanO:
	@rm -rf *.o
cleanProg:
	@rm -rf prog
cleanAll:
	@rm -rf *.o prog