#include <bits/stdc++.h>
using namespace std;

int dr[4]{ 1,0,-1,0 };
int dc[4]{ 0,1,0,-1 };

char board[102][102];
int dred[102][102];
int dgreen[102][102];
int dblue[102][102];
int dredgreen[102][102];

int n;

int bfs(int dist[][102])
{
	int num = 0;
	queue<pair<int, int>> q;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (-1 != dist[r][c]) continue;
			q.push({ r,c }); dist[r][c] = 1; ++num;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nxr = cur.first + dr[dir];
					int nxc = cur.second + dc[dir];
					if (nxr < 0 || nxr >= n || nxc < 0 || nxc >= n || -1 != dist[nxr][nxc]) continue;
					q.push({ nxr,nxc }); dist[nxr][nxc] = dist[cur.first][cur.second] + 1;
				}
			}
		}
	}

	return num;
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
			cin >> board[r][c];
			if ('R' == board[r][c])
			{
				dred[r][c] = -1;
				dredgreen[r][c] = -1;
			}
			else if ('G' == board[r][c])
			{
				dgreen[r][c] = -1;
				dredgreen[r][c] = -1;
			}
			else if ('B' == board[r][c])
			{
				dblue[r][c] = -1;
			}
		}
	}

	int rnum = bfs(dred);
	int gnum = bfs(dgreen);
	int bnum = bfs(dblue);
	int rgnum = bfs(dredgreen);

	cout << rnum + gnum + bnum << " " << rgnum + bnum;

	return 0;
}