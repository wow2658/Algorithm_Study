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
		int my, nh, k = 0; // m가로열 n세로행 [nh][my]

		cin >> my >> nh >> k;


		while (k--)
		{
			int m1, n1 = 0;
			cin >> m1 >> n1;
			board[n1][m1] = 1;
			dist[n1][m1] = -1;

		}

		/*	for (int i = 0; i < nh; i++)
			{
				for (int j = 0; j < my; j++)
				{
					cout << board[i][j] << ' ';
				}
				cout << '\n';
			}

			for (int i = 0; i < nh; i++)
			{
				for (int j = 0; j < my; j++)
				{
					cout << dist[i][j] << ' ';
				}
				cout << '\n';
			}*/


		int num = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < nh; i++)
		{
			for (int j = 0; j < my; j++)
			{
				if (board[i][j] == 1 && dist[i][j] == -1)
				{
					q.push({ i,j }); dist[i][j] = 1; num++;

					while (!q.empty())
					{
						auto cur = q.front(); q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int ny = cur.X + dy[dir];
							int nx = cur.Y + dx[dir];
							if (nx < 0 || nx >= my || ny < 0 || ny >= nh)continue;
							if (board[ny][nx] != 1 || dist[ny][nx] != -1)continue;
							q.push({ ny,nx }); dist[ny][nx] = dist[cur.Y][cur.X] + 1;
						}
					}

				}

			}
		}

		cout << num << "\n";



		for (int i = 0; i < nh; i++)
		{
			fill(board[i], board[i] + my, 0);
			fill(dist[i], dist[i] + my, 0);
		}
	}
}