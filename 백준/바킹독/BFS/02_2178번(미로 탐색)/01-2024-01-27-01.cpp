// https://www.acmicpc.net/problem/2178 https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/2178.cpp

#include <bits/stdc++.h>
using namespace std;
#define X first // 세밐콜론 실수 하지말자
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

string board[102]; // [][] 로 틀림 1. 왜 string 인가?
int dist[102][102]; // for문 에서 틀림
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1); // [][] 로 틀림 2. fill 복습

	// 이 문제는 끊겨있는 덩어리 찾는 문제가 아니라 쭉 이어져 있어서 시작점을 찾지 않는다.

	queue<pair<int, int>> Q; // 3. 여긴 또 왜 string,int이 아닐까?
	Q.push({ 0,0 }); dist[0][0] = 0; // -1 이었던 애들이라 시작할때 0넣나봄. 나는 ++해줬었는데 이것도 맞았을거 같다.

	while (!Q.empty())
	{
		auto cur = Q.front(); // pair<int,int>이 아니라 4. 왜 auto? 
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 솔직히 까먹었었다.
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // 4. 왜 '1'일까? [][]는 언제부터 쓸수있게 된걸까
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx,ny});

		}

	}
	cout << dist[n-1][m-1]+1; // 5. 왜 +1 인가? 시작을 -1로 시작하고 시작칸도 거리에 포함시켜서?




}
