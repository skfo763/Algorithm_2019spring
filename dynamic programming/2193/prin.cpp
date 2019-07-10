#include <cstdio>
#include <stdlib.h>

int dp[100][2];

int main(void) {
	
	int i, x;
	scanf("%d", &x);
	
	dp[1][0] = 0;
	dp[1][1] = 1;

	for(i=2; i<=x; i++) {
		dp[i][0] = dp[i-1][1] + dp[i-1][0];
		dp[i][1] = dp[i-1][0];
	}

	printf("%d\n", dp[x][0] + dp[x][1]);

	return 0;
}

