#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        unordered_map<string, int> clothings;
        int N, ans = 1;
        cin >> N;
        string a, b;
        while (N--)
        {
            cin >> a >> b;
            clothings[b]++; // 관심있는건 second
        }
        for (auto v : clothings) ans *= v.second + 1; // {0, A} * {0, B, C}
        cout << ans - 1 << '\n'; // {0,0} 제외
    }
}