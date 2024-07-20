#include <iostream>
#include <queue>
using namespace std;

const int LMT = 100001; // 문제의 제한 범위 상수 (0 <= 위치 <= 100,000)

int board[LMT + 2]; // 방문 및 시간을 저장하는 배열
int sis, bro; // 수빈이의 위치와 동생의 위치
queue<int> Q; // BFS를 위한 큐

// 텔레포트를 통해 2의 거듭제곱 위치로 이동하는 함수
void teleport(int num)
{
    int tmp = num; // 텔레포트 위치를 저장할 변수
    if (!tmp) // num이 0이면 텔레포트 불가
    {
        return; // 함수 종료
    }
    while (tmp < LMT && !board[bro]) // 텔레포트 가능한 범위 내에서 동생을 아직 찾지 못했을 때
    {
        if (!board[tmp]) // tmp 위치를 아직 방문하지 않았으면
        {
            board[tmp] = board[num]; // 이동한 위치의 시간을 현재 위치의 시간과 동일하게 설정 (문제조건에서 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동한다고 했으므로)
            Q.push(tmp); // 텔레포트한 위치를 큐에 추가
            if (tmp == bro) // 텔레포트한 위치가 동생의 위치면
            {
                return; // 함수 종료
            }
        }
        tmp <<= 1; // 텔레포트: 현재 위치를 2배로 이동
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sis >> bro; // 수빈이와 동생의 위치 입력

    board[sis] = 1; // 수빈이의 초기 위치 시간 설정 (1로 설정하여 방문 표시)
    Q.push(sis); // 수빈이의 위치를 큐에 추가
    teleport(sis); // 초기 위치에서 텔레포트 시도. 텔포가 0초짜리니까 하나라도 여기에서 걸리면 땡큐라서 일단 쭉 돌리고 시작함.

    // BFS 시작
    while (!board[bro]) // 동생의 위치를 방문하기 전까지 반복
    {
        int v = Q.front(); // 큐의 첫 번째 요소를 가져옴 (현재 위치)
        Q.pop(); // 큐에서 현재 위치를 제거

        vector<int> nvLst = { v + 1, v - 1 }; // 걷는 경우의 다음 위치들

        for (int nv : nvLst) // 다음 위치들을 순회
        {
            if (nv < 0 || LMT <= nv) // 다음 위치가 범위를 벗어나면
            {
                continue; // 해당 위치는 무시
            }
            if (board[nv]) // 다음 위치를 이미 방문한 경우
            {
                continue; // 해당 위치는 무시
            }
            board[nv] = board[v] + 1; // 다음 위치의 시간을 현재 위치 시간 + 1로 설정
            Q.push(nv); // 다음 위치를 큐에 추가
            teleport(nv); // 다음 위치에서 텔레포트 시도
        }
    }

    cout << board[bro] - 1; // 동생의 위치에 도달하는 최소 시간 출력
    // 시작을 1로 놓기 때문에 한번도 이동안하고 찾아지면(텔포에 걸리거나, sis == bro일때) 시작1-1=0,
    // 세번 이동했을때 찾으면 시작1+3 = 4 인 결과에 -1 해서 3을 출력 

}
