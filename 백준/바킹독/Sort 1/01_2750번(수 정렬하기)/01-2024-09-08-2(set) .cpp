#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, t;
    set<int> s;  // 정수를 저장할 set (중복 제거, 자동 정렬)

    cin >> N;
    while (N--)
    {
        cin >> t;  // 정수 t(1 ≤ t ≤ 1,000) 입력
        s.insert(t);  // set에 t 삽입 (자동으로 중복 제거 및 정렬)
    }

    // set에 저장된 값을 오름차순으로 출력
    for (auto x : s)
    {
        cout << x << '\n';  // 하나씩 출력
    }
}
