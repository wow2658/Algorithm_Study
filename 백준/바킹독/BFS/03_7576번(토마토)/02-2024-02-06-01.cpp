#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;
int board[1002][1002];
int dist[1002][1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
		// fill(dist[i], dist[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == -1) dist[i][j] = -1;
		}
	}

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1)
			{
				Q.push({ i,j }); dist[i][j] = 1;
			}
		}
	}
	int mx = 0;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != 0 || board[nx][ny] != 0) continue;
			Q.push({ nx,ny }); dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
		mx = max(mx, dist[cur.X][cur.Y]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << dist[i][j] << ' ';
			if (dist[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
		//cout << '\n';
	}
	cout << mx - 1;
}