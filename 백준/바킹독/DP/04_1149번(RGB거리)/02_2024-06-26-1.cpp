#include <iostream>

using namespace std;

int n;
int d[1003][3];
int r[1003];
int g[1003];
int b[1003];

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> r[i] >> g[i] >> b[i];
	// d는 비용을 넣는곳이고 수집은 rgb로!

	d[1][0] = r[1];
	d[1][1] = g[1];
	d[1][2] = b[1];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + b[i];
	}
	cout << *min_element(d[n], d[n] + 3);
	return 0;
}