#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m, year;
int area[303][303];
int vis[303][303];

int dx[] = { 1, 0, -1, 0 };  // 남, 동, 북, 서 방향
int dy[] = { 0, 1, 0, -1 };  // 남, 동, 북, 서 방향

// 배열 인덱스가 유효한지 확인
bool check(int i, int j)
{
	return (i >= 0 && i < n && j >= 0 && j < m);
}

// 방문 배열 초기화
void initvis()
{
	for (int i = 0; i < n; i++)
	{
		fill(vis[i], vis[i] + m, 0);
	}
}

// 1년의 시간 흐름을 진행
void melting()
{
	int zero[303][303] = { 0 };  // 빙산 주변의 바다(0)의 개수를 저장할 배열 초기화

	// 모든 셀을 순회
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (area[i][j] == 0) continue;  // 현재 셀이 바다(0)인 경우 건너뜀

			// 현재 셀이 빙산인 경우, 주변 4방향을 확인
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];  // 새로운 x 좌표 (현재 위치에서 방향 이동)
				int ny = j + dy[dir];  // 새로운 y 좌표 (현재 위치에서 방향 이동)

				// 새로운 좌표가 유효한 범위 내에 있고, 그 셀이 바다(0)인 경우
				if (check(nx, ny) && area[nx][ny] == 0)
				{
					zero[i][j]++;  // 현재 셀의 주변 바다 개수 증가
				}
			}
		}
	}

	// 모든 셀을 다시 순회하면서 빙산의 높이를 감소시킴
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 주변 바다 개수만큼 빙산의 높이를 감소시키되, 0보다 작아지지 않도록 함
			area[i][j] = max(0, area[i][j] - zero[i][j]);
		}
	}
}


// 빙산의 상태를 확인
// 0 : 빙산이 다 녹음, 1 : 아직 한 덩어리, 2 : 분리됨
int status()
{
	int x = -1, y = -1;   // 빙산의 임의의 좌표를 저장할 변수, 초기값은 유효하지 않은 값으로 설정
	int cnt1 = 0;         // 빙산의 총 개수

	// 빙산이 남아있는 아무 칸이나 선택
	for (int i = 0; i < n; i++)   // 행을 순회
	{
		for (int j = 0; j < m; j++)   // 열을 순회
		{
			if (area[i][j])   // 빙산이 존재하는 칸인 경우(0이 아닌 경우)
			{
				x = i;   // 빙산이 있는 좌표 x 저장
				y = j;   // 빙산이 있는 좌표 y 저장
				cnt1++;  // 빙산의 총 개수 증가
			}
		}
	}

	if (cnt1 == 0)   // 빙산이 남아있는 칸이 없는 경우
	{
		return 0;    // 빙산이 다 녹았음을 의미하는 0을 반환
	}

	int cnt2 = 0;         // (x, y)와 연결된 빙산의 수
	queue<pair<int, int>> q;  // BFS를 위한 큐
	vis[x][y] = 1;        // 현재 위치 방문 표시. 여기까지 왔다는건 x,y가 업데이트 되었다는 것이니까.
	q.push({ x, y });     // 큐에 현재 좌표 추가

	while (!q.empty())    // 큐가 빌 때까지 반복
	{
		auto cur = q.front();   // 큐의 맨 앞 좌표를 가져옴
		q.pop();                // 큐에서 제거
		cnt2++;                 // 연결된 빙산의 수 증가

		for (int i = 0; i < 4; i++)   // 네 방향으로 탐색
		{
			int nx = cur.X + dx[i];   // 새로운 x 좌표
			int ny = cur.Y + dy[i];   // 새로운 y 좌표

			// 새로운 좌표가 유효한 범위 밖에 있고, 처음 방문하는 빙산이 아니고, 빙산이 존재하는 경우가 아니면
			if (!check(nx, ny) || vis[nx][ny] == 1 || area[nx][ny] <= 0)
			{
				continue;   // 조건에 맞지 않으니까 건너뜀
			}

			vis[nx][ny] = 1;      // 새로운 좌표 방문 표시
			q.push({ nx, ny });   // 큐에 새로운 좌표 추가
		}
	}

	if (cnt1 == cnt2)   // 전체 빙산의 수와 연결된 빙산의 수가 일치하는 경우
	{
		return 1;       // 아직 한 덩어리임을 의미하는 1을 반환
	}

	return 2;   // 빙산이 여러 덩어리로 분리되었음을 의미하는 2를 반환
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> area[i][j];
		}
	}

	while (true)
	{
		year++; // 1년 추가
		melting(); // 빙산 녹이기
		initvis(); // 방문배열 초기화
		int check = status(); // 빙산의 상태 확인

		if (check == 0)
		{
			cout << 0;
			return 0;
		}
		else if (check == 1)
		{
			continue; // 아직 한 덩이
		}
		else
		{
			break; // check = 2, 분리됨
		}
	}

	cout << year;
	return 0;
}
