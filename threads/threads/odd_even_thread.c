#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* Even_no(int*);
void* Odd_no(int*);
int enable;
int main() {
	pthread_t even;
	pthread_t odd;
	pthread_mutex_init (&lock , NULL);
	int res = 0;
	int temp = 0;
	printf("enter the enable value:");
	scanf("%d" , &enable);
	time_t t;
	int value = 10;
	srand((unsigned)time(&t));
	while(value--) {
		temp = rand() %1000+1;
		res = pthread_create(&even, NULL, (void*)Even_no, &temp);
		res = pthread_create(&odd, NULL, (void*)Odd_no, &temp);
		pthread_mutex_destroy(&lock);	
		pthread_join(even, NULL);
		pthread_join(odd, NULL);
	}
}
void* Even_no(int* temp) {
	if(enable) pthread_mutex_lock(&lock);
	if(*temp % 2 == 0) {
		printf("Even no. is : %d\n", *temp);
	}
	if(enable) pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
//	printf("%d" , Even_no);
}

void* Odd_no(int* temp) {
	if(enable) pthread_mutex_lock(&lock);
	if(*temp % 2 != 0) {
		printf("Odd no. is : %d\n", *temp);
	}
	if(enable) pthread_mutex_unlock(&lock);
}  
