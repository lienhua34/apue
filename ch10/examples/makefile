../../common/apueerr.o: 
	cd ../../common & make apueerr.o
signaldemo: signaldemo.o ../../common/apueerr.o
	gcc -o signaldemo signaldemo.o ../../common/apueerr.o
alarmdemo: alarmdemo.o ../../common/apueerr.o
	gcc -o alarmdemo alarmdemo.o ../../common/apueerr.o
sigclddemo: sigclddemo.o ../../common/apueerr.o
	gcc -o sigclddemo sigclddemo.o ../../common/apueerr.o
readWithOvertime: readWithOvertime.o ../../common/apueerr.o
	gcc -o readWithOvertime readWithOvertime.o ../../common/apueerr.o
readWithLongjmp: readWithLongjmp.o ../../common/apueerr.o
	gcc -o readWithLongjmp readWithLongjmp.o ../../common/apueerr.o
pr_mask.o: pr_mask.c
	gcc -c pr_mask.c
mysignal.o: mysignal.c
	gcc -c mysignal.c
sigprocmaskdemo: sigprocmaskdemo.o ../../common/apueerr.o
	gcc -o sigprocmaskdemo sigprocmaskdemo.o ../../common/apueerr.o
sigjmpdemo: sigjmpdemo.o  pr_mask.o ../../common/apueerr.o
	gcc -o sigjmpdemo  sigjmpdemo.o  pr_mask.o ../../common/apueerr.o
sigsuspenddemo: sigsuspenddemo.o pr_mask.o ../../common/apueerr.o
	gcc -o sigsuspenddemo sigsuspenddemo.o pr_mask.o ../../common/apueerr.o
sigsuspenddemo1: sigsuspenddemo1.o ../../common/apueerr.o
	gcc -o sigsuspenddemo1 sigsuspenddemo1.o ../../common/apueerr.o

abortdemo: abortdemo.c
	gcc -o abortdemo abortdemo.c

clean:
	rm -f *.o
	rm -f signaldemo alarmdemo sigclddemo readWithOvertime readWithLongjmp sigprocmaskdemo sigjmpdemo sigsuspenddemo sigsuspenddemo1 abortdemo