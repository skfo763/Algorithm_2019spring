#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int getlevel(char a);
char* getPostfix(char *buf, char* buf2);
double getresult(char* buf);

int main(int argc, char **argv) {
	char *buf = new char[256];
	char *buf2 = new char[256];

	FILE *input_fp = fopen(argv[1], "rt");

	fgets(buf, 128, input_fp);
	buf[strlen(buf)] = '\0';

	getPostfix(buf, buf2);
	double t = getresult(buf2);

	FILE *output_fp = fopen(argv[2], "wt");
	fprintf(output_fp, "%0.2f", t);

	return 0;
}

double getresult(char* buf) {
	int i;
	stack<double> s;

	for(i=0; i<strlen(buf); i++) {
		char temp = buf[i];

		if(temp >= '0' && temp <= '9') {
			s.push((double) temp - '0');

		} else {
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();

			if(temp == '+') s.push(a+b); 
			else if(temp == '-')  s.push(a-b); 
			else if(temp == '*')  s.push(a*b); 
			else if(temp == '/')  s.push(a/b); 
		}
	}

	return s.top();
}

char* getPostfix(char* buf, char* buf2) {
	stack<char> s1;

	int i=0, j=0;
	for(i=0; i<strlen(buf); i++) {
		char temp = buf[i];

		if(temp == '+' || temp == '-' || temp == '*' || temp == '/') {
			if(s1.empty()) {
				s1.push(temp);
				continue;
			}

			int temp_lev = getlevel(temp);
			int top_lev = getlevel(s1.top());

			while(temp_lev < top_lev) {
				if(s1.empty()) break;
				
				buf2[j++] = s1.top();
				s1.pop();
			}
			s1.push(temp);

		} else if(temp >= '0' && temp <= '9') {
			buf2[j++] = temp;

		} else if(temp == '(') {
			s1.push(temp);

		} else if(temp == ')') {

			while(s1.top() != '(') {
				if(s1.empty()) break;
				buf2[j++] = s1.top();
				
				if(!s1.empty()) s1.pop();
			}
			s1.pop();
		}
	}

	while(!s1.empty()) {
		buf2[j++] = s1.top();
		s1.pop();
	}
}

int getlevel(char a) {
	if(a == '(') return 0;
	else if(a == '+' || a == '-') return 1;
	else if(a == '*' || a == '/') return 2;
}

