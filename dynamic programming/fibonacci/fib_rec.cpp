#include <stdio.h>
#include <stdlib.h>

int get_fibonacci(int value) {
	
	if(value == 1) return 1;
	if(value == 2) return 1;

	return get_fibonacci(value-1) + get_fibonacci(value-2);
}


int main(int argc, char** argv) {

	if(argc != 2) {
		printf("usage : ./a.out number_of_iteration\n");
		return -1;
	}

	int count = atoi(argv[1]);
	printf("%d\n", get_fibonacci(count));

	return 0;
}	
