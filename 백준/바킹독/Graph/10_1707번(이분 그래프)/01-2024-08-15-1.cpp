#include <iostream>
#include <queue>

using namespace std;

// 테스트 케이스 수를 저장할 변수
int k;

// 정점의 수와 간선의 수를 저장할 변수
int v, e;

// 정점의 그룹을 나타내는 배열. 그룹은 0과 1로 나누어집니다.
// -1은 아직 방문하지 않은 상태를 의미합니다.
int gr[20002];

// 각 정점의 인접 리스트를 저장하는 벡터 배열
vector<int> adj[20002];

// 이분 그래프 판별을 위한 함수
bool solve()
{
    // 모든 정점의 그룹을 -1로 초기화하여 방문하지 않았음을 나타냅니다.
    fill(gr, gr + v + 1, -1);

    // 각 정점을 순회합니다.
    for (int i = 1; i <= v; i++)
    {
        // 만약 정점 i가 이미 방문된 상태라면, 건너뜁니다.
        if (gr[i] != -1)
        {
            continue;
        }

        // BFS를 위한 큐를 선언하고, 현재 정점을 큐에 추가합니다.
        queue<int> q;
        q.push(i);

        // 현재 정점의 그룹을 0으로 설정합니다.
        gr[i] = 0;

        // BFS를 수행합니다.
        while (!q.empty())
        {
            // 큐에서 현재 정점을 꺼냅니다.
            int cur = q.front();
            q.pop();

            // 현재 정점과 연결된 모든 정점을 순회합니다.
            for (int nxt : adj[cur])
            {
                // 만약 연결된 정점이 이미 방문된 상태라면
                if (gr[nxt] != -1)
                {
                    // 현재 정점과 연결된 정점이 같은 그룹이라면 이분 그래프가 아닙니다.
                    if (gr[nxt] == gr[cur])
                    {
                        return false;
                    }
                    else
                    {
                        continue;
                    }
                }

                // 현재 정점의 그룹과 다른 그룹으로 다음 정점의 그룹을 설정합니다.
                gr[nxt] = (gr[cur] + 1) % 2;

                // 다음 정점을 큐에 추가합니다.
                q.push(nxt);
            }
        }
    }
    // 모든 정점을 순회했는데도 문제가 없다면, 이분 그래프입니다.
    return true;
}

int main(void)
{
    // 빠른 입출력을 위한 설정입니다.
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 테스트 케이스 수를 입력받습니다.
    cin >> k;

    // 각 테스트 케이스를 처리합니다.
    while (k--)
    {
        // 정점의 수와 간선의 수를 입력받습니다.
        cin >> v >> e;

        // 각 정점의 인접 리스트를 초기화합니다.
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
        }

        // 간선 정보를 입력받아 인접 리스트를 구성합니다.
        int i, j;
        while (e--)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        // 이분 그래프 여부를 판별하고 결과를 출력합니다.
        if (solve())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
