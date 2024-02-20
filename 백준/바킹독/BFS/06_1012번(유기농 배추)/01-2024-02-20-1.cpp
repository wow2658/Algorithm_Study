#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[51][51];
int dist[51][51];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	cin >> t;

	while (t--)
	{
		int m, n, k = 0; // m가로열 n세로행 [y][x]

		cin >> m >> n >> k;


		while (k--)
		{
			int m1, n1 = 0;
			cin >> m1 >> n1;
			board[n1][m1] = 1;
			dist[n1][m1] = -1;

		}

		int num = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && dist[i][j] == -1)
				{
					q.push({ i,j }); dist[i][j] = 1; num++;

					while (!q.empty())
					{
						auto cur = q.front(); q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
							if (board[ny][nx] != 1 || dist[ny][nx] != -1)continue;
							q.push({ ny,nx }); dist[ny][nx] = dist[cur.Y][cur.X] + 1;
						}
					}

				}

			}
		}

		cout << num << "\n";




	}
}