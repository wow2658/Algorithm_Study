#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);

    int k, l;
    cin >> k >> l;


    unordered_map<string, int> signup{};
    for (int i = 0; i < l; ++i) // 딱 l번만 진행한다.
    {
        string student_num;
        cin >> student_num;

        if (signup.find(student_num) != signup.end()) // find 성공하면
        {
            signup.erase(student_num);                // 새로고침
            signup[student_num] = i;
        }
        else
            signup[student_num] = i;
    }



    vector<pair<string, int>> slist(signup.begin(), signup.end()); // 해시에서 정말 자주쓰이는 vector 생성자

    sort(slist.begin(), slist.end(), [](auto& a, auto& b) { return a.second < b.second; }); // 순번 오름차순 커스텀

    int en = min(k, (int)slist.size()); // 한명이 중복할수도 있으니까

    for (int i = 0; i < en; ++i)
        cout << slist[i].first << '\n'; // 학번


    return 0;
}
