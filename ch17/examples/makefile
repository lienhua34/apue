../../common/apueerr.o:
	cd ../../commmon & make apueerr.o

sockun_demo: sockun_demo.o ../../common/apueerr.o
	gcc -o sockun_demo sockun_demo.o ../../common/apueerr.o

serv_listen.o: serv_listen.c
	gcc -c serv_listen.c

clean:
	rm -rf *.o
	rm -rf sockun_demo