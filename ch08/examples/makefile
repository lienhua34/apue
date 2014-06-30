../../common/apueerr.o: ../../common/apueerr.c
	cd ../../common & make apueerr.o

forkdemo: forkdemo.o ../../common/apueerr.o
	gcc -o forkdemo forkdemo.o ../../common/apueerr.o

clean:
	rm -f *.o
	rm -f forkdemo