#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        //  multiset에 3, 1, 4, 1, 5를 삽입하면 multiset은 {1, 1, 3, 4, 5}로 저장, 중복을 허용 
        multiset<int> ms;
        while (k--)
        {
            char com;
            cin >> com;
            if (com == 'D')
            {
                int q;
                cin >> q;
                if (ms.empty()) continue;

                // ms.end()는 마지막 원소 다음이므로, prev(ms.end())는 마지막 원소
                if (q == 1) ms.erase(prev(ms.end()));

                else ms.erase(ms.begin());
            }
            else
            {
                int q;
                cin >> q;
                ms.insert(q);
            }
        }
        if (ms.empty()) cout << "EMPTY\n";
        else
        {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}