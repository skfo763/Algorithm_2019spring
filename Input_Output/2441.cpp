#include <iostream>

int main(void) {
	int a;
	scanf("%d", &a);

	for(int i=a; i>0; i--) {
		for(int j=0; j<a-i; j++) {
			printf(" ");
		}

		for(int k=0; k<i; k++) {
			printf("*");
		}

		printf("\n");
	}
	
	return 0;
}
