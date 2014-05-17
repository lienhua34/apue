../../common/apueerr.o:
	cd ../../common && make apueerr.o
../../common/pathalloc.o:
	cd ../../common && make pathalloc.o
filetype: filetype.o ../../common/apueerr.o
	gcc -o filetype filetype.o ../../common/apueerr.o
accessfile: accessfile.o ../../common/apueerr.o
	gcc -o accessfile accessfile.o ../../common/apueerr.o
umaskdemo: umaskdemo.o ../../common/apueerr.o
	gcc -o umaskdemo umaskdemo.o ../../common/apueerr.o
chmoddemo: chmoddemo.o ../../common/apueerr.o
	gcc -o chmoddemo chmoddemo.o ../../common/apueerr.o
unlink: unlink.o ../../common/apueerr.o
	gcc -o unlink unlink.o ../../common/apueerr.o
utimedemo: utimedemo.o ../../common/apueerr.o
	gcc -o utimedemo utimedemo.o ../../common/apueerr.o
getcwd_demo: getcwd_demo.o ../../common/apueerr.o ../../common/pathalloc.o
	gcc -o getcwd_demo getcwd_demo.o ../../common/apueerr.o ../../common/pathalloc.o
st_dev_demo: st_dev_demo.o ../../common/apueerr.o
	gcc -o st_dev_demo st_dev_demo.o ../../common/apueerr.o
myftw: myftw.o ../../common/apueerr.o ../../common/pathalloc.o
	gcc -o myftw myftw.o ../../common/apueerr.o ../../common/pathalloc.o

clean:
	rm *.o
	rm filetype accessfile umaskdemo chmoddemo unlink utimedemo getcwd_demo st_dev_demo myftw