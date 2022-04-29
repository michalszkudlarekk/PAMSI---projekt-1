__start__: program
	./program

program: priorityqueue.o
	g++ -o program priorityqueue.o

main.o: priorityqueue.cpp priorityqueue.hh
	g++ -c -o priorityqueue.o priorityqueue.cpp

clean:
	rm -f *.o program	