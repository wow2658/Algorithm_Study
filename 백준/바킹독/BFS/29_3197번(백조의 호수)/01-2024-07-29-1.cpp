#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

const int MX = 1520;
int r, c, days = 0;
int dx[4] = { 1, 0, -1, 0 }; // 네 방향 이동을 위한 배열 (상하좌우)
int dy[4] = { 0, 1, 0, -1 };
int vis[MX][MX];     // 백조가 현재 어디를 방문했는지를 기록하는 배열
					 // 백조가 이동할 때 BFS를 통해 사용되며, 이미 방문한 위치는 다시 방문하지 않도록 한다.
int visited[MX][MX]; // 빙판이 녹는 과정을 기록하는 배열
				     // 빙판을 녹일 때 BFS를 통해 사용되며, 이미 녹이거나 처리한 위치는 다시 처리하지 않도록 한다.

string board[MX];        // 호수 상태를 기록하는 배열
bool isPossible = false; // 백조들이 만날 수 있는지 여부

queue<pair<int, int>> waterQ, nextWaterQ; // 현재 물 공간과 다음 날 녹을 빙판을 저장하는 큐
queue<pair<int, int>> swanQ, nextSwanQ;   // 백조의 현재 위치와 다음 날 이동할 위치를 저장하는 큐

// 경계 조건 확인 함수
bool OOB(int a, int b)
{
	return a < 0 || a >= r || b < 0 || b >= c;
}

// 빙판을 녹이는 함수
void meltIce()
{
	while (!waterQ.empty())
	{
		auto cur = waterQ.front(); waterQ.pop();
		visited[cur.X][cur.Y] = 1; // 현재 위치를 방문 처리

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || visited[nx][ny]) continue;

			if (board[nx][ny] == 'X') nextWaterQ.push({ nx, ny }); // 다음에 녹을 빙판을 저장. 
			visited[nx][ny] = 1; // 범위 내 미방문 했던곳만 방문 처리.
		}
	}
	
	// 녹이기로한 빙판을 실제로 물로 변경
	while (!nextWaterQ.empty())
	{
		auto cur = nextWaterQ.front(); nextWaterQ.pop();
		board[cur.X][cur.Y] = '.'; // 빙판을 물로 변경
		waterQ.push(cur); // 물 공간으로 큐에 저장
	}
	days++; // 하루가 지남
}

void meltIceDirect()
{
	auto cur = waterQ.front(); waterQ.pop();
	visited[cur.X][cur.Y] = 1; // 현재 위치를 방문 처리

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if (OOB(nx, ny) || visited[nx][ny]) continue;

		if (board[nx][ny] == 'X')
		{
			board[cur.X][cur.Y] = '.';  
			waterQ.push({ nx, ny }); 
		}
		visited[nx][ny] = 1; 
	}
	days++;
}

// 백조 찾는 함수
void findSwan()
{
	while (!swanQ.empty())
	{
		// 이동
		auto cur = swanQ.front(); swanQ.pop();

		// 탐색
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;

			if (board[nx][ny] == 'X')
			{
				vis[nx][ny] = 1;
				nextSwanQ.push({ nx, ny }); // 다음 이동할 장소로 저장
				continue;
			}
			else if (board[nx][ny] == 'L')
			{
				isPossible = true; // 백조가 만남
				break; // 더 이상 탐색할 필요 없음
			}
			vis[nx][ny] = 1; // 현재 위치를 방문 처리
			swanQ.push({ nx, ny }); // 다음 위치를 큐에 저장
		}
	}

	// 다음 날 이동할 백조 위치를 현재 백조 큐에 저장
	while (!nextSwanQ.empty())
	{
		auto cur = nextSwanQ.front(); nextSwanQ.pop();
		swanQ.push({ cur.X, cur.Y });
	}
}

// 백조 찾는 함수
void findSwanDirect()
{
	while (!swanQ.empty())
	{
		// 이동
		auto cur = swanQ.front(); swanQ.pop();

		// 탐색
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;

			if (board[nx][ny] == 'X')
			{
				vis[nx][ny] = 1;
				swanQ.push({ nx, ny }); // 다음 이동할 장소로 저장
				continue;
			}
			else if (board[nx][ny] == 'L')
			{
				isPossible = true; // 백조가 만남
				break; // 더 이상 탐색할 필요 없음
			}
			vis[nx][ny] = 1; // 현재 위치를 방문 처리
			swanQ.push({ nx, ny }); // 다음 위치를 큐에 저장
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c; // 행과 열 입력

	pair<int, int> swanStart; // 백조 시작 위치

	// 호수 상태 입력 및 초기화
	for (int i = 0; i < r; i++) cin >> board[i];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'L')
			{
				swanStart = { i, j }; // 백조 시작 위치 저장
			}
			if (board[i][j] != 'X') waterQ.push({ i, j }); // 물 공간 저장. 빙판이 아니라 물을 저장한다.

		}
	}

	swanQ.push(swanStart); // 백조 시작 위치 큐에 저장
	board[swanStart.X][swanStart.Y] = '.'; // 백조 위치를 물로 변경
	vis[swanStart.X][swanStart.Y] = 1; // 백조의 시작 위치를 방문 처리


	// 백조들이 만날 때까지 반복
	while (!isPossible)
	{
		//meltIce();     // 빙판 녹이기 q 2번 활용
		meltIceDirect(); // q 1번 활용
		findSwan();			// 백조 찾기 q 2번
		//findSwanDirect(); // q 1번
	}

	cout << days; // 결과 출력
}

/*
*

- 문제 상황
1. 빙판과 백조: 이 문제는 빙판이 녹아가는 과정을 시뮬레이션하면서 두 백조가 만나는 시점을 찾는 문제이다.

2. 직접 탐색의 비효율성: 매번 빙판을 전체적으로 녹이고 두 백조의 위치가 연결되어 있는지를 직접 확인하는 방법은 비효율적이다. 이 방법은 최악의 경우
O(max(R×C)) 시간복잡도를 가지며, 이는 입력 크기 R,C 가 최대 1500일 때 1500^3 연산을 필요로 하여 시간 초과를 초래할 수 있다.

- 효율적인 접근 방법
1. 빙판 녹이기 최적화:

문제: 매일 모든 얼음을 녹이는 것이 비효율적이다.
해결책: "이전 날에 녹은 얼음 주변"만 확인하여 새로운 빙판이 녹을 위치를 추적한다. 즉, 매일 빙판을 한 번에 다 녹이지 않고, 한 번에 한 레이어의 빙판만 처리한다.
설명: 얼음이 녹을 때, 이전에 물이 된 칸(즉, 물과 접촉한 얼음) 주변만을 탐색하여 다음에 녹을 얼음을 찾는다. 이렇게 하면 매일 모든 얼음을 새로 확인하지 않고, 이미 처리된 얼음 주변만 확인하여 효율적으로 처리할 수 있다.

2. 백조의 위치 탐색 최적화:

문제: 백조가 이동하는 경우 매일마다 백조의 현재 위치에서 BFS를 수행하여 이동할 수 있는지를 확인하는 것이 비효율적이다.
해결책: 백조가 이동할 때 얼음을 마주칠 경우, 그 얼음은 다음 날에 녹을 것이므로 그 위치를 임시로 기억해 두고, 그 위치에서 백조의 BFS를 처리하는 과정에 추가한다.
설명: 백조의 이동 과정에서 마주치는 얼음을 다음 날에 녹을 위치로 추가하여, 백조가 다음 날에 갈 수 있는 위치로 변환한다. 이렇게 하면 매일 백조의 위치와 이동 경로를 효율적으로 추적할 수 있다.

- 요약
기존 방법: 매일 모든 얼음을 녹이고 모든 백조의 연결 여부를 확인하는 방법은 비효율적이며 시간 초과를 초래할 수 있다.
효율적인 방법: 
1) 얼음이 녹는 과정을 단계별로 최적화하여, 매일 새로 녹을 얼음만 확인한다.
2) 백조가 이동하는 과정에서 얼음의 다음 날 녹을 위치를 미리 추적하여 BFS 탐색을 효율적으로 수행한다.

*
*/
