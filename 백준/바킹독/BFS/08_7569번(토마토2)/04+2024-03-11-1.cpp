#include <bits/stdc++.h>
using namespace std;

int dr[6]{ 1,-1,0,0,0,0 };
int dc[6]{ 0,0,1,-1,0,0 };
int dz[6]{ 0,0,0,0,1,-1 };

int board[102][102][102];
int dist[102][102][102];

int nr, mc, hz;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> mc >> nr >> hz;
	queue<tuple<int, int, int>> q;
	for (int z = 0; z < hz; z++)
	{
		for (int r = 0; r < nr; r++)
		{
			for (int c = 0; c < mc; c++)
			{
				cin >> board[z][r][c];
				if (0 == board[z][r][c])
				{
					dist[z][r][c] = -1;
				}
				else if (1 == board[z][r][c])
				{
					q.push({ z,r,c });
					dist[z][r][c] = 1; // 끝나고 1빼주기
				}
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		int cz = 0, cr = 0, cc = 0;
		tie(cz, cr, cc) = cur;
		for (int dir = 0; dir < 6; dir++)
		{
			int nxz = cz + dz[dir];
			int nxr = cr + dr[dir];
			int nxc = cc + dc[dir];
			if (nxz < 0 || nxz >= hz || nxr < 0 || nxr >= nr || nxc < 0 || nxc >= mc) continue;
			if (-1 != dist[nxz][nxr][nxc] || 0 != board[nxz][nxr][nxc]) continue;
			q.push({ nxz,nxr,nxc }); dist[nxz][nxr][nxc] = dist[cz][cr][cc] + 1;
		}
	}
	/*for (int z = 0; z < hz; z++)
	{
		for (int r = 0; r < nr; r++)
		{
			for (int c = 0; c < mc; c++)
			{
				cout << dist[z][r][c] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}*/
	int mx = 0;
	for (int z = 0; z < hz; z++)
	{
		for (int r = 0; r < nr; r++)
		{
			for (int c = 0; c < mc; c++)
			{
				if (-1 == dist[z][r][c])
				{
					cout << "-1"; return 0;
				}
				mx = max(mx, dist[z][r][c]);
			}
		}
	}
	cout << mx - 1;
	return 0;
}