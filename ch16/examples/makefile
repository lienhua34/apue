../../common/apueerr.o:
	cd ../../common & make apueerr.o
print_host_serv: print_host_serv.o ../../common/apueerr.o
	gcc -o print_host_serv print_host_serv.o ../../common/apueerr.o

clean:
	rm -rf *.o
	rm -rf print_host_serv
