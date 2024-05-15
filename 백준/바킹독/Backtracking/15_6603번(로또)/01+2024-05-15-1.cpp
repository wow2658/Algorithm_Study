#include <iostream>

using namespace std;

int k, input[20], arr[10];
bool isused[10];

void func(int cnt, int cur)
{
    if (cnt == 6) // 6개 다 골랐으면
    {
        for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    // 비내림차순
    // 중복선택x 중복출력x

    for (int i = cur; i < k; i++)
    {
        if (!isused[i])
        {
            arr[cnt] = input[i];
            isused[i] = 1;
            func(cnt + 1, i + 1);
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        cin >> k;
        if (k == 0) break; // 마지막줄 0검출
        for (int i = 0; i < k; i++) cin >> input[i]; // 첫수만큼 집합형성
        func(0, 0);
        cout << '\n';
    }
}