// 11634 - Generate Random Numbers

#include <iostream>
#include <set>
#include <string>
using namespace std;

#define NUM_DIGITS 4

typedef long long ll;

int getMiddleDigits(int N) {
	
	string s = to_string(N);
	
	while (s.length() != NUM_DIGITS * 2)
		s = "0" + s;
	
	int i = 2;
	while ((i < s.length() - 2) && (s[i] == '0'))
		i++;
	
	if (i == 6)
		return 0;
	return stoi(s.substr(i, s.length() - 2 - i));
}

int main() {
    int N, numVals;

	while ((cin >> N) && (N != 0)) {
		set<int> valSet;
		
		while (valSet.insert(N).second)
			N = getMiddleDigits(N * N);
		
		cout << valSet.size() << endl;
	}
	
    return 0;
}

