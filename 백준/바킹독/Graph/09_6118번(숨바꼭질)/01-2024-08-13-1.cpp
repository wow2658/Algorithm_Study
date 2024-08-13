#include <iostream>
#include <queue>

using namespace std;

// 최대 헛간 수를 정의합니다.
const int MX = 20'000;

// 인접 리스트를 저장할 벡터입니다.
vector<int> adj[MX + 2];

// 거리 배열을 정의합니다. -1로 초기화하여 방문하지 않은 노드를 표시합니다.
int dist[MX + 2], mx;

int main()
{
    // 빠른 입출력을 위한 설정입니다.
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 거리 배열을 -1로 초기화합니다. 이 배열은 BFS 중 방문 여부와 거리 정보를 저장합니다.
    memset(dist, -1, sizeof(dist));

    // 헛간의 수(n)와 양방향 길의 수(m)을 입력받습니다.
    int n, m;
    cin >> n >> m;

    // 양방향 길의 정보를 입력받아 인접 리스트를 구성합니다.
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        // u와 v가 서로 연결되어 있으므로 양방향으로 추가합니다.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS를 위한 큐를 정의하고, 시작 노드(1)를 큐에 추가합니다.
    queue<int> q;
    q.push(1);

    // 시작 노드의 거리를 0으로 설정합니다.
    dist[1] = 0;

    // BFS를 수행합니다.
    while (!q.empty())
    {
        // 현재 노드를 큐에서 꺼냅니다.
        int cur = q.front();
        q.pop();

        // 현재 노드와 연결된 모든 노드를 탐색합니다.
        for (int nxt : adj[cur])
        {
            // 아직 방문하지 않은 노드만 탐색합니다.
            if (dist[nxt] != -1)
            {
                continue;
            }

            // 현재 노드를 통해 다음 노드에 도달할 수 있는 거리를 설정합니다.
            dist[nxt] = dist[cur] + 1;

            // 가장 먼 거리 값을 업데이트합니다.
            mx = max(dist[nxt], mx);

            // 다음 노드를 큐에 추가합니다.
            q.push(nxt);
        }
    }

    // 가장 먼 거리와 그 거리와 같은 거리를 가진 헛간의 수를 계산합니다.
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        // 현재 헛간이 가장 먼 거리와 같은 경우 처리합니다.
        if (dist[i] == mx)
        {
            // 가장 작은 헛간 번호를 찾기 위해 첫 번째로 출력합니다.
            if (!cnt)
            {
                cout << i << ' ';
            }

            // 거리가 같은 헛간의 수를 증가시킵니다.
            cnt++;
        }
    }

    // 가장 먼 거리와 같은 거리를 가진 헛간의 수를 출력합니다.
    cout << mx << ' ' << cnt;
}

