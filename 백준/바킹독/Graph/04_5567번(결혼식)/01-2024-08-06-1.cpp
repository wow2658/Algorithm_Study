#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, m, a, b;         // 동기의 수(n), 친구 관계의 수(m), 친구 관계의 각 끝점(a, b)
vector<int> adj[505];   // 인접 리스트 (그래프의 표현)
int vis[505];           // 방문 여부 배열
int ans = 0;            // 초대할 사람의 수

// 깊이 우선 탐색 (DFS) 함수
void dfs()
{
    stack<int> s;       // 스택을 이용한 DFS 탐색을 위한 자료구조
    s.push(1);         // 상근이(1번 정점)부터 탐색 시작
    while (!s.empty())
    {
        int cur = s.top();  // 현재 정점
        s.pop();           // 스택에서 현재 정점을 제거
        if (vis[cur])      // 현재 정점이 이미 방문된 경우
        {
            continue;    // 다음 정점으로 넘어감
        }
        vis[cur] = 1;    // 현재 정점을 방문 처리

        for (auto nxt : adj[cur])
        {
            if (vis[nxt]) // 인접 정점(nxt)이 이미 방문된 경우
            {
                continue; // 다음 정점으로 넘어감
            }
            if (cur == 1) // 현재 정점이 상근이(1번)일 경우
            {
                s.push(nxt); // 상근이의 직접 친구는 스택에 추가
            }
            else
            {
                ans++; // 상근이의 친구의 친구는 초대 인원 수 증가
            }
            vis[nxt] = 1; // 인접 정점 방문 처리
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); // 빠른 입출력을 위한 설정
    cin.tie(0);              // 입력과 출력을 동기화하여 성능 개선

    cin >> n >> m;          // 동기의 수(n)와 친구 관계의 수(m) 입력

    while (m--)
    {
        cin >> a >> b;      // 친구 관계의 두 끝점(a, b) 입력
        adj[a].push_back(b); // 정점 a와 정점 b를 연결
        adj[b].push_back(a); // 정점 b와 정점 a를 연결 (양방향 그래프)
    }

    dfs();                // DFS 탐색 수행
    cout << ans;          // 초대할 사람의 수 출력
}
