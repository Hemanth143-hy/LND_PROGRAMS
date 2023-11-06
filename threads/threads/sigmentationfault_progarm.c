#include <stdio.h>
#include <signal.h>
void handle_sigint(int);
int main() {
	signal(SIGSEGV ,handle_sigint);
	printf("helllllo:");
	int *ptr = 98765;
	printf("%d" , ptr[45]);
	return 0;
}

void handle_sigint(int seg) {
	printf("the segmantation %p\n" ,handle_sigint); 	
}
