#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

string board[1002];
int distF[1002][1002];
int distJ[1002][1002];

int R, C;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> board[i];

	for (int i = 0; i < R; i++)
	{
		fill(distF[i], distF[i] + C, -1);
		fill(distJ[i], distJ[i] + C, -1);
	}

	queue<pair<int, int>> QF;
	queue<pair<int, int>> QJ;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 'F')
			{
				QF.push({ i,j }); distF[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				QJ.push({ i,j }); distJ[i][j] = 0;
			}
		}
	}

	while (!QF.empty())
	{
		auto cur = QF.front(); QF.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (distF[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			QF.push({ nx,ny }); distF[nx][ny] = distF[cur.X][cur.Y] + 1;
		}

	}

	while (!QJ.empty())
	{
		auto cur = QJ.front(); QJ.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << distJ[cur.X][cur.Y] + 1;
				return 0;
			}
			if (distJ[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (distF[nx][ny] >= 0 && distF[nx][ny] <= distJ[cur.X][cur.Y] + 1) continue;
			QJ.push({ nx,ny }); distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}