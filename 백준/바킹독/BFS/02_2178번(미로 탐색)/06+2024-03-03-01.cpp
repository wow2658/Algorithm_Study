#include <bits/stdc++.h>

using namespace std;

char board[102][102];
int dist[102][102];

int nr, mc;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

void Init()
{
	cin >> nr >> mc;

	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cin >> board[r][c];
			if ('1' == board[r][c]) dist[r][c] = -1;
		}
	}
}

void Bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 }); dist[0][0] = 1;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nxr = cur.first + dr[dir];
			int nxc = cur.second + dc[dir];
			if (nxr < 0 || nxr >= nr || nxc < 0 || nxc >= mc) continue;
			if ('0' == board[nxr][nxc] || -1 != dist[nxr][nxc]) continue;
			q.push({ nxr,nxc }); dist[nxr][nxc] = dist[cur.first][cur.second] + 1;
		}
	}
	cout << dist[nr - 1][mc - 1];
}

void Debug()
{
	cout << "\n";

	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cout << board[r][c] << " ";
		}
		cout << "\n";
	}

	cout << "\n"; cout << "\n";

	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < mc; c++)
		{
			cout << dist[r][c] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Init();
	Bfs();
	//Debug();
}