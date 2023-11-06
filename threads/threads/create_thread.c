#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
pthread_cond_t con = PTHREAD_COND_INITIALIZER;
//pthread_cond_t con1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int enable;
int ret = 0;
void* func(int ret); 
void* func1(int ret); 
int main() {	
	pthread_t thread;
	pthread_t thread1;
	int s;
	int y;
	printf("enter the enable value '0' or '1' ");
	scanf("%d" , &enable);	
//	y = pthread_mutex_init(&lock , NULL);
//	printf("%d\n" , y);
	s = pthread_create(&thread , NULL ,(void*)func , NULL);	
	s = pthread_create(&thread1 , NULL ,(void*)func1 , NULL);	
	pthread_join(thread , NULL);
	pthread_join(thread1 , NULL);
	if(y != 0) {
		printf("the thread is not created;\n");
	}
	printf("hello:\n");
//	pthread_mutex_destroy(&lock);
}
void* func(int ret) {
	if(enable) {
		pthread_mutex_lock(&lock);
	while(ret == 1) {
	pthread_cond_wait(&con, &lock);
	pthread_cond_signal(&con);		
	for(int i = 0 ; i < 100; i++) {
			printf("0");
			fflush(stdout);
	}
		printf("inside thread1");
	ret = 1; 
	if(enable) {
		pthread_mutex_unlock(&lock);
	}
	
	printf("\n");
	pthread_exit(func);
		}	 
	}
}
void* func1(int ret) {
	if(enable) {
		pthread_mutex_lock(&lock);
	while(ret == 0 ) {
	for(int i = 0 ; i < 100; i++) {
			printf("1");
			fflush(stdout);
	} 
		printf("inside thread2");
	ret = ret+1;
	pthread_cond_wait(&con, &lock);
	pthread_cond_signal(&con);
	if(enable) {	
			pthread_mutex_unlock(&lock);
		}	
	printf("\n");
		}	
	}
	pthread_exit(func1);
}
