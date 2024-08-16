#include <iostream>
#include <queue>

using namespace std;

// 구슬의 개수와 저울에 올려 본 쌍의 개수
int n, m;

// 구슬이 무거운 방향과 가벼운 방향을 저장하는 인접 리스트
vector<int> hv[101], li[101];

// 방문 여부를 체크하는 배열
bool vis[101];

// 구슬이 무게 순서의 중간에 있을 수 없는지 판별하는 함수
//bool solve(int st, vector<int>(&adj)[]) // 컴파일 오류
bool solve(int st, vector<int>(adj)[])
{
    // 방문 배열을 초기화하여 모든 정점을 미방문 상태로 설정
    fill(vis, vis + n + 1, 0);

    // BFS를 위한 큐 선언
    queue<int> q;

    // 시작 정점을 큐에 추가하고 방문 표시
    q.push(st);
    vis[st] = 1;

    // 현재 구슬보다 무거운/가벼운 구슬의 개수
    int cnt = 0;

    // BFS 수행
    while (!q.empty())
    {
        // 큐에서 현재 정점을 꺼냄
        int cur = q.front(); q.pop();

        // 현재 정점과 연결된 모든 정점을 순회
        for (int nxt : adj[cur])
        {
            // 이미 방문한 정점이면 건너뜀
            if (vis[nxt])
            {
                continue;
            }

            // 다음 정점을 큐에 추가하고 방문 표시
            q.push(nxt);
            vis[nxt] = 1;

            // 카운터 증가
            cnt++;
        }
    }

    // 현재 정점보다 무거운 구슬 또는 가벼운 구슬의 수가
    // 전체 구슬의 절반 이상이면 중간에 있을 수 없음
    return cnt >= (n + 1) / 2;
}

int main(void)
{
    // 빠른 입출력을 위한 설정
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 구슬의 개수와 저울에 올려 본 쌍의 개수를 입력받음
    cin >> n >> m;

    // 저울에 올려 본 쌍의 개수 만큼 반복
    while (m--)
    {
        // 구슬의 무게 비교 결과 입력받음
        int u, v;
        cin >> u >> v;

        // 구슬 u가 구슬 v보다 무겁다는 정보 저장
        hv[u].push_back(v);

        // 구슬 v가 구슬 u보다 가볍다는 정보 저장
        li[v].push_back(u);
    }

    // 무게가 중간이 될 수 없는 구슬의 개수
    int ans = 0;

    // 각 구슬에 대해 solve 함수 호출
    for (int i = 1; i <= n; i++)
    {
        // 구슬 i가 무게 중간 순서에 있을 수 없는 경우 증가
        ans += (solve(i, hv) || solve(i, li));
    }

    // 결과 출력
    cout << ans;
}
