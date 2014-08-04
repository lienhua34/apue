../../common/apueerr.o:
	cd ../../common & make apueerr.o
pipe_demo: pipe_demo.o ../../common/apueerr.o
	gcc -o pipe_demo pipe_demo.o ../../common/apueerr.o
pipe_2_pager: pipe_2_pager.o ../../common/apueerr.o
	gcc -o pipe_2_pager pipe_2_pager.o ../../common/apueerr.o

parent_child_sync.o: parent_child_sync.c
	gcc -c parent_child_sync.c

popen_2_pager: popen_2_pager.o ../../common/apueerr.o
	gcc -o popen_2_pager popen_2_pager.o ../../common/apueerr.o

filter_upchar: filter_upchar.o ../../common/apueerr.o
	gcc -o filter_upchar filter_upchar.o ../../common/apueerr.o
filter_demo: filter_demo.o ../../common/apueerr.o
	gcc -o filter_demo filter_demo.o ../../common/apueerr.o

add2: add2.o ../../common/apueerr.o
	gcc -o add2 add2.o ../../common/apueerr.o

add2_coprocess: add2_coprocess.o ../../common/apueerr.o
	gcc -o add2_coprocess add2_coprocess.o ../../common/apueerr.o

clean:
	rm -rf *.o
	rm -rf pipe_demo pipe_2_pager popen_2_pager filter_upchar filter_demo add2 add2_coprocess