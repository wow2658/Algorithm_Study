#include <bits/stdc++.h>

using namespace std;

int nr, mc;
int dr[4]{ 1,0,-1,0 };
int dc[4]{ 0,1,0,-1 };

int board[1002][1002];
int dist[1002][1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> mc >> nr;
	queue<pair<int, int>> q;
	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cin >> board[r][c];
			if (0 == board[r][c]) dist[r][c] = -1;
			else if (-1 == board[r][c]) dist[r][c] = 0;
			else if (1 == board[r][c])
			{
				dist[r][c] = 1; q.push({ r,c });
			}
		}
	}



	while (!q.empty())
	{
		//int area = 0;

		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nxr = cur.first + dr[dir];
			int nxc = cur.second + dc[dir];
			if (nxr < 0 || nxr >= nr || nxc < 0 || nxc >= mc) continue;
			if (-1 == board[nxr][nxc] || -1 != dist[nxr][nxc])continue;
			q.push({ nxr ,nxc }); dist[nxr][nxc] = dist[cur.first][cur.second] + 1;
			//area++;
		}
		//mx = max(mx, area);
	}

	int mx = 0;
	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			if (-1 == dist[r][c])
			{
				cout << -1; return 0;
			}
			mx = max(mx, dist[r][c]);
		}
	}

	cout << mx - 1;

	/*for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cout << board[r][c] << " ";
		}
		cout << "\n";
	}

	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cout << dist[r][c] << " ";
		}
		cout << "\n";
	}*/
}