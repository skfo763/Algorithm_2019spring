#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int count, i;
	string a, b;

	scanf("%d", &count);
	for(i=0; i<count; i++) {
		getline(cin, a, ',');
		getline(cin, b);

		cout << stoi(a) + stoi(b) << endl;
	}

	return 0;
}
