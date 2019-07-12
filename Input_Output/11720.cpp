#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	
	int count, i;
	int result = 0;
	string s_c, n;

	getline(cin, s_c);
	count = stoi(s_c);

	getline(cin, n);
	for(i=0; i<count; i++) {
		result += n.at(i) - '0';
	}

	printf("%d\n", result);
	return 0;
}
