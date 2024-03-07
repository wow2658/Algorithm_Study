#include <bits/stdc++.h>

using namespace std;

int nr, mc, knum;

int dr[4]{ 1,0,-1,0 };
int dc[4]{ 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;
	while (t--)
	{
		bool board[52][52]{ {} };
		int  dist[52][52]{ {} };
		cin >> mc >> nr >> knum;
		while (knum--)
		{
			int mcc = 0, nrr = 0;
			cin >> mcc >> nrr;
			board[nrr][mcc] = 1;
			dist[nrr][mcc] = -1;
		}
		//for (int r = 0; r < nr; ++r)
		//{
		//	for (int c = 0; c < mc; ++c)
		//	{
		//		cout << board[r][c] << " ";
		//	}
		//	cout << '\n';
		//}

		int num = 0;
		queue<pair<int, int>> q;
		for (int r = 0; r < nr; ++r)
		{
			for (int c = 0; c < mc; ++c)
			{
				if (1 != board[r][c] || -1 != dist[r][c]) continue;
				q.push({ r,c }); dist[r][c] = 1; ++num;

				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; ++dir)
					{
						int nxr = cur.first + dr[dir];
						int nxc = cur.second + dc[dir];
						if (nxr < 0 || nxr >= nr || nxc < 0 || nxc >= mc) continue;
						if (1 != board[nxr][nxc] || -1 != dist[nxr][nxc])continue;
						q.push({ nxr,nxc }); dist[nxr][nxc] = dist[cur.first][cur.second] + 1;
					}
				}
			}
		}
		cout << num << '\n';
	}

	return 0;
}