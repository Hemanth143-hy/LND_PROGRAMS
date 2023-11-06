#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum)	{
	printf("Caught signal %d" , signum);
}
int main()
{
	signal(SIGINT, handle_sigint);
	for(int i = 1; ;i++) {
		printf("%d :inside main fun\n", i);
		pause();
	}
	return 0;
}
