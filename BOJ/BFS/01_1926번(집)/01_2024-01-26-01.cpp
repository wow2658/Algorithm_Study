 // http://boj.kr/2edfa3c97260480d81e3133d389c119f

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502]; //왜 501이 아니라 502일까? '\n'에 더해서 여유를 하나 더 두는건가?
bool vis[502][502];
int n,m;

int dx[4] = {1,0,-1,0}; // x는 행(지하로 플러스되는 층수)
int dy[4] = {0,1,0,-1}; // y는 열(오른쪽으로 증가하는 호수) 마치 uv처럼  

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for (int i = 0; i < n; i ++ )
	{
		for (int j = 0; j < m; j++)
		{
			cin>>board[i][j];
		}
	}
	int mx = 0;  // 변수명을 max로 써버리면 STL max랑 충돌이 나는것 같다 로컬 변수니 꼭 0으로 초기화
	int num = 0; // 여기에서 Q와 area를 초기화 해두지 않는 이유는 각 영역마다 새롭게 시작하기 위해

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] || board[i][j] == 0) continue; // board[i][j] != 1와 차이가 있을까?
			queue<pair<int,int>> Q;
			vis[i][j] = 1; Q.push({i,j});
			num++; // 시작점 안착과 동시에 개수에 반영
      
			int area = 0;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop(); area++;
				for (int dir = 0; dir < 4; dir++) // 하 우 상 좌
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
					if(vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1; Q.push({nx,ny});
				}
			}
			mx = max(mx,area); // 모험 한번 끝났으니 정산
		}
	}
	cout << num << '\n' << mx;
}
