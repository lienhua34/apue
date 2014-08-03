../../common/apueerr.o:
	cd ../../common & make apueerr.o
pipe_demo: pipe_demo.o ../../common/apueerr.o
	gcc -o pipe_demo pipe_demo.o ../../common/apueerr.o
pipe_2_pager: pipe_2_pager.o ../../common/apueerr.o
	gcc -o pipe_2_pager pipe_2_pager.o ../../common/apueerr.o

parent_child_sync.o: parent_child_sync.c
	gcc -c parent_child_sync.c
clean:
	rm -rf *.o
	rm -rf pipe_demo pipe_2_pager