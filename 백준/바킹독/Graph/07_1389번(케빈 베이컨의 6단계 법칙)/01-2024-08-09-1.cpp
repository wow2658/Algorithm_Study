#include <iostream>
#include <queue>

using namespace std;

// 최대 유저 수 (문제에서 최대 100명)
const int MX = 100;

// 무한을 의미하는 값
const int INF = 0x7f7f7f7f;

// 각 유저의 친구 관계를 저장할 인접 리스트
vector<int> adj[MX + 2];

// 각 유저까지의 최단 거리를 저장할 배열
int dist[MX + 2];

// 케빈 베이컨 수의 최소값과 그 값을 가진 유저 번호
int mn = INF, ans;

// BFS를 사용하여 주어진 시작 정점에서의 케빈 베이컨 수를 계산하는 함수
int bfs(int st)
{
    // 큐를 사용하여 BFS 탐색을 수행
    queue<int> q;

    // 현재 유저까지의 거리 합계
    int sum = 0;

    // 시작 정점의 거리를 0으로 설정
    dist[st] = 0;

    // 시작 정점을 큐에 추가
    q.push(st);

    // 큐가 비어있지 않을 때까지 반복
    while (!q.empty())
    {
        // 큐에서 현재 정점을 꺼냄
        int cur = q.front();
        q.pop();

        // 현재 정점과 연결된 모든 인접 정점을 탐색
        for (int nxt : adj[cur])
        {
            // 인접 정점이 이미 방문된 경우 (거리 값이 0보다 큰 경우)
            if (dist[nxt] != -1)
            {
                continue; // 다음 인접 정점으로 넘어감
            }

            // 인접 정점의 거리를 현재 정점의 거리 + 1로 설정
            dist[nxt] = dist[cur] + 1;

            // 거리 합계에 현재 정점까지의 거리 추가
            sum += dist[nxt];

            // 인접 정점을 큐에 추가
            q.push(nxt);
        }
    }

    // 계산된 거리 합계를 반환
    return sum;
}

int main()
{
    // 빠른 입출력을 위한 설정
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 유저 수(n)와 친구 관계의 수(m) 입력
    int n, m;
    cin >> n >> m;

    // 친구 관계의 수만큼 반복
    while (m--)
    {
        // 각 친구 관계의 두 유저 번호(u, v) 입력
        int u, v;
        cin >> u >> v;

        // 양방향 그래프이므로 두 정점 모두에 대해 친구 관계 추가
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 모든 유저에 대해 케빈 베이컨 수를 계산
    for (int i = 1; i <= n; i++)
    {
        // 거리 배열을 초기화 (모든 거리를 -1로 설정)
        fill(dist, dist + n + 1, -1);

        // 현재 유저를 시작 정점으로 BFS 수행
        int sum = bfs(i);

        // 현재 유저의 케빈 베이컨 수가 최소값보다 작으면 갱신
        if (sum >= mn)
        {
            continue; // 현재 유저의 케빈 베이컨 수가 최소값보다 크면 넘어감
        }

        // 최소값과 유저 번호 갱신
        mn = sum;
        ans = i;
    }

    // 케빈 베이컨 수가 가장 작은 유저 번호 출력
    cout << ans;
}
