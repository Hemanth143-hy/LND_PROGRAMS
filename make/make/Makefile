target : main.o fun1.o  fun2.o
	$(cc) main.o fun1.o fun2.o $(flag) Hello
main.o : main.c header.h
	$(cc) -c main.c
fun1.o : fun1.c header.h
	$(cc) -c fun1.c
fun2.o : fun2.c header.h
	$(cc) -c fun2.c
create :
	gcc -o hello *.c header.h
out :
	./hello

