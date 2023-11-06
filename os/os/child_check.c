#include <stdio.h>
#include <unistd.h>
int main()
{ 	
	fork();
	printf("%d\n", getpid());
	printf("%d\n", getppid());
return 0;
}
