../../common/apueerr.o: 
	cd ../../common & make apueerr.o

daemonize: daemonize.o ../../common/apueerr.o
	gcc -o daemonize daemonize.o ../../common/apueerr.o

clean:
	rm -rf *.o
	rm -rf daemonize