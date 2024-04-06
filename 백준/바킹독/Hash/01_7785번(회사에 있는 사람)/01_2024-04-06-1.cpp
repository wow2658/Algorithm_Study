#if 1
#include <unordered_set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unordered_set<string> s;

bool compareDescending(const string& a, const string& b)
{
    return a > b;
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        string name, log;
        cin >> name >> log;
        if (log == "enter") s.insert(name);
        else s.erase(name);
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), compareDescending);
    for (const auto& x : ans) cout << x << '\n';

}
#else
#include <unordered_set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unordered_set<string> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        string name, log;
        cin >> name >> log;
        if (log == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans;
    for (const string& str : s)
    {
        ans.push_back(str);
    }
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto x : ans) cout << x << '\n';

}
#endif