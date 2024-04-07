#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string i2s[100005];
unordered_map<string, int> s2i;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> i2s[i];      // string 배열의 한계 : i로s 찾기는 가능하지만 s로i 찾기는 불가능하다.
        s2i[i2s[i]] = i;    // 그래서 i2s[i](string)과 i를 짝 지어줘서 s로i찾기 전용 컨테이너를 따로 마련한 것
    }

    while (m--)
    {
        string query;
        cin >> query;
        if (isdigit(query[0]))                    // 이 부분도 떠올리기 쉽지않다.
            cout << i2s[stoi(query)] << '\n';     // int배열이었으면 그냥 query썼으면 되는데 string배열로 만들어놔서 stoi한번 거치고 간것
        else
            cout << s2i[query] << '\n';
    }
}
