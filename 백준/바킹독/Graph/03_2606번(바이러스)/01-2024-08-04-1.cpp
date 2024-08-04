#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int v, e, a, b;        // 정점의 수(v), 간선의 수(e), 간선의 양 끝점(a, b)
vector<int> adj[105];  // 인접 리스트 (그래프 표현)
int vis[105];          // 방문 여부 배열
int ans = 0;           // 바이러스에 감염된 컴퓨터 수

// 깊이 우선 탐색 (DFS) 함수
void dfs(int cur)
{
    vis[cur] = 1;         // 현재 정점(cur)을 방문 처리
    for (auto nxt : adj[cur])
    {
        // 인접 정점(nxt)이 이미 방문된 경우
        if (vis[nxt])
        {
            continue;     // 다음 정점으로 넘어감
        }

        ans++;            // 바이러스가 전파된 컴퓨터 수 증가
        dfs(nxt);         // 인접 정점에 대해 DFS 호출
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;           // 정점의 수와 간선의 수 입력
    while (e--)
    {
        cin >> a >> b;       // 간선의 두 끝점 입력
        adj[a].push_back(b); // 정점 a와 정점 b를 연결
        adj[b].push_back(a); // 정점 b와 정점 a를 연결 (양방향 그래프)
    }

    dfs(1);                  // 1번 정점에서부터 DFS 탐색 시작
    cout << ans;             // 감염된 컴퓨터 수 출력
}
