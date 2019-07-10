#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int dp[10000];


int get_max_score(int* st, int x) {
	
	int a=-1; int b=-1;

	if(x == 0) return 0;
	if(x == 1) return st[1];
	if(x == 2) return st[1]+st[2];

	if(dp[x-2] != 0) {
		a = dp[x-2];
	} else {
		a = get_max_score(st, x-2);
	}

	if(dp[x-3] != 0) {
		b = dp[x-3];
		b = get_max_score(st, x-3);
	}

	return dp[x] = max(a+st[x], b+st[x-1]+st[x]);
}

int main(int argc, char** argv) {

	int count, i;
	scanf("%d", &count);
	int* st = new int [ count+1 ];

	for(i=1; i<=count; i++) {
		scanf("%d", &st[i]);
	}

	printf("%d\n", get_max_score(st, count));

}
