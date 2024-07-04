#include <iostream>
using namespace std;

int t, n;
long long d[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1] = 1; d[2] = 1; d[3] = 1;
	for (int i = 4; i < 101; i++)
	{
		d[i] = d[i - 2] + d[i - 3];
	}

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		cout << d[n] << "\n";

	}
}