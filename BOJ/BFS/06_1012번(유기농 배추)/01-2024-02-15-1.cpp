#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool board[2502][2502];
bool vis[2502][2502];

int t;
int num;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--)
	{
		int n = 0; //세로길이 층행
		int m = 0; //가로길이 호열
		int k = 0; //직접 심는 갯수

		cin >> m >> n >> k;



		while (k--)
		{
			int m1 = 0;
			int n1 = 0;
			cin >> m1 >> n1;
			if (n1 < 0 || n1 >= n || m1 < 0 || m1 >= m) return 0;

			board[n1][m1] = 1; // 내기준으로 생각-> 아래로 x(n) 우로 y(m)
		}

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << board[i][j] << " ";

		//	}
		//	cout << '\n';
		//}
		// 초기 세팅 완료

		queue<pair<int, int>> Q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 1 && vis[i][j] == 0)
				{
					Q.push({ i,j }); vis[i][j] = 1; num++;
					while (!Q.empty())
					{
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
							Q.push({ nx,ny }); vis[nx][ny] = 1;
						}

					}
				}
			}
		}
		cout << num << '\n';

		// 초기화
		num = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				vis[i][j] = 0;
				board[i][j] = 0;
			}
		}
	}


}