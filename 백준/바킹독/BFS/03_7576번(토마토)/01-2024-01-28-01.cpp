//  https://www.acmicpc.net/problem/7576  http://boj.kr/ae38aa7eb7a44aca87e9d7928402d040
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[1002][1002];
int dist[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	// for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(board[i][j] == 0) dist[i][j] = -1;
		}
	}

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1)
			{
				Q.push({ i,j }); dist[i][j] = 0;

			}
		}
	}

	int ans = 0;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 보드가 -1이면 거른다. dist가 이미들른곳이면 거른다.
			if (dist[nx][ny] >= 0 || board[nx][ny] == -1) continue;
			Q.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;

		}

	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << "-1";
				return 0;
			}

			ans = max(ans, dist[i][j]);
		}

	}
	cout << ans << "\n";



}
