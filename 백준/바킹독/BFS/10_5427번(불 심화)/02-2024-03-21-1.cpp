#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[1002][1002];
int df[1002][1002];
int dj[1002][1002];

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
		queue<pair<int, int>> qf;
		queue<pair<int, int>> qj;
		bool ss = false;
		int r, c = 0; // r행 c열
		cin >> c >> r; // w가로너비 열부터 h세로높이 행다음

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '.')
				{
					df[i][j] = -1;
					dj[i][j] = -1;
				}
				else if (board[i][j] == '*')
				{
					qf.push({ i,j });
					df[i][j] = 0;
				}
				else if (board[i][j] == '@')
				{
					qj.push({ i,j });
					dj[i][j] = 0;
					df[i][j] = -1;
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
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
				if (board[nx][ny] == '#' || df[nx][ny] != -1)continue;
				qf.push({ nx,ny }); df[nx][ny] = df[cur.X][cur.Y] + 1;
			}
		}


		while (!qj.empty() && !ss)
		{
			auto cur = qj.front(); qj.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				{
					cout << dj[cur.X][cur.Y] + 1 << '\n';
					ss = true;
					break;
				}
				if (board[nx][ny] == '#' || dj[nx][ny] != -1)continue;
				if (df[nx][ny] != -1 && dj[cur.X][cur.Y] + 1 >= df[nx][ny])continue;
				qj.push({ nx,ny }); dj[nx][ny] = dj[cur.X][cur.Y] + 1;
			}
		}
		if (!ss)
		{
			cout << "IMPOSSIBLE\n";
		}


		// 초기화
		for (int i = 0; i < r; i++)
		{
			fill(dj[i], dj[i] + c, 0);
			fill(df[i], df[i] + c, 0);
		}
	}


}