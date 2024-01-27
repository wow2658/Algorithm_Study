// https://www.acmicpc.net/problem/2178 https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/2178.cpp
// fail
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];
int dist[102][102];
int n, m;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int area = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)	fill(dist[i], dist[i] + m, -1);

	queue<pair<int, int>> Q;
	Q.push({ 0,0 }); dist[0][0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] >= 0 || board[i][j] != 1) continue;

			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
					if (dist[nx][ny] > dist[cur.X][cur.Y] || board[nx][ny] == 0)continue;
					Q.push({ nx,ny }); dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				}
				area = dist[cur.X][cur.Y] + 1;
			}

		}
	}
	cout << area;
}
