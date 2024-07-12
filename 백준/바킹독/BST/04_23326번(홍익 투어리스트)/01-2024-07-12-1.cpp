#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> hu; // 명소들의 위치를 저장할 집합
    int N, Q, t, curr = 1; // N: 구역의 개수, Q: 쿼리의 개수, t: 임시 변수, curr: 현재 위치
    cin >> N >> Q; // N과 Q 입력

    // 구역별 명소 여부 입력
    for (int i = 1; i <= N; i++)
    {
        cin >> t;            // 각 구역의 명소 여부 입력
        if (t) hu.insert(i); // 명소인 경우 집합에 위치 저장
    }

    // 쿼리 처리
    while (Q--)
    {
        cin >> t; // 쿼리 타입 입력
        switch (t)
        {
        case 1: // 명소 지정 또는 해제
            cin >> t; // 구역 번호 입력
            if (hu.find(t) != hu.end()) // 이미 명소인 경우
                hu.erase(t); // 명소에서 해제
            else
                hu.insert(t); // 명소로 지정
            break;

        case 2: // 시계 방향으로 이동
            cin >> t; // 이동할 칸 수 입력
            curr = (curr + t - 1) % N + 1; // 현재 위치 갱신 (위치 체계가 1-based이기 때문에 +1. 이걸 해주려면 미리 -1로 빼놔줘야 한다.)
            break;

        case 3: // 명소까지의 최단 거리 출력
            if (hu.empty()) // 명소가 없는 경우
                cout << -1 << '\n'; // -1 출력
            else
            {
                auto it = hu.lower_bound(curr); // 현재 위치보다 같거나 큰 첫 번째 명소 찾기
                if (it != hu.end()) // 찾은 경우
                    cout << *it - curr << '\n'; // 해당 명소까지의 거리 출력
                else
                    cout << N - curr + *hu.begin() << '\n'; // 못 찾은 경우 (순환 구조 고려)
            }
        }
    }
}
