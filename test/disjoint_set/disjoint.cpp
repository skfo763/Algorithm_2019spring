#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int find_set_arr(int *arr, int x) {
	return arr[x];
}

int find_set_tree(int *arr, int x) {

	while(arr[x] != x) {
		x = arr[x];
	}

	return x;
}

void union_set_arr(int *arr, int size, int x, int y) {
	int i;

	for(i=0; i<size; i++) {
		if(arr[i] == y) {
			arr[i] = x;
		}
	}
}

void union_set_tree(int *arr, int x, int y) {
	x = find_set_tree(arr, x);
	y = find_set_tree(arr, y);

	if(x != y) {
		arr[y] = x;
	}
}

int main(int argc, char** argv) {
	
	if(argc != 2) {
		printf("Usage: ./a.out(execution_file) operation_type(-t for tree method, -a for array method)\n");
		return -1;
	}


	char* op = argv[1];
	int array_num, op_count, i, j, op_code, op_a, op_b;
	scanf("%d %d", &array_num, &op_count);

	int *arr = new int [ array_num ];  // allocation of memory

	for(i=0; i<array_num; i++) { 	   // initialization of memory
		arr[i] = i;
	}

	for(i=0; i<op_count; i++) {
		scanf("%d %d %d", &op_code, &op_a, &op_b);

		if(op_code == 0) {			// check two sets are inside of same sets

			if(strncmp(op, "-t", 2) == 0) {
				if(find_set_tree(arr, op_a) == find_set_tree(arr, op_b)) printf("same set\n");
				else printf("different set\n");

			} else if(strncmp(op, "-a", 2) == 0) {	
				if(find_set_arr(arr, op_a) == find_set_arr(arr, op_b)) printf("same set\n");
				else printf("different set\n");

			} else {
				exit(-1);
			
			}

		} else if(op_code == 1) {   // union two set

			if(strncmp(op, "-t", 2) == 0) {
				union_set_tree(arr, op_a, op_b);		

			} else if(strncmp(op, "-a", 2) == 0) {	
				union_set_arr(arr, array_num, op_a, op_b);
			
			} else {
				exit(-1);
			}
		}
	}

	delete [] arr;
	return 0;
}
