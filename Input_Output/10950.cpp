#include <cstdio>
#include <stdlib.h>

int main(void) {
	
	int i, count, a, b;
	scanf("%d", &count);
	
	int* ans = new int [count];
	
	for(i=0; i<count; i++) {
		int temp_a, temp_b;
		scanf("%d %d", &temp_a, &temp_b);

		ans[i] = temp_a + temp_b;
	}

	for(i=0; i<count; i++) {
		printf("%d\n", ans[i]);
	}

	delete [] ans;
	return 0;
}
