#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
	int count;
	scanf("%d", &count);
	int* arr = new int [count];
	
	for(int i=0; i<count; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+count);

	cout << arr[0] << " " << arr[count-1] << endl;
}
