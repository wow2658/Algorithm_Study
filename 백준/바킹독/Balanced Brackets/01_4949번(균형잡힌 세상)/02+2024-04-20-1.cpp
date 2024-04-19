#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string a;
		getline(cin, a);
		if ("." == a) break;

		stack<char> s;
		bool isValid = true;
		for (char c : a)
		{
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')')
			{
				if (s.empty() || s.top() != '(') // c != '(' 디버깅으로 잡아낸 오류! 잘 생각하자
				{
					isValid = false;
					break;
				}
				s.pop();
			}
			else if (c == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					isValid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) isValid = false;

		if (isValid) cout << "yes\n";
		else cout << "no\n";
	}
}
