#include <cstdio>
#include <stdlib.h>

int dp[10000];

int getCount(int n) {
	
	if(n == 1) {
		return 1;
	
	} else if(n == 2) {
		return 2;
	
	} else if(dp[n] != 0) { 
		return dp[n];

	} else {
		return dp[n] = (getCount(n-1) + getCount(n-2))%10007;
	
	}
}


int main(void) {
	
	int n;
	scanf("%d", &n);
	printf("%d\n", getCount(n));
	
	return 0;
}
