../../common/apueerr.o:
	cd ../../common & make apueerr.o
set_fl.o: set_fl.c
	gcc -c set_fl.c
clr_fl.o: clr_fl.c
	gcc -c clr_fl.c
nonblock_io_demo: nonblock_io_demo.o set_fl.o clr_fl.o ../../common/apueerr.o
	gcc -o nonblock_io_demo ../../common/apueerr.o set_fl.o clr_fl.o nonblock_io_demo.o

lock_reg.o:lock_reg.c
	gcc -c lock_reg.c
lock_test.o:lock_test.c
	gcc -c lock_test.c
lockfile.o:lockfile.c
	gcc -c lockfile.c

deadlock_demo: deadlock_demo.o lock_reg.o lock_test.o ../../common/apueerr.o ../../ch10/examples/parent_child_comm_demo.o
	gcc -o deadlock_demo ../../common/apueerr.o ../../ch10/examples/parent_child_comm_demo.o lock_test.o lock_reg.o deadlock_demo.o

isastream_demo: isastream_demo.o ../../common/apueerr.o
	gcc -o isastream_demo ../../common/apueerr.o isastream_demo.o

ilist_demo: ilist_demo.o ../../common/apueerr.o
	gcc -o ilist_demo ../../common/apueerr.o ilist_demo.o

getmsg_demo: getmsg_demo.o ../../common/apueerr.o
	gcc -o getmsg_demo getmsg_demo.o ../../common/apueerr.o

readn_writen.o: readn_writen.c
	gcc -c readn_writen.c

mmap_demo: mmap_demo.o ../../common/apueerr.o
	gcc -o mmap_demo ../../common/apueerr.o mmap_demo.o

clean:
	rm -rf *.o
	rm -rf nonblock_io_demo deadlock_demo isastream_demo ilist_demo getmsg_demo mmap_demo