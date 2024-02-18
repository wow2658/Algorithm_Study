#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[304][304];

int dx[8] = { 2, 1,-1,-2,-2,-1, 1, 2 };
int dy[8] = { 1, 2, 2, 1,-1,-2,-2,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	while (t--)
	{
		int l = 0;
		cin >> l;
		for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);

		int x0, y0, x1, y1 = 0;
		cin >> x0 >> y0;
		cin >> x1 >> y1;

		queue<pair<int, int>> q;
		q.push({ x0,y0 }); dist[x0][y0] = 0;
		//while (dist[x1][y1] == 0)
		while (!q.empty() && dist[x1][y1] == -1)
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (dist[nx][ny] > -1) continue;
				q.push({ nx,ny }); dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}

		//for (int i = 0; i < l; i++)
		//{
		//	for (int j = 0; j < l; j++)
		//	{
		//		cout << dist[i][j] << " ";

		//	}
		//	cout << "\n";
		//}
		cout << dist[x1][y1] << "\n";

		//ÃÊ±âÈ­
		for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, 0);
	}

}