#include <iostream>
#include <queue>

using namespace std;

// 최대 컴퓨터 수를 정의합니다 (문제의 최대값보다 약간 큽니다).
const int NMX = 10'002;

// 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 해킹 가능한 수를 저장할 변수입니다.
int mx;

// 각 컴퓨터에서 해킹 가능한 컴퓨터 수를 저장할 배열입니다.
int sc[NMX];

// 각 컴퓨터의 친구 관계를 저장할 인접 리스트입니다.
vector<int> adj[NMX];

// 방문 여부를 저장할 배열입니다.
bool vis[NMX];

// 깊이 우선 탐색(DFS)을 사용하여 해킹 가능한 컴퓨터 수를 계산하는 함수입니다.
void trav(int cur)
{
    // 현재 컴퓨터를 방문했음을 표시합니다.
    vis[cur] = 1;

    // 현재 컴퓨터의 해킹 가능한 컴퓨터 수를 증가시킵니다.
    sc[cur]++;

    // 가장 많은 해킹 가능한 컴퓨터 수를 업데이트합니다.
    mx = max(mx, sc[cur]);

    // 현재 컴퓨터와 연결된 모든 컴퓨터를 탐색합니다.
    for (int nxt : adj[cur])
    {
        // 이미 방문한 컴퓨터는 탐색하지 않습니다.
        if (vis[nxt])
        {
            continue;
        }

        // 다음 컴퓨터를 재귀적으로 탐색합니다.
        trav(nxt);
    }
}

int main()
{
    // 빠른 입출력을 위한 설정입니다.
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 컴퓨터 수(n)와 신뢰 관계의 수(m)를 입력받습니다.
    int n, m;
    cin >> n >> m;

    // 신뢰 관계 정보를 입력받아 인접 리스트를 구성합니다.
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        // u가 v를 신뢰하므로, v를 u의 인접 리스트에 추가합니다.
        adj[u].push_back(v);
    }

    // 각 컴퓨터에서의 해킹 가능한 컴퓨터 수를 초기화합니다.
    fill(sc, sc + NMX, 0);

    // 각 컴퓨터를 시작 정점으로 깊이 우선 탐색을 수행합니다.
    for (int i = 1; i <= n; i++)
    {
        // 방문 배열을 초기화합니다.
        fill(vis, vis + NMX, 0);

        // 컴퓨터 i에서 시작하여 해킹 가능한 컴퓨터 수를 계산합니다.
        trav(i);
    }

    // 가장 많은 해킹 가능한 컴퓨터 수를 가진 컴퓨터를 출력합니다.
    for (int i = 1; i <= n; i++)
    {
        // 현재 컴퓨터의 해킹 가능한 수가 가장 큰 수와 같으면 출력합니다.
        if (sc[i] == mx)
        {
            cout << i << ' ';
        }
    }
}

