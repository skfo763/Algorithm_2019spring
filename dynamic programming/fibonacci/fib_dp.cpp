#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX 1000000

using namespace std;

long long get_fibonacci(long* box, int value) {
	
	if(value == 1 || value == 2) return 1;
	if(box[value] != 0) return box[value];

	box[value] = get_fibonacci(box, value-1) + get_fibonacci(box, value-2);
	return box[value];
}


int main(int argc, char** argv) {

	if(argc != 2) {
		printf("usage : ./a.out number_of_iteration\n");
		return -1;
	}

	int count = atoi(argv[1]);
	long* box = new long [ MAX ];
	printf("%lld\n", get_fibonacci(box, count));


	delete [] box;
	return 0;
}	
