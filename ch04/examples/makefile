../../common/apueerr.o:
	ch ../../common && make apueerr.o
filetype: filetype.o ../../common/apueerr.o
	gcc -o filetype filetype.o ../../common/apueerr.o
accessfile: accessfile.o ../../common/apueerr.o
	gcc -o accessfile accessfile.o ../../common/apueerr.o
umaskdemo: umaskdemo.o ../../common/apueerr.o
	gcc -o umaskdemo umaskdemo.o ../../common/apueerr.o
chmoddemo: chmoddemo.o ../../common/apueerr.o
	gcc -o chmoddemo chmoddemo.o ../../common/apueerr.o

clean:
	rm *.o
	rm filetype accessfile umaskdemo chmoddemo