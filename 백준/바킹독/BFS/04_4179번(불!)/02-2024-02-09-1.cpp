#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r, c;

string board[1002];
int distj[1002][1002];
int distf[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
		fill(distj[i], distj[i] + c, -1);
		fill(distf[i], distf[i] + c, -1);
	}

	queue<pair<int, int>> qj;
	queue<pair<int, int>> qf;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'J')
			{
				qj.push({ i,j });
				distj[i][j] = 0;
			}
			if (board[i][j] == 'F')
			{
				qf.push({ i,j });
				distf[i][j] = 0;
			}
		}
	}

	while (!qf.empty())
	{
		auto cur = qf.front(); qf.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (distf[nx][ny] != -1 || board[nx][ny] == '#') continue;
			qf.push({ nx,ny }); distf[nx][ny] = distf[cur.X][cur.Y] + 1;
		}
	}

	while (!qj.empty())
	{
		auto cur = qj.front(); qj.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << distj[cur.X][cur.Y] + 1;
				return 0;
			}
			if (distj[nx][ny] != -1 || board[nx][ny] == '#') continue;
			if (distj[nx][ny] >= distf[nx][ny]) continue;
			qj.push({ nx,ny }); distj[nx][ny] = distj[cur.X][cur.Y] + 1;
		}
	}
	cout << "IMPOSSIBLE";


	//for (int i = 0; i < r; i++)
	//{
	//	for (int j = 0; j < c; j++)
	//	{
	//		cout << distj[i][j] << " ";

	//	}
	//	cout << "\n";
	//}

	//for (int i = 0; i < r; i++)
	//{
	//	for (int j = 0; j < c; j++)
	//	{
	//		cout << distf[i][j] << " ";

	//	}
	//	cout << "\n";
	//}
}