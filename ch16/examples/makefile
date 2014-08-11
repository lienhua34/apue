../../common/apueerr.o:
	cd ../../common & make apueerr.o
print_host_serv: print_host_serv.o ../../common/apueerr.o
	gcc -o print_host_serv print_host_serv.o ../../common/apueerr.o

connect_retry.o: connect_retry.c
	gcc -c connect_retry.c

initserver.o: initserver.c
	gcc -c initserver.c

clean:
	rm -rf *.o
	rm -rf print_host_serv
