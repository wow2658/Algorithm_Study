#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int dist[303][303];

int dr[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int dc[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };


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


		int r0, c0, r1, c1 = 0;
		cin >> r0 >> c0;
		cin >> r1 >> c1;

		queue<pair<int, int>> q;

		q.push({ r0,c0 }); dist[r0][c0] = 0;



		while (!q.empty() || dist[r1][c1] == -1)
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nr = cur.F + dr[dir];
				int nc = cur.S + dc[dir];
				if (nr < 0 || nr >= l || nc < 0 || nc >= l)continue;
				if (dist[nr][nc] != -1)continue;
				q.push({ nr,nc }); dist[nr][nc] = dist[cur.F][cur.S] + 1;

			}
		}

		cout << dist[r1][c1] << '\n';



		for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, 0);
	}



}