all: libmyBank.a libmyBank.so mains maind

mains: main.o libmyBank.a
	gcc -Wall -g -o mains main.o libmyBank.a

maind: main.o
	gcc -Wall -g -o maind main.o ./libmyBank.so

libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o

libmyBank.so: myBank.o
	gcc -shared -o libmyBank.so myBank.o

myBank.o: myBank.c
	gcc -Wall -g -c myBank.c

main.o: main.c myBank.h
	gcc -Wall -g -c main.c

.PHONY: clean myBanks myBankd

mymaths: libmyBank.a

mymathd: libmyBank.so

clean:
	rm -f *.o *.a *.so mains maind
