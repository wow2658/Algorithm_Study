#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, m, st;            // 정점의 수, 간선의 수, 시작 정점
vector<int> adj[1001];   // 인접 리스트 (그래프 표현)
bool vis[1001];          // 방문 여부 배열

// 비재귀 DFS 탐색
void dfs1()
{
    stack<int> s;       // 정점을 저장할 스택
    s.push(st);         // 시작 정점을 스택에 추가

    while (!s.empty())  // 스택이 비어있지 않은 동안 반복
    {
        int cur = s.top(); // 스택의 가장 위에 있는 정점 추출
        s.pop();           // 추출한 정점을 스택에서 제거

        if (vis[cur])      // 현재 정점이 이미 방문된 경우
        {
            continue;      // 빠른 포기. 다음 정점으로 넘어감
        }

        vis[cur] = true;    // 현재 정점을 방문 처리
        cout << cur << ' '; // 현재 정점 출력

        // 인접 정점을 역순으로 스택에 추가
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int nxt = adj[cur][adj[cur].size() - 1 - i]; // 신기하다.
            if (vis[nxt]) // 인접 정점이 이미 방문된 경우
            {
                continue; // 다음 정점으로 넘어감
            }

            s.push(nxt);  // 인접 정점을 스택에 추가
        }
    }
}

// 재귀 DFS 탐색
void dfs2(int cur)
{
    vis[cur] = true; // 현재 정점을 방문 처리
    cout << cur << ' '; // 현재 정점 출력

    // 인접 정점에 대해 재귀 호출
    for (auto nxt : adj[cur])
    {
        if (vis[nxt]) // 인접 정점이 이미 방문된 경우
        {
            continue; // 다음 정점으로 넘어감
        }

        dfs2(nxt); // 아주 간단. 인접 정점에 대해 재귀 DFS 호출
    }
}

// BFS 탐색
void bfs()
{
    queue<int> q;      // 정점을 저장할 큐
    q.push(st);       // 시작 정점을 큐에 추가
    vis[st] = true;   // 시작 정점을 방문 처리

    while (!q.empty()) // 큐가 비어있지 않은 동안 반복
    {
        int cur = q.front(); // 큐의 가장 앞에 있는 정점 추출
        cout << cur << ' '; // 현재 정점 출력
        q.pop();           // 추출한 정점을 큐에서 제거

        // 인접 정점에 대해 큐에 추가
        for (auto nxt : adj[cur])
        {
            if (vis[nxt]) // 인접 정점이 이미 방문된 경우
            {
                continue; // 다음 정점으로 넘어감
            }

            q.push(nxt); // 인접 정점을 큐에 추가
            vis[nxt] = true; // 인접 정점을 방문 처리
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st; // 정점 수, 간선 수, 시작 정점 입력

    // 간선 정보를 입력받아 그래프 구성
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // u에서 v로 가는 간선 추가
        adj[v].push_back(u); // v에서 u로 가는 간선 추가
    }

    // 각 정점의 인접 리스트를 정렬 (정점 번호가 작은 순서대로 탐색하기 위해)
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    // 비재귀 DFS 탐색 수행
    dfs1(); // dfs2(st); // 주석 처리된 재귀 DFS도 사용할 수 있습니다.
    cout << '\n'; // DFS와 BFS 결과를 구분하기 위해 줄 바꿈

    // 방문 여부 배열 초기화
    fill(vis + 1, vis + n + 1, false);

    // BFS 탐색 수행
    bfs();
}
