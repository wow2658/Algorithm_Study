#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 1000000 // 최대 비밀번호 값
#define INF -1 // 거리의 초기값 (도달 불가)

// 거리 배열을 정의
int dist[MAX_N + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, tmp;

    // 비밀번호의 최대값 입력
    cin >> n;
    // 로그인 시도에 사용된 비밀번호 개수 입력
    cin >> m;

    // 로그인 시도 비밀번호들을 저장할 벡터
    vector<int> start;
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp;
        start.push_back(tmp);
    }

    // 거리 배열을 -1로 초기화 (도달 불가 상태를 의미)
    fill(dist, dist + n + 2, INF);

    // BFS를 위한 큐
    queue<int> q;
    // 로그인 시도 비밀번호들의 거리값을 0으로 설정하고 큐에 추가
    for (const auto& e : start)
    {
        dist[e] = 0;
        q.push(e);
    }

    // BFS 탐색 시작
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 현재 비밀번호에서 비트를 하나씩 뒤집어서 새로운 비밀번호 생성
        // 1000000이면 20비트로 표현가능하긴 하지만, 보통 int32의 전체 비트를 고려하기 떄문
        for (int k = 0; k < 31; ++k)
        {
            int next;

            /*

            // 현재 비밀번호의 k번째 비트가 1이면 해당 비트를 0으로 변경
            if (cur & (1 << k))
            {
                next = cur & ~(1 << k);
            }
            else
            {
                // 현재 비밀번호의 k번째 비트가 0이면 해당 비트를 1로 변경
                next = cur | (1 << k);
            }

            */

            // 어차피 토글하는 기능이면 코드 한번에 처리가능 하지 않나?
            next = cur ^ (1 << k);

            // 새로운 비밀번호가 최대값을 초과하거나 이미 방문한 경우는 무시
            if (next > n || dist[next] >= 0)
            {
                continue;
            }

            // 새로운 비밀번호의 거리 값을 현재 비밀번호의 거리 + 1로 설정
            dist[next] = dist[cur] + 1;
            // 큐에 새로운 비밀번호 추가
            q.push(next);
        }
    }

    // 안전도가 제일 높은 비밀번호의 안전도 찾기
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = max(ans, dist[i]); // 최대 안전도 업데이트
    }

    // 결과 출력
    cout << ans;
    return 0;
}
