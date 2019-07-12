#include <iostream>
using namespace std;

int main(void) {
	int a;
	scanf("%d", &a);

	for(int i=a; i>0; i--) {
		for(int j=0; j<i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}
