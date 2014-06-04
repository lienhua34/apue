../../commmon/apueerr.o:
	cd ../../commmon & make apueerr.o

atexit_demo: atexit_demo.o ../../common/apueerr.o
	gcc -o atexit_demo atexit_demo.o ../../common/apueerr.o

echoarg: echoarg.o ../../common/apueerr.o
	gcc -o echoarg echoarg.o ../../common/apueerr.o

echoenviron: echoenviron.o
	gcc -o echoenviron echoenviron.o

clean:
	rm -f *.o
	rm atexit_demo echoarg echoenviron