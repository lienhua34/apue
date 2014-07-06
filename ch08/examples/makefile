../../common/apueerr.o: ../../common/apueerr.c
	cd ../../common & make apueerr.o

forkdemo: forkdemo.o ../../common/apueerr.o
	gcc -o forkdemo forkdemo.o ../../common/apueerr.o

vforkdemo: vforkdemo.o ../../common/apueerr.o
	gcc -o vforkdemo vforkdemo.o ../../common/apueerr.o

waitdemo: waitdemo.o ../../common/apueerr.o
	gcc -o waitdemo waitdemo.o ../../common/apueerr.o

waitpiddemo: waitpiddemo.o ../../common/apueerr.o
	gcc -o waitpiddemo waitpiddemo.o ../../common/apueerr.o

racecond_demo: racecond_demo.o ../../common/apueerr.o
	gcc -o racecond_demo racecond_demo.o ../../common/apueerr.o

execdemo: execdemo.o ../../common/apueerr.o
	gcc -o execdemo execdemo.o ../../common/apueerr.o

echoall: echoall.o ../../common/apueerr.o
	gcc -o echoall echoall.o ../../common/apueerr.o

execinterp: execinterp.o ../../common/apueerr.o
	gcc -o execinterp execinterp.o ../../common/apueerr.o

systemdemo: systemdemo.o ../../common/apueerr.o
	gcc -o systemdemo systemdemo.o ../../common/apueerr.o

tsys: tsys.o ../../common/apueerr.o
	gcc -o tsys tsys.o ../../common/apueerr.o

printuids: printuids.o ../../common/apueerr.o
	gcc -o printuids printuids.o ../../common/apueerr.o

getlogindemo: getlogindemo.o ../../common/apueerr.o
	gcc -o getlogindemo getlogindemo.o ../../common/apueerr.o

timesdemo: timesdemo.o ../../common/apueerr.o
	gcc -o timesdemo timesdemo.o ../../common/apueerr.o

clean:
	rm -f *.o
	rm -f forkdemo vforkdemo waitdemo waitpiddemo racecond_demo execdemo execinterp systemdemo tsys printuids getlogindemo timesdemo