#include <iostream>

using namespace std;

int main(void) {
	
	int i, count, a, b;
	scanf("%d", &count);

	for(i=1; i<=count; i++) {
		scanf("%d %d", &a, &b);
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << endl;
	}

	return 0;
}
