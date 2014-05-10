../../common/apueerr.o: ../../common/apueerr.c
	cd ../common/ && make apueerr.o
	cd ../ch01/
myls: myls.o ../../common/apueerr.o
	gcc -o myls myls.o ../../common/apueerr.o

mycat: mycat.o ../../common/apueerr.o
	gcc -o mycat mycat.o ../../common/apueerr.o

mycat_stdio: mycat_stdio.o ../../common/apueerr.o
	gcc -o mycat_stdio mycat_stdio.o ../../common/apueerr.o

simpleshell: simpleshell.o ../../common/apueerr.o
	gcc -o simpleshell simpleshell.o ../../common/apueerr.o

error_demo: error_demo.o ../../common/apueerr.o
	gcc -o error_demo error_demo.o ../../common/apueerr.o

clean:
	rm *.o
	rm myls mycat mycat_stdio simpleshell error_demo