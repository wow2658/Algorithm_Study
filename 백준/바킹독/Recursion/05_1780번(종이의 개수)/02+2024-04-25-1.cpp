#include <iostream>

using namespace std;

int n;
int paper[2200][2200];
int cnt[3];

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

void solve(int x, int y, int z)
{
	if (chk(x, y, z))
	{
		cnt[paper[x][y] + 1]++;
		return;					// 디버깅으로 잡아냄. 안하면 무한루프 실수
	}

	int sn = z / 3;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
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

	for (int i = 0; i < 3; i++)
	{
		cout << cnt[i] << "\n";
	}

}