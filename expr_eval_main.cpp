#include <iostream>
#include <string>
#include "expr_eval.h"
#include <iomanip>



using namespace std;

int main(){
	string re;
	double xn;
	while (cin >> re) {
		if (re.find("x") != string::npos) {
			cin >> xn;
			cout << fixed;
			cout << setprecision(2);
			cout << eval(re, xn);
			cout << "\n";
		}
		else {
			cout << fixed;
			cout << setprecision(2);
			cout << eval(re, 0);
			cout << "\n";
		}
	}
	cout << "\n";
}
