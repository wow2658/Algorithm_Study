#include <iostream>
#include <queue>

using namespace std;

bool board[305][305];
int dist[305][305];

int dr[8] = { -1,-2,-2,-1,1,2,2,1 };
int dc[8] = { 2,1,-1,-2,-2,-1,1,2 };

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t = 0; // test
	cin >> t;
	while (t--)
	{
		int l = 0; // length
		cin >> l;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				board[i][j] = 0;
				dist[i][j] = -1;
			}
		}

		queue<pair<int, int>> q;

		int sr = 0, sc = 0; // start
		cin >> sr >> sc;
		board[sr][sc] = 1;

		int gr = 0, gc = 0; // goal
		cin >> gr >> gc;
		board[gr][gc] = 1;

		q.push({ sr,sc }); 	dist[sr][sc] = 0;

		while (-1 == dist[gr][gc] || !q.empty())
		{
			auto cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				if (nr < 0 || nr >= l || nc < 0 || nc >= l) continue;
				if (-1 != dist[nr][nc]) continue;
				q.push({ nr,nc }); dist[nr][nc] = dist[cur.first][cur.second] + 1;
			}

		}
		cout << dist[gr][gc] << "\n";

		// fill 함수 쓰는방법을 까먹었는지 먹히질 않는다
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				board[i][j] = 0;
				dist[i][j] = 0;
			}
		}
		// fill함수 잘못된 사용 예

		//fill(dist[l], dist[l] + l, 0);  ->  for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, 0);

	}


	return 0;
}
