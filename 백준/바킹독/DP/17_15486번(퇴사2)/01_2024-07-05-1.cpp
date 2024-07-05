#include <iostream>
#include <algorithm> // max_element를 사용하기 위해 추가
using namespace std;


int n;
int d[1500005];
int t[1500005];
int p[1500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; --i)
	{
		if (i + t[i] <= n + 1)
		{
			d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
		}
		else
		{
			d[i] = d[i + 1];
		}
	}

	cout << *max_element(d + 1, d + n + 1);
}
