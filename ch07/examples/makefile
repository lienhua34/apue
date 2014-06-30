../../commmon/apueerr.o:
	cd ../../commmon & make apueerr.o

atexit_demo: atexit_demo.o ../../common/apueerr.o
	gcc -o atexit_demo atexit_demo.o ../../common/apueerr.o

echoarg: echoarg.o ../../common/apueerr.o
	gcc -o echoarg echoarg.o ../../common/apueerr.o

echoenviron: echoenviron.o
	gcc -o echoenviron echoenviron.o

envdemo: envdemo.o
	gcc -o envdemo envdemo.o

setjmpdemo: setjmpdemo.o
	gcc -O -o setjmpdemo setjmpdemo.o

clean:
	rm -f *.o
	rm atexit_demo echoarg echoenviron envdemo setjmpdemo