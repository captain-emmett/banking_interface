all: homework3

homework3: user_interface.o database.o
	gcc -o homework3 user_interface.o database.o

user_interface.o: user_interface.c record.h database.h
	gcc -ansi -pedantic-errors -Wall -c user_interface.c

database.o: database.c record.h
	gcc -ansi -pedantic-errors -Wall -c database.c

clean:
	rm -f user_interface.o database.o homework3