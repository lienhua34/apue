../../common/apueerr.o: 
	cd ../../common & make apueerr.o

daemonize: daemonize.o ../../common/apueerr.o
	gcc -o daemonize daemonize.o ../../common/apueerr.o

already_running.o: already_running.c
	gcc -c already_running.c

clean:
	rm -rf *.o
	rm -rf daemonize