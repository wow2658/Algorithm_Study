#include <iostream>
#include <queue>

using namespace std;

// 그래프를 인접 리스트로 표현
vector<int> adj[1005];
// 방문 여부를 기록하는 배열
bool vis[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    // 그래프의 정점 수와 간선 수 입력
    cin >> n >> m;

    // 그래프 입력 처리
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        // 무방향 그래프이므로, 두 정점 간의 간선을 양방향으로 추가
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS를 사용하여 연결 요소의 개수를 셀 변수
    int num = 0;

    // 모든 정점을 검사
    for (int i = 1; i <= n; i++)
    {
        // 현재 정점이 이미 방문된 경우, 새로운 연결 요소가 아니므로 건너뜀
        if (vis[i]) continue;

        // 새로운 연결 요소를 발견했으므로, 개수를 증가시킴
        num++;

        // BFS 탐색을 위한 큐 초기화
        queue<int> q;
        q.push(i);  // 시작 정점 큐에 추가
        vis[i] = true;  // 시작 정점 방문 처리

        // BFS 탐색
        while (!q.empty())
        {
            int cur = q.front(); // 큐에서 현재 정점 추출
            q.pop();

            // 현재 정점과 연결된 모든 인접 정점 탐색
            for (auto nxt : adj[cur])
            {
                // 인접 정점이 이미 방문된 경우, 큐에 추가하지 않음
                if (vis[nxt]) continue;

                // 인접 정점이 방문되지 않은 경우, 큐에 추가하고 방문 처리
                q.push(nxt);
                vis[nxt] = true;  // 인접 정점 방문 처리
            }
        }
    }

    // 연결 요소의 개수 출력
    cout << num;
}
