#include <iostream>
#include <queue>

using namespace std;

int n; // 회원 수
vector<int> adj[52]; // 각 회원의 친구 관계를 저장하는 인접 리스트
vector<pair<int, int>> candsc; // 회장 후보 목록 (현재 사용되지 않음)
int score[52]; // 각 회원의 점수

// BFS를 사용하여 특정 회원의 점수를 계산하는 함수
int bfs(int st)
{
    queue<int> q; // BFS를 위한 큐
    int dist[52]; // 각 회원까지의 거리

    // 거리 배열을 초기화 (모든 값을 -1로 설정)
    fill(dist, dist + n + 1, -1);

    dist[st] = 0; // 시작 정점의 거리는 0
    q.push(st);   // 시작 정점을 큐에 추가

    while (!q.empty())
    {
        int cur = q.front(); // 큐에서 정점 꺼내기
        q.pop(); // 큐에서 정점 제거

        // 현재 정점의 모든 친구를 탐색
        for (int fr : adj[cur])
        {
            // 친구 정점이 이미 방문된 경우 continue
            if (dist[fr] != -1)
            {
                continue;
            }

            // 친구 정점의 거리를 현재 정점의 거리 + 1로 설정
            dist[fr] = dist[cur] + 1;

            // 친구 정점을 큐에 추가
            q.push(fr);
        }
    }

    // 가장 먼 정점까지의 거리 계산
    int val = *max_element(dist + 1, dist + n + 1);

    // 친구가 없는 경우 (거리가 0인 경우) 점수를 100으로 설정
    if (val == 0)
    {
        return 100;
    }

    return val;
}

int main()
{
    ios::sync_with_stdio(0); // I/O 성능 최적화
    cin.tie(0); // cin과 cout의 동기화를 해제

    cin >> n; // 회원 수 입력

    int u = 0, v = 0;

    // 입력으로 주어진 친구 관계를 인접 리스트에 저장
    while (u != -1 && v != -1)
    {
        cin >> u >> v;

        if (u != -1 && v != -1)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // 모든 회원에 대해 BFS를 수행하여 점수를 계산
    for (int i = 1; i <= n; i++)
    {
        score[i] = bfs(i);
    }

    // 가장 낮은 점수 찾기
    int mnscore = *min_element(score + 1, score + n + 1);

    vector<int> cand; // 후보 목록

    // 점수가 가장 낮은 회원들을 후보 목록에 추가
    for (int i = 1; i <= n; i++)
    {
        if (score[i] == mnscore)
        {
            cand.push_back(i);
        }
    }

    // 점수와 후보 수 출력
    cout << mnscore << ' ' << cand.size() << '\n';

    // 후보 목록을 오름차순으로 출력
    for (int c : cand)
    {
        cout << c << ' ';
    }
}
