#include <iostream>
#include <algorithm>

using namespace std;

int a[1000002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int m = 0;
	cin >> m;
	while (m--)
	{
		int t = 0;
		cin >> t;
		cout << binary_search(a, a + n, t) << '\n';
	}
}
