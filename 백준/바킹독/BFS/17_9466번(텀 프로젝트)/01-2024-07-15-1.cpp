#include <iostream>
using namespace std;

int arr[100005];    // 각 학생이 선택한 학생을 저장하는 배열
int n;              // 학생 수
int state[100005];  // 각 학생의 방문 상태를 저장하는 배열

const int NOT_VISITED = 0;  // 아직 방문하지 않은 상태를 나타내는 상수
const int CYCLE_IN = -1;    // 사이클에 속하는 학생을 나타내는 상수

// 주어진 학생 x로부터 시작해서 DFS를 수행하는 함수
void run(int x)
{
    int cur = x; // 현재 학생 번호를 저장
    while (true)
    {
        state[cur] = x; // 걸리기만하면 일단 이번 라운드인 x로 싹 체크. 현재 학생의 상태를 현재 DFS의 시작점으로 표시
        cur = arr[cur]; // cur학생은 다음으로 누굴 찍었나? 다음 학생으로 이동

        // 이번 DFS 방문에서 다시 방문한 학생에 도달했을 경우
        if (state[cur] == x)
        {
            // 사이클에 속하는 학생들을 사이클 상태로 변경
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        // 이전 DFS 방문에서 이미 방문한 학생에 도달했을 경우
        else if (state[cur] != 0)
        {
            return;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; // 테스트 케이스의 수
    cin >> t;

    while (t--)
    {
        cin >> n; // 학생 수 입력
        fill(state + 1, state + n + 1, 0); // 방문 상태 배열 초기화

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i]; // 각 학생이 선택한 학생 입력
        }

        for (int i = 1; i <= n; i++)
        {
            if (state[i] == NOT_VISITED)
            {
                run(i); // 방문하지 않은 학생에 대해 DFS 수행
            }
        }

        int cnt = 0; // 사이클에 속하지 않는 학생 수를 세는 변수

        for (int i = 1; i <= n; i++)
        {
            if (state[i] != CYCLE_IN)
            {
                cnt++; // 사이클에 속하지 않는 학생을 카운트
            }
        }

        cout << cnt << '\n'; // 결과 출력
    }
}
