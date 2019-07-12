#include <iostream>

int main(void) {
	int count, i, k, j;
	scanf("%d", &count);

	for(i=1; i<=count; i++) {
		
		for(k=0; k<i; k++) {
			printf("*");
		}

		for(j=0; j<2*(count-i); j++) {
			printf(" ");
		}

		for(k=0; k<i; k++) {
			printf("*");
		}

		printf("\n");
	}

	for(i=count-1; i>=1; i--) {
	
		for(k=0; k<i; k++) {
			printf("*");
		}

		for(j=0; j<2*(count-i); j++) {
			printf(" ");
		}

		for(k=0; k<i; k++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
