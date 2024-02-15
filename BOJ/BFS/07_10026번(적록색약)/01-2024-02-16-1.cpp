#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];

bool vr[102][102];
bool vg[102][102];
bool vb[102][102];

bool vrg[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int nr, ng, nb, nrg;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> board[i];

	queue<pair<int, int>> qr;
	queue<pair<int, int>> qg;
	queue<pair<int, int>> qb;

	queue<pair<int, int>> qrg;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R' && vr[i][j] == 0)
			{
				qr.push({ i,j }); vr[i][j] = 1; nr++;
				while (!qr.empty())
				{
					auto cur = qr.front(); qr.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != 'R' || vr[nx][ny] == 1) continue;
						qr.push({ nx,ny }); vr[nx][ny] = 1;
					}

				}
			}
			else if (board[i][j] == 'G' && vg[i][j] == 0)
			{
				qg.push({ i,j }); vg[i][j] = 1; ng++;
				while (!qg.empty())
				{
					auto cur = qg.front(); qg.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != 'G' || vg[nx][ny] == 1) continue;
						qg.push({ nx,ny }); vg[nx][ny] = 1;
					}

				}
			}
			else if (board[i][j] == 'B' && vb[i][j] == 0)
			{
				qb.push({ i,j }); vb[i][j] = 1; nb++;
				while (!qb.empty())
				{
					auto cur = qb.front(); qb.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != 'B' || vb[nx][ny] == 1) continue;
						qb.push({ nx,ny }); vb[nx][ny] = 1;
					}

				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R' && vrg[i][j] == 0)
			{
				qrg.push({ i,j }); vrg[i][j] = 1; nrg++;
				while (!qrg.empty())
				{
					auto cur = qrg.front(); qrg.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] == 'B' || vrg[nx][ny] == 1) continue;
						qrg.push({ nx,ny }); vrg[nx][ny] = 1;
					}

				}
			}
		}
	}
	cout << nr + ng + nb << " " << nrg + nb;



}