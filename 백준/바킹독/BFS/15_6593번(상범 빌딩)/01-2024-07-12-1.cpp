#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MX = 31; // 최대 빌딩 크기 (1 ≤ L, R, C ≤ 30)
int dx[6] = { 0, 0, 1, -1, 0, 0 }; // 동, 서, 남, 북, 상, 하 방향 배열
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int l, r, c; // 층 수, 행 수, 열 수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> l >> r >> c; // 빌딩의 층 수, 행 수, 열 수 입력
		if (l == 0 && r == 0 && c == 0) break; // 종료 조건

		queue<tuple<int, int, int>> Q; // BFS를 위한 큐 (층, 행, 열)

		char board[MX][MX][MX];		   // 빌딩을 나타내는 3차원 배열
		int dist[MX][MX][MX];		   // 거리 저장을 위한 3차원 배열
		bool isEscape = false;	       // 탈출 여부 확인

		// 3x3 배열 fill 초기화
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				fill(dist[i][j], dist[i][j] + c, -1); // 방문하지 않은 칸은 -1로 설정
			}
		}

		// 빌딩 입력 및 시작점(S) 찾기
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				for (int k = 0; k < c; ++k)
				{
					cin >> board[i][j][k];      // 빌딩 각 칸의 상태 입력
					if (board[i][j][k] == 'S')  // 시작점(S)인 경우
					{
						Q.push({ i, j, k });    // 큐에 시작점 추가
						dist[i][j][k] = 0;      // 시작점의 거리 -1에서 0으로 설정
					}
				}
			}
		}

		// BFS 탐색 시작
		while (!Q.empty())
		{
			auto cur = Q.front(); Q.pop();    // 큐의 앞 요소를 가져와 제거
			int curH, curX, curY;			  // 현재 위치
			tie(curH, curX, curY) = cur;      // 현재 위치를 층, 행, 열로 분해

			for (int dir = 0; dir < 6; ++dir) // 6방향 탐색
			{
				int nh = curH + dh[dir];      // 새로운 층
				int nx = curX + dx[dir];      // 새로운 행
				int ny = curY + dy[dir];      // 새로운 열

				// 범위를 벗어난 경우 무시
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l) continue;
				// 벽이거나 이미 방문한 경우 무시
				if (board[nh][nx][ny] == '#' || dist[nh][nx][ny] != -1) continue;

				dist[nh][nx][ny] = dist[curH][curX][curY] + 1; // 새로운 위치의 거리 갱신

				// 출구를 찾은 경우
				if (board[nh][nx][ny] == 'E')
				{
					cout << "Escaped in " << dist[nh][nx][ny] << " minute(s).\n"; // 탈출 시간 출력
					isEscape = true; // 탈출 성공
					break;			 // 탐색 종료
				}

				Q.push({ nh, nx, ny });      // 새로운 위치 큐에 추가
			}
			if (isEscape) break;			 // 탈출한 경우 반복 종료
		}
		if (!isEscape) cout << "Trapped!\n"; // 탈출하지 못한 경우 출력
	}
	return 0;
}
