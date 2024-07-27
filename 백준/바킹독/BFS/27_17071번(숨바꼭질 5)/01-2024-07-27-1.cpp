#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int LMT = 500'000; // 좌표의 최대값
int board[LMT + 2]; // 사용되지 않음
int vis[2][LMT + 2]; // 방문 여부와 시간을 저장하는 배열

// vis[0][x]는 짝수 시간에 수빈이가 위치 x를 방문한 시간을 기록
// vis[1][x]는 홀수 시간에 수빈이가 위치 x를 방문한 시간을 기록

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int bro, sis, ans = 0; // 동생 위치, 수빈 위치, 정답 변수 초기화
    queue<pair<int, int>> Q; // BFS를 위한 {위치, 시간} 큐
    cin >> sis >> bro; // 수빈과 동생의 초기 위치 입력
    Q.push({ sis, 0 }); // 수빈의 초기 위치와 시간을 큐에 삽입

    // 방문 배열을 초기화: -1은 아직 방문하지 않았음을 의미
    for (int i = 0; i < 2; i++)
    {
        fill(vis[i], vis[i] + LMT + 2, -1); // 방문 여부를 초기화
    }
    vis[0][sis] = 0; // 수빈의 초기 위치를 방문했다고 표시

    // BFS를 이용하여 수빈의 모든 가능한 위치와 시간을 탐색
    while (!Q.empty())
    {
        int v, vt, nvt; // 현재 위치, 현재 시간, 다음 시간
        tie(v, vt) = Q.front(); // 큐에서 현재 위치와 시간을 꺼냄
        nvt = vt + 1; // 다음 시간 계산
        Q.pop(); // 큐에서 현재 위치 제거

        // 수빈의 다음 가능한 위치를 계산 (순간이동, +1 이동, -1 이동)
        for (int nv : {2 * v, v + 1, v - 1})
        {
            // 다음 위치가 유효한 범위인지 확인
            if (nv < 0 || LMT < nv)
            {
                continue; // 범위를 벗어난 경우 무시
            }

            // 다음 위치가 이미 방문된 적이 있는지 확인
            if (vis[nvt % 2][nv] != -1)
            {
                continue; // 이미 방문한 경우 무시
            }

            vis[nvt % 2][nv] = nvt; // 다음 위치를 방문했다고 표시
            Q.push({ nv, nvt }); // 큐에 다음 위치와 시간을 삽입
        }
    }

    bool found = false; // 동생을 찾았는지 여부
    // 동생의 위치를 시간에 따라 갱신하며 수빈이 동생을 찾을 수 있는지 확인
    while (bro <= LMT)
    {
        // 현재 시간에 동생의 위치가 수빈의 방문 시간 내에 있는지 확인
        if (vis[ans % 2][bro] <= ans)
        {
            found = true; // 동생을 찾았음을 표시
            break; // 반복문 종료
        }
        bro += ++ans; // 동생의 다음 위치 계산 (이동 거리 증가)
    }

    // 동생을 찾았는지 여부에 따라 결과 출력
    if (found)
    {
        cout << ans; // 동생을 찾은 시간을 출력
    }
    else
    {
        cout << -1; // 동생을 찾을 수 없는 경우 -1 출력
    }
}

