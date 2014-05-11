../../common/apueerr.o: 
	cd ../../common && make apueerr.o
lseek_demo: lseek_demo.o
	gcc -o lseek_demo lseek_demo.o
create_hole_file: create_hole_file.o ../../common/apueerr.o
	gcc -o create_hole_file create_hole_file.o ../../common/apueerr.o
flprinter: flprinter.o ../../common/apueerr.o
	gcc -o flprinter flprinter.o ../../common/apueerr.o

clean:
	rm *.o
	rm lseek_demo create_hole_file flprinter