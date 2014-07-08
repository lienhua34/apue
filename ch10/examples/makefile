../../common/apueerr.o: 
	cd ../../common & make apueerr.o
signaldemo: signaldemo.o ../../common/apueerr.o
	gcc -o signaldemo signaldemo.o ../../common/apueerr.o

clean:
	rm -f *.o
	rm -f signaldemo