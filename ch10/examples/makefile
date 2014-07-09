../../common/apueerr.o: 
	cd ../../common & make apueerr.o
signaldemo: signaldemo.o ../../common/apueerr.o
	gcc -o signaldemo signaldemo.o ../../common/apueerr.o
alarmdemo: alarmdemo.o ../../common/apueerr.o
	gcc -o alarmdemo alarmdemo.o ../../common/apueerr.o
sigclddemo: sigclddemo.o ../../common/apueerr.o

clean:
	rm -f *.o
	rm -f signaldemo alarmdemo sigclddemo