#include <iostream>
#include <string>
using namespace std;

int main(void) {
   
	string text;
    while (getline(cin, text)) {
        cout << text << endl;
    }

	return 0;
}
