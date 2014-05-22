../../common/apueerr.o:
	cd ../../common & make apueerr.o
pr_stdio: pr_stdio.o ../../common/apueerr.o
	gcc -o pr_stdio pr_stdio.o ../../common/apueerr.o
tempfile: tempfile.o ../../common/apueerr.o
	gcc -o tempfile tempfile.o ../../common/apueerr.o
tempnam_demo: tempnam_demo.o ../../common/apueerr.o
	gcc -o tempnam_demo tempnam_demo.o ../../common/apueerr.o

clean:
	rm -f *.o
	rm pr_stdio tempfile tempnam_demo