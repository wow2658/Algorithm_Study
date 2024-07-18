#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

const int MX = 102;
int board[MX][MX];      // 지도를 저장할 배열
int vis[MX][MX];        // 방문 여부를 저장할 배열
int dist[MX][MX];       // 거리 정보를 저장할 배열
int dx[4] = { 1, -1, 0, 0 }; // 방향 배열 (상하좌우)
int dy[4] = { 0, 0, 1, -1 }; // 방향 배열 (상하좌우)
int n; // 지도의 크기

// BFS를 사용하여 섬을 구분하는 함수
void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> Q; // BFS를 위한 큐
	Q.push({ x, y });        // 시작점을 큐에 추가
	vis[x][y] = 1;           // 시작점 방문 표시
	board[x][y] = cnt;       // 섬 번호 지정

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop(); // 큐에서 현재 위치를 꺼냄

		for (int dir = 0; dir < 4; dir++) // 상하좌우로 이동
		{
			int nx = cur.X + dx[dir]; // 다음 위치 계산
			int ny = cur.Y + dy[dir]; // 다음 위치 계산
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위를 벗어나면 무시
			if (vis[nx][ny] || board[nx][ny] == 0) continue; // 이미 방문했거나 바다면 무시

			vis[nx][ny] = 1; // 방문 표시
			board[nx][ny] = cnt; // 섬 번호 지정
			Q.push({ nx, ny }); // 다음 위치를 큐에 추가
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; // 지도의 크기 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j]; // 지도 정보 입력
		}
	}

	int cnt = 0; // 섬 번호 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 && !vis[i][j]) // 육지이면서 아직 방문하지 않은 경우 (vis[i][j] == 0)
			{
				bfs(i, j, ++cnt); // BFS를 사용하여 섬 구분
			}
		}
	}

	/*

1 1 1 0 0 0 0 2 2 2
1 1 1 1 0 0 0 0 2 2
1 0 1 1 0 0 0 0 2 2
0 0 1 1 1 0 0 0 0 2
0 0 0 1 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0
0 0 0 0 3 3 0 0 0 0
0 0 0 0 3 3 3 0 0 0
0 0 0 0 0 0 0 0 0 0

0   0  0 -1  -1 -1  -1  0  0  0
0   0  0  0  -1 -1  -1 -1  0  0
0  -1  0  0  -1 -1  -1 -1  0  0
-1 -1  0  0   0 -1  -1 -1 -1  0
-1 -1 -1  0  -1 -1  -1 -1 -1  0
-1 -1 -1 -1  -1 -1  -1 -1 -1  0
-1 -1 -1 -1  -1 -1  -1 -1 -1 -1
-1 -1 -1 -1   0  0  -1 -1 -1 -1
-1 -1 -1 -1   0  0   0 -1 -1 -1
-1 -1 -1 -1  -1 -1  -1 -1 -1 -1

1 1 1 1 1 2 2 2 2 2
1 1 1 1 1 1 2 2 2 2
1 1 1 1 1 1 2 2 2 2
1 1 1 1 1 1 1 2 2 2
1 1 1 1 1 1 1 2 2 2
1 1 1 1 1 3 2 2 2 2
1 1 1 1 3 3 3 2 2 2
3 3 3 3 3 3 3 3 2 2
3 3 3 3 3 3 3 3 3 2
3 3 3 3 3 3 3 3 3 2


0 0 0 1 2 2 1 0 0 0
0 0 0 0 1 2 2 1 0 0
0 1 0 0 1 2 2 1 0 0
1 1 0 0 0 1 2 2 1 0
2 2 1 0 1 2 3 2 1 0
3 3 2 1 2 2 3 2 1 0
4 4 3 2 1 1 2 3 2 1
4 3 2 1 0 0 1 2 3 2
4 3 2 1 0 0 0 1 2 3
5 4 3 2 1 1 1 2 3 4

	*/


	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 0)
			{
				dist[i][j] = 0; // 육지의 초기 거리 설정
				Q.push({ i, j }); // 큐에 추가
			}
			else
			{
				dist[i][j] = -1; // 바다의 초기 거리 설정
			}
		}
	}

	cout << "start board \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "start dist \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";

	}

	int ans = INT_MAX; // 최소 다리 길이 초기화
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop(); // 큐에서 현재 위치를 꺼냄

		for (int dir = 0; dir < 4; dir++) // 상하좌우로 이동
		{
			int nx = cur.X + dx[dir]; // 다음 위치 계산
			int ny = cur.Y + dy[dir]; // 다음 위치 계산
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위를 벗어나면 무시
			if (dist[nx][ny] != -1) continue; // 이미 방문한 경우 무시

			dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리 갱신

			board[nx][ny] = board[cur.X][cur.Y]; // 섬 번호 갱신

			Q.push({ nx, ny }); // 다음 위치를 큐에 추가
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int dir = 0; dir < 4; dir++) // 상하좌우로 이동
			{
				int nx = i + dx[dir]; // 다음 위치 계산
				int ny = j + dy[dir]; // 다음 위치 계산
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;   // 범위를 벗어나면 무시
				if ( (board[i][j] != board[nx][ny]) && board[nx][ny] != 0) // 다른 섬인 경우
				{
					ans = min(ans, dist[i][j] + dist[nx][ny]); // 최소 다리 길이 갱신
				}
			}
		}
	}

	cout << "new board \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "new dist \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	cout << ans << '\n'; // 결과 출력
	return 0;
}
