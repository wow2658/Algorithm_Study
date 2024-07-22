#include <iostream>
#include <queue>
using namespace std;

// 위치 배열의 최대 한계를 정의하고 여분의 공간을 확보
const int LMT = 100001;
int board[LMT + 2];  // 방문한 위치와 시간을 추적하기 위한 배열
int prePos[LMT + 2]; // 이번 풀이 핵심. 경로를 재구성하기 위해 이전 위치를 저장하는 배열
int sis, bro;        // 수빈이와 동생의 위치를 저장하는 변수
queue<int> Q;        // BFS를 위한 큐

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 수빈이와 동생의 초기 위치를 입력받음
    cin >> sis >> bro;

    // BFS 시작 위치 초기화
    board[sis] = 1; // 시작 위치를 방문했음을 표시하고 시간 1로 설정
    prePos[sis] = sis; // 시작 위치의 이전 위치는 자기 자신으로 설정
    Q.push(sis); // 시작 위치를 큐에 넣음

    // 최단 경로를 찾기 위한 BFS 수행
    while (!board[bro])
    {
        // 동생의 위치를 찾을 때까지 반복
        int v = Q.front(); Q.pop(); // 현재 위치를 큐에서 꺼냄
        for (int nv : { v + 1, v - 1, 2 * v }) // 가능한 다음 위치를 확인
        { 
            if (nv < 0 || LMT <= nv) continue; // 경계를 벗어나는 위치는 무시
            if (board[nv]) continue; // 이미 방문한 위치는 무시
            board[nv] = board[v] + 1; // 방문 시간 기록 (현재 시간 + 1)
            prePos[nv] = v; // 이전 위치를 저장
            Q.push(nv); // 새로운 위치를 큐에 넣음
        }
    }

    // 동생의 위치에 도달하는 최소 시간을 출력
    cout << board[bro] - 1 << '\n'; // 1-based time을 0-based로 변환하여 출력

    // 이동 경로를 재구성하고 출력
    deque<int> track = { bro }; // 동생의 위치에서 시작
    while (track.front() != sis) // 시작 위치에 도달할 때까지 반복
        track.push_front(prePos[track.front()]); // 이전 위치를 앞에 추가
    for (int p : track) cout << p << ' '; // 경로를 출력

}
