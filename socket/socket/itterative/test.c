#include <stdio.h>
int swap(int num);
int main() {
	int n;
	swap(n);
}
int swap(int num) {
	unsigned int n = 0x12345678;
	n = ((n << 28) | (n >>28) | (((n << 4) >> 28) << 4) 
		| (((n >> 4) << 28) >> 4) |(((n << 8) >> 28) << 8) 
		| ((( n >> 8) << 28) >> 8) | (((n << 12) >> 28) <<12) 
		| (((n >> 12) <<28 ) >> 12));
	printf("%x",n);
}
