../../common/apueerr.o:
	cd ../../common & make apueerr.o
set_fl.o: set_fl.c
	gcc -c set_fl.c
clr_fl.o: clr_fl.c
	gcc -c clr_fl.c
nonblock_io_demo: nonblock_io_demo.o set_fl.o clr_fl.o ../../common/apueerr.o
	gcc -o nonblock_io_demo ../../common/apueerr.o set_fl.o clr_fl.o nonblock_io_demo.o

clean:
	rm -rf *.o
	rm -rf nonblock_io_demo