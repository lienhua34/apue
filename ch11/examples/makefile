../../common/apueerr.o: ../../common/apueerr.c
	cd ../../common & make apueerr.o
pthread_create_demo: pthread_create_demo.o ../../common/apueerr.o
	gcc -o pthread_create_demo -pthread pthread_create_demo.o ../../common/apueerr.o
thread_exitcode_demo: thread_exitcode_demo.o ../../common/apueerr.o
	gcc -o thread_exitcode_demo -pthread thread_exitcode_demo.o ../../common/apueerr.o
err_thread_exitcode_demo: err_thread_exitcode_demo.o ../../common/apueerr.o
	gcc -o err_thread_exitcode_demo -pthread err_thread_exitcode_demo.o ../../common/apueerr.o
pthread_cleanup_demo: pthread_cleanup_demo.o ../../common/apueerr.o
	gcc -o pthread_cleanup_demo -pthread pthread_cleanup_demo.o ../../common/apueerr.o
producer_consumer: producer_consumer.o ../../common/apueerr.o
	gcc -o producer_consumer -pthread producer_consumer.o ../../common/apueerr.o

clean: 
	rm -f *.o
	rm -f pthread_create_demo thread_exitcode_demo err_thread_exitcode_demo pthread_cleanup_demo producer_consumer