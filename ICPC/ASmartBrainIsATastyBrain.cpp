#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main() {
	bool t1, t2;
	char c;
	int i, x, X;
	cin >> X;

	for (x = 1; x <= X; x++) {
		stack<char> stk;
		queue<char> postfix;
		string s = "";

		while ((cin >> c) && (c != '='))
			s.push_back(c);

		// Convert to postfix
		for (i = 0; i < s.length(); i++) {
			c = s[i];
			if (c == ')') {
				while (stk.top() != '(') {
					postfix.push(stk.top());
					stk.pop();
				}
				stk.pop();
			}
			else if (c == '(' || c == '&' || c == '|')
				stk.push(c);
			else if (c == '!') {
				if (s[i + 1] == 't') {
					postfix.push('f');
					i++;
				}
				else if (s[i + 1] == 'f') {
					postfix.push('t');
					i++;
				}
				else
					stk.push(c);
			}
			else
				postfix.push(c);
		}

		while (!stk.empty()) {
			postfix.push(stk.top());
			stk.pop();
		}

		// Evaluate postfix logical expression
		while (!postfix.empty()) {
			c = postfix.front();
			postfix.pop();

			if (c == '!') {
				t1 = (stk.top() == 't');
				stk.pop();

				stk.push(t1 == true ? 'f' : 't');
			}
			else if (c == '&') {
				t1 = (stk.top() == 't');
				stk.pop();

				t2 = (stk.top() == 't');
				stk.pop();

				stk.push((t1 == true && t2 == true) ? 't' : 'f');
			}
			else if (c == '|') {
				t1 = (stk.top() == 't');
				stk.pop();

				t2 = (stk.top() == 't');
				stk.pop();

				stk.push((t1 == true || t2 == true) ? 't' : 'f');
			}
			else
				stk.push(c);
		}

		cin >> c;
		if (c == stk.top())
			cout << x << ": Good brain" << endl;
		else
			cout << x << ": Bad brain" << endl;
	}

	return 0;
}