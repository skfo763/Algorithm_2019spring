#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define INF 2147384000

using namespace std;

int find_n(int* box, int x) {
	int data[3] = {INF, INF, INF};

	if(x == 1) return 0;
	if(x%3 == 0) {
		if(box[x/3] != 0) data[0] = box[x/3]+1;
		else data[0] = find_n(box, x/3)+1;
	}
	
	if(x%2 == 0) {
		if(box[x/2] != 0) data[1] = box[x/2]+1;
		else data[1] = find_n(box, x/2)+1;
	}
	
	if(box[x-1] != 0) data[2] = box[x-1]+1;
	else data[2] = find_n(box, x-1)+1;
	
	return box[x] = *min_element(data, data+3);
}



int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	int* t = new int [ n + 10 ];
	printf("%d", find_n(t, n));
}
