#include <iostream>
using namespace std;

int main(void) {
	int i, month, day;
	string ans[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int a = 0;

	scanf("%d %d", &month, &day);
	
	for(i=1; i<month; i++) {
		if(i==2) {
			a += 28;
		} else if(i==4 || i==6 || i==9 || i==11) {
			a += 30;
		} else {
			a += 31;
		}
	}

	a += day;

	cout << ans [a%7];
	return 0;
}
