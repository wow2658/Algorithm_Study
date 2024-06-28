#include <iostream>
#include <stack>
using namespace std;

int n;
int d[100004];
stack<int> s;

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	s.push(1);

	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		s.push(i - 1);
		if (i % 3 == 0)
		{
			if (d[i] > d[i / 3] + 1)
			{
				d[i] = d[i / 3] + 1;
				s.pop();
				s.push(i / 3);
			}
		}
		if (i % 2 == 0)
		{
			if (d[i] > d[i / 2] + 1)
			{
				d[i] = d[i / 2] + 1;
				s.pop();
				s.push(i / 2);
			}
		}


	}

	cout << d[n] << "\n";
	s.push(n);
	for (int i = 1; i <= n; i++)
	{
		cout << s.top() << " ";
		if (s.top() == 1) return 0;
		s.pop();
	}



	return 0;
}