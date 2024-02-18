#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (n % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (n % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n];

}