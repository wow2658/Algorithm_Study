#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int board[102][102][102];
int dist[102][102][102];

int dr[6] = { 1,-1,0,0,0,0, };
int dc[6] = { 0,0,1,-1,0,0, };
int dz[6] = { 0,0,0,0,1,-1 };
int r, c, z;
queue<tuple<int, int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> c >> r >> z;

	for (int h = 0; h < z; h++)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> board[i][j][h];
				if (board[i][j][h] == 0)
				{
					dist[i][j][h] = -1;
				}
				else if (board[i][j][h] == 1)
				{
					q.push({ i,j,h });
				}
				else if (board[i][j][h] == -1)
				{
					//
				}

			}
		}
	}


	//for (int h = 0; h < z; h++)
	//{
	//	for (int i = 0; i < r; i++)
	//	{
	//		for (int j = 0; j < c; j++)
	//		{
	//			cout << board[i][j][h] << " ";

	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//}

	//cout << "\n";
	//cout << "\n";


	//for (int h = 0; h < z; h++)
	//{
	//	for (int i = 0; i < r; i++)
	//	{
	//		for (int j = 0; j < c; j++)
	//		{
	//			cout << dist[i][j][h] << " ";

	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//}


	int cr, cc, cz = 0;

	while (!q.empty())
	{
		tie(cr, cc, cz) = q.front(); q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nr = cr + dr[dir];
			int nc = cc + dc[dir];
			int nz = cz + dz[dir];
			if (dist[nr][nc][nz] != -1 || board[nr][nc][nz] != 0) continue;
			if (nr < 0 || nr >= r || nc < 0 || nc >= c || nz < 0 || nz >= z) continue;
			q.push({ nr,nc,nz }); dist[nr][nc][nz] = dist[cr][cc][cz] + 1;
		}
	}

	int mx = 0;
	for (int h = 0; h < z; h++)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (dist[i][j][h] == -1)
				{
					cout << -1;
					return 0;
				}
				mx = max(mx, dist[i][j][h]);
			}
		}
	}
	cout << mx;

}