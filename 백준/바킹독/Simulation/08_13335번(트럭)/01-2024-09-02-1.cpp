#include <iostream>

using namespace std;

int n, w, L, ans;      // 트럭의 수, 다리의 길이, 최대하중, 걸린 시간을 저장할 변수
int bridge[101];       // 다리의 칸별 무게(트럭의 무게)를 저장하는 배열
queue<int> truck;      // 이동할 트럭의 목록을 저장하는 큐

// 다리가 비었는지 확인하는 함수
bool isEmpty()
{
    for (int i = 0; i < w; ++i)    // 다리의 각 칸을 확인
        if (bridge[i]) return false;   // 다리에 트럭이 있으면 false 반환
    return true;                      // 다리가 비어있으면 true 반환
}

// 트럭의 이동을 진행하는 함수
void go()
{
    for (int i = w - 1; i > 0; --i)  // 다리의 끝에서부터 앞쪽으로 이동
        bridge[i] = bridge[i - 1];  // 한 칸씩 뒤로 밀어줌
    bridge[0] = 0;                // 다리의 첫 칸은 비워줌
}

// 다리 위 트럭의 무게를 계산하는 함수
int calculate()
{
    int sum = 0;                 // 트럭 무게의 합을 저장할 변수 초기화
    for (int i = 0; i < w; ++i)   // 다리의 각 칸을 확인
        sum += bridge[i];        // 각 칸의 트럭 무게를 합산
    return sum;                  // 다리 위 트럭의 총 무게를 반환
}

int main(void)
{
    ios::sync_with_stdio(0);    // 입출력 속도 향상
    cin.tie(0);                 // 입출력 분리

    cin >> n >> w >> L;          // 트럭의 수, 다리 길이, 최대하중 입력 받음

    while (n--)                  // 트럭 수만큼 반복
    {                 
        int i;                   // 각 트럭의 무게를 저장할 변수
        cin >> i;                // 트럭의 무게 입력 받음
        truck.push(i);           // 트럭 목록 큐에 저장
    }

    do {
        int tmp = calculate();   // 현재 다리 위 트럭들의 총 무게 계산
        if (tmp <= L)             // 다리 위 무게가 최대하중을 넘지 않으면
        {
            tmp -= bridge[w - 1];  // 다리 끝에 도달한 트럭의 무게를 제외
            go();                  // 트럭을 한 칸씩 이동시킴

            if (!truck.empty() && (tmp + truck.front() <= L)) // 추가로 이동할 트럭이 있고, 다리가 무게를 버틸 경우
            {
                bridge[0] = truck.front();  // 다리의 첫 칸에 새로운 트럭 올림
                truck.pop();                // 트럭 큐에서 해당 트럭 제거
            }
        }
        ++ans;                   // 경과 시간 1 증가
    } while (!isEmpty());         // 모든 트럭이 다리를 건널 때까지 반복

    cout << ans;                 // 모든 트럭이 건너는 데 걸린 시간 출력
}
