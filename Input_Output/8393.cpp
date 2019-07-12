#include <iostream>

int main(void) {

	int a;
	scanf("%d", &a);
	int result = 0;

	for(int i=1; i<=a; i++) {
		result += i;	
	}

	printf("%d", result);
}
