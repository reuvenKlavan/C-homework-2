cc=gcc
FLAG=-Wall

all: myBanklib mains

myBanklib:myBanklib.a

mains: main.o myBanklib.a
	$(cc) $(FLAG) -g -o mains main.o myBanklib.a

myBanklib.a: myBank.o
	ar rcs -o myBanklib.a myBank.o

main.o:myBank.h main.c
	$(cc) $(FLAG) -g -c -FPIC main.c

myBank.o:myBank.c
	$(cc) $(FLAG) -g -c -FPIC myBank.c

.PHONY: all clean myBanklib

clean:
	rm -f *.o *.a *.so mains
