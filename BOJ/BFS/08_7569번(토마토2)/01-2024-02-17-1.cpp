#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102][102];
int dist[102][102][102];

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int m, n, h;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h; //     x 위아래가 n            y 좌우가 m        층간 h      

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[j][k][i];
				if (board[j][k][i] == 1)
				{
					dist[j][k][i] = 1; // 나중에 결과에서 -1하자
					q.push({ j,k,i });
				}
				else if (board[j][k][i] == 0) dist[j][k][i] = 0;
				else if (board[j][k][i] == -1) dist[j][k][i] = -1;
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		int cx, cy, cz = 0;
		tie(cx, cy, cz) = cur;
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			int nz = cz + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (board[nx][ny][nz] != 0 || dist[nx][ny][nz] != -1) continue;
			q.push({ nx,ny,nz }); dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
		}
	}

	int mx = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == 0)
				{
					//cout << -1; //return 0;
				}


				mx = max(mx, dist[j][k][i]);
			}
		}
	}

	cout << mx;

}