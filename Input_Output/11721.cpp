#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string k;
	getline(cin, k);

	for(int i=0; i<k.size(); i++) {
		if(i%10 == 0 && i != 0) {
			cout << endl << k.at(i);
		} else {
			cout << k.at(i);
		}
	}

	return 0;
}
