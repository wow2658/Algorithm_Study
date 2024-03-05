#include <bits/stdc++.h>

using namespace std;

int rr, cc;
int dr[4]{ 1,0,-1,0 };
int dc[4]{ 0,1,0,-1 };

char board[1002][1002];
int distJ[1002][1002];
int distF[1002][1002];


void bfs(queue<pair<int, int>>& Q, int _dist[][1002])
{

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nxr = cur.first + dr[dir];
			int nxc = cur.second + dc[dir];
			if (nxr < 0 || nxr >= rr || nxc < 0 || nxc >= cc) continue;
			if ('#' == board[nxr][nxc] || -1 != _dist[nxr][nxc]) continue;
			Q.push({ nxr,nxc }); _dist[nxr][nxc] = _dist[cur.first][cur.second] + 1;
		}
	}
}

int bfs(queue<pair<int, int>>& Q, int _distJ[][1002], int _distF[][1002])
{

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nxr = cur.first + dr[dir];
			int nxc = cur.second + dc[dir];
			if (nxr < 0 || nxr >= rr || nxc < 0 || nxc >= cc)
			{
				cout << _distJ[cur.first][cur.second] + 1;
				return 1;
			}
			if ('#' == board[nxr][nxc] || -1 != _distJ[nxr][nxc]) continue;
			if (-1 != _distF[nxr][nxc] && _distJ[cur.first][cur.second] + 1 >= _distF[nxr][nxc]) continue;
			Q.push({ nxr,nxc }); _distJ[nxr][nxc] = _distJ[cur.first][cur.second] + 1;
		}
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> qj;
	queue<pair<int, int>> qf;

	cin >> rr >> cc;
	for (int r = 0; r < rr; r++)
	{
		for (int c = 0; c < cc; c++)
		{
			cin >> board[r][c];

			if ('.' == board[r][c])
			{
				distJ[r][c] = -1;	distF[r][c] = -1;
			}
			else if ('J' == board[r][c])
			{
				distJ[r][c] = 0;	qj.push({ r,c });
				distF[r][c] = -1;
			}
			else if ('F' == board[r][c])
			{
				qf.push({ r,c });		distF[r][c] = 0;
			}
		}
	}

	bfs(qf, distF);

	//for (int r = 0; r < rr; r++)
	//{
	//	for (int c = 0; c < cc; c++)
	//	{
	//		cout<< distF[r][c] << " ";
	//	}
	//	cout << '\n';
	//}
	int result = bfs(qj, distJ, distF);
	/*for (int r = 0; r < rr; r++)
	{
		for (int c = 0; c < cc; c++)
		{
			cout << distJ[r][c] << " ";
		}
		cout << '\n';
	}*/
	if (1 == result) return 0;

	cout << "IMPOSSIBLE\n";


}