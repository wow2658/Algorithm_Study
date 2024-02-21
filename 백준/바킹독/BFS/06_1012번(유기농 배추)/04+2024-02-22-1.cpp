#include <bits/stdc++.h>
using namespace std;

int board[52][52];
int dist[52][52];
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
		int nh, my, k = 0;
		cin >> my >> nh >> k;

		while (k--)
		{
			int m1, n1 = 0;
			cin >> m1 >> n1;

			board[n1][m1] = 1;
			dist[n1][m1] = -1;


		}
		queue<pair<int, int>> q;
		int num = 0;
		for (int i = 0; i < nh; i++)
		{
			for (int j = 0; j < my; j++)
			{
				if (board[i][j] == 1 && dist[i][j] == -1)
				{
					q.push({ j,i }); dist[i][j] = 1;
					num++;

					while (!q.empty())
					{
						auto c = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int fmy = c.first + dy[dir];
							int snh = c.second + dx[dir];
							if (fmy < 0 || fmy >= my || snh < 0 || snh >= nh) continue;
							if (board[snh][fmy] != 1 || dist[snh][fmy] != -1) continue;
							q.push({ fmy,snh });
							dist[snh][fmy] = dist[c.second][c.first] + 1;

						}
					}
				}
			}
		}

		cout << num << "\n";

		for (int i = 0; i < nh; i++) fill(board[i], board[i] + my, 0);
		for (int i = 0; i < nh; i++) fill(dist[i], dist[i] + my, 0);

		/*for (int i = 0; i < nh; i++)
		{
			for (int j = 0; j < my; j++)
			{
				cout<< board[i][j] << ' ';
			}
				cout<< '\n';
		}
		cout << '\n';
		cout << '\n';
		for (int i = 0; i < nh; i++)
		{
			for (int j = 0; j < my; j++)
			{
				cout << dist[i][j] << ' ';
			}
			cout << '\n';
		}*/
	}

}