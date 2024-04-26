#include <iostream>

using namespace std;

int n;
int paper[130][130];
int cnt[2];

bool chk(int x, int y, int n)
{
	for (int r = x; r < x + n; r++)
	{
		for (int c = y; c < y + n; c++)
		{
			if (paper[x][y] != paper[r][c]) return false;
		}
	}
	return true;
}

void solve(int x, int y, int n)
{
	if (chk(x, y, n))
	{
		cnt[paper[x][y]]++;
		return;
	}

	int sn = n / 2;
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			solve(x + r * sn, y + c * sn, sn);
		}
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cin >> paper[r][c];
		}
	}
	solve(0, 0, n);
	for (int i = 0; i < 2; i++)
	{
		cout << cnt[i] << '\n';
	}
}