#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H
#define PI 3.14159265

#include <string>
#include "mystack.h"
#include <string.h>
#include <math.h>

using namespace std;

class expr_eval{
  private:
        // Declare which ever necessary variables and methods
	
	
  public:
        double eval(string, double);
	bool prec(char, char);
	double doop(char, double, double);
};

bool prec(char op1, char op2) {
	if (op2 == '(' || op2 == ')') {
		return false;
	}
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
		return false;
	}

	if (op1 == '^' && (op2 == '*' || op2 == '/' || op2 == '+' || op2 == '-')) {
		return false;
	}

	return true;
}

double doop(char op, double b, double a) {
	if (op == '+') {
		return a + b;
	}
	if (op == '-') {
		return a - b;
	}
	if (op == '*') {
		return a * b;
	}
	if (op == '^') {
		return pow(a, b);
		
	}
	return a / b;
}

double eval(string s, double d1) {
	mystack<double> nums;
	mystack<char> ops;
	
	int n = s.length();
	char array[n + 1];
	strcpy(array, s.c_str());
	int isn = 0;
	for (int i = 0; i < n; i++) {
		int d = i;
		isn = 0;
		while ((array[d] > 47 && array[d] < 58) || array[d] == 46) {
			d++;
			isn = 1;
		}
		if (isn) {
			string s1 = s.substr(i,d - i);
			double num = atof(s1.c_str());
			nums.push(num);
			i = d - 1;
		} else {

			if (array[i] == 'x') {
				nums.push(d1);
			}

			if(array[i] == '(') {
				ops.push(array[i]);
			}
			if (array[i] == ')') {
				while (ops.top() != '(') {
					double t1 = nums.pop();
					double t2 = nums.pop();
					char c1 = ops.pop();
					nums.push(doop(c1, t1, t2));
				}
				ops.pop();
				if (ops.top() == 's') {
					double t1 = nums.pop();
					ops.pop();
					nums.push(sin(t1*PI/180));
				}
				if (ops.top() == 'l') {
					double t1 = nums.pop();
					ops.pop();
					nums.push(log10(t1));
				}
				if (ops.top() == 'c') {
					double t1 = nums.pop();
					ops.pop();
					nums.push(cos(t1*PI/180));
				}
				if (ops.top() == 't') {
					double t1 = nums.pop();
					ops.pop();
					nums.push(tan(t1*PI/180));
				}
			}
			if (array[i] == 's') {
				ops.push(array[i]);
				i = i + 2;
			}
			if (array[i] == 'c') {
				ops.push(array[i]);
				i = i + 2;
			}

			if (array[i] == 't') {
				ops.push(array[i]);
				i = i + 2;
			}

			if (array[i] == 'l') {
				ops.push(array[i]);
				i = i + 2;
			}

			if (array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/' || array[i] == '^') {
				while (nums.size() > 1 && prec(array[i], ops.top())) {
					double t1 = nums.pop();
					double t2 = nums.pop();
					char c1 = ops.pop();
					nums.push(doop(c1, t1, t2));
				}
				ops.push(array[i]);
			}
			
		}	
		
	}


	while (!ops.empty()) {
		double t1 = nums.pop();
		double t2 = nums.pop();
		char c1 = ops.pop();
		nums.push(doop(c1, t1, t2));
	}
	return nums.pop();
}
#endif
