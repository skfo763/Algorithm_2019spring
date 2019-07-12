#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int a, b;
	vector <int> v;

	while(true) {
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0) break;
		else {
			v.push_back(a+b);
		}
	}

	for(int i=0; i<v.size(); i++) {
		printf("%d\n", v[i]); 
	}

	return 0;
}
