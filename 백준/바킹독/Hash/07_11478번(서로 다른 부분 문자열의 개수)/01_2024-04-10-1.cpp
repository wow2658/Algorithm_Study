#include <unordered_set>
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	unordered_set<string> uset;

	cin >> s;
	for (int start = 0; start < s.length(); start++)
		for (int len = 1; start + len <= s.length(); len++)
			//for (int len = 1; start <= s.length() - len; len++)  // error
				// a
				// ab
				// aba
				// abab
				// ababc    // 5번
				//  b
				//  ba
				//  bab
				//  babc    // 4번
			uset.insert(s.substr(start, len));
	cout << uset.size();
}