#include<stdio.h>
#if DEQS == 1
int main()
{
	char str[10] = {"HEManth"};
	int count = 0;
	char *ptr;
	ptr = str;
//	for( i = 0; i < 10; i++) {
//	if(*ptr >= 'A' && *ptr <= 'Z' || *ptr >= 'a' && *ptr<= 'z') {
	while (*ptr != '\0') {
		count = count+1 ;
		ptr++;
	}
	printf("%d",count);

}
#endif
#if DEQS == 2
 string_length( 
