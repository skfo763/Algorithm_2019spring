#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


int get_add(int x) {
	if(x == 1) return 1;
	if(x == 2) return 2;
	if(x == 3) return 4;

	return get_add(x-1) + get_add(x-2) + get_add(x-3);
}



int main(int argc, char** argv) {

	int count, i;
	scanf("%d", &count);
	int* data = new int [count];

	for(i=0; i<count; i++) {
		int a;
		scanf("%d", &a);
		data[i] = get_add(a);
	}

	for(i=0; i<count; i++) {
		printf("%d\n", data[i]);
	}


	delete [] data;
}
