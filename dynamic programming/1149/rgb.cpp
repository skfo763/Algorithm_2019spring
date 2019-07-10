#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int dp[10000][3];
int col_val[10000][3];

int main(void) {
	int count, i;
	scanf("%d", &count);

	for(i=1; i<=count; i++) {
		scanf("%d %d %d", &col_val[i][0], &col_val[i][1], &col_val[i][2]);
	}

	for(i=1; i<=count; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) +col_val[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + col_val[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + col_val[i][2];
	}

	printf("%d\n", min(min(dp[count][0], dp[count][1]), dp[count][2]));


	return 0;
}
