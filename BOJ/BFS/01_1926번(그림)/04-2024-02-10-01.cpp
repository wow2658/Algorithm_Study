#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;

int board[502][502];
bool vis[502][502];

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
	int num = 0;
	int mx = 0;

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == 0)
			{
				Q.push({ i,j }); vis[i][j] = 1; num++;

				int area = 1;
				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
						Q.push({ nx,ny }); vis[nx][ny] = 1; area++;

					}
					mx = max(mx, area);
				}
			}
		}
	}

	cout << num << '\n' << mx;

}