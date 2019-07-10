#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct SOLVE {
	int value;
	pair<int, int> zo;
} solve;

solve dp_data[100000];

solve fibonacci(solve x) {
	solve result;

	if(x.value == 0) {
		result.value = 0;
		result.zo = make_pair(x.zo.first+1, x.zo.second);
		
		return result;

	} else if(x.value == 1) {
		result.value = 1;
		result.zo = make_pair(x.zo.first, x.zo.second+1);
		
		return result;

	} else if(dp_data[x.value].value != 0) {
		result.value = dp_data[x.value].value;
		result.zo = make_pair(x.zo.first + dp_data[x.value].zo.first, x.zo.second + dp_data[x.value].zo.second);

		return result;
	
	} else {
		solve tp1, tp2, r1, r2, f;
		
		tp1.value=x.value-1;	tp1.zo=x.zo;
		tp2.value=x.value-2;	tp2.zo=x.zo;

		r1 = fibonacci(tp1);
		r2 = fibonacci(tp2);

		f.value = r1.value+r2.value;
		f.zo = make_pair(r1.zo.first + r2.zo.first, r1.zo.second + r2.zo.second);
		
		return dp_data[x.value] = f;
	}
}

int main(void) {
	int count, i;
	scanf("%d", &count);
	
	pair<int, int>* data = new pair<int, int> [count];
	
	for(i=0; i<count; i++) {
		int temp;
		scanf("%d", &temp);
		solve x;
		x.value = temp;
		x.zo = make_pair(0, 0);
		solve te = fibonacci(x);
		
		data[i] = make_pair(te.zo.first, te.zo.second);
	}

	for(i=0; i<count; i++) {
		printf("%d %d\n", data[i].first, data[i].second);
	}

	delete [] data;
	return 0;
}
