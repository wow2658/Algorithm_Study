#include <bits/stdc++.h>

using namespace std;

int nr, mc, num, mx;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

bool board[502][502];
int	 dist[502][502];

void bfs()
{


	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			if (0 == board[r][c] || -1 != dist[r][c]) continue;
			queue<pair<int, int>> q;
			q.push({ r,c });
			dist[r][c] = 0;
			++num;
			int area = 1;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nxr = cur.first + dr[dir];
					int nxc = cur.second + dc[dir];
					if (nxr < 0 || nxr >= nr || nxc < 0 || nxc >= mc) continue;
					if (0 == board[nxr][nxc] || -1 != dist[nxr][nxc]) continue;
					q.push({ nxr,nxc });
					dist[nxr][nxc] = dist[cur.first][cur.second] + 1;
					++area;
				}

				mx = max(mx, area);
			}
			area = 0;
		}
	}

	cout << num << '\n' << mx;
}

void setting(int nr, int mc)
{
	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cin >> board[r][c];

			if (board[r][c] == 1) dist[r][c] = -1;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> nr >> mc;

	setting(nr, mc);
	bfs();
}