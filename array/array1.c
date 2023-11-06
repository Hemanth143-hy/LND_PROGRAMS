#include <stdio.h>
#include <unistd.h>
int main() {

  int values[5];
//	printf("%d\n",getpid());
//	printf("%d\n",getppid());
//	kill();
  printf("Enter 5 integers: ");
  for(int i = 0; i < 5; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying integers: \n ");
  for(int i = 0; i < 5; ++i) {
     printf("%d\n", values[i]);
  }
  printf("\n");
  for(int i = 4; i >= 0; --i) {
		printf("%d\n" , values[i]);
  }
  return 0;
}
